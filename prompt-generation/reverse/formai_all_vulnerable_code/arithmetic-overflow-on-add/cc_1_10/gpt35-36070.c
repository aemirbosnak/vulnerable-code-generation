//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20
#define MAX_TIME_LIMIT 60

int main() {
    srand(time(NULL)); // Initialize random seed
    
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"apple", "banana", "cherry", "dragonfruit", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pineapple", "quince", "raspberry", "strawberry", "tangerine", "ugli fruit", "watermelon", "xylocarp", "yellow watermelon", "zucchini", "apricot", "blueberry", "cantaloupe", "date", "eggplant", "fig", "grapefruit", "huckleberry", "italian plum", "jujube", "kiwifruit", "lychee", "mulberry", "nananavocado", "olive", "papaya", "quince", "rambutan", "strawberry guava", "tangelo", "ugli fruit", "vanilla bean",  "west indian cherry",  "xigua", "yellow passionfruit", "zinfandel grape"};
    printf("Welcome to Typing Speed Test!\n");
    printf("You will have 60 seconds to type as many words as you can. Ready? Go!\n");
    printf("Type the words exactly as shown including the casing. Press enter after each word.\n\n");

    int correct_words = 0;
    int incorrect_words = 0;
    time_t start_time = time(NULL);
    time_t end_time = start_time + MAX_TIME_LIMIT;

    while (difftime(end_time, time(NULL)) > 0) {
        int random_index = rand() % MAX_WORDS;
        char* target_word = words[random_index];
        int word_length = strlen(target_word);
        char word_input[MAX_WORD_LENGTH];

        printf("%s\n", target_word);
        fgets(word_input, MAX_WORD_LENGTH, stdin);
        word_input[strcspn(word_input, "\n")] = '\0';

        if (strcmp(word_input, target_word) == 0) {
            printf("Correct!\n\n");
            correct_words++;
        } else {
            printf("Incorrect.\n\n");
            incorrect_words++;
        }
    }

    printf("Times up! You typed %d correct words and %d incorrect words.\n", correct_words, incorrect_words);

    double accuracy = ((double)correct_words / (correct_words + incorrect_words)) * 100;
    printf("Your typing accuracy is %.2f%%.\n", accuracy);

    double typing_speed = (double)correct_words / MAX_TIME_LIMIT * 60;
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}