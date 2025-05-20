//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000

struct word_count {
    char word[50];
    int count;
};

void read_words(struct word_count words[], int num_words, FILE *file) {
    char line[1000];
    int line_num = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        int i, j;
        for (i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                for (j = i + 1; j < strlen(line); j++) {
                    if (!isalpha(line[j])) {
                        strncpy(words[num_words].word, line + i, j - i);
                        words[num_words].word[j - i] = '\0';
                        words[num_words].count++;
                        num_words++;
                        i = j;
                        break;
                    }
                }
            }
        }
        line_num++;
    }
}

void sort_words(struct word_count words[], int num_words) {
    int i, j;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[j].count > words[i].count) {
                struct word_count temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void display_words(struct word_count words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    struct word_count words[MAX_WORDS];
    int num_words = 0;
    read_words(words, num_words, file);
    fclose(file);
    sort_words(words, num_words);
    display_words(words, num_words);
    return 0;
}