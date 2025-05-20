//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[50];
    int atomic_number;
    int atomic_mass;
} element;

element periodic_table[ELEMENTS];

void load_periodic_table() {
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error loading periodic table\n");
        exit(1);
    }

    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%s %s %d %d", periodic_table[i].symbol, periodic_table[i].name, &periodic_table[i].atomic_number, &periodic_table[i].atomic_mass);
        i++;
    }

    fclose(file);
}

int main() {
    load_periodic_table();

    int score = 0;
    int num_questions = 10;
    char input[50];

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % ELEMENTS;
        printf("Question %d: What is the symbol for element %s?\n", i+1, periodic_table[index].name);
        scanf("%s", input);

        if (strcmp(input, periodic_table[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[index].symbol);
        }
    }

    printf("Your final score is %d out of %d.\n", score, num_questions);

    return 0;
}