//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {

    // Declare and initialize the string variables
    char greeting[] = "Hello";
    char name[20];
    char full_greeting[50];

    // Ask for the user's name and store it in the 'name' variable
    printf("What is your name? ");
    scanf("%s", name);

    // Concatenate the greeting and name strings to make the full greeting
    strcpy(full_greeting, greeting);
    strcat(full_greeting, " ");
    strcat(full_greeting, name);

    // Print the full greeting
    printf("%s, welcome to our program!\n", full_greeting);

    // Ask the user for a new string to search for in the full greeting
    char search_str[20];
    printf("Enter a string to search for in the greeting: ");
    scanf("%s", search_str);

    // Use the strstr() function to search for the user's string
    if (strstr(full_greeting, search_str) != NULL) {
        printf("'%s' is found in the greeting!\n", search_str);
    } else {
        printf("'%s' is not found in the greeting.\n", search_str);
    }

    // Ask the user for a character to replace in the greeting
    char replace_char;
    printf("Enter a character to replace in the greeting: ");
    scanf(" %c", &replace_char);

    // Use a loop to replace all instances of the character in the greeting
    for (int i = 0; i < strlen(full_greeting); i++) {
        if (full_greeting[i] == replace_char) {
            full_greeting[i] = '*';
        }
    }

    // Print the modified greeting
    printf("Here is the modified greeting: %s\n", full_greeting);

    return 0;
}