//Falcon-180B DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_file(FILE *file, char *filename) {
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int i, j;
        for (i = 0; line[i]!= '\0'; i++) {
            if (isalpha(line[i])) {
                for (j = 0; j < strlen(line) - i; j++) {
                    if (!isalpha(line[i + j])) {
                        break;
                    }
                }
                strncpy(line + i, " ", j);
                line[i + j] = '\0';
            }
        }
        printf("%s", line);
    }
}

void count_words(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }
    read_file(file, filename);
    fclose(file);
}

void sort_words(Word words[], int num_words) {
    int i, j;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[j].count > words[i].count) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(Word words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    count_words(filename);
    return 0;
}