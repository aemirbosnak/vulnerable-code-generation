//FormAI DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    int choice, len, i;

    printf("Enter a string: ");
    fgets(string, 100, stdin);
    len = strlen(string);

    do {
        printf("\nChoose an operation to perform on the string:\n");
        printf("1. Count the number of vowels\n");
        printf("2. Reverse the string\n");
        printf("3. Count the number of words\n");
        printf("4. Replace a character in the string\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // to absorb the extra newline character

        switch (choice) {
            case 1: {
                int vowelCount = 0;
                for (i = 0; i < len; i++) {
                    if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
                        string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
                        vowelCount++;
                }
                printf("\nThe string has %d vowel(s).\n", vowelCount);
                break;
            }

            case 2: {
                printf("\nThe reversed string is: ");
                for (i = len - 1; i >= 0; i--) {
                    printf("%c", string[i]);
                }
                printf("\n");
                break;
            }

            case 3: {
                int wordCount = 0;
                for (i = 0; i < len; i++) {
                    if (string[i] == ' ' && i != len - 1 && string[i + 1] != ' ')
                        wordCount++;
                }
                wordCount++; // add 1 to count the last word after the final space, if any
                printf("\nThe string has %d word(s).\n", wordCount);
                break;
            }

            case 4: {
                char oldChar, newChar;
                printf("\nEnter the character to replace: ");
                scanf("%c", &oldChar);
                getchar(); // to absorb the extra newline character
                printf("Enter the new character: ");
                scanf("%c", &newChar);
                getchar(); // to absorb the extra newline character
                for (i = 0; i < len; i++) {
                    if (string[i] == oldChar)
                        string[i] = newChar;
                }
                printf("\nThe modified string is: %s\n", string);
                break;
            }

            case 5: {
                printf("\nExiting program...\n");
                break;
            }

            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 5);

    return 0;
}