//FormAI DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main()
{
    char string1[50] = "Hello, World!";
    char string2[50] = "Welcome to the code revolution!";

    // Changing strings to uppercase
    for (int i = 0; i < strlen(string1); i++)
    {
        string1[i] = toupper(string1[i]);
    }

    for (int i = 0; i < strlen(string2); i++)
    {
        string2[i] = toupper(string2[i]);
    }

    printf("Original Strings:\n");
    printf("%s\n", string1);
    printf("%s\n\n", string2);

    // Concatenating strings
    strcat(string1, string2);
    printf("Concatenated String:\n");
    printf("%s\n\n", string1);

    // Reversing strings
    int string_length = strlen(string1);
    char reversed_string[string_length];

    for (int i = 0; i < string_length; i++)
    {
        reversed_string[i] = string1[string_length - 1 - i];
    }
    reversed_string[string_length] = '\0';

    printf("Reversed String:\n");
    printf("%s\n\n", reversed_string);

    // Removing vowels
    char vowels[] = "AEIOUaeiou";
    int vow_length = strlen(vowels);

    for (int i = 0; i < strlen(string1); i++)
    {
        for (int j = 0; j < vow_length; j++)
        {
            if (string1[i] == vowels[j])
            {
                for (int k = i; k < strlen(string1); k++)
                {
                    string1[k] = string1[k + 1];
                }
                i--;
                break;
            }
        }
    }

    printf("String without Vowels:\n");
    printf("%s\n\n", string1);

    return 0;
}