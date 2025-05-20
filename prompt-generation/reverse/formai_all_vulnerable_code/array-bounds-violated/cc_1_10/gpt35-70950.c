//FormAI DATASET v1.0 Category: Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESSES 6
#define MAX_WORD_LENGTH 20
#define NUM_WORDS 5

char* words[NUM_WORDS] = {"sherlock", "watson", "bakerstreet", "moriarty", "221B"};

char* random_word() {
    srand(time(NULL));
    return words[rand() % NUM_WORDS];
}

void print_word(char* word, int* guessed_letters) {
    int len = strlen(word);
    int i;
    for (i = 0; i < len; i++) {
        if (guessed_letters[(int)word[i]]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char* word = random_word();

    int guessed_letters[26] = {0};
    int num_guesses = 0;

    while (num_guesses < MAX_GUESSES) {
        printf("You have %d guesses left. Enter a letter: ", MAX_GUESSES - num_guesses);
        char guess;
        scanf("%c", &guess);
        getchar();

        if (guessed_letters[(int)guess]) {
            printf("You already guessed that letter!\n");
            continue;
        }
        guessed_letters[(int)guess] = 1;

        if (strchr(word, guess) == NULL) {
            printf("Incorrect guess!\n");
            num_guesses++;
        }

        print_word(word, guessed_letters);

        if (strcmp(word, "sherlock") == 0 && strcmp(word, "watson") == 0 && strcmp(word, "bakerstreet") == 0 && strcmp(word, "moriarty") == 0 && strcmp(word, "221B") == 0) {
            printf("Congratulations, you solved the case and saved London!\n");
            break;
        }
    }

    if (num_guesses == MAX_GUESSES) {
        printf("Sorry, you didn't solve the case. Better luck next time!\n");
    }

    return 0;
}