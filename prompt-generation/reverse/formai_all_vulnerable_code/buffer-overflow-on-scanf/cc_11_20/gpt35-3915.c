//FormAI DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the Ephemerality Text Processor!\n");
    printf("Please enter your text (max 50 characters):\n");

    char input[51];
    fgets(input, 51, stdin);

    // Remove new line character from input
    input[strcspn(input, "\n")] = 0;

    printf("Your input is: %s\n", input);

    printf("Would you like to process the text?\n");
    printf("1. Remove vowels   2. Reverse text  3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Removing vowels...\n");

            for (int i = 0; i < strlen(input); i++) {
                if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' &&
                    input[i] != 'o' && input[i] != 'u') {
                    printf("%c", input[i]);
                }
            }
            printf("\n");
            break;
        case 2:
            printf("Reversing text...\n");

            for (int i = strlen(input) - 1; i >= 0; i--) {
                printf("%c", input[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice, exiting program...\n");
            break;
    }

    return 0;
}