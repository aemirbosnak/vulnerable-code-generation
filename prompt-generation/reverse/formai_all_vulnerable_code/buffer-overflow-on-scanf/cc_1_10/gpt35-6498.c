//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void print_menu()
{
    printf("Enter a number to select an option\n");
    printf("1. Concatenate two strings\n");
    printf("2. Reverse a string\n");
    printf("3. Count the number of vowels in a string\n");
    printf("4. Exit\n");
}

void concatenate_strings(char str1[], char str2[])
{
    char result[MAX_STRING_LENGTH];
    strcpy(result, str1);
    strcat(result, str2);

    printf("Concatenated string: %s\n", result);
}

void reverse_string(char str[])
{
    int length = strlen(str);
    char result[MAX_STRING_LENGTH];

    for (int i = 0; i < length; i++)
    {
        result[i] = str[length - i - 1];
    }

    result[length] = '\0';

    printf("Reversed string: %s\n", result);
}

int count_vowels(char str[])
{
    int count = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        char ch = tolower(str[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    char input_str[MAX_STRING_LENGTH];
    char input_str2[MAX_STRING_LENGTH];
    int choice = 0;

    while (choice != 4)
    {
        print_menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the first string:\n");
                scanf("%s", input_str);

                printf("Enter the second string:\n");
                scanf("%s", input_str2);

                concatenate_strings(input_str, input_str2);
                break;

            case 2:
                printf("Enter the string to reverse:\n");
                scanf("%s", input_str);

                reverse_string(input_str);
                break;

            case 3:
                printf("Enter the string to count vowels:\n");
                scanf("%s", input_str);

                printf("Number of vowels: %d\n", count_vowels(input_str));
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}