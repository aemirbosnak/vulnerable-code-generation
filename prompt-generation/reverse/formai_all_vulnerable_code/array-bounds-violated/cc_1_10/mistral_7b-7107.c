//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

typedef struct {
    char str[MAX_LENGTH];
    int len;
} String;

String randomizeString(String str) {
    int i, j, k;
    char temp;

    srand(time(NULL));

    for (i = 0; i < str.len/2; i++) {
        j = rand() % str.len;
        k = rand() % str.len;

        temp = str.str[j];
        str.str[j] = str.str[k];
        str.str[k] = temp;
    }

    return str;
}

String reverseString(String str) {
    int i;
    char temp;

    for (i = 0; i < str.len/2; i++) {
        temp = str.str[i];
        str.str[i] = str.str[str.len - i - 1];
        str.str[str.len - i - 1] = temp;
    }

    return str;
}

String capitalizeFirstLetter(String str) {
    if (str.len > 0) {
        str.str[0] = toupper(str.str[0]);
    }

    return str;
}

String addSuffix(String str, String suffix) {
    int i, lenSuffix;

    lenSuffix = suffix.len;

    for (i = str.len; i <= str.len + lenSuffix; i++) {
        str.str[i] = suffix.str[i - str.len];
    }

    str.len += lenSuffix;

    return str;
}

void printString(String str) {
    printf("%.*s\n", str.len, str.str);
}

int main() {
    String input, output, suffix;

    printf("Enter a string: ");
    fgets(input.str, MAX_LENGTH, stdin);
    input.len = strlen(input.str);
    input.str[input.len - 1] = '\0'; // Remove newline character

    printf("Enter a suffix: ");
    fgets(suffix.str, MAX_LENGTH, stdin);
    suffix.len = strlen(suffix.str);
    suffix.str[suffix.len - 1] = '\0'; // Remove newline character

    output = input;

    output = randomizeString(output);
    output = capitalizeFirstLetter(output);
    output = reverseString(output);
    output = addSuffix(output, suffix);

    printString(output);

    return 0;
}