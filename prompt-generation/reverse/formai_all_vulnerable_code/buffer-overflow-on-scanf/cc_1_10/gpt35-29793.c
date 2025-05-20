//FormAI DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the String Manipulation program! \n");

    char str[100];
    char new_str[100];
    char c;
    int i, j = 0;

    printf("Please enter a string: ");
    scanf("%s", str);

    printf("Please enter a character to check if it is in the string: ");
    scanf(" %c", &c);

    for (i = 0; i < strlen(str); i++) { // loop through each character in the string
        if (str[i] == c) {
            printf("Character %c found at position %d!\n", c, i);
        }
    }

    printf("Please enter a substring to search for in the string: ");
    scanf("%s", new_str);

    if (strstr(str, new_str)) {
        printf("Substring %s found in string %s!\n", new_str, str);
    } else {
        printf("Substring %s not found in string %s :(\n", new_str, str);
    }

    printf("Original string: %s\n", str);

    // Reverse the string
    for (i = strlen(str) - 1; i >= 0; i--) {
        new_str[j++] = str[i];
    }
    new_str[j] = '\0'; // add null terminating character to end

    printf("Reverse string: %s\n", new_str);

    char duplicate_str[100];
    strcpy(duplicate_str, str); // copy original string to duplicate

    printf("Duplicate string: %s\n", duplicate_str);

    char new_char;
    printf("Please enter a new character to replace an old character in the string: ");
    scanf(" %c", &new_char);

    char old_char;
    printf("Please enter the old character to replace with the new character: ");
    scanf(" %c", &old_char);

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == old_char) {
            str[i] = new_char; // replace old character with new character
        }
    }
    printf("New string: %s\n", str);

    return 0; // successful program
}