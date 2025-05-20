//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// function to check if the entered string contains only alphanumeric characters
bool isAlphanumeric(char* str) {
    for(int i=0; i<strlen(str); i++) {
        if(!isalnum(str[i]))
            return false;
    }
    return true;
}

// function to check if the entered string contains only numeric characters
bool isNumeric(char* str) {
    for(int i=0; i<strlen(str); i++) {
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}

// function to sanitize the input string by removing non-alphanumeric characters
void sanitizeInput(char* input) {
    char sanitizedInput[strlen(input)];
    int j=0;
    
    for(int i=0; i<strlen(input); i++) {
        if(isalnum(input[i]))
            sanitizedInput[j++] = input[i];
    }
    sanitizedInput[j] = '\0';
    
    strcpy(input, sanitizedInput);
}

int main() {
    char input[100];
    printf("Welcome to User Input Sanitizer!\n");
    
    // get user input
    printf("Enter an alphanumeric string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove the newline character
    
    // check if input is alphanumeric
    if(!isAlphanumeric(input)) {
        printf("Error: Input contains non-alphanumeric characters.\n");
        return 1;
    }
    
    // sanitize the input
    sanitizeInput(input);
    
    // display sanitized input
    printf("Sanitized Input: %s\n", input);
    
    return 0;
}