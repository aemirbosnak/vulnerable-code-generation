//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main() {
    char buffer[MAX_BUF_SIZE];
    int fd;
    ssize_t read_size;
    int cnt = 0;
    int i, j;
    char **lines = (char **) malloc(sizeof(char*) * MAX_BUF_SIZE);

    // Open the file containing boot-time messages
    fd = open("/var/log/boot.log", O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open the file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the contents of the file into buffer
    read_size = read(fd, buffer, MAX_BUF_SIZE);
    if (read_size == -1) {
        fprintf(stderr, "Failed to read from the file.\n");
        exit(EXIT_FAILURE);
    }

    // Parse each line and store them in lines array
    lines[cnt] = strtok(buffer, "\n");
    while (lines[cnt] != NULL) {
        cnt++;
        lines[cnt] = strtok(NULL, "\n");
    }

    // Remove duplicate entries and unnecessary lines
    for(i=0; i<cnt; i++) {
        if(strstr(lines[i], "Started") != NULL || strstr(lines[i], "Stopping") != NULL) {
            for(j=i+1; j<cnt; j++) {
                if (strcmp(lines[i], lines[j]) == 0) {
                    memmove(&lines[j], &lines[j+1], (cnt - j) * sizeof(char*));
                    cnt--;
                    j--;
                }
            }
        }
        else {
            memmove(&lines[i], &lines[i+1], (cnt - i) * sizeof(char*));
            cnt--;
            i--;
        }
    }

    // Write the optimized contents back to the file
    fd = open("/var/log/boot.log", O_WRONLY | O_TRUNC);
    if (fd == -1) {
        fprintf(stderr, "Failed to open the file for writing.\n");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<cnt; i++) {
        write(fd, lines[i], strlen(lines[i]));
        write(fd, "\n", sizeof(char));
    }

    close(fd);
    free(lines);

    return 0;
}