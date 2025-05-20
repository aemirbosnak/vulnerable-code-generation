//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

void reverseString(char* str) {
    int length = strlen(str);
    char reversed[MAX_STRING_LENGTH];
    int j = 0;
    for(int i = length - 1; i >= 0; i--) {
        reversed[j++] = str[i];
    }
    reversed[j] = '\0';
    strcpy(str, reversed);
}

void capitalizeString(char* str) {
    int length = strlen(str);
    for(int i = 0; i < length; i++) {
        if(isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void removeWhitespace(char* str) {
    int length = strlen(str);
    int j = 0;
    for(int i = 0; i < length; i++) {
        if(!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void removePunctuation(char* str) {
    int length = strlen(str);
    int j = 0;
    for(int i = 0; i < length; i++) {
        if(!ispunct(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void countFrequency(char* str) {
    int length = strlen(str);
    int freq[256] = {0};
    for(int i = 0; i < length; i++) {
        freq[str[i]]++;
    }
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            printf("%c: %d\n", i, freq[i]);
        }
    }
}

int main() {
    char input[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Original string: %s\n", input);
    reverseString(input);
    printf("Reversed string: %s\n", input);

    printf("Capitalized string: %s\n", input);
    capitalizeString(input);

    printf("String without whitespace: %s\n", input);
    removeWhitespace(input);

    printf("String without punctuation: %s\n", input);
    removePunctuation(input);

    printf("Frequency of characters: \n");
    countFrequency(input);

    return 0;
}