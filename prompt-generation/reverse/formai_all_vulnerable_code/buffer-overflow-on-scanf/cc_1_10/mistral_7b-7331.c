//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} word_t;

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_separator(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void split_word(char *word, char *line, int *position) {
    int i = *position;
    int j = 0;

    while (is_separator(line[i])) {
        i++;
    }

    *position = i;

    while (line[i] && !is_separator(line[i]) && i - *position < WORD_LENGTH - 1) {
        word[j++] = line[i++];
    }

    word[j] = '\0';
    to_lower(word);
}

int main() {
    FILE *file;
    char filename[100];
    char line[1024];
    char word[WORD_LENGTH];
    int position = 0;
    word_t words[MAX_WORDS];

    printf("Torvalds-style Word Counter v1.0\n");
    printf("---------------------------------\n");
    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int num_words = 0;
    while (fgets(line, sizeof(line), file)) {
        while (num_words < MAX_WORDS && strlen(words[num_words].word) < WORD_LENGTH) {
            split_word(words[num_words].word, line, &position);
            if (strlen(words[num_words].word) > 0) {
                for (int i = num_words - 1; i >= 0 && strcmp(words[i].word, words[num_words].word) && words[i].count > 0; i--) {
                    words[i].count += words[num_words].count;
                }
                if (num_words > 0 && strcmp(words[num_words - 1].word, words[num_words].word)) {
                    words[num_words].count++;
                    num_words++;
                }
            }
        }
    }

    fclose(file);

    printf("\nWord\tCount\n-------------------------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}