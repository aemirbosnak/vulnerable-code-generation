//FormAI DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a letter or not
int isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert a string to upper case
char *toUpper(char *str) {
    int i;
    int length = strlen(str);

    for (i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }

    return str;
}

// Function to remove all vowels from a string
char *removeVowels(char *str) {
    int i, j;
    int length = strlen(str);

    for (i = 0, j = 0; i < length; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'
                && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';

    return str;
}

// Main function to run the program
int main() {
    char sentence[1000];
    int choice;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // Remove new line character from fgets input

    do {
        printf("\n");
        printf("1 - Convert sentence to upper case\n");
        printf("2 - Remove all vowels from sentence\n");
        printf("3 - Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            toUpper(sentence);
            printf("Result: %s\n", sentence);
            break;
        case 2:
            removeVowels(sentence);
            printf("Result: %s\n", sentence);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 3);

    return 0;
}