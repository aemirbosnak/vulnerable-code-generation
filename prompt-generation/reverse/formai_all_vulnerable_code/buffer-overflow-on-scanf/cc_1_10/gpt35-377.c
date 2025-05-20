//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char string1[100], string2[100];
    int choice;

    printf("Welcome to the C String Manipulator!\n\n");

    printf("Enter the first string: ");
    fgets(string1, sizeof(string1), stdin);

    printf("\nEnter the second string: ");
    fgets(string2, sizeof(string2), stdin);

    printf("\nChoose an option to manipulate the strings: \n");
    printf("1. Concatenate the strings\n");
    printf("2. Compare the strings\n");
    printf("3. Copy the first string\n");
    printf("4. Find the length of each string\n");
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcat(string1, string2);
            printf("\nThe concatenated string is: %s\n", string1);
            break;
        case 2:
            if (strcmp(string1, string2) == 0) {
                printf("\nThe strings are equal.\n");
            } else {
                printf("\nThe strings are not equal.\n");
            }
            break;
        case 3:
            strcpy(string2, string1);
            printf("\nThe copied string is: %s\n", string2);
            break;
        case 4:
            printf("\nThe length of string 1 is: %ld\n", strlen(string1));
            printf("The length of string 2 is: %ld\n", strlen(string2));
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    printf("\nThank you for using the C String Manipulator! Have a great day!\n");

    return 0;
}