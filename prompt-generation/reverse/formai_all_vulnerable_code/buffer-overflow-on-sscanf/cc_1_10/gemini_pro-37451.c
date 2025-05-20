//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define MAX_PATH 1024

typedef struct proc_info {
	pid_t pid;
	char *name;
	long rss;
	long vms;
} proc_info;

int compare_procs(const void *a, const void *b) {
	proc_info *p1 = (proc_info *)a;
	proc_info *p2 = (proc_info *)b;

	return p1->rss - p2->rss;
}

int main(void) {
	DIR *proc_dir;
	struct dirent *entry;
	char path[MAX_PATH];
	int fd;
	char buf[1024];
	long rss, vms;
	int i, count = 0;
	proc_info *procs;

	proc_dir = opendir(PROC_DIR);
	if (proc_dir == NULL) {
		perror("opendir");
		return 1;
	}

	while ((entry = readdir(proc_dir)) != NULL) {
		if (entry->d_type != DT_DIR)
			continue;

		if (sscanf(entry->d_name, "%d", &i) != 1)
			continue;

		count++;
	}
	rewinddir(proc_dir);

	procs = malloc(sizeof(proc_info) * count);
	if (procs == NULL) {
		perror("malloc");
		closedir(proc_dir);
		return 1;
	}

	count = 0;
	while ((entry = readdir(proc_dir)) != NULL) {
		if (entry->d_type != DT_DIR)
			continue;

		if (sscanf(entry->d_name, "%d", &i) != 1)
			continue;

		procs[count].pid = i;

		snprintf(path, MAX_PATH, "%s/%d/comm", PROC_DIR, i);
		fd = open(path, O_RDONLY);
		if (fd == -1) {
			perror("open");
			continue;
		}

		if (read(fd, buf, sizeof(buf)) == -1) {
			perror("read");
			close(fd);
			continue;
		}

		close(fd);
		buf[strlen(buf) - 1] = '\0';
		procs[count].name = strdup(buf);

		snprintf(path, MAX_PATH, "%s/%d/statm", PROC_DIR, i);
		fd = open(path, O_RDONLY);
		if (fd == -1) {
			perror("open");
			continue;
		}

		if (read(fd, buf, sizeof(buf)) == -1) {
			perror("read");
			close(fd);
			continue;
		}

		close(fd);
		sscanf(buf, "%ld %ld", &rss, &vms);
		procs[count].rss = rss;
		procs[count].vms = vms;

		count++;
	}
	closedir(proc_dir);

	qsort(procs, count, sizeof(proc_info), compare_procs);

	for (i = 0; i < count; i++) {
		printf("%5d %10s %10ld %10ld\n",
		       procs[i].pid,
		       procs[i].name,
		       procs[i].rss,
		       procs[i].vms);
	}

	return 0;
}