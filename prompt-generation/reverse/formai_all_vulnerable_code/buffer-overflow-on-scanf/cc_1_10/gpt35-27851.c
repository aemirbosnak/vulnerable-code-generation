//FormAI DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int option, len;

    printf("Welcome to the C String Manipulation program!\n");

    printf("Please enter your first string: ");
    scanf("%s", str1);

    printf("Please enter your second string: ");
    scanf("%s", str2);

    // Let's find the length of the first string entered by the user
    len = strlen(str1);
    printf("The length of your first string is %d.\n", len);

    // Let's concatenate both the strings entered by the user and print the final output
    strcat(str1, str2);
    printf("The concatenated string is: %s\n", str1);

    do {
        printf("\nWhat operation do you want to perform next?\n");
        printf("1. Compare both strings\n");
        printf("2. Convert first string to uppercase\n");
        printf("3. Convert second string to lowercase\n");
        printf("4. Exit program\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Let's compare both strings entered by the user
                if (strcmp(str1, str2) == 0) {
                    printf("The strings are equal.\n");
                } else {
                    printf("The strings are not equal.\n");
                }
                break;

            case 2:
                // Let's convert the first string to uppercase
                for (int i = 0; i < len; i++) {
                    str1[i] = toupper(str1[i]);
                }
                printf("The uppercase string is: %s\n", str1);
                break;

            case 3:
                // Let's convert the second string to lowercase
                len = strlen(str2);
                for (int i = 0; i < len; i++) {
                    str2[i] = tolower(str2[i]);
                }
                printf("The lowercase string is: %s\n", str2);
                break;

            case 4:
                printf("Thank you for using the C String Manipulation program!\n");
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 4);

    return 0;
}