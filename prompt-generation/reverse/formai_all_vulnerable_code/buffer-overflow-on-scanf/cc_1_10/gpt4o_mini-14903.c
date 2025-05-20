//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function prototypes
void sanitizeInput(char *input);
void createUser();
void displayUser(const char *username);

int main() {
    char choice;
    
    printf("======== Welcome to the User Input Sanitizer! ========\n");
    printf("Are you ready to create a user? (Y/N): ");
    scanf(" %c", &choice);

    if (tolower(choice) == 'y') {
        createUser();
    } else {
        printf("You chose not to create a user. Stay safe out there!\n");
    }

    return 0;
}

void createUser() {
    char username[MAX_INPUT_LENGTH];
    printf("Enter a username (max %d characters): ", MAX_INPUT_LENGTH - 1);
    scanf(" %[^\n]", username); // Read a full line including spaces

    printf("\n- Processing your input...\n");
    sanitizeInput(username);
    
    displayUser(username);
}

void sanitizeInput(char *input) {
    printf("Oh no! Let's make sure this username is safe...\n");

    // Step 1: Length check
    if (strlen(input) >= MAX_INPUT_LENGTH) {
        printf("** ERROR **: Username exceeds maximum length!\n");
        exit(EXIT_FAILURE);
    }

    // Step 2: Remove any disallowed characters
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i]) && input[i] != '_' && input[i] != '-') {
            printf("** WARNING **: Illegal character '%c' detected! Replacing with '_'.\n", input[i]);
            input[i] = '_'; // Replace disallowed characters with underscore
        }
    }

    // Optional: Trim leading/trailing whitespace
    char *start = input;
    while (isspace((unsigned char)*start)) start++;
    char *end = input + strlen(input) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    
    // Null terminate the string correctly
    *(end + 1) = '\0';
    
    printf("Sanitized Username: '%s'\n", start);
    strcpy(input, start); // Save back the sanitized input
}

void displayUser(const char *username) {
    printf("\n- User creation successful! Your sanitized username is:\n");
    printf("**** Username: %s ****\n", username);
    printf("Thank you for using the User Input Sanitizer. Stay vigilantly safe!\n");
}