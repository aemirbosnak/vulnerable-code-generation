//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 118

struct element {
    char name[20];
    char symbol[10];
    int atomic_number;
    int atomic_weight;
};

void read_elements(struct element *table) {
    FILE *fp;
    fp = fopen("elements.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %d %d", table[i].name, table[i].symbol, &table[i].atomic_number, &table[i].atomic_weight)!= EOF) {
        i++;
    }

    fclose(fp);
}

void print_table(struct element *table) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        printf("%-20s %-10s %d %d\n", table[i].name, table[i].symbol, table[i].atomic_number, table[i].atomic_weight);
    }
}

int main() {
    struct element table[SIZE];

    srand(time(NULL));
    int random_index;

    read_elements(table);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &random_index);

    int correct_answers = 0;

    for (int i = 0; i < random_index; i++) {
        int random_element = rand() % SIZE;

        printf("\nQuestion %d:\n", i + 1);
        printf("What is the symbol for element %s?\n", table[random_element].name);

        char answer[10];
        scanf("%s", answer);

        if (strcmp(answer, table[random_element].symbol) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", table[random_element].symbol);
        }
    }

    printf("\nYou got %d out of %d questions correct.\n", correct_answers, random_index);

    return 0;
}