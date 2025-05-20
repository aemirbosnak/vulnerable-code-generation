//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

// Function to generate a random conspiracy theory
void generate_conspiracy_theory(char* theory) {
    srand(time(NULL));

    // Fill the theory with random words
    for (int i = 0; i < MAX_WORDS; i++) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        char word[MAX_WORD_LENGTH];
        for (int j = 0; j < word_length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[word_length] = '\0';
        strcat(theory, word);
        strcat(theory, " ");
    }

    // Add a random accusation
    char accusation[MAX_WORD_LENGTH];
    for (int i = 0; i < rand() % MAX_WORD_LENGTH + 1; i++) {
        accusation[i] = rand() % 26 + 'a';
    }
    accusation[rand() % MAX_WORD_LENGTH + 1] = '\0';
    strcat(theory, " is behind the ");
    strcat(theory, accusation);
    strcat(theory, " conspiracy!");

    // Print the generated theory
    printf("%s\n", theory);
}

int main() {
    int num_theories;
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &num_theories);

    for (int i = 0; i < num_theories; i++) {
        char theory[MAX_CONSPIRACIES];
        generate_conspiracy_theory(theory);
    }

    return 0;
}