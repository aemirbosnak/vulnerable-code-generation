//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

char words[MAX_WORDS][MAX_WORD_LEN];
int num_words = 0;

void load_words(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(words[num_words], line);
        num_words++;
    }

    fclose(fp);
}

void type_word(char* word, int index) {
    printf("Type '%s': ", word);
    char input[MAX_WORD_LEN];
    fgets(input, MAX_WORD_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, word) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct word is '%s'.\n", word);
    }
}

void test_typing(int start_index, int end_index) {
    srand(time(NULL));
    int rand_index = rand() % (end_index - start_index + 1) + start_index;

    type_word(words[rand_index], rand_index);

    if (end_index - start_index > 1) {
        test_typing(start_index, rand_index - 1);
        test_typing(rand_index + 1, end_index);
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    printf("Enter words file name: ");
    scanf("%s", filename);
    load_words(filename);

    printf("Enter number of words to type: ");
    scanf("%d", &num_words);

    test_typing(0, num_words - 1);

    return 0;
}