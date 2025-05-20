//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define MAX_ATTEMPTS 3
#define MAX_SCORE 118

typedef struct {
    char name[3];
    char symbol[3];
    int atomic_number;
    int group;
    int period;
} element_t;

element_t elements[NUM_ELEMENTS];

void initialize_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open elements file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s %d %d %d\n", elements[i].name, elements[i].symbol, &elements[i].atomic_number, &elements[i].group, &elements[i].period)!= EOF) {
        i++;
    }

    fclose(file);
}

void shuffle_elements() {
    srand(time(NULL));
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int j = rand() % NUM_ELEMENTS;
        element_t temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

void print_element(element_t element) {
    printf("%-10s %-5s %d\n", element.name, element.symbol, element.atomic_number);
}

int main() {
    initialize_elements();
    shuffle_elements();

    int score = 0;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS && score < MAX_SCORE) {
        printf("Round %d:\n", attempts + 1);
        for (int i = 0; i < NUM_ELEMENTS; i++) {
            print_element(elements[i]);
        }

        int choice;
        printf("\nEnter the number of the element: ");
        scanf("%d", &choice);

        if (choice >= 0 && choice < NUM_ELEMENTS) {
            element_t correct_element = elements[choice];
            printf("\nYou chose %s (%s) with atomic number %d.\n", correct_element.name, correct_element.symbol, correct_element.atomic_number);
            score++;
        } else {
            printf("\nInvalid choice.\n");
        }

        attempts++;
    }

    printf("\nFinal score: %d/%d\n", score, MAX_SCORE);

    return 0;
}