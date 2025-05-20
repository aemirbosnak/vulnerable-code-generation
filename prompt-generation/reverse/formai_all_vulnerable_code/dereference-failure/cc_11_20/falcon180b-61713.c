//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>

typedef struct {
    pid_t pid;
    char name[16];
    int status;
} process_t;

int main(int argc, char **argv) {
    char path[1024];
    DIR *dir;
    struct dirent *ent;
    int count = 0;
    process_t *processes = NULL;
    int max_processes = 100;
    int status;

    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    strcpy(path, argv[1]);
    strcat(path, "/");

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: %s is not a directory\n", path);
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
            sprintf(path + strlen(path), "/%s", ent->d_name);
            if (count >= max_processes) {
                printf("Maximum number of processes reached\n");
                break;
            }
            processes = realloc(processes, sizeof(process_t) * ++count);
            processes[count - 1].pid = fork();
            if (processes[count - 1].pid == -1) {
                printf("Error forking process\n");
                exit(1);
            } else if (processes[count - 1].pid == 0) {
                execlp("ls", "ls", path, NULL);
                exit(1);
            }
        }
    }

    closedir(dir);

    while (count > 0) {
        waitpid(processes[--count].pid, &status, WNOHANG);
    }

    return 0;
}