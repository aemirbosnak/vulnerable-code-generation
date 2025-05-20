//FormAI DATASET v1.0 Category: System boot optimizer ; Style: accurate
#include <stdio.h>

int main() {

    printf("Welcome to the C System Boot Optimizer!\n");

    int num_of_processes, num_of_services;

    // Ask user for number of processes and services
    printf("How many processes are currently running on your system?\n");
    scanf("%d", &num_of_processes);

    printf("How many services are currently running on your system?\n");
    scanf("%d", &num_of_services);

    // Calculate total number of programs running
    int total_programs = num_of_processes + num_of_services;

    // Suggest actions based on total number of programs running
    if (total_programs < 50) {
        printf("Your system is running efficiently.\n");
    } else if (total_programs >= 50 && total_programs < 100) {
        printf("Your system may benefit from disabling some unnecessary programs.\n");
    } else {
        printf("Your system is overloaded and needs optimization immediately.\n");
    }

    // Check disk space usage and suggest actions
    int disk_usage;
    printf("What is the current disk space usage on your system in GB?\n");
    scanf("%d", &disk_usage);
    if (disk_usage < 20) {
        printf("You have plenty of available disk space.\n");
    } else {
        printf("Your system may benefit from freeing up disk space.\n");
    }

    // Check for fragmented disk and suggest actions
    int fragments;
    printf("How many fragmented files are on your system?\n");
    scanf("%d", &fragments);
    if (fragments == 0) {
        printf("Your disk is not fragmented.\n");
    } else {
        printf("Your system may benefit from defragmentation.\n");
    }

    // Suggest cleaning up temporary files
    char choice;
    printf("Would you like to clean up temporary files? (y/n)\n");
    scanf(" %c", &choice);
    if (choice == 'y') {
        printf("Cleaning up temporary files...\n");
        // Code to delete temporary files goes here
    } else {
        printf("Skipping temporary file cleanup.\n");
    }

    printf("Thank you for using the C System Boot Optimizer! Have a great day.\n");
    return 0;
}