//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

char *words[MAX_WORDS];
int num_words;

void read_words(FILE *file) {
    char word[MAX_WORD_LENGTH];
    char *ptr;
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        ptr = strtok(word, " \t\n\r\f\v");
        while (ptr!= NULL) {
            if (i >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            words[i++] = strdup(ptr);
            ptr = strtok(NULL, " \t\n\r\f\v");
        }
    }
    num_words = i;
}

void stem(char *word) {
    int len = strlen(word);
    char *ptr = word + len - 1;

    while (*ptr =='s' || *ptr == 'e' || *ptr == 'd' || *ptr == 'i' || *ptr == 'n' || *ptr == 'g') {
        *ptr-- = '\0';
        len--;
    }

    if (len > 0) {
        strcpy(word, word + len);
    }
}

void search(char *query) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(query, words[i]) == 0) {
            printf("Found: %s\n", query);
            return;
        }
    }
    printf("Not found: %s\n", query);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *ptr;
    char query[MAX_WORD_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_words(file);
    fclose(file);

    while (1) {
        printf("Enter a query: ");
        fgets(line, MAX_WORD_LENGTH, stdin);
        ptr = strtok(line, "\n");
        strcpy(query, ptr);
        stem(query);
        search(query);
    }

    return 0;
}