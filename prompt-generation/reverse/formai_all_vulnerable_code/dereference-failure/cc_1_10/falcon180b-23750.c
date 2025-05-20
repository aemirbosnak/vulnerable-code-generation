//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_LINE_LENGTH 10000

// Function to remove leading and trailing whitespace from a string
void trim(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (isspace(str[i])) {
        i++;
    }

    while (isspace(str[j])) {
        j--;
    }

    if (i > j) {
        str[0] = '\0';
    } else {
        str[j+1] = '\0';
        for (int k = i; k <= j; k++) {
            str[k] = tolower(str[k]);
        }
    }
}

// Function to split a string into words
void split(char* str, char* words[]) {
    char* token = strtok(str, ",.?!;:");
    int i = 0;

    while (token!= NULL) {
        trim(token);
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, ",.?!;:");
    }
}

// Function to translate a sentence from English to Cat
void translate(char* english[], char* cat[]) {
    strcpy(cat[0], "Meow ");

    for (int i = 1; i < strlen(english); i++) {
        strcpy(cat[i], english[i]);
    }
}

// Function to print a sentence in a romantic style
void print_sentence(char* words[]) {
    for (int i = 0; i < strlen(words); i++) {
        printf("%s ", words[i]);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char* english[MAX_SENTENCE_LENGTH];
    char* cat[MAX_SENTENCE_LENGTH];

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strlen(line) > MAX_SENTENCE_LENGTH) {
            printf("Error: Sentence is too long.\n");
            continue;
        }

        split(line, english);
        translate(english, cat);
        printf("English: ");
        print_sentence(english);
        printf("\nCat: ");
        print_sentence(cat);
        printf("\n\n");
    }

    fclose(file);
    return 0;
}