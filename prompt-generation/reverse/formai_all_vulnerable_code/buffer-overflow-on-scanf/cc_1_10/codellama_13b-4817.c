//Code Llama-13B DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>

    #define MAX_FILE_NAME 1024
    #define MAX_FILE_SIZE 1024*1024*1024

    int main() {
        char file_name[MAX_FILE_NAME];
        int file_size;
        char virus_name[] = "VIRUS.EXE";

        while (1) {
            printf("Enter file name: ");
            scanf("%s", file_name);

            struct stat file_stat;
            if (stat(file_name, &file_stat) == -1) {
                perror("stat");
                continue;
            }

            file_size = file_stat.st_size;
            if (file_size > MAX_FILE_SIZE) {
                printf("File size is too large.\n");
                continue;
            }

            int fd = open(file_name, O_RDONLY);
            if (fd == -1) {
                perror("open");
                continue;
            }

            char *buffer = malloc(file_size);
            if (buffer == NULL) {
                perror("malloc");
                continue;
            }

            read(fd, buffer, file_size);
            close(fd);

            if (strstr(buffer, virus_name) != NULL) {
                printf("Virus detected!\n");
                free(buffer);
                continue;
            }

            printf("File is clean.\n");
            free(buffer);
        }

        return 0;
    }