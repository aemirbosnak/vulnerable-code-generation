//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word* words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        int length = rand() % MAX_WORD_LENGTH + 1;
        words[i].length = length;
        int j;
        for (j = 0; j < length; j++) {
            char c = rand() % 26 + 'a';
            words[i].word[j] = c;
        }
        words[i].word[length] = '\0';
    }
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words: ");
    scanf("%d", &num_words);

    Word words[MAX_WORDS];
    generate_words(words, num_words);

    int num_correct = 0;
    int num_incorrect = 0;
    int total_time = 0;

    printf("Press enter to begin the test\n");
    getchar();

    clock_t start = clock();
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
        char input[MAX_WORD_LENGTH];
        int j;
        for (j = 0; j < words[i].length; j++) {
            char c = getchar();
            if (c == words[i].word[j]) {
                printf("%c", c);
            } else {
                printf("%c", '*');
                num_incorrect++;
            }
        }
        printf("\n");
        if (num_incorrect == 0) {
            num_correct++;
        }
        num_incorrect = 0;
    }

    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("You typed %d words correctly and %d words incorrectly\n", num_correct, num_incorrect);
    printf("Your typing speed is %.2f words per minute\n", (double)num_words / elapsed_time);

    return 0;
}