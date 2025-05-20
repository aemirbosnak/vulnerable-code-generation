//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    // Declare a buffer to store the user's input.
    char input[MAX_INPUT_LENGTH];

    // Get the user's input.
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove any leading or trailing whitespace from the input.
    // Convert to Upper Case
    char *p = malloc(strlen(input)+1);
    strcpy(p, input);
    for (int i = 0; i < strlen(p); i++) {
        p[i] = toupper(p[i]);
    }

    //Validate Input
    int valid = 1;
    for (int i = 0; i < strlen(p); i++) {
        if (!((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= '0' && p[i] <= '9') || p[i] == ' ')) {
            valid = 0;
            break;
        }
    }
    //Check if Input is alphanumeric
    if(!valid){
        printf("Invalid input. Please enter only alphanumeric characters.\n");
    }
    // Check if Input is empty
    else if (strlen(p) == 0) {
        printf("Invalid input. Please enter a non-empty string.\n");
    }
    // Check if Input is too long
    else if (strlen(p) > MAX_INPUT_LENGTH) {
        printf("Invalid input. Please enter a string that is no longer than %d characters.\n", MAX_INPUT_LENGTH);
    }
    // Check if Input contains any special characters
    else if (strpbrk(p, "!@#$%^&*()_+=-`~,./'<>?;:[]{}\"") != NULL) {
        printf("Invalid input. Please enter a string that does not contain any special characters.\n");
    }
    // Input is valid
    else {
        printf("Valid input: %s\n", p);
    }
    free(p);
    return 0;
}