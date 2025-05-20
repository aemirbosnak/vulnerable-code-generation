//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 1000
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

bool is_word_char(char c) {
    return isalpha(c);
}

bool is_space_char(char c) {
    return isspace(c);
}

bool is_delimiter_char(char c) {
    return is_space_char(c) || is_word_char(c);
}

int count_words(char* line, int line_len) {
    int word_count = 0;
    char* word_start = line;
    char* word_end = line;
    while (word_end < line + line_len) {
        if (is_delimiter_char(*word_end)) {
            *word_end = '\0';
            word_count++;
            word_start = word_end + 1;
        }
        word_end++;
    }
    return word_count;
}

void print_word_counts(WordCount* word_counts, int num_words) {
    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[MAX_FILE_NAME_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    WordCount word_counts[MAX_WORD_LEN];
    int num_words = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        int line_len = strlen(line);
        int word_count = count_words(line, line_len);
        for (int i = 0; i < word_count; i++) {
            char* word_start = line + (i * MAX_WORD_LEN);
            char* word_end = word_start;
            while (is_word_char(*word_end)) {
                word_end++;
            }
            *word_end = '\0';
            strcpy(word_counts[num_words].word, word_start);
            word_counts[num_words].count = 1;
            num_words++;
        }
    }

    fclose(file);

    int total_words = 0;
    for (int i = 0; i < num_words; i++) {
        total_words += word_counts[i].count;
    }

    printf("Total words: %d\n", total_words);
    print_word_counts(word_counts, num_words);

    return 0;
}