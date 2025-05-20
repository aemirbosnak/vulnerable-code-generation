//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define BUFFER_SIZE 10
#define NUM_RANDOMS 20

void generate_random_numbers(int write_fd) {
    close(write_fd);
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < NUM_RANDOMS; i++) {
        int num = rand() % 100; // Generate random number between 0 and 99
        write(write_fd, &num, sizeof(int)); // Write to pipe
    }
    close(write_fd);
    exit(0); // Exit the child process after writing
}

void calculate_average(int read_fd) {
    close(read_fd);
    int num;
    int sum = 0, count = 0;
    
    while (read(read_fd, &num, sizeof(int)) > 0) {
        sum += num;
        count++;
    }
    
    if (count > 0) {
        float average = (float)sum / count;
        printf("Average of the generated random numbers is: %.2f\n", average);
    } else {
        printf("No numbers were read.\n");
    }
    
    close(read_fd);
    exit(0); // Exit the child process after processing
}

int main() {
    int pipe_fd[2];
    pid_t pid1, pid2;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }

    // Create the first child process for generating random numbers
    if ((pid1 = fork()) == -1) {
        perror("fork");
        return 1;
    }

    if (pid1 == 0) {
        close(pipe_fd[0]); // Close unused read end
        generate_random_numbers(pipe_fd[1]); // Call the function to write numbers
    }

    // Create the second child process for calculating the average
    if ((pid2 = fork()) == -1) {
        perror("fork");
        return 1;
    }

    if (pid2 == 0) {
        close(pipe_fd[1]); // Close unused write end
        calculate_average(pipe_fd[0]); // Call the function to read and calculate
    }

    // Parent process closes both ends of the pipe
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    // Wait for both children to complete
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    printf("Both child processes have completed.\n");
    return 0;
}