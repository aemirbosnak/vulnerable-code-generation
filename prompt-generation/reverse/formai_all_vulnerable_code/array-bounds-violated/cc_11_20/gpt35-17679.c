//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() { 
    // Grateful String Manipulation Program
    printf("********************************\n");
    printf("*** Grateful String Program ***\n");
    printf("********************************\n\n");

    // Declare Variables
    char text[100];
    char temp;
    int i, j, len;

    // Get User Input
    printf("Please enter a string: ");
    fgets(text, 100, stdin);
    len = strlen(text);

    // Remove New Line Character from User Input
    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
        len--;
    }

    // Reversing the String
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = text[i];
        text[i] = text[j];
        text[j] = temp;
    }

    // Capitalizing Every Other Character
    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            text[i] = toupper(text[i]);
        }
    }

    // Replace Every Vowel with "grateful"
    for (i = 0; i < len; i++) {
        switch (text[i]) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                memmove(&text[i + 8], &text[i + 1], len - i);
                strncpy(&text[i], "grateful", 8);
                len += 7;
                i += 7;
                break;
            default:
                break;
        }
    }

    // Print the Grateful String
    printf("\nYour Grateful String: %s\n", text);

    return 0; 
}