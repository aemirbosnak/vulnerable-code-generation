//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

typedef struct {
    int pid;
    char name[16];
} process;

void read_processes(process *procs, int count) {
    DIR *dir;
    struct dirent *ent;
    char path[20];
    int i = 0;

    snprintf(path, sizeof(path), "/proc");
    dir = opendir(path);

    if (dir) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(path, sizeof(path), "/proc/%s/stat", ent->d_name);
                int fd = open(path, O_RDONLY);
                if (fd >= 0) {
                    char buffer[1024];
                    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
                    close(fd);

                    if (bytes_read > 0) {
                        char *token = strtok(buffer, " ");
                        while (token!= NULL) {
                            if (i == count) {
                                break;
                            }
                            if (strcmp(token, "pid") == 0) {
                                token = strtok(NULL, " ");
                                procs[i].pid = atoi(token);
                            } else if (strcmp(token, "comm") == 0) {
                                token = strtok(NULL, " ");
                                strncpy(procs[i].name, token, sizeof(procs[i].name) - 1);
                            }
                            token = strtok(NULL, " ");
                            i++;
                        }
                    }
                }
            }
        }
        closedir(dir);
    }
}

void print_processes(process *procs, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", procs[i].pid, procs[i].name);
    }
}

int main() {
    process procs[100];
    int count = 0;

    read_processes(procs, 100);
    print_processes(procs, count);

    return 0;
}