//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void reverseString(char str[])
{
    int length = strlen(str);
    char temp;

    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main(void)
{
    char string[MAX_STRING_LENGTH], reversedString[MAX_STRING_LENGTH];
    int i, j, k;

    /* Prompt user for input */
    printf("Enter a string: ");
    fgets(string, MAX_STRING_LENGTH, stdin);
    string[strlen(string) - 1] = '\0';

    /* Copy the original string to the reversed string */
    strcpy(reversedString, string);

    /* Reverse the reversed string */
    reverseString(reversedString);

    /* Print the original string */
    printf("\nOriginal String: %s\n", string);

    /* Print the reversed string */
    printf("Reversed String: %s\n", reversedString);

    /* Remove the vowels from the reversed string */
    for (i = j = 0; reversedString[i]; i++) {
        if (reversedString[i] != 'a' && reversedString[i] != 'e' && reversedString[i] != 'i' && reversedString[i] != 'o' && reversedString[i] != 'u' && reversedString[i] != 'A' && reversedString[i] != 'E' && reversedString[i] != 'I' && reversedString[i] != 'O' && reversedString[i] != 'U') {
            reversedString[j++] = reversedString[i];
        }
    }

    /* Insert a space every three characters in the reversed string */
    for (i = j = 0; reversedString[i]; i++) {
        if (i % 3 == 0 && i != 0) {
            string[j++] = ' ';
        }
        string[j++] = reversedString[i];
    }
    string[j] = '\0';

    /* Convert the original string to uppercase */
    for (k = 0; string[k]; k++) {
        string[k] = toupper(string[k]);
    }

    /* Print the modified string */
    printf("Modified String: %s", string);

    return 0;
}