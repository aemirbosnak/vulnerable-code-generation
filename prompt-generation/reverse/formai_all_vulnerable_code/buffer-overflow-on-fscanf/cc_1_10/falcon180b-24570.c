//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void load_words() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: unable to open words.txt\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    num_words = i;
    fclose(file);
}

void generate_random_word() {
    int index = rand() % num_words;
    printf("%s", words[index]);
}

int main() {
    srand(time(NULL));
    load_words();

    int correct_answers = 0;
    int total_answers = 0;
    int max_speed = 0;
    char user_answer[MAX_WORD_LENGTH];

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Press ENTER to begin...\n");
    getchar();

    while (1) {
        generate_random_word();
        printf("\nType the word above: ");
        fgets(user_answer, MAX_WORD_LENGTH, stdin);
        user_answer[strcspn(user_answer, "\n")] = '\0';

        if (strcmp(user_answer, words[0]) == 0) {
            correct_answers++;
        }

        total_answers++;

        if (total_answers % 10 == 0) {
            int speed = (int) (total_answers / ((double) total_answers / 10));
            if (speed > max_speed) {
                max_speed = speed;
            }
        }
    }

    printf("\nTest complete!\n");
    printf("You answered %d out of %d questions correctly.\n", correct_answers, num_words);
    printf("Your maximum typing speed was %d words per minute.\n", max_speed);

    return 0;
}