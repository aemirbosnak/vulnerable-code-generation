//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_NAME_LENGTH 256
#define MAX_AGE 100
#define MAX_HEIGHT 200

// Structure to store user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int height;
} user_info_t;

// Function to read user information from a file
user_info_t read_user_info(FILE *file) {
    user_info_t user;
    fscanf(file, "%s %d %d", user.name, &user.age, &user.height);
    return user;
}

// Function to write user information to a file
void write_user_info(FILE *file, user_info_t user) {
    fprintf(file, "%s %d %d", user.name, user.age, user.height);
}

int main() {
    // Open a file in read/write mode
    FILE *file = fopen("user_info.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the user information from the file
    user_info_t user;
    user = read_user_info(file);

    // Display the user information
    printf("Name: %s\nAge: %d\nHeight: %d\n", user.name, user.age, user.height);

    // Ask the user for new information
    printf("Would you like to update your information? (y/n) ");
    char response;
    scanf(" %c", &response);

    // If the user wants to update their information...
    if (response == 'y' || response == 'Y') {
        // Get the new information from the user
        printf("Enter your new name: ");
        fgets(user.name, MAX_NAME_LENGTH, stdin);
        printf("Enter your new age: ");
        scanf("%d", &user.age);
        printf("Enter your new height: ");
        scanf("%d", &user.height);

        // Write the new user information to the file
        write_user_info(file, user);

        // Display the updated user information
        printf("Name: %s\nAge: %d\nHeight: %d\n", user.name, user.age, user.height);
    }

    // Close the file
    fclose(file);

    return 0;
}