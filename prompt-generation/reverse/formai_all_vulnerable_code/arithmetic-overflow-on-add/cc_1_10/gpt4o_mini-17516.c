//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define error codes
#define MEMORY_ERROR 1
#define FILE_ERROR 2
#define IO_ERROR 3

// Function to handle errors by printing a message and exiting
void handleError(int errorCode, const char *message) {
    switch(errorCode) {
        case MEMORY_ERROR:
            fprintf(stderr, "Memory Allocation Error: %s\n", message);
            break;
        case FILE_ERROR:
            fprintf(stderr, "File Error: %s\n", message);
            break;
        case IO_ERROR:
            fprintf(stderr, "IO Error: %s\n", message);
            break;
        default:
            fprintf(stderr, "Unknown Error: %s\n", message);
            break;
    }
    exit(errorCode);
}

// Struct to hold user data
typedef struct {
    char name[100];
    int age;
} User;

// Function to read user data from a file
User* readUserData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handleError(FILE_ERROR, "Could not open file for reading.");
    }

    User *user = malloc(sizeof(User));
    if (!user) {
        fclose(file);
        handleError(MEMORY_ERROR, "Unable to allocate memory for user data.");
    }

    // Read the user's name and age from the file
    if (fscanf(file, "%99s %d", user->name, &user->age) != 2) {
        fclose(file);
        free(user);
        handleError(IO_ERROR, "Failed to read user data from file.");
    }

    fclose(file);
    return user;
}

// Function to write user data to a file
void writeUserData(const char *filename, User *user) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        handleError(FILE_ERROR, "Could not open file for writing.");
    }

    // Write the user's name and age to the file
    if (fprintf(file, "%s %d\n", user->name, user->age) < 0) {
        fclose(file);
        handleError(IO_ERROR, "Failed to write user data to file.");
    }

    fclose(file);
}

// Function to display user data
void displayUserData(User *user) {
    if (user == NULL) {
        handleError(IO_ERROR, "User data is not available to display.");
    }
    printf("User Name: %s\n", user->name);
    printf("User Age: %d\n", user->age);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read user data from input file
    User *user = readUserData(argv[1]);

    // Display user data to the console
    displayUserData(user);

    // Modify user data
    user->age += 1; // Increase age by 1 for example
    printf("Updated Age: %d\n", user->age);

    // Write updated user data to output file
    writeUserData(argv[2], user);

    // Clean up
    free(user);
    return EXIT_SUCCESS;
}