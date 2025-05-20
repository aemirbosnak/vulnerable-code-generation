//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int num_words;
} WordCountTable;

void initialize_word_count_table(WordCountTable *table) {
    table->num_words = 0;
    table->words = NULL;
}

void add_word_to_table(WordCountTable *table, char *word) {
    WordCount *new_word = malloc(sizeof(WordCount));
    strcpy(new_word->word, word);
    new_word->count = 1;
    table->words = realloc(table->words, sizeof(WordCount) * ++table->num_words);
    table->words[table->num_words - 1] = *new_word;
}

void print_word_count_table(WordCountTable *table) {
    printf("Word Count Table:\n");
    printf("------------------\n");
    for (int i = 0; i < table->num_words; i++) {
        printf("%s: %d\n", table->words[i].word, table->words[i].count);
    }
}

void free_word_count_table(WordCountTable *table) {
    for (int i = 0; i < table->num_words; i++) {
        free(table->words[i].word);
    }
    free(table->words);
    table->num_words = 0;
}

int main() {
    FILE *file;
    char ch;
    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    int char_count = 0;
    int word_count = 0;
    int sentence_count = 0;
    int paragraph_count = 0;
    WordCountTable table;

    initialize_word_count_table(&table);

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            line_num++;
        }

        if (isalnum(ch)) {
            char_count++;
            word_count++;
        } else if (ch == '.'|| ch == '!'|| ch == '? ') {
            sentence_count++;
        } else if (ch == '\n' &&!isspace(fgetc(file))) {
            paragraph_count++;
        }

        if (strlen(line) >= MAX_LINE_LENGTH) {
            printf("Error: Line is too long.\n");
            exit(1);
        }

        strncat(line, &ch, 1);
    }

    fclose(file);

    add_word_to_table(&table, "Example");
    add_word_to_table(&table, "Text");

    print_word_count_table(&table);

    free_word_count_table(&table);

    printf("Characters: %d\n", char_count);
    printf("Words: %d\n", word_count);
    printf("Sentences: %d\n", sentence_count);
    printf("Paragraphs: %d\n", paragraph_count);

    return 0;
}