//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define MAX_DATE_LENGTH 10

char* get_word(char* sentence, int* index) {
    char* word = malloc(MAX_WORD_LENGTH * sizeof(char));
    int length = 0;
    while (isspace(sentence[*index]) == 0 && length < MAX_WORD_LENGTH - 1) {
        word[*index - *index] = sentence[*index];
        (*index)++;
        length++;
    }
    word[length] = '\0';
    return word;
}

char* get_date(char* sentence, int* index) {
    char* date = malloc(MAX_DATE_LENGTH * sizeof(char));
    int length = 0;
    while (isdigit(sentence[*index]) == 0 && length < MAX_DATE_LENGTH - 1) {
        date[*index - *index] = sentence[*index];
        (*index)++;
        length++;
    }
    date[length] = '\0';
    return date;
}

int is_date(char* date) {
    struct tm tm;
    strptime(date, "%d/%m/%Y", &tm);
    return mktime(&tm)!= -1;
}

void convert_date(char* date) {
    struct tm tm;
    strptime(date, "%d/%m/%Y", &tm);
    printf("%.4d-%.2d-%.2d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    int index = 0;
    char* word = get_word(sentence, &index);
    while (strcmp(word, "")!= 0) {
        char* date = get_date(sentence, &index);
        if (is_date(date)) {
            convert_date(date);
        }
        word = get_word(sentence, &index);
    }
    return 0;
}