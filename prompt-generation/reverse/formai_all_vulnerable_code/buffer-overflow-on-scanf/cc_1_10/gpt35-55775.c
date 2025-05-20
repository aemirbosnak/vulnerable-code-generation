//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int size;
} WordList;

char *parse_word(char *str)
{
    static char buffer[MAX_WORD_LENGTH];
    int i = 0;

    while (isalpha(*str) && i < MAX_WORD_LENGTH - 1) {
        buffer[i++] = tolower(*str++);
    }
    buffer[i] = '\0';
    return buffer;
}

int index_of_word(WordList *list, char *word)
{
    int i;
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void add_word(WordList *list, char *word)
{
    int index = index_of_word(list, word);

    if (index == -1) {
        if (list->size == MAX_WORDS) {
            printf("Error: List is full\n");
            exit(1);
        }
        Word new_word;
        strcpy(new_word.word, word);
        new_word.count = 1;
        list->words[list->size++] = new_word;
    } else {
        list->words[index].count++;
    }
}

void print_word_list(WordList *list)
{
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].count);
    }
}

void sort_word_list(WordList *list)
{
    int i, j;
    Word temp_word;

    for (i = 0; i < list->size - 1; i++) {
        for (j = 0; j < list->size - i - 1; j++) {
            if (list->words[j].count < list->words[j+1].count) {
                temp_word = list->words[j];
                list->words[j] = list->words[j+1];
                list->words[j+1] = temp_word;
            }
        }
    }
}

int main()
{
    FILE *fp;
    char filename[50];
    char line[500];
    WordList list;
    list.size = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        char *word = parse_word(line);
        if (strlen(word) > 0) {
            add_word(&list, word);
        }
    }

    sort_word_list(&list);
    print_word_list(&list);

    fclose(fp);
    return 0;
}