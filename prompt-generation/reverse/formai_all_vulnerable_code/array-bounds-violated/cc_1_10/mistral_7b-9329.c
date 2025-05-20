//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100
#define WORDS_COUNT 5
#define LENGTH_MIN 5
#define LENGTH_MAX 20

char *words[WORDS_COUNT];

void init_words() {
    int i;
    char str[SIZE];
    FILE *fp;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open words file.\n");
        exit(1);
    }

    for (i = 0; i < WORDS_COUNT; i++) {
        fgets(str, SIZE, fp);
        str[strlen(str) - 1] = '\0';
        words[i] = malloc(strlen(str) + 1);
        strcpy(words[i], str);
    }

    fclose(fp);
}

void print_word(char *word) {
    int i;

    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z')
            putchar(word[i] + 32);
        else
            putchar(word[i]);
        if (i % 3 == 2 && i < strlen(word) - 1)
            putchar(' ');
    }
    putchar('\n');
}

void test(char *word) {
    int i, j, len;
    char input[strlen(word) + 1];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < strlen(word); j++) {
            scanf("%c", &input[j]);
            if (input[j] != word[j]) {
                printf("Error: Incorrect character at position %d. Try again.\n", j + 1);
                i--;
                break;
            }
        }
        len = strlen(word);
        if (strlen(input) != len) {
            printf("Error: Incorrect length. Try again.\n");
            i--;
            break;
        }
        if (strcmp(input, word) != 0) {
            printf("Error: Incorrect word. Try again.\n");
            i--;
            break;
        }
        printf("Correct! Next word.\n");
        memset(input, 0, strlen(input) + 1);
    }

    printf("Congratulations! You have passed the test.\n");
}

int main() {
    int i;
    clock_t start, end;
    double time_spent;

    init_words();

    start = clock();

    for (i = 0; i < WORDS_COUNT; i++) {
        print_word(words[i]);
        test(words[i]);
    }

    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Test completed in %.2f seconds.\n", time_spent);

    for (i = 0; i < WORDS_COUNT; i++)
        free(words[i]);

    return 0;
}