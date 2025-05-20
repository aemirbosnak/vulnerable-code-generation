//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 1000

void generateRandomString(char* str, int length) {
    const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        str[i] = alphanum[rand() % strlen(alphanum)];
    }
    str[length] = '\0';
}

void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void convertToLowerCase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

void convertToUpperCase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char inputString[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", inputString);

    char reversedString[MAX_LENGTH];
    strcpy(reversedString, inputString);
    reverseString(reversedString);

    printf("Reversed string: %s\n", reversedString);

    char lowercaseString[MAX_LENGTH];
    strcpy(lowercaseString, inputString);
    convertToLowerCase(lowercaseString);

    printf("Lowercase string: %s\n", lowercaseString);

    char uppercaseString[MAX_LENGTH];
    strcpy(uppercaseString, inputString);
    convertToUpperCase(uppercaseString);

    printf("Uppercase string: %s\n", uppercaseString);

    char randomString[MAX_LENGTH];
    generateRandomString(randomString, strlen(inputString));

    printf("Random string: %s\n", randomString);

    return 0;
}