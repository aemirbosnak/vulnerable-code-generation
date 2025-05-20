//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/* Function to tokenize a string */
char *tokenize(char *str) {
    char *token = strtok(str, " ");
    while (token!= NULL) {
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

/* Function to calculate the frequency of words in a string */
void word_frequency(char *str) {
    char *token;
    int freq[26] = {0}; /* Assuming only lowercase alphabets */
    while ((token = strtok(str, " "))!= NULL) {
        freq[(int)token[0] - 97]++; /* Subtracting 97 to get index from 0 to 25 */
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", (char)i + 97, freq[i]);
        }
    }
}

/* Function to check if a string contains only alphabets */
int is_alpha(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[1000];
    printf("Enter a string:\n");
    fgets(input, sizeof(input), stdin);
    if (is_alpha(input)) {
        tokenize(input);
        word_frequency(input);
    } else {
        printf("Invalid input. Please enter only alphabets.\n");
    }
    return 0;
}