//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10
#define WPM_DISPLAY_THRESHOLD 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;
int current_word;
int correct_words;
int incorrect_words;
int total_words;
int wpm;
int start_time;
int end_time;

void init() {
    srand(time(NULL));
    num_words = rand() % MAX_WORDS + 1;
    for (int i = 0; i < num_words; i++) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        char word[MAX_WORD_LENGTH];
        for (int j = 0; j < word_length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        strcpy(words[i], word);
    }
    current_word = 0;
    correct_words = 0;
    incorrect_words = 0;
    total_words = 0;
    wpm = 0;
    start_time = 0;
    end_time = 0;
}

void display_word() {
    printf("Type the following word: ");
    for (int i = 0; i < strlen(words[current_word]); i++) {
        printf("_");
    }
    printf("\n");
}

void check_word(char word[MAX_WORD_LENGTH]) {
    if (strcmp(word, words[current_word]) == 0) {
        correct_words++;
    } else {
        incorrect_words++;
    }
    total_words++;
}

void update_wpm() {
    if (total_words >= WPM_DISPLAY_THRESHOLD) {
        end_time = time(NULL);
        wpm = (total_words - incorrect_words) * 60 / (end_time - start_time);
        printf("Your current typing speed is %d WPM\n", wpm);
    }
}

int main() {
    init();
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing random words.\n");
    printf("Press enter to start the test.\n");
    getchar();
    start_time = time(NULL);
    while (current_word < num_words) {
        display_word();
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        check_word(input);
        current_word++;
    }
    end_time = time(NULL);
    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your final typing speed is %d WPM.\n", wpm);
    return 0;
}