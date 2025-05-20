//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <math.h>

#define NUMBER_OF_POINTS 1000000
#define NUMBER_OF_PROCESSES 4

void estimate_pi(int number_of_points, int write_fd) {
    int inside_circle = 0;
    double x, y;
    
    // Seed for random number generation
    srand(time(NULL) ^ (getpid() << 16));

    // Generate random points and check if they fall within the unit circle
    for (int i = 0; i < number_of_points; i++) {
        x = (double)rand() / (double)RAND_MAX; // Generate random x
        y = (double)rand() / (double)RAND_MAX; // Generate random y
        if (sqrt(x * x + y * y) <= 1.0) {
            inside_circle++;
        }
    }
    
    // Send the result back to the parent process via pipe
    write(write_fd, &inside_circle, sizeof(inside_circle));
}

int main() {
    int pipe_fd[2]; // Pipe for communication
    pid_t pid;
    int total_inside_circle = 0;
    int points_per_process = NUMBER_OF_POINTS / NUMBER_OF_PROCESSES;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < NUMBER_OF_PROCESSES; i++) {
        // Fork process
        pid = fork();
        if (pid < 0) {
            perror("fork");
            return EXIT_FAILURE;
        } else if (pid == 0) {
            // Child process
            close(pipe_fd[0]); // Close read end of the pipe
            estimate_pi(points_per_process, pipe_fd[1]);
            close(pipe_fd[1]); // Close write end of the pipe
            exit(0); // Exit child process
        }
    }

    // Parent process
    close(pipe_fd[1]); // Close write end of the pipe

    // Collect results from child processes
    for (int i = 0; i < NUMBER_OF_PROCESSES; i++) {
        int inside_circle;
        read(pipe_fd[0], &inside_circle, sizeof(inside_circle));
        total_inside_circle += inside_circle;
    }
    close(pipe_fd[0]); // Close read end of the pipe

    // Wait for all child processes to finish
    for (int i = 0; i < NUMBER_OF_PROCESSES; i++) {
        wait(NULL);
    }

    // Calculate Pi
    double pi_estimate = (double)(total_inside_circle) / (NUMBER_OF_POINTS) * 4.0;

    // Print result
    printf("Estimated value of Pi after %d points and %d processes: %f\n", NUMBER_OF_POINTS, NUMBER_OF_PROCESSES, pi_estimate);

    return EXIT_SUCCESS;
}