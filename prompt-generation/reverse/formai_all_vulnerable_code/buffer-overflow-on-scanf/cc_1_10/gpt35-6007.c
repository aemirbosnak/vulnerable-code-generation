//FormAI DATASET v1.0 Category: System administration ; Style: creative
// A Unique C System Administration Example
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // Check if user has root privileges
    if(getuid() != 0) {
        printf("This program needs to be run as root!\n");
        exit(1);
    }

    // Print welcome message
    printf("Welcome to the C System Administration Example Program!\n\n");

    // Get user input
    printf("Please enter a filename: ");
    char filename[256];
    scanf("%s", filename);

    // Create the file
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }

    // Write to the file
    fprintf(file, "This is a test file created by the C System Administration Example Program.");

    // Close the file
    fclose(file);

    // Print success message
    printf("File created successfully!\n");

    // Set file permissions
    if(chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) != 0) {
        printf("Error setting file permissions!\n");
        exit(1);
    }

    // Print success message
    printf("File permissions set successfully!\n");

    // Delete the file
    if(remove(filename) != 0) {
        printf("Error deleting file!\n");
        exit(1);
    }

    // Print success message
    printf("File deleted successfully!\n");

    // Done!
    return 0;
}