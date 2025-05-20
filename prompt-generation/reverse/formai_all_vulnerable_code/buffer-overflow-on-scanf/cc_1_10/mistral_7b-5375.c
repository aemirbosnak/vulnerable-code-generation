//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MIN_INT 1
#define MAX_INT 10

void read_string(char* str, char* message) {
    printf("%s", message);
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void read_integer(int* number, char* message) {
    int input;
    char invalid_input_message[50] = "Invalid input. Please enter a valid integer.";

    while (1) {
        printf("%s", message);
        if (scanf("%d", &input) != 1) {
            printf("%s", invalid_input_message);
            scanf("%*s"); // Consume any leftover input
            continue;
        }
        if (*number < MIN_INT || *number > MAX_INT) {
            printf("Error: Number must be between %d and %d.\n", MIN_INT, MAX_INT);
            continue;
        }
        *number = input;
        break;
    }
}

int main() {
    char string[MAX_STRING_LENGTH];
    int number;
    char welcome_message[50] = "Welcome to the C input program!";
    char read_string_message[50] = "Please enter a string: ";
    char read_integer_message[50] = "Please enter a number between 1 and 10: ";

    printf("%s\n", welcome_message);

    read_string(string, read_string_message);
    printf("String: %s\n", string);

    read_integer(&number, read_integer_message);
    printf("Number: %d\n", number);

    return 0;
}