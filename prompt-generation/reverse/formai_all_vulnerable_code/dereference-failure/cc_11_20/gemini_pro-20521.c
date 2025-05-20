//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

int main() {
    char *proc_path = "/proc";
    DIR *proc_dir;
    struct dirent *proc_dirent;
    pid_t pid;
    char *pid_path;
    FILE *pid_file;
    char *status_path;
    FILE *status_file;
    char line[1024];
    char *field;
    int i;

    proc_dir = opendir(proc_path);
    if (proc_dir == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((proc_dirent = readdir(proc_dir)) != NULL) {
        pid = atoi(proc_dirent->d_name);
        if (pid > 0) {
            pid_path = malloc(strlen(proc_path) + strlen(proc_dirent->d_name) + 1);
            if (pid_path == NULL) {
                perror("malloc");
                exit(1);
            }
            sprintf(pid_path, "%s/%s", proc_path, proc_dirent->d_name);

            status_path = malloc(strlen(pid_path) + strlen("/status") + 1);
            if (status_path == NULL) {
                perror("malloc");
                exit(1);
            }
            sprintf(status_path, "%s/status", pid_path);

            status_file = fopen(status_path, "r");
            if (status_file == NULL) {
                perror("fopen");
                exit(1);
            }

            i = 0;
            while (fgets(line, sizeof(line), status_file) != NULL) {
                field = strtok(line, ":");
                if (field != NULL) {
                    printf("%s", field);
                    field = strtok(NULL, "\n");
                    if (field != NULL) {
                        printf(": %s", field);
                    }
                }
                i++;
                if (i == 1) {
                    printf("\n");
                }
            }

            fclose(status_file);
            free(status_path);
            free(pid_path);
        }
    }

    closedir(proc_dir);

    return 0;
}