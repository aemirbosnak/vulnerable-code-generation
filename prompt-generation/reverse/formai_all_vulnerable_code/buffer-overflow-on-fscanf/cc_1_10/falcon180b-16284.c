//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 80
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 4
#define MAX_ATOMIC_WEIGHT_LENGTH 6
#define MAX_ELEMENT_NAME_LENGTH 80

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    double atomic_weight;
} Element;

void read_elements(Element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %lf", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].atomic_weight) == 4) {
        count++;
    }
    fclose(file);
}

void shuffle_array(Element elements[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    Element elements[NUM_ELEMENTS];
    read_elements(elements);
    shuffle_array(elements, NUM_ELEMENTS);

    int score = 0;
    int num_questions = 10;
    char input_buffer[MAX_NAME_LENGTH];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", num_questions);

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % NUM_ELEMENTS;
        printf("Question %d:\n", i+1);
        printf("Name: ");
        scanf("%s", input_buffer);
        if (strcmp(elements[index].name, input_buffer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].name);
        }
    }

    printf("Your final score is %d out of %d.\n", score, num_questions);

    return 0;
}