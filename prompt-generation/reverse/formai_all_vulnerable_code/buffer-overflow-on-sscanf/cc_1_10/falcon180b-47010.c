//Falcon-180B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum length for strings
#define MAX_LENGTH 100

// Function to validate user input for a string
int validateString(char* str) {
    int length = strlen(str);
    
    // Check if the string is empty or too long
    if (length == 0 || length > MAX_LENGTH) {
        printf("Error: String must be between 1 and %d characters.\n", MAX_LENGTH);
        return 0;
    }
    
    // Check if the string contains only letters
    for (int i = 0; i < length; i++) {
        if (!isalpha(str[i])) {
            printf("Error: String must contain only letters.\n");
            return 0;
        }
    }
    
    // If all checks pass, return 1 to indicate success
    return 1;
}

// Function to validate user input for an integer
int validateInt(char* str) {
    int num;
    
    // Convert the string to an integer
    if (sscanf(str, "%d", &num)!= 1) {
        printf("Error: Input must be an integer.\n");
        return 0;
    }
    
    // If the integer is negative, print an error message and return 0
    if (num < 0) {
        printf("Error: Integer must be non-negative.\n");
        return 0;
    }
    
    // If all checks pass, return 1 to indicate success
    return 1;
}

int main() {
    char name[MAX_LENGTH];
    int age;
    
    // Prompt the user for their name
    printf("What is your name? ");
    fgets(name, MAX_LENGTH, stdin);
    
    // Validate the user's name
    if (!validateString(name)) {
        return 1;
    }
    
    // Set the user's name
    printf("Hello, %s!\n", name);
    
    // Prompt the user for their age
    printf("How old are you? ");
    scanf("%s", name);
    
    // Validate the user's age
    if (!validateInt(name)) {
        return 1;
    }
    
    // Convert the age string to an integer
    age = atoi(name);
    
    // Print a happy message to the user
    printf("You are %d years old, %s! That's fantastic!\n", age, name);
    
    return 0;
}