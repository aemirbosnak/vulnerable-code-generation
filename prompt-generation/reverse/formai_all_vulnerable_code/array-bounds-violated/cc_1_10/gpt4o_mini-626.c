//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void printCharacterFrequency(char *str) {
    int frequency[256] = {0};

    for (int i = 0; str[i]; i++) {
        frequency[(unsigned char)str[i]]++;
    }

    printf("\nCharacter Frequencies:\n");
    for (int i = 32; i < 127; i++) { // Print only printable characters
        if (frequency[i] > 0) {
            printf("'%c' : %d\n", i, frequency[i]);
        }
    }
}

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void stripPunctuation(char *str) {
    char *ptr = str;
    char *output = str;

    while (*ptr) {
        if (!ispunct((unsigned char)*ptr)) {
            *output++ = *ptr;
        }
        ptr++;
    }
    *output = '\0'; // Null-terminate the stripped string
}

void findUniqueCharacters(char *str) {
    char unique[256] = {0};
    int index = 0;

    for (int i = 0; str[i]; i++) {
        if (!strchr(unique, str[i])) {
            unique[index++] = str[i];
        }
    }
    unique[index] = '\0'; // Null-terminate the unique string
    printf("\nUnique Characters: %s\n", unique);
}

int main() {
    char inputString[256];
    
    printf("Ah, Watson! We have an intriguing case of string manipulation. Please provide the text for analysis: ");
    fgets(inputString, sizeof(inputString), stdin);
  
    // Strip newline at the end:
    size_t ln = strlen(inputString) - 1;
    if (inputString[ln] == '\n') {
        inputString[ln] = '\0';
    }

    printf("\nOriginal String: %s\n", inputString);
    
    // Convert to lowercase
    char lowercase[256];
    strcpy(lowercase, inputString);
    toLowerCase(lowercase);
    printf("Lowercase String: %s\n", lowercase);
    
    // Convert to uppercase
    char uppercase[256];
    strcpy(uppercase, inputString);
    toUpperCase(uppercase);
    printf("Uppercase String: %s\n", uppercase);
    
    // Print character frequency
    printCharacterFrequency(inputString);
    
    // Reverse the string
    char reversed[256];
    strcpy(reversed, inputString);
    reverseString(reversed);
    printf("Reversed String: %s\n", reversed);
    
    // Strip punctuation
    stripPunctuation(inputString);
    printf("String after stripping punctuation: %s\n", inputString);
    
    // Find unique characters
    findUniqueCharacters(inputString);
    
    printf("\nElementary, my dear Watson! Each string manipulation yields new insights into the mystery of language.\n");
    
    return 0;
}