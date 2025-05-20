//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define MAX_PATH_LEN 1024
#define MAX_PROCESSES 1024

struct process {
    pid_t pid;
    char *name;
    char *path;
    char *args;
};

int compare_processes(const void *a, const void *b) {
    struct process *pa = (struct process *)a;
    struct process *pb = (struct process *)b;
    return pa->pid - pb->pid;
}

int main(int argc, char **argv) {
    DIR *procdir;
    struct dirent *dirent;
    char path[MAX_PATH_LEN];
    char line[MAX_PATH_LEN];
    char *s, *t;
    int fd, ret;
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    procdir = opendir("/proc");
    if (procdir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((dirent = readdir(procdir)) != NULL) {
        if (sscanf(dirent->d_name, "%d", &processes[num_processes].pid) != 1) {
            continue;
        }

        snprintf(path, sizeof(path), "/proc/%s/status", dirent->d_name);
        fd = open(path, O_RDONLY);
        if (fd == -1) {
            perror("open");
            continue;
        }

        ret = read(fd, line, sizeof(line) - 1);
        close(fd);
        if (ret == -1) {
            perror("read");
            continue;
        }
        line[ret] = '\0';

        processes[num_processes].name = strchr(line, ' ') + 1;
        s = strchr(processes[num_processes].name, '(');
        processes[num_processes].name[s - processes[num_processes].name - 1] = '\0';

        t = strrchr(line, ')');
        processes[num_processes].args = t + 2;

        snprintf(path, sizeof(path), "/proc/%s/cwd", dirent->d_name);
        processes[num_processes].path = realpath(path, NULL);

        num_processes++;
    }

    closedir(procdir);

    qsort(processes, num_processes, sizeof(struct process), compare_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("%5d %s %s %s\n", processes[i].pid, processes[i].name, processes[i].args, processes[i].path);
    }

    return EXIT_SUCCESS;
}