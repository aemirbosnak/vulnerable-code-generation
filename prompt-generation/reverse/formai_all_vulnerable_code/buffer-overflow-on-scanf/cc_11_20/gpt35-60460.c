//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50], result[100];
    int choice, length1, length2, i, j, k = 0;

    printf("Welcome to the C String Manipulation Program!\n\n");

    printf("Please enter the first string: ");
    fgets(str1, 50, stdin);
    length1 = strlen(str1);

    printf("Please enter the second string: ");
    fgets(str2, 50, stdin);
    length2 = strlen(str2);

    printf("Please choose an option from the menu:\n");
    printf("1. Concatenate the strings\n");
    printf("2. Reverse the strings\n");
    printf("3. Convert to uppercase\n");
    printf("4. Convert to lowercase\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Concatenating the strings...\n");
        for (i = 0; i < length1; i++)
        {
            result[k] = str1[i];
            k++;
        }
        for (j = 0; j < length2; j++)
        {
            result[k] = str2[j];
            k++;
        }
        printf("Result: %s\n", result);
    }
    else if (choice == 2)
    {
        printf("Reversing the strings...\n");
        for (i = 0; i < length1; i++)
        {
            result[i] = str1[length1 - 1 - i];
        }
        result[length1] = ' ';
        k = length1 + 1;
        for (j = 0; j < length2; j++)
        {
            result[k] = str2[length2 - 1 - j];
            k++;
        }
        printf("Result: %s\n", result);
    }
    else if (choice == 3)
    {
        printf("Converting to uppercase...\n");
        for (i = 0; i < length1; i++)
        {
            result[i] = toupper(str1[i]);
        }
        result[length1] = ' ';
        k = length1 + 1;
        for (j = 0; j < length2; j++)
        {
            result[k] = toupper(str2[j]);
            k++;
        }
        printf("Result: %s\n", result);
    }
    else if (choice == 4)
    {
        printf("Converting to lowercase...\n");
        for (i = 0; i < length1; i++)
        {
            result[i] = tolower(str1[i]);
        }
        result[length1] = ' ';
        k = length1 + 1;
        for (j = 0; j < length2; j++)
        {
            result[k] = tolower(str2[j]);
            k++;
        }
        printf("Result: %s\n", result);
    }
    else
    {
        printf("Invalid choice. Please run the program again.\n");
    }

    printf("\nThank you for using the C String Manipulation Program!\n");

    return 0;
}