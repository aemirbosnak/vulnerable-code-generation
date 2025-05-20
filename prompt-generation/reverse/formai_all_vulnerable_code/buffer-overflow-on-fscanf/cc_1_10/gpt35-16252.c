//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3

typedef struct Element {
    int atomic_number;
    char symbol[MAX_SYMBOL_LENGTH];
    char name[20];
    float atomic_mass;
} Element;

int main() {
    Element periodic_table[MAX_ELEMENTS];

    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%d %s %s %f", &periodic_table[i].atomic_number, periodic_table[i].symbol, periodic_table[i].name, &periodic_table[i].atomic_mass) != EOF) {
        i++;
    }

    fclose(file);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("There are %d elements in the periodic table. Let's see how many you can name!\n\n", i);

    int score = 0;
    char guess[MAX_SYMBOL_LENGTH];
    int guessed[MAX_ELEMENTS] = {0};

    while (score < i) {
        int random_index = rand() % i;

        if (guessed[random_index] == 0) {
            printf("What is the symbol for %s?\n", periodic_table[random_index].name);
            scanf("%s", guess);

            if (strcmp(guess, periodic_table[random_index].symbol) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The symbol for %s is %s.\n", periodic_table[random_index].name, periodic_table[random_index].symbol);
            }

            guessed[random_index] = 1;

            if (score == i) {
                printf("\nCongratulations, you named all the elements in the periodic table!\n");
            } else {
                float percentage = ((float)score / i) * 100;
                printf("Your score is %d out of %d (%.2f%%)\n\n", score, i, percentage);
            }
        }
    }

    return 0;
}