//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

char string[MAX_LENGTH];

void removeVowels(char* str) {
    char vowels[] = "aeiouAEIOU";
    int i, j;
    for (i = 0, j = 0; i < strlen(str); i++) {
        if (strchr(vowels, tolower(str[i])) == NULL) {
            string[j++] = tolower(str[i]);
        }
    }
    string[j] = '\0';
}

void reverseString(char* str) {
    int i, j;
    for (i = strlen(str) - 1, j = 0; i >= 0; i--, j++) {
        string[j] = str[i];
    }
    string[j] = '\0';
}

void convertToUpper(char* str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        string[i] = toupper(str[i]);
    }
    string[i] = '\0';
}

void countWords(char* str) {
    int i, j, count = 0;
    for (i = 0; str[i]!= '\0'; i++) {
        if (isspace(str[i])) {
            count++;
        }
    }
    sprintf(string, "Number of words: %d", count);
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", input);

    printf("Original string: %s\n", input);

    removeVowels(input);
    printf("String without vowels: %s\n", string);

    reverseString(input);
    printf("Reversed string: %s\n", string);

    convertToUpper(input);
    printf("String in uppercase: %s\n", string);

    countWords(input);
    printf("Number of words: %s\n", string);

    return 0;
}