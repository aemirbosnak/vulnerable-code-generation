//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], temp[100];
    int choice, len1, len2;

    printf("Welcome to C String Manipulation Program!\n");

    do {
        printf("\nPlease enter your choice:\n");
        printf("1. Concatenate two strings\n");
        printf("2. Swap two strings\n");
        printf("3. Reverse a string\n");
        printf("4. Exit Program\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Concatenate two strings
                printf("\nEnter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);

                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 2: // Swap two strings
                printf("\nEnter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);

                strcpy(temp, str1);
                strcpy(str1, str2);
                strcpy(str2, temp);

                printf("First string after swap: %s\n", str1);
                printf("Second string after swap: %s\n", str2);
                break;

            case 3: // Reverse a string
                printf("\nEnter a string: ");
                scanf("%s", str1);

                len1 = strlen(str1);
                for(int i=0; i<len1/2; i++) {
                    temp[i] = str1[len1-i-1];
                    str1[len1-i-1] = str1[i];
                    str1[i] = temp[i];
                }

                printf("Reversed string: %s\n", str1);
                break;

            case 4: // Exit program
                printf("\nThank you for using C String Manipulation Program!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

    } while(choice != 4);

    return 0;
}