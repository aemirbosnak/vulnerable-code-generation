//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define our cheerful program name
#define PROGRAM_NAME "HappySystemAdministration"

// Function to print a happy message
void print_happy_message(void) {
    printf("😊 Hello there! I'm here to help you with your system administration needs! 🎉\n");
}

// Function to print a sad message
void print_sad_message(void) {
    printf("😔 Oh no! It looks like we have a problem with your system. 😔\n");
}

// Function to check if a process is running
int is_process_running(const char *process_name) {
    int pid = 0;
    FILE *fp = NULL;

    // Try to open the process's pid file
    if ((fp = fopen(process_name, "r")) == NULL) {
        print_sad_message();
        return 0;
    }

    // Read the pid from the pid file
    if (fscanf(fp, "%d", &pid) == 0) {
        print_sad_message();
        return 0;
    }

    // Close the pid file
    fclose(fp);

    // Check if the process is still running
    if (kill(pid, 0) == 0) {
        print_happy_message();
        return 1;
    } else {
        print_sad_message();
        return 0;
    }
}

int main(int argc, char *argv[]) {
    // Check if the user has specified a process to check
    if (argc < 2) {
        print_sad_message();
        return 1;
    }

    // Check if the process is running
    if (!is_process_running(argv[1])) {
        print_sad_message();
        return 1;
    }

    // Print a happy message
    print_happy_message();

    // Wait for the process to finish
    wait(NULL);

    // Print a happy message again
    print_happy_message();

    return 0;
}