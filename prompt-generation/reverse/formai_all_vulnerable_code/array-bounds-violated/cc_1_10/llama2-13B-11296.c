//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUMBER_OF_CHILDREN 8

// Function to print a happy message
void print_happy_message() {
    printf("Happy coding! 😊👍💻\n");
}

// Function to print an error message
void print_error_message(char *message) {
    printf("Oops! 😟😠 %s\n", message);
}

// Function to create a new process
pid_t create_process(char *command) {
    // Create a new process
    pid_t pid = fork();

    // If the fork() fails, print an error message
    if (pid < 0) {
        print_error_message("Fork failed!");
        return 1;
    }

    // If the fork() succeeds, print a happy message
    else if (pid > 0) {
        print_happy_message();
    }

    // If the fork() succeeds and we are in the parent process...
    else {
        // Execute the command
        if (execv(command, &command) < 0) {
            print_error_message("Exec failed!");
            return 1;
        }
    }

    return 0;
}

int main() {
    // Print a happy message
    print_happy_message();

    // Create a new process
    char command[] = "ls -l";
    create_process(command);

    // Create another new process
    command[0] = 'd';
    command[1] = 'i';
    command[2] = 'r';
    command[3] = 't';
    command[4] = 'y';
    command[5] = 'u';
    command[6] = 'm';
    command[7] = 'p';
    command[8] = 0;
    create_process(command);

    // Wait for all children to finish
    wait(NULL);

    // Print a happy message again
    print_happy_message();

    return 0;
}