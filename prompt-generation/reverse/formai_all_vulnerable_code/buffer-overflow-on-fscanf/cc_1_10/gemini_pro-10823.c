//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    int atomic_number;
    char name[MAX_NAME_LENGTH + 1];
    char symbol[3];
    double atomic_mass;
    int group;
    int period;
} element;

element periodic_table[NUM_ELEMENTS];

void load_periodic_table() {
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        perror("Error opening periodic table file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        fscanf(file, "%d %s %s %lf %d %d", &periodic_table[i].atomic_number, periodic_table[i].name, periodic_table[i].symbol, &periodic_table[i].atomic_mass, &periodic_table[i].group, &periodic_table[i].period);
    }

    fclose(file);
}

void print_periodic_table() {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%d %s %s %lf %d %d\n", periodic_table[i].atomic_number, periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_mass, periodic_table[i].group, periodic_table[i].period);
    }
}

void quiz_periodic_table() {
    int score = 0;

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        char answer[MAX_NAME_LENGTH + 1];

        printf("What is the name of element %d (%s)? ", periodic_table[i].atomic_number, periodic_table[i].symbol);
        scanf("%s", answer);

        if (strcmp(answer, periodic_table[i].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[i].name);
        }
    }

    printf("Your score is %d out of %d.\n", score, NUM_ELEMENTS);
}

int main() {
    load_periodic_table();
    print_periodic_table();
    quiz_periodic_table();

    return 0;
}