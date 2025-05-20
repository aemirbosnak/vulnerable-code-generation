//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 256

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} WordFrequency;

char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, file)) == -1) {
        printf("Error reading line\n");
        exit(1);
    }

    return line;
}

void split_line(char *line, char **words) {
    char *word = strtok(line, " ");
    int num_words = 0;

    while (word!= NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }
}

void update_word_count(WordCount *word_counts, int num_words, const char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }

    word_counts[num_words].word = strdup(word);
    word_counts[num_words].count = 1;
    num_words++;
}

void print_word_frequency(WordFrequency *word_frequency) {
    int i;

    for (i = 0; i < word_frequency->num_words; i++) {
        printf("%s: %d\n", word_frequency->word_counts[i].word, word_frequency->word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char *line;
    char **words;
    WordFrequency word_frequency = {NULL, 0};

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((line = read_line(file))!= NULL) {
        words = malloc(MAX_WORD_SIZE * sizeof(char *));
        split_line(line, words);

        int num_words = 0;
        while (words[num_words]!= NULL) {
            num_words++;
        }

        word_frequency.word_counts = realloc(word_frequency.word_counts, num_words * sizeof(WordCount));
        word_frequency.num_words = num_words;

        for (int i = 0; i < num_words; i++) {
            update_word_count(word_frequency.word_counts, num_words, words[i]);
        }

        free(words);
        free(line);
    }

    print_word_frequency(&word_frequency);

    for (int i = 0; i < word_frequency.num_words; i++) {
        free(word_frequency.word_counts[i].word);
    }
    free(word_frequency.word_counts);

    fclose(file);

    return 0;
}