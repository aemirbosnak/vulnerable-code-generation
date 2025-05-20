//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
// Welcome to the User Input Sanitizer Bot!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100 // maximum allowed input size
#define ALPHA_ONLY 1 // restrict user input to only alphabets
#define NUM_ONLY 2 // restrict user input to only numbers

// Function to check if given string contains only alphabets 
int is_alpha(char* input) {
    for(int i = 0; i < strlen(input); i++) {
        if(!isalpha(input[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if given string contains only numbers 
int is_num(char* input) {
    for(int i = 0; i < strlen(input); i++) {
        if(!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int sanitize_type; // to hold user input sanitizer type preference
    
    printf("Hi there! I'm the User Input Sanitizer bot, here to sanitize your input!\n");
    printf("Please enter the type of input you want to sanitize:\n");
    printf("1. Only Alphabets\n");
    printf("2. Only Numbers\n");
    
    // Input type preference
    scanf("%d", &sanitize_type);
    if(sanitize_type != ALPHA_ONLY && sanitize_type != NUM_ONLY) {
        printf("Invalid input type preference. Exiting program.\n");
        exit(1);
    }
    
    printf("Great! Now please enter your input (maximum %d characters):\n", MAX_INPUT_SIZE);
    scanf("%s", input);

    // Depending on the user's preference, sanitize the input 
    if(sanitize_type == ALPHA_ONLY) {
        if(!is_alpha(input)) {
            printf("The input you provided contains non-alphabetic characters.\n");
            printf("Sanitizing input...\n");
            for(int i = 0; input[i]; i++) {
                if(isalpha(input[i])) {
                    output[i] = input[i];
                }
            }
            output[strlen(output)] = '\0';
        }
        else {
            printf("The input you provided is already alphabetic. No need to sanitize.\n");
            strcpy(output, input);
        }
    }
    else if(sanitize_type == NUM_ONLY) {
        if(!is_num(input)) {
            printf("The input you provided contains non-numeric characters.\n");
            printf("Sanitizing input...\n");
            for(int i = 0; input[i]; i++) {
                if(isdigit(input[i])) {
                    output[i] = input[i];
                }
            }
            output[strlen(output)] = '\0';
        }
        else {
            printf("The input you provided is already numeric. No need to sanitize.\n");
            strcpy(output, input);
        }
    }
    
    // Output the sanitized input 
    printf("Your sanitized input is: %s\n", output);
    
    return 0;
}