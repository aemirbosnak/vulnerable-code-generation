//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

// Function to check if a word is correct
int is_correct(char* typed_word, char* correct_word) {
    int len = strlen(correct_word);
    int typed_len = strlen(typed_word);
    if (len!= typed_len) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (correct_word[i]!= typed_word[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LEN];
    char correct_words[MAX_WORDS][MAX_WORD_LEN];
    int num_words = 0;

    // Read words from file
    FILE* f = fopen("words.txt", "r");
    if (f == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }
    char word[MAX_WORD_LEN];
    while (fscanf(f, "%s", word)!= EOF) {
        strcpy(words[num_words], word);
        num_words++;
    }
    fclose(f);

    // Shuffle words
    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char temp[MAX_WORD_LEN];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }

    // Start typing test
    int score = 0;
    int time_left = 60;
    printf("Welcome to the Typing Speed Test!\n");
    printf("You have 60 seconds to type as many words as you can.\n");
    printf("Press enter to start:\n");
    getchar();
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
        fflush(stdout);
        char typed_word[MAX_WORD_LEN];
        scanf("%s", typed_word);
        if (is_correct(typed_word, words[i])) {
            score++;
        }
        time_left--;
        if (time_left == 0) {
            printf("\nTime's up! Your final score is %d.\n", score);
            break;
        }
    }

    return 0;
}