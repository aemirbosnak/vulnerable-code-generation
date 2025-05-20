//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define MAX_PROC 2048
#define MAX_LINE 1024

typedef struct {
    int pid;
    char name[MAX_LINE];
    int status;
} Process;

void read_proc(int fd, char *filename) {
    char buffer[MAX_LINE];
    char *ptr;
    int count = 0;
    Process procs[MAX_PROC];

    while (count < MAX_PROC && read(fd, buffer, MAX_LINE) > 0) {
        ptr = strtok(buffer, "\n");
        while (ptr!= NULL) {
            if (count < MAX_PROC) {
                strcpy(procs[count].name, ptr);
                procs[count].pid = atoi(ptr);
                procs[count].status = 0;
                count++;
            }
            ptr = strtok(NULL, "\n");
        }
    }
    close(fd);

    for (int i = 0; i < count; i++) {
        waitpid(procs[i].pid, &procs[i].status, WNOHANG);
    }

    printf("Processes running:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %s %d\n", procs[i].pid, procs[i].name, procs[i].status);
    }
}

int main() {
    char filename[MAX_LINE];
    strcpy(filename, "/proc");

    DIR *dir;
    struct dirent *ent;
    dir = opendir(filename);

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            sprintf(filename, "/proc/%s", ent->d_name);
            int fd = open(filename, O_RDONLY);
            if (fd!= -1) {
                read_proc(fd, filename);
                close(fd);
            }
        }
    }

    closedir(dir);
    return 0;
}