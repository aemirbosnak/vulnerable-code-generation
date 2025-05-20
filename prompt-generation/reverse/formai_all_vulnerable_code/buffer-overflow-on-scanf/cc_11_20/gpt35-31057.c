//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char original_string[50], new_string[50], reverse_string[50];
    int i, j, len, vowel_count = 0, consonant_count = 0;

    // Get user input
    printf("Enter a string: ");
    scanf("%s", original_string);

    // Copy original_string to new_string
    strcpy(new_string, original_string);

    // Get length of original_string
    len = strlen(original_string);

    // Capitalize first letter of original_string
    if (original_string[0] >= 'a' && original_string[0] <= 'z')
    {
        original_string[0] = original_string[0] - 32;
    }

    // Count vowels and consonants in original_string
    for (i = 0; i < len; i++)
    {
        if (original_string[i] == 'a' || original_string[i] == 'A' ||
            original_string[i] == 'e' || original_string[i] == 'E' ||
            original_string[i] == 'i' || original_string[i] == 'I' ||
            original_string[i] == 'o' || original_string[i] == 'O' ||
            original_string[i] == 'u' || original_string[i] == 'U')
        {
            vowel_count++;
        }
        else if ((original_string[i] >= 'a' && original_string[i] <= 'z') || (original_string[i] >= 'A' && original_string[i] <= 'Z'))
        {
            consonant_count++;
        }
    }

    // Reverse original_string
    for (i = len - 1, j = 0; i >= 0; i--, j++)
    {
        reverse_string[j] = original_string[i];
    }
    reverse_string[j] = '\0';

    // Output results
    printf("\nOriginal String: %s\n", original_string);
    printf("New String: %s\n", new_string);
    printf("First Letter Capitalized: %s\n", original_string);
    printf("Vowel Count: %d\n", vowel_count);
    printf("Consonant Count: %d\n", consonant_count);
    printf("Reversed String: %s\n", reverse_string);

    return 0;
}