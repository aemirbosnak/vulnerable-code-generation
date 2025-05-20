//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 20 // Buffer size for pipe

// Function prototypes
void squareChild(int read_fd);
void cubeChild(int read_fd);

// Main program
int main() {
    int fd_square[2]; // Pipe for square child
    int fd_cube[2];   // Pipe for cube child
    pid_t pid_square, pid_cube;

    // Create pipes
    if (pipe(fd_square) == -1 || pipe(fd_cube) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create square child process
    if ((pid_square = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid_square == 0) {
        // Child process for square
        close(fd_square[1]); // Close write end
        squareChild(fd_square[0]);
        exit(EXIT_SUCCESS);
    }

    // Create cube child process
    if ((pid_cube = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid_cube == 0) {
        // Child process for cube
        close(fd_cube[1]); // Close write end
        cubeChild(fd_cube[0]);
        exit(EXIT_SUCCESS);
    }

    // Parent process
    close(fd_square[0]); // Close read end of square pipe
    close(fd_cube[0]);   // Close read end of cube pipe

    // Sending numbers to children
    int numbers[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        write(fd_square[1], &numbers[i], sizeof(numbers[i]));
        write(fd_cube[1], &numbers[i], sizeof(numbers[i]));
    }

    close(fd_square[1]); // Close write end after sending data
    close(fd_cube[1]);   // Close write end after sending data

    // Wait for children to finish
    wait(NULL);
    wait(NULL);

    printf("Parent process finished.\n");
    return 0;
}

// Function for square child
void squareChild(int read_fd) {
    int num;
    while (read(read_fd, &num, sizeof(num)) > 0) {
        printf("Square of %d is %d\n", num, num * num);
    }
}

// Function for cube child
void cubeChild(int read_fd) {
    int num;
    while (read(read_fd, &num, sizeof(num)) > 0) {
        printf("Cube of %d is %d\n", num, num * num * num);
    }
}