//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

// Function to reverse a string
char *reverseString(char *str) {
    int len = strlen(str);
    char *reversedStr = (char *)malloc(len + 1);
    int i;
    for (i = 0; i < len; i++) {
        reversedStr[i] = str[len - i - 1];
    }
    reversedStr[len] = '\0';
    return reversedStr;
}

// Function to find the longest palindrome in a string
char *longestPalindrome(char *str) {
    int len = strlen(str);
    int i, j, k, maxLen = 0, start = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            for (k = 0; i + k < j - k && str[i + k] == str[j - k]; k++);
            if (k > maxLen) {
                maxLen = k;
                start = i;
            }
        }
    }
    char *palindrome = (char *)malloc(maxLen + 1);
    for (i = 0; i < maxLen; i++) {
        palindrome[i] = str[start + i];
    }
    palindrome[maxLen] = '\0';
    return palindrome;
}

// Function to find the most frequent character in a string
char mostFrequentCharacter(char *str) {
    int len = strlen(str);
    int frequencies[256] = {0};
    int i, maxFrequency = 0, maxChar = '\0';
    for (i = 0; i < len; i++) {
        frequencies[str[i]]++;
    }
    for (i = 0; i < 256; i++) {
        if (frequencies[i] > maxFrequency) {
            maxFrequency = frequencies[i];
            maxChar = i;
        }
    }
    return maxChar;
}

// Function to find the number of words in a string
int numberOfWords(char *str) {
    int len = strlen(str);
    int i, count = 0;
    int inWord = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

// Function to find the number of sentences in a string
int numberOfSentences(char *str) {
    int len = strlen(str);
    int i, count = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == '.' || str[i] == '?' || str[i] == '!') {
            count++;
        }
    }
    return count;
}

// Function to find the number of paragraphs in a string
int numberOfParagraphs(char *str) {
    int len = strlen(str);
    int i, count = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == '\n') {
            count++;
        }
    }
    return count;
}

// Main function
int main() {
    // Get the input string from the user
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    gets(str);

    // Print the original string
    printf("Original string: %s\n", str);

    // Print the reversed string
    char *reversedStr = reverseString(str);
    printf("Reversed string: %s\n", reversedStr);

    // Print the longest palindrome in the string
    char *palindrome = longestPalindrome(str);
    printf("Longest palindrome: %s\n", palindrome);

    // Print the most frequent character in the string
    char mostFrequentChar = mostFrequentCharacter(str);
    printf("Most frequent character: %c\n", mostFrequentChar);

    // Print the number of words in the string
    int numberOfWordsInStr = numberOfWords(str);
    printf("Number of words: %d\n", numberOfWordsInStr);

    // Print the number of sentences in the string
    int numberOfSentencesInStr = numberOfSentences(str);
    printf("Number of sentences: %d\n", numberOfSentencesInStr);

    // Print the number of paragraphs in the string
    int numberOfParagraphsInStr = numberOfParagraphs(str);
    printf("Number of paragraphs: %d\n", numberOfParagraphsInStr);

    // Free the allocated memory
    free(reversedStr);
    free(palindrome);

    return 0;
}