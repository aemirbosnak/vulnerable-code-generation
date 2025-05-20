//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 20
#define MAX_TESTS 5
#define MAX_TEST_LENGTH 60

char words[MAX_WORDS][MAX_WORD_LENGTH];
int word_lengths[MAX_WORDS];
int num_words;

void load_words(void) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        word_lengths[i] = strlen(word);
        i++;
    }

    num_words = i;

    fclose(file);
}

void generate_test(void) {
    int test_length;
    int i;

    srand(time(NULL));
    test_length = rand() % MAX_TEST_LENGTH + 1;

    printf("Test length: %d words\n", test_length);

    for (i = 0; i < test_length; i++) {
        int word_index = rand() % num_words;
        printf("%s ", words[word_index]);
    }

    printf("\n");
}

int main(void) {
    int num_tests;
    int i;

    load_words();

    printf("Enter number of tests: ");
    scanf("%d", &num_tests);

    if (num_tests < 1 || num_tests > MAX_TESTS) {
        printf("Invalid number of tests\n");
        exit(1);
    }

    for (i = 0; i < num_tests; i++) {
        generate_test();
    }

    return 0;
}