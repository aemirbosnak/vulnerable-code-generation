//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Function to count the number of vowels in a string
int count_vowels(char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    char str1[50], str2[50];

    // Input two strings from the user
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    // Find the length of both strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Convert all characters in string 1 to uppercase
    for (int i = 0; i < len1; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] = str1[i] - 32;
        }
    }

    // Convert all characters in string 2 to lowercase
    for (int i = 0; i < len2; i++) {
        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] = str2[i] + 32;
        }
    }

    // Concatenate the two strings
    strcat(str1, str2);

    // Find the number of vowels in the concatenated string
    int vowels = count_vowels(str1);

    // Print the final output
    printf("Result: %s\n", str1);
    printf("Number of vowels: %d\n", vowels);

    return 0;
}