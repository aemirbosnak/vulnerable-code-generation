//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FILE_SIZE 1024
#define NUM_USERS 5
#define BUFFER_SIZE 1024

typedef struct user_info {
    int user_index;
    char filename[256];
} user_info_t;

int main() {
    user_info_t users[NUM_USERS];

    // Initialize the users
    for (int i = 0; i < NUM_USERS; i++) {
        users[i].user_index = i;
        users[i].filename[0] = '\0';
    }

    // Allocate shared memory for the files
    char* files = mmap(NULL, FILE_SIZE * NUM_USERS, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (files == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Main loop
    while (1) {
        int user_index;
        char command[BUFFER_SIZE];

        // Prompt the user for input
        printf("Enter your command (write/read/exit): ");
        fgets(command, BUFFER_SIZE, stdin);

        // Parse the command
        sscanf(command, "%d", &user_index);
        if (user_index == -1) {
            continue;
        }

        // Check if the user is allowed to access the file
        if (users[user_index].user_index!= user_index) {
            fprintf(stderr, "Access denied\n");
            continue;
        }

        // Open the file
        int fd = open(users[user_index].filename, O_RDWR);
        if (fd == -1) {
            perror("open");
            continue;
        }

        // Read or write the file
        if (strcmp(command, "write") == 0) {
            char* buffer = malloc(FILE_SIZE);
            if (buffer == NULL) {
                perror("malloc");
                continue;
            }
            ssize_t bytes_read = read(fd, buffer, FILE_SIZE);
            if (bytes_read == -1) {
                perror("read");
                continue;
            }
            close(fd);
            close(fd);
            mmap(buffer, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
            write(fd, buffer, FILE_SIZE);
            munmap(buffer, FILE_SIZE);
            close(fd);
        } else if (strcmp(command, "read") == 0) {
            char* buffer = malloc(FILE_SIZE);
            if (buffer == NULL) {
                perror("malloc");
                continue;
            }
            ssize_t bytes_read = read(fd, buffer, FILE_SIZE);
            if (bytes_read == -1) {
                perror("read");
                continue;
            }
            close(fd);
            close(fd);
            printf("%s\n", buffer);
            munmap(buffer, FILE_SIZE);
        } else {
            fprintf(stderr, "Invalid command\n");
        }
    }

    munmap(files, FILE_SIZE * NUM_USERS);
    return 0;
}