//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 100

// Function to check if two strings are anagrams
int checkAnagrams(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
        return 0;

    int charCount[26] = {0}; // Initialize all to 0

    // Increment the count for each character in the first string
    for (int i = 0; i < len1; i++) {
        charCount[str1[i] - 'a']++;
    }

    // Decrement the count for each character in the second string
    for (int i = 0; i < len2; i++) {
        charCount[str2[i] - 'a']--;
    }

    // Check if all counts are 0, indicating that the two strings are anagrams
    for (int i = 0; i < 26; i++) {
        if (charCount[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {

    // Declare two string arrays to hold user input
    char str1[MAX_STRING_LEN];
    char str2[MAX_STRING_LEN];

    // Get user input for the first string
    printf("Enter the first string: ");
    fgets(str1, MAX_STRING_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character at the end

    // Get user input for the second string
    printf("Enter the second string: ");
    fgets(str2, MAX_STRING_LEN, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the newline character at the end

    // Check if the strings are anagrams and print the result
    if (checkAnagrams(str1, str2)) {
        printf("The strings \"%s\" and \"%s\" are anagrams\n", str1, str2);
    } else {
        printf("The strings \"%s\" and \"%s\" are not anagrams\n", str1, str2);
    }

    return 0;
}