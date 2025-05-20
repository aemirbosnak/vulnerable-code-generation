//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_FILENAME 100

char buffer[MAX_LINE];
char filename[MAX_FILENAME];
int fd;

void create_file(char *filename) {
    fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1) {
        perror("Error creating file.");
        exit(EXIT_FAILURE);
    }

    printf("File created successfully.\n");
}

void open_file(char *filename) {
    fd = open(filename, O_RDWR);

    if (fd == -1) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully.\n");
}

void save_file(char *filename) {
    ssize_t bytes_written;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        bytes_written = write(fd, buffer, strlen(buffer) + 1);

        if (bytes_written == -1) {
            perror("Error writing to file.");
            exit(EXIT_FAILURE);
        }
    }

    printf("File saved successfully.\n");
}

int main(int argc, char *argv[]) {
    int choice;
    char command[MAX_FILENAME];

    while (1) {
        printf("\nText Editor\n");
        printf("1. Create new file\n");
        printf("2. Open existing file\n");
        printf("3. Save and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", filename);
                create_file(filename);
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%s", filename);
                open_file(filename);

                printf("Press Ctrl+Z and Enter to exit text editor and save changes.\n");
                while (1) {
                    if (fgets(buffer, sizeof(buffer), stdin) == NULL || feof(stdin)) {
                        save_file(filename);
                        break;
                    }
                }
                close(fd);
                break;

            case 3:
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}