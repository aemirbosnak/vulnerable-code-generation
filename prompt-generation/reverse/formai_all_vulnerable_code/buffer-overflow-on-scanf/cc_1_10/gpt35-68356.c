//FormAI DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 100

// Function to reverse the order of characters in a string
char* reverseString(char *str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

// Function to convert a string to upper case
void toUpperCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to convert a string to lower case
void toLowerCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to remove all occurrences of a character in a string
void removeChar(char *str, char c) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != c) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[MAX_STR_LENGTH];
    printf("Enter a string (up to %d characters): ", MAX_STR_LENGTH-1);
    fgets(str, MAX_STR_LENGTH, stdin);

    // Remove the newline character from fgets input
    str[strcspn(str, "\n")] = '\0';

    printf("\nOriginal string: %s\n", str);

    printf("\nReversed string: %s\n", reverseString(str));

    toUpperCase(str);
    printf("\nUppercase string: %s\n", str);

    toLowerCase(str);
    printf("\nLowercase string: %s\n", str);

    char c;
    printf("\nEnter a character to remove from the string: ");
    scanf("%c", &c);
    removeChar(str, c);
    printf("\nString with all occurrences of %c removed: %s\n", c, str);

    return 0;
}