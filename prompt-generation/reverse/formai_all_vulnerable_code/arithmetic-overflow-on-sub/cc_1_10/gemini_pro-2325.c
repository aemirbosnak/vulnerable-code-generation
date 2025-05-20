//GEMINI-pro DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Define the maximum number of processes to be created
#define MAX_PROCESSES 10

// Define the maximum number of seconds to run the program
#define MAX_SECONDS 10

// Create an array of child process IDs
pid_t child_pids[MAX_PROCESSES];

// Create a function to generate a random number between two values
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Create a function to create a child process
pid_t create_child_process() {
    // Create a new child process
    pid_t child_pid = fork();

    // Check if the child process was created successfully
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // If the child process was created successfully, return the child process ID
    return child_pid;
}

// Create a function to wait for a child process to exit
void wait_for_child_process(pid_t child_pid) {
    // Wait for the child process to exit
    int status;
    waitpid(child_pid, &status, 0);

    // Check if the child process exited successfully
    if (WIFEXITED(status)) {
        printf("Child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));
    } else {
        printf("Child process %d exited abnormally\n", child_pid);
    }
}

// Create a function to run the program
void run_program() {
    // Get the current time
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    // Create a random number of child processes
    int num_processes = generate_random_number(1, MAX_PROCESSES);
    for (int i = 0; i < num_processes; i++) {
        child_pids[i] = create_child_process();
    }

    // Wait for the child processes to exit
    for (int i = 0; i < num_processes; i++) {
        wait_for_child_process(child_pids[i]);
    }

    // Get the current time
    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    // Calculate the time taken to run the program
    double time_taken = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Program took %f seconds to run\n", time_taken);
}

// Create a function to main
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Run the program
    run_program();

    return 0;
}