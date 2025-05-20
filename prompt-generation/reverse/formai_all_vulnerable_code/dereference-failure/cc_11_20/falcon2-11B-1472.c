//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
    char *dir_path = "/path/to/source";
    char *backup_path = "/path/to/backup";
    char *command = "tar -cvzf \"%s\" \"%s\"";

    if (mkdir(backup_path, 0777) == -1) {
        perror("mkdir");
        exit(1);
    }

    char *backup_file = (char *)malloc(strlen(backup_path) + strlen(".tar.gz") + 2);
    strcpy(backup_file, backup_path);
    strcat(backup_file, ".tar.gz");

    FILE *fd = popen(command, "w");
    if (fd == NULL) {
        perror("popen");
        exit(1);
    }

    int child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    } else if (child_pid == 0) {
        // Child process writes the backup file
        if (write(fd, command, sizeof(command))!= sizeof(command)) {
            perror("write");
            exit(1);
        }
        if (write(fd, dir_path, strlen(dir_path))!= strlen(dir_path)) {
            perror("write");
            exit(1);
        }
        if (write(fd, "\n", 1)!= 1) {
            perror("write");
            exit(1);
        }
        if (write(fd, backup_path, strlen(backup_path))!= strlen(backup_path)) {
            perror("write");
            exit(1);
        }
        if (write(fd, "\n", 1)!= 1) {
            perror("write");
            exit(1);
        }
        if (pclose(fd) == -1) {
            perror("pclose");
            exit(1);
        }
    } else {
        // Parent process waits for the child process to finish
        if (waitpid(child_pid, NULL, 0) == -1) {
            perror("waitpid");
            exit(1);
        }
    }

    printf("Backup created successfully\n");
    free(backup_file);
    return 0;
}