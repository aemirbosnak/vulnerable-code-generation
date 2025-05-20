//Falcon-180B DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 10
#define SENTENCE_LENGTH 100
#define PARAGRAPH_LENGTH 500

char *process_word(char *word) {
    int i, j;
    char *result = malloc(WORD_LENGTH * sizeof(char));

    for (i = 0, j = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            result[j] = tolower(word[i]);
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

char *process_sentence(char *sentence) {
    int i, j;
    char *result = malloc(SENTENCE_LENGTH * sizeof(char));

    for (i = 0, j = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            result[j] = tolower(sentence[i]);
            j++;
        } else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?') {
            result[j] = sentence[i];
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

char *process_paragraph(char *paragraph) {
    int i, j;
    char *result = malloc(PARAGRAPH_LENGTH * sizeof(char));

    for (i = 0, j = 0; i < strlen(paragraph); i++) {
        if (isalpha(paragraph[i])) {
            result[j] = tolower(paragraph[i]);
            j++;
        } else if (paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?') {
            result[j] = paragraph[i];
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

void print_word_count(char *word, int count) {
    printf("%s: %d\n", word, count);
}

void print_sentence_count(char *sentence, int count) {
    printf("%s: %d\n", sentence, count);
}

void print_paragraph_count(char *paragraph, int count) {
    printf("%s: %d\n", paragraph, count);
}

int main() {
    FILE *file;
    char ch;
    char *word = malloc(WORD_LENGTH * sizeof(char));
    char *sentence = malloc(SENTENCE_LENGTH * sizeof(char));
    char *paragraph = malloc(PARAGRAPH_LENGTH * sizeof(char));

    int word_count = 0, sentence_count = 0, paragraph_count = 0;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            strcat(word, &ch);
        } else if (ch == '.' || ch == '!' || ch == '?') {
            process_word(word);
            print_word_count(word, ++word_count);
            strcpy(word, "");
        }

        if (isalpha(ch)) {
            strcat(sentence, &ch);
        } else if (ch == '.' || ch == '!' || ch == '?') {
            process_sentence(sentence);
            print_sentence_count(sentence, ++sentence_count);
            strcpy(sentence, "");
        }

        if (isalpha(ch)) {
            strcat(paragraph, &ch);
        } else if (ch == '.' || ch == '!' || ch == '?') {
            process_paragraph(paragraph);
            print_paragraph_count(paragraph, ++paragraph_count);
            strcpy(paragraph, "");
        }
    }

    fclose(file);

    return 0;
}