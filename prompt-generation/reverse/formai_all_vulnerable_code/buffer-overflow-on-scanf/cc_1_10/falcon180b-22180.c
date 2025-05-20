//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char text[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word words[], int count) {
    for (int i = 0; i < count; i++) {
        int length = rand() % MAX_WORD_LENGTH + 1;
        words[i].length = length;
        for (int j = 0; j < length; j++) {
            words[i].text[j] = rand() % 26 + 'a';
        }
        words[i].text[length] = '\0';
    }
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    struct word words[MAX_WORDS];
    generate_words(words, num_words);

    int total_chars = 0;
    int correct_chars = 0;
    int incorrect_chars = 0;

    printf("Press enter to start the test\n");
    fflush(stdout);
    getchar();

    clock_t start = clock();
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].text);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        int len = strlen(input);
        total_chars += len;

        if (len == words[i].length && strcmp(input, words[i].text) == 0) {
            correct_chars += len;
        } else {
            incorrect_chars += len;
        }
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTest completed\n");
    printf("Total characters: %d\n", total_chars);
    printf("Correct characters: %d\n", correct_chars);
    printf("Incorrect characters: %d\n", incorrect_chars);
    printf("Time taken: %.2f seconds\n", time_taken);

    return 0;
}