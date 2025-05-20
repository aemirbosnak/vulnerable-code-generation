//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>

#define MAX_PATH_LENGTH 4096
#define MAX_PROCESSES 1024
#define MAX_CMDLINE_LENGTH 256

struct process {
    pid_t pid;
    char *cmdline;
};

struct process processes[MAX_PROCESSES];
int num_processes = 0;

int read_processes() {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PATH_LENGTH];
    int fd;
    char buf[MAX_CMDLINE_LENGTH];
    int len;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (sscanf(ent->d_name, "%d", &processes[num_processes].pid) != 1) {
            continue;
        }

        snprintf(path, MAX_PATH_LENGTH, "/proc/%d/cmdline", processes[num_processes].pid);
        fd = open(path, O_RDONLY);
        if (fd == -1) {
            perror("open");
            continue;
        }

        len = read(fd, buf, MAX_CMDLINE_LENGTH - 1);
        if (len == -1) {
            perror("read");
            close(fd);
            continue;
        }

        buf[len] = '\0';
        processes[num_processes].cmdline = strdup(buf);
        close(fd);

        num_processes++;
    }

    closedir(dir);

    return 0;
}

int compare_processes(const void *a, const void *b) {
    const struct process *pa = a;
    const struct process *pb = b;

    return strcmp(pa->cmdline, pb->cmdline);
}

int main() {
    int i;

    if (read_processes() == -1) {
        return EXIT_FAILURE;
    }

    qsort(processes, num_processes, sizeof(struct process), compare_processes);

    for (i = 0; i < num_processes; i++) {
        printf("%d %s\n", processes[i].pid, processes[i].cmdline);
        free(processes[i].cmdline);
    }

    return EXIT_SUCCESS;
}