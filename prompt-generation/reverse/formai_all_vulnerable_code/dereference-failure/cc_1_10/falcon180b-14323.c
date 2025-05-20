//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function prototypes
void funny_string_manipulation(char* string);

int main() {
    char string[MAX_STRING_LENGTH];

    // Get user input
    printf("Enter a string (maximum %d characters): ", MAX_STRING_LENGTH - 1);
    scanf("%s", string);

    // Manipulate the string
    funny_string_manipulation(string);

    // Print the manipulated string
    printf("The funny manipulated string: %s\n", string);

    return 0;
}

// Function to manipulate the string in a funny way
void funny_string_manipulation(char* string) {
    // Convert the string to lowercase
    for (int i = 0; string[i]!= '\0'; i++) {
        string[i] = tolower(string[i]);
    }

    // Reverse the string
    char reversed_string[MAX_STRING_LENGTH];
    strcpy(reversed_string, string);
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++) {
        char temp = reversed_string[i];
        reversed_string[i] = reversed_string[length - i - 1];
        reversed_string[length - i - 1] = temp;
    }

    // Replace every other character with "lol"
    char* new_string = malloc(MAX_STRING_LENGTH);
    int new_string_length = 0;
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            strcat(new_string, "lol");
            new_string_length += 3;
        } else {
            strcat(new_string, &string[i]);
            new_string_length++;
        }
    }

    // Print the manipulated string
    printf("The funny manipulated string: %s\n", new_string);
}