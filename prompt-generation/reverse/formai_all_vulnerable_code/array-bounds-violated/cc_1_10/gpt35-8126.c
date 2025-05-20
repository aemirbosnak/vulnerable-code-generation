//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORD_COUNT 10000

typedef struct
{
    char word[MAX_WORD_LEN];
    int count;
} Word;

int read_words(FILE *fp, char **word_list);
void count_words(char *word_list, Word *word_set, int n_words);
void sort_words(Word **word_set, int n_words);
void print_result(Word *word_set, int n_words);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *word_list = NULL;
    Word word_set[MAX_WORD_COUNT];

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Failed to open file %s\n", argv[1]);
        exit(2);
    }

    int n_words = read_words(fp, &word_list);
    fclose(fp);

    if (n_words > MAX_WORD_COUNT)
    {
        printf("Too many words in file\n");
        exit(3);
    }

    count_words(word_list, word_set, n_words);
    free(word_list);

    Word *sorted_word_set[n_words];
    int i;
    for (i = 0; i < n_words; i++)
    {
        sorted_word_set[i] = &word_set[i];
    }
    sort_words(sorted_word_set, n_words);

    print_result(*sorted_word_set, n_words);

    exit(0);
}

int read_words(FILE *fp, char **word_list)
{
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buf = (char *)malloc(fsize + 1);
    fread(buf, 1, fsize, fp);
    buf[fsize] = '\0';

    int i, n_words = 0, in_word = 0;
    for (i = 0; i < strlen(buf); i++)
    {
        if (!isspace(buf[i]))
        {
            if (in_word == 0)
            {
                word_list[n_words] = &buf[i];
                n_words++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
            buf[i] = '\0';
        }
    }

    return n_words;
}

void count_words(char *word_list, Word *word_set, int n_words)
{
    int i, j, found;
    for (i = 0; i < n_words; i++)
    {
        found = 0;
        for (j = 0; j < i; j++)
        {
            if (strcmp(word_list + i * MAX_WORD_LEN, word_list + j * MAX_WORD_LEN) == 0)
            {
                word_set[j].count++;
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            strncpy(word_set[i].word, word_list + i * MAX_WORD_LEN, MAX_WORD_LEN);
            word_set[i].count = 1;
        }
    }
}

void sort_words(Word **word_set, int n_words)
{
    int i, j;
    for (i = 1; i < n_words; i++)
    {
        Word *value = word_set[i];
        j = i - 1;
        while (j >= 0 && value->count > word_set[j]->count)
        {
            word_set[j + 1] = word_set[j];
            j--;
        }
        word_set[j + 1] = value;
    }
}

void print_result(Word *word_set, int n_words)
{
    int i;
    for (i = 0; i < n_words; i++)
    {
        if (word_set[i].count == 0)
            break;
        printf("%-20s %d\n", word_set[i].word, word_set[i].count);
    }
}