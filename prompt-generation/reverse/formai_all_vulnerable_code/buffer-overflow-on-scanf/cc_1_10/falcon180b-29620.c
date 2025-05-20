//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to remove all vowels from the given string
void removeVowels(char* str) {
    int i, j;
    char vowels[] = "aeiouAEIOU";
    for (i = 0, j = 0; i < strlen(str); i++) {
        if (strchr(vowels, str[i]) == NULL) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to reverse the given string
void reverseString(char* str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert the given string to uppercase
void toUpperCase(char* str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to count the number of words in the given string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to replace all occurrences of a character with another character
void replaceChar(char* str, char find, char replace) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (str[i] == find) {
            str[i] = replace;
        }
    }
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove vowels from the string
    removeVowels(str);
    printf("String without vowels: %s\n", str);

    // Reverse the string
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Convert the string to uppercase
    toUpperCase(str);
    printf("String in uppercase: %s\n", str);

    // Count the number of words in the string
    int numWords = countWords(str);
    printf("Number of words: %d\n", numWords);

    // Replace all occurrences of a character with another character
    replaceChar(str, 'a', 'x');
    printf("String with replaced characters: %s\n", str);

    return 0;
}