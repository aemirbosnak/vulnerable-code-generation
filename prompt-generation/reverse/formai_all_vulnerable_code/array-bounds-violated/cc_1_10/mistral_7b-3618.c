//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 1024
#define WORD_LEN 50

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void process_word(char *word) {
    int len = strlen(word);
    char reversed_word[WORD_LEN];
    strcpy(reversed_word, word);
    reverse_string(reversed_word);

    int i;
    for (i = 0; i < len; i++) {
        if (isalpha(word[i]))
            putchar(tolower(word[i]));
        else if (isdigit(word[i]))
            putchar(word[i]);
        else
            continue;
    }

    putchar(' ');
    for (i = 0; i < len; i++) {
        if (isalpha(reversed_word[i]))
            putchar(toupper(reversed_word[i]));
        else if (isdigit(reversed_word[i]))
            putchar(reversed_word[i]);
        else
            continue;
    }

    putchar(' ');
}

int main() {
    char line[MAX_LINE];
    char *token;
    int count = 0;

    printf("Enter a line of text:\n");
    fgets(line, MAX_LINE, stdin);
    line[strlen(line) - 1] = '\0';

    token = strtok(line, " ");
    while (token != NULL) {
        process_word(token);
        token = strtok(NULL, " ");
        count++;
    }

    printf("\n%d words processed.\n", count);

    return 0;
}