//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

int main() {
    pid_t child_pid;
    int status;
    int cpid;
    DIR *dir;
    struct dirent *de;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Could not open /proc");
        exit(1);
    }

    while ((de = readdir(dir))!= NULL) {
        if (strncmp(de->d_name, ".", strlen(".")) == 0 || strncmp(de->d_name, "..", strlen("..")) == 0) {
            continue;
        }

        cpid = atoi(de->d_name);
        child_pid = fork();

        if (child_pid == 0) {
            printf("Child process ID: %d\n", getpid());
            printf("Parent process ID: %d\n", getppid());
            printf("Process name: %s\n", de->d_name);
            printf("Process status: %s\n", (waitpid(child_pid, &status, 0) == -1)? "Unknown" : "Running");
            printf("Process ID: %d\n", cpid);
            printf("Process environment variables:\n");
            for (int i = 0; i < 10; i++) {
                char* var = getenv(de->d_name);
                if (var!= NULL) {
                    printf("%s = %s\n", de->d_name, var);
                } else {
                    printf("%s = (null)\n", de->d_name);
                }
            }
            printf("Parent process ID: %d\n", getppid());
            printf("Parent process name: %s\n", "parent");
            printf("Parent process status: %s\n", "running");
            exit(0);
        } else {
            if (waitpid(child_pid, &status, 0) == -1) {
                perror("waitpid");
            }
            printf("Parent process ID: %d\n", getppid());
            printf("Parent process name: %s\n", "parent");
            printf("Parent process status: %s\n", (waitpid(child_pid, &status, 0) == -1)? "Unknown" : "Running");
            exit(0);
        }
    }

    closedir(dir);
    return 0;
}