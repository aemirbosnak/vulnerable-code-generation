//FormAI DATASET v1.0 Category: Data validation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to check if input is a valid integer
int is_valid_int(char *input) {
    int i;
    
    // iterate through each character of input
    for (i = 0; input[i] != '\0'; i++) {
        // check if current character is a digit
        if (!isdigit(input[i])) {
            return 0; // return false if current character is not a digit
        }
    }
    
    return 1; // return true if all characters are digits
}

int main() {
    char input[10];
    int age;
    
    // get user input
    printf("Enter your age: ");
    fgets(input, sizeof(input), stdin);
    
    // remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    
    // validate input
    while (!is_valid_int(input)) {
        printf("Invalid input. Please enter a valid age: ");
        fgets(input, sizeof(input), stdin);
        
        // remove newline character from input
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }
    }
    
    // convert input to an integer
    age = atoi(input);
    
    // output final result
    printf("Your age is %d\n", age);
    
    return 0;
}