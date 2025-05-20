//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define WORD_SIZE 50

void reverse_string(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void reverse_word(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char input[100][WORD_SIZE];
    char* token;
    int i = 0, j = 0, k = 0, len;

    printf("Enter a string: ");
    fgets(input[i], sizeof(input[i]), stdin);
    input[i][strlen(input[i]) - 1] = '\0'; // Remove newline character

    token = strtok(input[i], " ");
    while (token != NULL) {
        len = strlen(token);
        reverse_string(token);
        strcat(input[i], " ");
        strcat(input[i], token);
        strcat(input[i], " ");

        token = strtok(NULL, " ");
    }

    reverse_string(input[i]);

    printf("\nReversed Words: %s\n", input[i]);

    for (i = 0; input[i][0] != '\0'; i++) {
        j = 0;
        k = 0;

        while (input[i][j] != ' ' && input[i][j] != '\0') {
            if (isalpha(input[i][j])) {
                reverse_word(input[i], k, j - 1);
                j++;
                k += (input[i][j] - 'a' + 1) / 2;
            } else {
                j++;
            }
        }
    }

    printf("\nReversed Each Character: %s\n", input[i]);

    return 0;
}