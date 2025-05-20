//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define WPM_THRESHOLD 50
#define MIN_TIME 10

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word *words, int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    int count = 0;
    while (count < num_words && fscanf(file, "%s", words[count].word)!= EOF) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;

    generate_words(words, MAX_WORDS);
    num_words = MAX_WORDS;

    srand(time(NULL));
    int index = rand() % num_words;

    printf("Type the following words as quickly and accurately as possible:\n");
    for (int i = 0; i < num_words; i++) {
        if (i!= index) {
            printf("%s ", words[i].word);
        }
    }

    char input[MAX_WORD_LENGTH];
    int length = 0;

    clock_t start = clock();
    while (length < words[index].length) {
        char c = getchar();
        if (isalpha(c)) {
            input[length++] = tolower(c);
        } else if (c == '\b') {
            if (length > 0) {
                length--;
            }
        }
    }

    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    int wpm = (int)((words[index].length / elapsed) * 60);

    if (wpm >= WPM_THRESHOLD) {
        printf("Congratulations, you have reached the minimum typing speed of %d WPM!\n", WPM_THRESHOLD);
    } else {
        printf("Your typing speed is %d WPM.\n", wpm);
    }

    return 0;
}