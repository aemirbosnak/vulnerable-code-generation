//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>

typedef struct {
    pid_t pid;
    char name[16];
} process_t;

int compare_processes(const void *a, const void *b) {
    const process_t *p1 = a;
    const process_t *p2 = b;
    return strcmp(p1->name, p2->name);
}

int main() {
    DIR *dir;
    struct dirent *ent;
    int fd;
    char path[1024];
    pid_t pid;
    char name[16];
    process_t *processes = NULL;
    int num_processes = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(path, sizeof(path), "/proc/%s", ent->d_name);
                if ((fd = open(path, O_RDONLY))!= -1) {
                    if (fscanf(fd, "%d", &pid) == 1) {
                        snprintf(name, sizeof(name), "%d", pid);
                        processes = realloc(processes, sizeof(process_t) * ++num_processes);
                        processes[num_processes - 1].pid = pid;
                        strncpy(processes[num_processes - 1].name, name, sizeof(processes[num_processes - 1].name));
                    }
                    close(fd);
                }
            }
        }
        closedir(dir);

        qsort(processes, num_processes, sizeof(process_t), compare_processes);

        for (int i = 0; i < num_processes; i++) {
            printf("%-5d %-16s\n", processes[i].pid, processes[i].name);
        }

        free(processes);
    } else {
        perror("opendir");
    }

    return 0;
}