//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
void sanitize_input(char *str) {
    int i, j;
    char ch;
    
    // Loop through each character in the string
    for(i = 0; str[i] != '\0'; i++) {
        // If character is not alphabetic or numeric
        if(!isalnum(str[i])) {
            // Replace it with an underscore
            str[i] = '_';
        } else {
            // If character is lowercase, convert to uppercase
            if(islower(str[i])) {
                str[i] = toupper(str[i]);
            }
        }
    }
    
    // Remove any consecutive underscores
    for(i = 0; str[i] == '_'; i++) {
    }
    for(j = i; str[j] != '\0'; j++) {
        if(str[j] != '_') {
            i++;
            str[i] = str[j];
        }
    }
    str[i] = '\0';
    
    // Remove any underscores at the end of the string
    for(i = strlen(str) - 1; i >= 0 && str[i] == '_'; i--) {
        str[i] = '\0';
    }
}

int main() {
    char str[100];
    
    // Get input from user
    printf("Please enter a string: ");
    fgets(str, 100, stdin);
    
    // Remove newline character from input
    str[strlen(str) - 1] = '\0';
    
    // Sanitize input
    sanitize_input(str);
    
    // Print sanitized input
    printf("Your input has been sanitized: %s\n", str);

    return 0;
}