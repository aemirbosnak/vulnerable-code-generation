//FormAI DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], temp[100];
    int choice,len;

    while (1)
    {
        printf("Select an option from the following:\n");
        printf("1. Concatenate two strings.\n");
        printf("2. Find the length of a string.\n");
        printf("3. Reverse a string.\n");
        printf("4. Exit.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Concatenating two strings
            printf("\nEnter the first string: ");
            scanf("%s", str1);
            printf("Enter the second string: ");
            scanf("%s", str2);

            strcat(str1, str2);
            printf("\nConcatenated String: %s\n", str1);
            break;

        case 2:
            // Finding the length of a string
            printf("\nEnter a string: ");
            scanf("%s", str1);

            len = strlen(str1);
            printf("\nLength of the string is: %d\n", len);
            break;

        case 3:
            // Reversing a string
            printf("\nEnter a string: ");
            scanf("%s", str1);

            len = strlen(str1);
            for (int i = 0; i < len / 2; i++)
            {
                temp[i] = str1[i];
                str1[i] = str1[len - i - 1];
                str1[len - i - 1] = temp[i];
            }

            printf("\nReversed string: %s\n", str1);
            break;

        case 4:
            // Exiting the program
            printf("\nExiting the program...");
            exit(0);

        default:
            printf("\nInvalid option selected! Please try again.\n");
            break;
        }
    }
    return 0;
}