//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int check_input(char *input, char *word) {
    if (strcmp(input, word) == 0) {
        printf("Correct!\n");
        return 1;
    }
    else {
        printf("Incorrect. Expected: %s\n", word);
        return 0;
    }
}

void print_word(char *word) {
    printf("\n");
    for (int i = 0; i < strlen(word); ++i) {
        printf("%c ", word[i]);
    }
    printf("\n");
}

void display_results(int correct, int total_time) {
    int cpm = (correct / total_time) * 60;
    int wpm = cpm / 5;
    printf("Results:\n");
    printf("Correct: %d\n", correct);
    printf("Total time: %d seconds\n", total_time);
    printf("Typing speed: %d words per minute\n", wpm);
}

int main() {
    char *words[] = {"apple", "banana", "orange", "grape", "watermelon",
                     "pineapple", "coconut", "strawberry", "mango", "kiwi"};
    int num_words = 10;

    int correct = 0;
    time_t start, end;
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with 10 words.\n");
    printf("Type each word correctly to advance.\n");
    printf("Press any key to begin.\n");
    getchar();

    srand(time(NULL));
    for (int i = 0; i < num_words; ++i) {
        printf("\nWord #%d:\n", i + 1);
        int random_index = rand() % num_words;
        char *word = words[random_index];
        print_word(word);
        time(&start);

        char input[100];
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;

        int is_correct = check_input(input, word);
        if (is_correct) {
            ++correct;
        }

        time(&end);
        double time_taken = end - start;
        printf("Time taken: %.f seconds\n", time_taken);
    }

    display_results(correct, end - start);
    return 0;
}