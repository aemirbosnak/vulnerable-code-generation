//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

/**
 * Function to reverse a string.
 */
void reverseString(char *str) {
    int i, j;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/**
 * Function to calculate the frequency of a character in a string.
 */
int countFrequency(char *str, char ch) {
    int frequency = 0;

    while (*str) {
        if (*str == ch) {
            frequency++;
        }
        str++;
    }

    return frequency;
}

/**
 * Function to remove a character from a string.
 */
void removeChar(char *str, char ch) {
    int i, j;

    for (i = 0, j = 0; i < strlen(str); i++) {
        if (str[i] != ch) {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove the newline character at the end of the string.
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    // Reverse the string.
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Count the frequency of a character in the string.
    char ch;
    printf("Enter a character to count its frequency: ");
    scanf("%c", &ch);
    int frequency = countFrequency(str, ch);
    printf("Frequency of %c: %d\n", ch, frequency);

    // Remove a character from the string.
    printf("Enter a character to remove from the string: ");
    scanf(" %c", &ch);
    removeChar(str, ch);
    printf("String after removing %c: %s\n", ch, str);

    return 0;
}