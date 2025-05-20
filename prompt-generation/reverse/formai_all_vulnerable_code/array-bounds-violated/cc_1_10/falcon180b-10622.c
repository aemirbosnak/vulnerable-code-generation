//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse(char* str) {
    int length = strlen(str);
    char temp;
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void capitalize(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    int length = strlen(input);

    // Remove leading and trailing whitespace
    while (isspace(input[0])) {
        strcpy(input, &input[1]);
        length--;
    }
    while (isspace(input[length - 1])) {
        input[length - 1] = '\0';
        length--;
    }

    // Reverse the string
    reverse(input);

    // Capitalize the first letter of each word
    char* word = strtok(input, " ");
    while (word!= NULL) {
        capitalize(word);
        printf("%s ", word);
        word = strtok(NULL, " ");
    }

    return 0;
}