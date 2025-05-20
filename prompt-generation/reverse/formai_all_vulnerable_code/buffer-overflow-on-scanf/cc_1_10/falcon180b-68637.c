//Falcon-180B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE* file, WordCount* word_counts, int num_words) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i;

    for (i = 0; i < num_words; i++) {
        word_counts[i].count = 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* token = strtok(line, ",.!?:;\"'");

        while (token!= NULL) {
            strcpy(word, token);
            token = strtok(NULL, ",.!?:;\"'");

            int j;
            for (j = 0; j < num_words; j++) {
                if (strcmp(word, word_counts[j].word) == 0) {
                    word_counts[j].count++;
                    break;
                }
            }

            if (j == num_words) {
                printf("Unknown word: %s\n", word);
            }
        }
    }
}

void print_word_counts(WordCount* word_counts, int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE* file;
    char filename[MAX_LINE_LENGTH];
    WordCount word_counts[10];
    int num_words;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the number of words to count: ");
    scanf("%d", &num_words);

    read_file(file, word_counts, num_words);
    print_word_counts(word_counts, num_words);

    fclose(file);

    return 0;
}