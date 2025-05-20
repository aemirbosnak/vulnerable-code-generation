//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_LINE_LENGTH 10000

// Function to remove leading and trailing spaces from a string
void trim(char* str) {
    char* end;
    if (str!= NULL) {
        end = str + strlen(str) - 1;
        while (isspace(*end)) {
            end--;
            *end = '\0';
        }
        while (isspace(*str)) {
            str++;
        }
    }
}

// Function to tokenize a sentence into words
int tokenize(char* sentence, char* words[]) {
    int count = 0;
    char* token = strtok(sentence, ",.?!;:");
    while (token!= NULL) {
        trim(token);
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, ",.?!;:");
    }
    return count;
}

// Function to translate a word from English to Cat
void translate(char* english, char* cat[]) {
    strcpy(cat, english);
    for (int i = 0; i < strlen(cat); i++) {
        if (isalpha(cat[i])) {
            cat[i] = tolower(cat[i]);
        }
    }
}

// Function to translate a sentence from English to Cat
void translate_sentence(char* english, char* cat) {
    cat[0] = '\0';
    int word_count = tokenize(english, cat);
    for (int i = 0; i < word_count; i++) {
        translate(cat[i], cat);
        strcat(cat, " ");
    }
}

int main() {
    FILE* input_file;
    char line[MAX_LINE_LENGTH];
    char english[MAX_SENTENCE_LENGTH];
    char cat[MAX_SENTENCE_LENGTH];

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        trim(line);
        if (strlen(line) > 0) {
            strcpy(english, line);
            translate_sentence(english, cat);
            printf("%s\n", cat);
        }
    }

    fclose(input_file);
    return 0;
}