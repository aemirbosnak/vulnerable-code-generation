//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    // Welcome message
    printf("Welcome to the String Manipulator program by Chatbot 9000.\n");

    // Get user input
    printf("Please enter a string:\n");
    char str[100];
    scanf("%[^\n]", str);
    getchar();

    // Determine string length
    int len = strlen(str);

    // Reverse the string
    char rev_str[100];
    int i;
    for (i = 0; i < len; i++) {
        rev_str[i] = str[len-i-1];
    }
    rev_str[len] = '\0';

    // Count the number of words in the string
    int num_words = 1; // start at 1 because there's at least 1 word
    for (i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            num_words++;
        }
    }

    // Count the number of vowels in the string
    int num_vowels = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            num_vowels++;
        }
    }

    // Convert the string to uppercase
    char upper_str[100];
    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            upper_str[i] = str[i] - 32;
        } else {
            upper_str[i] = str[i];
        }
    }
    upper_str[len] = '\0';

    // Print the results
    printf("The reverse of the string is: %s\n", rev_str);
    printf("The string has %d words.\n", num_words);
    printf("The string has %d vowels.\n", num_vowels);
    printf("The uppercase version of the string is: %s\n", upper_str);

    return 0;
}