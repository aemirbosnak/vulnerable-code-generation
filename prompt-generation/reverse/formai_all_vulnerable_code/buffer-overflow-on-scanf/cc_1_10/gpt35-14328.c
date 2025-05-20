//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 10
#define SECONDS 30

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"apple", "banana", "cherry", "date", "fig", "grape", "kiwi", "lemon", "orange", "pear",
                                               "pineapple", "plum", "raspberry", "strawberry", "watermelon", "peach", "apricot", "blackberry", 
                                               "blueberry", "boysenberry", "cantaloupe", "cranberry", "elderberry", "grapefruit", "honeydew", 
                                               "mandarin", "mango", "papaya", "persimmon", "pomegranate", "tangerine", "tomato", "avocado",
                                               "bell pepper", "broccoli", "cabbage", "carrot", "cauliflower", "celery", "corn", "cucumber",
                                               "eggplant", "garlic", "lettuce", "mushroom", "onion", "peas", "potato", "pumpkin", "spinach",
                                               "sweet potato", "zucchini"};

    int num_words = sizeof(words) / sizeof(words[0]);
    int correct_words = 0;
    int start_time = 0;
    int end_time = 0;
    int current_time = 0;
    int elapsed_time = 0;
    int word_index = 0;
    char input_word[MAX_WORD_LENGTH];

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Ken Thompson Typing Speed Test!\n\n");
    printf("You will have %d seconds to type as many words as possible.\n\n", SECONDS);
    printf("Press enter to begin...");
    getchar();

    start_time = time(NULL);

    while(elapsed_time < SECONDS) {
        word_index = rand() % num_words;
        printf("\nType the word '%s': ", words[word_index]);
        scanf("%s", input_word);

        if(strcmp(input_word, words[word_index]) == 0) { // Input matches word
            printf("Correct!");
            correct_words++;
        } else { // Input doesn't match word
            printf("Incorrect. The correct word was '%s'.", words[word_index]);
        }

        current_time = time(NULL);
        elapsed_time = current_time - start_time;
    }

    end_time = time(NULL);
    elapsed_time = end_time - start_time;

    printf("\n\nTime's up!\n\n");
    printf("You typed %d correct words in %d seconds.\n", correct_words, elapsed_time);
    printf("Your typing speed was %d words per minute.\n", (int)(60.0 * correct_words / elapsed_time));

    return 0;
}