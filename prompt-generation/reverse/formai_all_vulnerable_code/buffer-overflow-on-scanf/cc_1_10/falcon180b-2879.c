//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverseString(char* str) {
    int length = strlen(str);
    char temp[MAX_LENGTH];
    strcpy(temp, str);
    for (int i = 0; i < length / 2; i++) {
        char c = temp[i];
        temp[i] = temp[length - i - 1];
        temp[length - i - 1] = c;
    }
    strcpy(str, temp);
}

void capitalizeFirstLetter(char* str) {
    if (isalpha(str[0])) {
        str[0] = toupper(str[0]);
    }
}

void removeSpaces(char* str) {
    int length = strlen(str);
    char temp[MAX_LENGTH];
    strcpy(temp, str);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(temp[i])) {
            temp[j] = temp[i];
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

void countWords(char* str) {
    int count = 0;
    int length = strlen(str);
    int i = 0;
    while (i < length) {
        if (isspace(str[i])) {
            count++;
        }
        i++;
    }
    printf("Number of words: %d\n", count + 1);
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Original string: %s\n", input);

    reverseString(input);
    printf("Reversed string: %s\n", input);

    capitalizeFirstLetter(input);
    printf("Capitalized first letter: %s\n", input);

    removeSpaces(input);
    printf("Removed spaces: %s\n", input);

    countWords(input);

    return 0;
}