//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *text;
    int length;
} Text;

void read_file(const char *filename, Text *text) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *pos = strchr(line, '\n');
        if (pos!= NULL) {
            *pos = '\0';
        }

        strcat(text->text, line);
        text->length += strlen(line);
    }

    fclose(file);
}

void count_words(const char *text, WordCount *word_counts, int num_word_counts) {
    char *token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_word_counts; i++) {
            if (strcmp(token, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }

        if (i == num_word_counts) {
            if (num_word_counts == MAX_WORD_LENGTH) {
                printf("Error: too many unique words in text\n");
                exit(1);
            }

            WordCount *new_word_counts = malloc(sizeof(WordCount) * (num_word_counts + 1));
            memcpy(new_word_counts, word_counts, sizeof(WordCount) * num_word_counts);
            free(word_counts);
            word_counts = new_word_counts;
            word_counts[num_word_counts].word = strdup(token);
            word_counts[num_word_counts].count = 1;
            num_word_counts++;
        }

        token = strtok(NULL, ",.?!;:");
    }
}

void print_word_counts(const WordCount *word_counts, int num_word_counts) {
    printf("Word\tCount\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Text text;
    read_file(argv[1], &text);

    WordCount *word_counts = malloc(sizeof(WordCount) * MAX_WORD_LENGTH);
    int num_word_counts = 0;

    count_words(text.text, word_counts, num_word_counts);
    print_word_counts(word_counts, num_word_counts);

    free(word_counts);
    free(text.text);

    return 0;
}