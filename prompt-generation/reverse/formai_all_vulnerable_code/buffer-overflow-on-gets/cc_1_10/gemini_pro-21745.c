//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function to remove duplicate characters from a string
char *removeDuplicates(char *str) {
    int i, j, len = strlen(str);
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                str[j] = '\0';
            }
        }
    }
    return str;
}

// Function to reverse a string
char *reverseString(char *str) {
    int i, len = strlen(str);
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

// Function to find the longest palindrome in a string
char *longestPalindrome(char *str) {
    int i, j, len = strlen(str), maxLen = 0, startIndex = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] == str[j] && j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                startIndex = i;
            }
        }
    }
    char *palindrome = (char *)malloc(maxLen + 1);
    strncpy(palindrome, str + startIndex, maxLen);
    palindrome[maxLen] = '\0';
    return palindrome;
}

// Function to find the most frequent character in a string
char mostFrequentCharacter(char *str) {
    int i, j, len = strlen(str), count = 0, maxCount = 0;
    char mostFrequentChar;
    for (i = 0; i < len; i++) {
        count = 0;
        for (j = 0; j < len; j++) {
            if (str[i] == str[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequentChar = str[i];
        }
    }
    return mostFrequentChar;
}

// Function to generate all permutations of a string
void permutations(char *str, int start, int end) {
    int i;
    if (start == end) {
        printf("%s\n", str);
    } else {
        for (i = start; i <= end; i++) {
            char temp = str[start];
            str[start] = str[i];
            str[i] = temp;
            permutations(str, start + 1, end);
            temp = str[start];
            str[start] = str[i];
            str[i] = temp;
        }
    }
}

int main() {
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    gets(str);

    printf("Removed duplicates: %s\n", removeDuplicates(str));
    printf("Reversed string: %s\n", reverseString(str));
    printf("Longest palindrome: %s\n", longestPalindrome(str));
    printf("Most frequent character: %c\n", mostFrequentCharacter(str));
    printf("Permutations:\n");
    permutations(str, 0, strlen(str) - 1);
    return 0;
}