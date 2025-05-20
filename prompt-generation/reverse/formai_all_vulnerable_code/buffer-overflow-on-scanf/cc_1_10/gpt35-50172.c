//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int option, length, index;

    printf("Enter first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0; // Removes newline character from user input

    printf("\nEnter second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0; // Removes newline character from user input

    printf("\nChoose an option from below:\n\n");
    printf("1. Concatenate the two strings\n");
    printf("2. Find the length of the first string\n");
    printf("3. Find the index of a character in the first string\n");
    printf("4. Exit\n\n");

    printf("Your option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            strcat(str1, str2);
            printf("\nConcatenated string: %s\n", str1);
            break;
        case 2:
            length = strlen(str1);
            printf("\nLength of the first string: %d\n", length);
            break;
        case 3:
            printf("\nEnter the character you want to find: ");
            getchar(); // Clears input buffer
            char c = getchar();
            index = strchr(str1, c) - str1;
            if (index >= 0) {
                printf("\nIndex of %c in the first string: %d\n", c, index);
            } else {
                printf("\n%c not found in the first string.\n", c);
            }
            break;
        case 4:
            printf("\nExiting program...\n");
            break;
        default:
            printf("\nPlease enter a valid option.\n");
            break;
    }

    return 0;
}