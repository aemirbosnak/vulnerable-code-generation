//FormAI DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
/*
* This program demonstrates the power of C string manipulation.
* It reads a string of text and then manipulates it in various ways.
* Linus Torvalds style programming at its finest!
*/

#include <stdio.h>

int main(void) {
    char text[1000], copy[1000];
    int choice, i, j, k;

    // Read the input string
    printf("Enter the string of text you want to manipulate: \n");
    fgets(text, sizeof(text), stdin);

    // Display the string menu
    printf("Choose an option to manipulate the string: \n");
    printf("1. Reverse the string\n");
    printf("2. Convert all characters to uppercase\n");
    printf("3. Remove all vowels\n");
    printf("4. Count the number of times a character appears\n");
    printf("5. Exit\n");

    // Prompt the user to choose an option
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected operation on the string
    switch (choice) {
        // Reverse the string
        case 1:
            for (i = 0, j = strlen(text)-1; i < strlen(text); i++, j--)
                copy[i] = text[j];
            copy[i] = '\0';
            printf("The reversed string is: %s\n", copy);
            break;

        // Convert all characters to uppercase
        case 2:
            for (i = 0; i < strlen(text); i++)
                copy[i] = toupper(text[i]);
            printf("The string in uppercase is: %s\n", copy);
            break;

        // Remove all vowels
        case 3:
            for (i = 0, j = 0; i < strlen(text); i++) {
                if (text[i] != 'a' && text[i] != 'e' && text[i] != 'i' && text[i] != 'o' && text[i] != 'u' 
                    && text[i] != 'A' && text[i] != 'E' && text[i] != 'I' && text[i] != 'O' && text[i] != 'U') {
                    copy[j++] = text[i];
                }
            }
            copy[j] = '\0';
            printf("The string with all vowels removed is: %s\n", copy);
            break;

        // Count the number of times a character appears
        case 4:
            printf("Enter the character you want to count: ");
            scanf(" %c", &text[0]);
            k = 0;
            for (i = 0; i < strlen(text); i++) {
                if (text[i] == text[0]) {
                    k++;
                }
            }
            printf("The character %c appears %d times in the string.\n", text[0], k);
            break;

        // Exit the program
        case 5:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}