//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_FORTUNES 5
#define BUFFER_SIZE 256

// Fortune Teller options
const char *fortunes[NUM_FORTUNES] = {
    "You will discover a hidden talent.",
    "A great opportunity will come your way.",
    "Someone close to you will bring good news.",
    "You will encounter an exciting adventure.",
    "Happiness is in your near future."
};

// Function to generate a random fortune
void get_fortune(int write_fd) {
    srand(time(NULL) ^ (getpid() << 16)); // Seed with process ID
    int index = rand() % NUM_FORTUNES;
    write(write_fd, fortunes[index], strlen(fortunes[index]) + 1); // Send fortune
    close(write_fd);
    exit(0); // Exit the child process
}

int main() {
    int pipe_fd[2]; // Create a pipe
    pid_t pid;

    // Create the pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a new process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(pipe_fd[1]); // Close the write end of the pipe
        char fortune[BUFFER_SIZE];

        // Read fortune from the child process
        read(pipe_fd[0], fortune, sizeof(fortune));
        printf("Your fortune: %s\n", fortune);
        close(pipe_fd[0]); // Close the read end of the pipe

        // Wait for the child process to finish
        wait(NULL);
    } else { // Child process
        close(pipe_fd[0]); // Close the read end of the pipe
        get_fortune(pipe_fd[1]); // Generate and send the fortune
    }

    return 0;
}