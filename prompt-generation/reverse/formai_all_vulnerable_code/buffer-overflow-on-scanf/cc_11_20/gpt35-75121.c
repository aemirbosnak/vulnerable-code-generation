//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];
    int choice, len1, len2, i, j;

    printf("Welcome to String Manipulation Program!\n\n");

    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    len1 = strlen(str1);
    if (str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
        len1--;
    }

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    len2 = strlen(str2);
    if (str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
        len2--;
    }

    printf("\nChoose an operation to perform:\n");
    printf("1. Concatenate the two strings\n");
    printf("2. Reverse the first string\n");
    printf("3. Replace a character in the first string\n");
    printf("4. Find the first occurrence of a character in the first string\n");
    printf("5. Sort the two strings in alphabetical order\n");
    printf("6. Exit the program\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcat(str1, str2);
            printf("\nThe concatenated string is: %s\n", str1);
            break;

        case 2:
            for (i = 0, j = len1 - 1; i < j; i++, j--) {
                temp[i] = str1[j];
                temp[j] = str1[i];
            }
            if (i == j) {
                temp[i] = str1[i];
            }
            printf("\nThe reversed string is: %s\n", temp);
            break;

        case 3:
            printf("\nEnter the character to replace: ");
            char find, replace;
            scanf(" %c", &find);
            getchar();

            printf("Enter the character to replace '%c': ", find);
            scanf(" %c", &replace);

            for (i = 0; i < len1; i++) {
                if (str1[i] == find) {
                    str1[i] = replace;
                }
            }
            printf("\nThe new string is: %s\n", str1);
            break;

        case 4:
            printf("\nEnter the character to find: ");
            char c;
            scanf(" %c", &c);

            for (i = 0; i < len1; i++) {
                if (str1[i] == c) {
                    printf("\nThe character '%c' was found at index %d\n", c, i);
                    break;
                }
            }
            if (i == len1) {
                printf("\nThe character '%c' was not found in the string\n", c);
            }
            break;

        case 5:
            if (strcmp(str1, str2) < 0) {
                printf("\nThe sorted strings are: \n%s\n%s\n", str1, str2);
            } else {
                printf("\nThe sorted strings are: \n%s\n%s\n", str2, str1);
            }
            break;

        case 6:
            printf("\nGoodbye!\n");
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
    }

    return 0;
}