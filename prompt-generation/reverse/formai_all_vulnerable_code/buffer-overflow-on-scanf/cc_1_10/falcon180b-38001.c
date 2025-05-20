//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length/2; i++) {
        char temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    if (length == 0 || length == 1) {
        return 1;
    }
    for (int i = 0; i < length/2; i++) {
        if (tolower(str[i])!= tolower(str[length-i-1])) {
            return 0;
        }
    }
    return 1;
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
            count++;
        }
    }
    return count;
}

// Function to get the frequency of a character in a string
int getFrequency(char* str, char ch) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (tolower(str[i]) == tolower(ch)) {
            count++;
        }
    }
    return count;
}

// Function to get the most frequent character in a string
char getMostFrequentChar(char* str) {
    int maxCount = 0;
    char mostFrequentChar = '\0';
    for (int i = 0; i < strlen(str); i++) {
        int count = getFrequency(str, str[i]);
        if (count > maxCount) {
            maxCount = count;
            mostFrequentChar = str[i];
        }
    }
    return mostFrequentChar;
}

// Function to get the least frequent character in a string
char getLeastFrequentChar(char* str) {
    int minCount = 999;
    char leastFrequentChar = '\0';
    for (int i = 0; i < strlen(str); i++) {
        int count = getFrequency(str, str[i]);
        if (count < minCount) {
            minCount = count;
            leastFrequentChar = str[i];
        }
    }
    return leastFrequentChar;
}

// Function to print the results
void printResults(char* str) {
    printf("Is Palindrome: %s\n", isPalindrome(str)? "Yes" : "No");
    printf("Number of Vowels: %d\n", countVowels(str));
    printf("Most Frequent Character: %c\n", getMostFrequentChar(str));
    printf("Least Frequent Character: %c\n", getLeastFrequentChar(str));
}

// Main function
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    reverse(input);
    printResults(input);
    return 0;
}