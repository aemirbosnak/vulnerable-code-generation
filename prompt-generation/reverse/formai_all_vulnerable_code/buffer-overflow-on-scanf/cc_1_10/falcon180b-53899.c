//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_SIZE 100
#define MAX_WORD_SIZE 20
#define FILENAME_SIZE 50

// Function prototypes
void read_file(FILE *file, char *word);
void write_file(FILE *file, char *word);
int compare_words(const void *a, const void *b);

int main() {
    char filename[FILENAME_SIZE];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    char word[MAX_WORD_SIZE];
    read_file(file, word);

    qsort(word, strlen(word), sizeof(char), compare_words);

    printf("\nSorted words:\n");
    for (int i = 0; i < strlen(word); i++) {
        printf("%c ", word[i]);
    }

    fclose(file);
    return 0;
}

void read_file(FILE *file, char *word) {
    char ch;
    int count = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[count++] = tolower(ch);
        }
    }
    word[count] = '\0';
}

void write_file(FILE *file, char *word) {
    fprintf(file, "%s\n", word);
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}