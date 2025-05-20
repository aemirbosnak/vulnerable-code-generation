//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    pid_t pid;
    char name[256];
    int status;
} process_info;

int main() {
    // Get the current directory
    char cwd[256];
    getcwd(cwd, sizeof(cwd));

    // Open the directory
    DIR *dir = opendir(cwd);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Get the list of files in the directory
    struct dirent *dent;
    while ((dent = readdir(dir)) != NULL) {
        // Check if the file is a directory
        struct stat sb;
        if (stat(dent->d_name, &sb) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(sb.st_mode)) {
            // Recursively call the function to get the list of files in the subdirectory
            printf("%s/\n", dent->d_name);
            main(dent->d_name);
        } else {
            // Check if the file is a process file
            if (strstr(dent->d_name, "proc/") != NULL) {
                // Get the process ID
                pid_t pid = atoi(dent->d_name + 5);

                // Get the process name
                char name[256];
                sprintf(name, "/proc/%d/comm", pid);
                int fd = open(name, O_RDONLY);
                if (fd == -1) {
                    perror("open");
                    continue;
                }

                if (read(fd, name, sizeof(name)) == -1) {
                    perror("read");
                    close(fd);
                    continue;
                }

                close(fd);

                // Get the process status
                sprintf(name, "/proc/%d/status", pid);
                fd = open(name, O_RDONLY);
                if (fd == -1) {
                    perror("open");
                    continue;
                }

                char buf[1024];
                if (read(fd, buf, sizeof(buf)) == -1) {
                    perror("read");
                    close(fd);
                    continue;
                }

                close(fd);

                // Parse the process status
                char *ptr = strstr(buf, "State:");
                if (ptr == NULL) {
                    continue;
                }

                ptr += 7;
                while (*ptr == ' ') {
                    ptr++;
                }

                char *end = strchr(ptr, '\n');
                if (end == NULL) {
                    continue;
                }

                int status = *ptr;

                // Print the process information
                printf("%d %s %c\n", pid, name, status);
            }
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}