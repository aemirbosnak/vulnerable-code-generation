//FormAI DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void convertToUpper(char string[]);
void convertToLower(char string[]);
void removeSpaces(char string[]);
void reverseString(char string[]);
void replaceChar(char string[], char oldChar, char newChar);
bool isPalindrome(char string[]);
bool isAnagram(char string1[], char string2[]);

int main()
{
    char string[MAX_STRING_LENGTH];
    int option = 0;

    do
    {
        printf("-------------------\n");
        printf("String Manipulation\n");
        printf("-------------------\n");
        printf("1. Convert to Uppercase\n");
        printf("2. Convert to Lowercase\n");
        printf("3. Remove Spaces\n");
        printf("4. Reverse String\n");
        printf("5. Replace Character\n");
        printf("6. Check if Palindrome\n");
        printf("7. Check if Anagram\n");
        printf("8. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter a string: ");
            scanf(" %[^\n]", string);
            convertToUpper(string);
            printf("\nResult: %s\n", string);
            break;

        case 2:
            printf("\nEnter a string: ");
            scanf(" %[^\n]", string);
            convertToLower(string);
            printf("\nResult: %s\n", string);
            break;

        case 3:
            printf("\nEnter a string: ");
            scanf(" %[^\n]", string);
            removeSpaces(string);
            printf("\nResult: %s\n", string);
            break;

        case 4:
            printf("\nEnter a string: ");
            scanf(" %[^\n]", string);
            reverseString(string);
            printf("\nResult: %s\n", string);
            break;

        case 5:
            printf("\nEnter a string: ");
            scanf(" %[^\n]", string);
            char oldChar, newChar;
            printf("\nEnter the character to replace: ");
            getchar();
            oldChar = getchar();
            printf("\nEnter the new character: ");
            getchar();
            newChar = getchar();
            replaceChar(string, oldChar, newChar);
            printf("\nResult: %s\n", string);
            break;

        case 6:
            printf("\nEnter a string: ");
            scanf(" %[^\n]", string);
            if (isPalindrome(string))
            {
                printf("\n%s is a Palindrome.\n", string);
            }
            else
            {
                printf("\n%s is not a Palindrome.\n", string);
            }
            break;

        case 7:
            printf("\nEnter first string: ");
            scanf(" %[^\n]", string);
            char string2[MAX_STRING_LENGTH];
            printf("\nEnter second string: ");
            scanf(" %[^\n]", string2);
            if (isAnagram(string, string2))
            {
                printf("\n%s and %s are Anagrams.\n", string, string2);
            }
            else
            {
                printf("\n%s and %s are not Anagrams.\n", string, string2);
            }
            break;

        case 8:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (option != 8);

    return 0;
}

void convertToUpper(char string[])
{
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 32;
        }
    }
}

void convertToLower(char string[])
{
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}

void removeSpaces(char string[])
{
    int length = strlen(string);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (string[i] != ' ')
        {
            string[count++] = string[i];
        }
    }
    string[count] = '\0';
}

void reverseString(char string[])
{
    int length = strlen(string);
    int start = 0, end = length - 1;
    while (start < end)
    {
        char temp = string[start];
        string[start] = string[end];
        string[end] = temp;
        start++;
        end--;
    }
}

void replaceChar(char string[], char oldChar, char newChar)
{
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        if (string[i] == oldChar)
        {
            string[i] = newChar;
        }
    }
}

bool isPalindrome(char string[])
{
    int length = strlen(string);
    int start = 0, end = length - 1;
    while (start < end)
    {
        if (string[start] != string[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isAnagram(char string1[], char string2[])
{
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    if (length1 != length2)
    {
        return false;
    }
    int charCount[26] = {0};
    for (int i = 0; i < length1; i++)
    {
        charCount[string1[i] - 'a']++;
    }
    for (int i = 0; i < length2; i++)
    {
        charCount[string2[i] - 'a']--;
        if (charCount[string2[i] - 'a'] < 0)
        {
            return false;
        }
    }
    return true;
}