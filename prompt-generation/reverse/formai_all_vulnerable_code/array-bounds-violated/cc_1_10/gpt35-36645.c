//FormAI DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

int isWordChar(char c);
void processWord(char * word);
void processLine(char * line, int length);

int main() {
    char line[1000];
    int length;

    printf("Enter a sentence: ");

    if (fgets(line, sizeof(line), stdin) != NULL) {
        length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
        }
        processLine(line, length);
    }

    return 0;
}

int isWordChar(char c) {
    return isalpha(c) || c == '-' || c == '\'';
}

void processWord(char * word) {
    int length = strlen(word);

    if (length > MAX_WORD_LENGTH) {
        printf("'%s' is too long.\n", word);
        return;
    }

    for (int i = 0; i < length; i++) {
        if (!isWordChar(word[i])) {
            printf("'%s' contains invalid character '%c'.\n", word, word[i]);
            return;
        }
    }

    printf("'%s' is a valid word.\n", word);
}

void processLine(char * line, int length) {
    char word[MAX_WORD_LENGTH + 1];
    int i, j;

    for (i = 0, j = 0; i < length; i++) {
        if (isWordChar(line[i])) {
            if (j == MAX_WORD_LENGTH) {
                printf("'%s' is too long.\n", word);
                j = 0;
            }
            word[j++] = tolower(line[i]);
        } else if (j > 0) {
            word[j] = '\0';
            processWord(word);
            j = 0;
        }
    }

    if (j > 0) {
        word[j] = '\0';
        processWord(word);
    }
}