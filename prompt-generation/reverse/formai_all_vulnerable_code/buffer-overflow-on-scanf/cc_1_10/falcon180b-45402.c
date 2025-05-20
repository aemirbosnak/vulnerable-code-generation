//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[50];
    int pid;
} process_t;

void read_processes(char *folder, process_t *processes) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    dir = opendir(folder);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char path[100];
            sprintf(path, "%s/%s", folder, ent->d_name);

            int fd = open(path, O_RDONLY);
            if (fd > 0) {
                char buffer[BUFFER_SIZE];
                memset(buffer, 0, BUFFER_SIZE);
                int bytes_read = read(fd, buffer, BUFFER_SIZE);

                if (bytes_read > 0) {
                    char *token = strtok(buffer, " ");
                    while (token!= NULL) {
                        if (strncmp(token, "PID=", 4) == 0) {
                            sscanf(token, "PID=%d", &processes[count].pid);
                        } else if (strncmp(token, "Name=", 5) == 0) {
                            strcpy(processes[count].name, token + 5);
                        }

                        token = strtok(NULL, " ");
                        count++;
                    }
                }

                close(fd);
            }
        }

        closedir(dir);
    }
}

void print_processes(process_t *processes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (PID: %d)\n", processes[i].name, processes[i].pid);
    }
}

int main() {
    char folder[50];
    printf("Enter the folder path: ");
    scanf("%s", folder);

    process_t processes[100];
    int count = 0;

    read_processes(folder, processes);
    print_processes(processes, count);

    return 0;
}