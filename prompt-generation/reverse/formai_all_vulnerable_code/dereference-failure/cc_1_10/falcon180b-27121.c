//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_INPUT_NUMBER 10

// Function to sanitize input
void sanitize_input(char* input) {
    // Remove leading/trailing whitespace
    char* trimmed_input = input;
    while (isspace(*trimmed_input)) {
        trimmed_input++;
    }
    int length = strlen(trimmed_input);
    while (isspace(trimmed_input[length - 1])) {
        trimmed_input[length - 1] = '\0';
        length--;
    }

    // Copy sanitized input to original input
    strcpy(input, trimmed_input);
}

// Function to get integer input from user
int get_integer_input(char* prompt) {
    int input;
    printf("%s", prompt);
    if (scanf("%d", &input)!= 1) {
        printf("Invalid input. Please enter an integer.\n");
        exit(1);
    }
    return input;
}

// Function to get string input from user
void get_string_input(char* prompt, char* input) {
    printf("%s", prompt);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
}

int main() {
    char name[MAX_INPUT_LENGTH];
    get_string_input("Enter your name: ", name);

    char favorite_color[MAX_INPUT_LENGTH];
    get_string_input("Enter your favorite color: ", favorite_color);

    int number_of_pets;
    number_of_pets = get_integer_input("Enter the number of pets you have: ");

    printf("Hello, %s. Your favorite color is %s and you have %d pets.\n", name, favorite_color, number_of_pets);

    return 0;
}