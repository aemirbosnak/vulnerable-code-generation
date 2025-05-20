//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void uppercase(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void lowercase(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input[MAX_LENGTH];
    char reversed[MAX_LENGTH];
    char uppercased[MAX_LENGTH];
    char lowercased[MAX_LENGTH];
    int i;

    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    reverse(input);
    printf("Reversed string: %s\n", input);

    // Convert to uppercase
    uppercase(input);
    printf("Uppercase string: %s\n", input);

    // Convert to lowercase
    lowercase(input);
    printf("Lowercase string: %s\n", input);

    // Copy the reversed string to a new variable
    strcpy(reversed, input);

    // Reverse the reversed string
    reverse(reversed);

    // Check if the original string is equal to the reversed and reversed string
    if (strcmp(input, reversed) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}