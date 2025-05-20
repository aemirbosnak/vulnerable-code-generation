//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 118

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    int group;
    int period;
    char state[10];
};

void shuffle(int *array, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void print_options(struct element elements[], int indices[], int size) {
    for (int i = 0; i < size; i++) {
        int index = indices[i];
        printf("%d. What is the symbol for %s?\n", i+1, elements[index].name);
    }
}

void take_quiz(struct element elements[], int indices[], int size) {
    int score = 0;
    print_options(elements, indices, size);

    for (int i = 0; i < size; i++) {
        int index = indices[i];
        char answer[3];
        printf("Answer for option %d: ", i+1);
        scanf("%s", answer);
        if (strcmp(answer, elements[index].symbol) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct symbol is %s\n", elements[index].symbol);
        }
    }

    printf("\nYou scored %d/%d\n", score, size);
}

void initialize_elements(struct element elements[]) {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("File does not exist!");
        exit(1);
    }

    int index = 0;
    char line[100];
    while (fgets(line, 100, fp)) {
        sscanf(line, "%[^,],%[^,],%d,%d,%d,%[^,\n]", elements[index].symbol, elements[index].name, &elements[index].atomic_number, &elements[index].group, &elements[index].period, elements[index].state);
        index++;
    }

    fclose(fp);
}

int main() {
    struct element elements[SIZE];
    initialize_elements(elements);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked to enter the symbol for a number of elements.\n");
    printf("At the end of the quiz, your score will be displayed.\n");

    int num_questions;
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);

    if (num_questions > SIZE || num_questions < 1) {
        printf("Invalid number of questions!\n");
        exit(1);
    }

    int indices[SIZE];
    for (int i = 0; i < SIZE; i++) {
        indices[i] = i;
    }

    shuffle(indices, SIZE);
    take_quiz(elements, indices, num_questions);

    return 0;
}