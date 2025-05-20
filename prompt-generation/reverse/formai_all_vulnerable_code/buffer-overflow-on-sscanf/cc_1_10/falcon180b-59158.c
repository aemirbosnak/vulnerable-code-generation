//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 10

typedef struct {
    char name[50];
    char symbol[3];
    int atomic_number;
    int atomic_mass;
    char category[20];
} Element;

Element periodic_table[MAX_ELEMENTS];
int num_elements;

void load_periodic_table() {
    FILE *file;
    char line[100];
    int i = 0;

    file = fopen("periodic_table.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open periodic_table.txt\n");
        exit(1);
    }

    while (fgets(line, 100, file)!= NULL) {
        sscanf(line, "%s %s %d %d %s", periodic_table[i].name, periodic_table[i].symbol, &periodic_table[i].atomic_number, &periodic_table[i].atomic_mass, periodic_table[i].category);
        i++;
    }

    num_elements = i;

    fclose(file);
}

void shuffle_periodic_table() {
    int i, j, temp;

    for (i = 0; i < num_elements - 1; i++) {
        for (j = i + 1; j < num_elements; j++) {
            srand(time(NULL));
            temp = rand() % num_elements;

            Element temp_element = periodic_table[i];
            periodic_table[i] = periodic_table[temp];
            periodic_table[temp] = temp_element;
        }
    }
}

int main() {
    load_periodic_table();
    shuffle_periodic_table();

    int score = 0;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        int correct_answers = 0;
        int element_index;

        srand(time(NULL));
        element_index = rand() % num_elements;

        printf("Question %d:\n", ++attempts);
        printf("What is the name of element %s?\n", periodic_table[element_index].symbol);
        scanf("%s", periodic_table[element_index].name);

        if (strcmp(periodic_table[element_index].name, periodic_table[element_index].name) == 0) {
            correct_answers++;
        }

        if (correct_answers == 1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[element_index].name);
        }
    }

    printf("\nYour final score is %d out of %d.\n", score, MAX_ATTEMPTS);

    return 0;
}