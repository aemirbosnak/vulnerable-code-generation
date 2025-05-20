//FormAI DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    char data[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;

    // read input from file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    while (fgets(data[rows], MAX_COLS, fp) != NULL) {
        cols = strlen(data[rows]);
        data[rows][cols-1] = '\0'; // remove newline character from end of line
        rows++;
    }
    fclose(fp);

    // find total number of words
    int wordCount = 0;
    for (int i = 0; i < rows; i++) {
        char *token = strtok(data[i], " ");
        while (token != NULL) {
            wordCount++;
            token = strtok(NULL, " ");
        }
    }
    printf("Total number of words in input: %d\n", wordCount);

    // find most common word
    char *mostCommonWord = "";
    int mostCommonWordFrequency = 0;
    for (int i = 0; i < rows; i++) {
        char *token = strtok(data[i], " ");
        while (token != NULL) {
            int frequency = 0;
            for (int j = i+1; j < rows; j++) {
                char *temp = strtok(data[j], " ");
                while (temp != NULL) {
                    if (strcmp(temp, token) == 0) {
                        frequency++;
                    }
                    temp = strtok(NULL, " ");
                }
            }
            if (frequency > mostCommonWordFrequency) {
                mostCommonWordFrequency = frequency;
                mostCommonWord = token;
            }
            token = strtok(NULL, " ");
        }
    }
    printf("Most common word in input: %s\n", mostCommonWord);

    // find longest palindrome
    char *longestPalindrome = "";
    int longestPalindromeLength = 0;
    for (int i = 0; i < rows; i++) {
        char *temp = strtok(data[i], " ");
        while (temp != NULL) {
            int len = strlen(temp);
            int start = 0, end = len-1, isPalindrome = 1;
            while (start < end) {
                if (temp[start] != temp[end]) {
                    isPalindrome = 0;
                    break;
                }
                start++;
                end--;
            }
            if (isPalindrome == 1 && len > longestPalindromeLength) {
                longestPalindromeLength = len;
                longestPalindrome = temp;
            }
            temp = strtok(NULL, " ");
        }
    }
    printf("Longest palindrome in input: %s\n", longestPalindrome);

    return 0;
}