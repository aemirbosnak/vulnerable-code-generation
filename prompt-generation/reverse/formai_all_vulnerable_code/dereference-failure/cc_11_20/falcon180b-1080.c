//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[64];
    int status;
} process_t;

int main() {
    int num_processes = 0;
    int fd;
    char buf[BUF_SIZE];
    process_t *processes = (process_t *) malloc(MAX_PROCESSES * sizeof(process_t));
    memset(processes, 0, MAX_PROCESSES * sizeof(process_t));

    fd = open("/proc", O_RDONLY);
    if (fd == -1) {
        printf("Error opening /proc directory: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        int i;
        for (i = 0; i < num_processes; i++) {
            if (processes[i].status == 0) {
                int ret = read(fd, buf, BUF_SIZE);
                if (ret <= 0) {
                    printf("Error reading /proc directory: %s\n", strerror(errno));
                    return 1;
                }

                char *token = strtok(buf, "\n");
                while (token!= NULL) {
                    if (sscanf(token, "%d", &processes[i].pid) == 1) {
                        processes[i].status = 1;
                        break;
                    }
                    token = strtok(NULL, "\n");
                }
                if (processes[i].status == 1) {
                    num_processes++;
                }
            }
        }

        if (num_processes == MAX_PROCESSES) {
            break;
        }

        usleep(100000);
    }

    close(fd);

    while (1) {
        int i;
        printf("Enter process ID to view:\n");
        scanf("%d", &i);
        for (int j = 0; j < num_processes; j++) {
            if (processes[j].pid == i) {
                printf("Name: %s\n", processes[j].name);
                printf("Status: %d\n", processes[j].status);
                break;
            }
        }
    }

    return 0;
}