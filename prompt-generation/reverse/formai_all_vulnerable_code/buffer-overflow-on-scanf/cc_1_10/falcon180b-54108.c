//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    int i = 0;

    for (int j = length - 1; j >= 0; j--) {
        reversed[i++] = str[j];
    }

    reversed[i] = '\0';
    strcpy(str, reversed);
    free(reversed);
}

void capitalize(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void encrypt(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = str[i] + 3;
        if (str[i] > 'z') {
            str[i] = str[i] - 26;
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Original string: %s\n", input);
    reverse(input);
    printf("Reversed string: %s\n", input);

    printf("Original string: %s\n", input);
    capitalize(input);
    printf("Capitalized string: %s\n", input);

    printf("Original string: %s\n", input);
    encrypt(input);
    printf("Encrypted string: %s\n", input);

    return 0;
}