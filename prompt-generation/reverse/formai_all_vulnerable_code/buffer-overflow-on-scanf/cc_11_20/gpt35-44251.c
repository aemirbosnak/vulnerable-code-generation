//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    int choice;

    printf("Welcome to String Manipulator!\n\n");

    printf("Enter your first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter your second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Removing the new line character from the input
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    printf("\n1. Concatenate the two strings\n");
    printf("2. Find the length of each string\n");
    printf("3. Compare the two strings\n");
    printf("4. Convert each string to uppercase\n");
    printf("5. Convert each string to lowercase\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcat(str1, str2);
            printf("\nConcatenated string: %s\n", str1);
            break;
        case 2:
            printf("\nLength of first string: %d\n", strlen(str1));
            printf("Length of second string: %d\n", strlen(str2));
            break;
        case 3:
            if (strcmp(str1, str2) == 0) {
                printf("\nBoth strings are equal.\n");
            } else {
                printf("\nThe strings are not equal.\n");
            }
            break;
        case 4:
            for (int i = 0; str1[i] != '\0'; i++) {
                str1[i] = toupper(str1[i]);
            }
            for (int i = 0; str2[i] != '\0'; i++) {
                str2[i] = toupper(str2[i]);
            }
            printf("\nFirst string in uppercase: %s\n", str1);
            printf("Second string in uppercase: %s\n", str2);
            break;
        case 5:
            for (int i = 0; str1[i] != '\0'; i++) {
                str1[i] = tolower(str1[i]);
            }
            for (int i = 0; str2[i] != '\0'; i++) {
                str2[i] = tolower(str2[i]);
            }
            printf("\nFirst string in lowercase: %s\n", str1);
            printf("Second string in lowercase: %s\n", str2);
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}