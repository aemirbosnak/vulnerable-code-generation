//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ELEMENTS 118

typedef struct {
    char name[2]; // 2-letter symbol
    char full_name[50]; // full name
    int atomic_number; // atomic number
    int atomic_mass; // atomic mass
    char category[20]; // element category (e.g. metal, nonmetal, metalloid)
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *fp = fopen("elements.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d %d %s\n", &elements[count].name, elements[count].full_name, &elements[count].atomic_number, &elements[count].atomic_mass, elements[count].category)!= EOF) {
        count++;
    }

    fclose(fp);
}

void shuffle_elements() {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    load_elements();
    shuffle_elements();

    int score = 0;
    int num_questions = 10; // number of questions to ask

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for element %s?\n", i+1, elements[index].full_name);

        char input[3];
        scanf("%s", input);

        if (strcmp(input, elements[index].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].name);
        }
    }

    printf("You got %d out of %d questions correct.\n", score, num_questions);

    return 0;
}