//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ELEMENT_NAME_LENGTH 20
#define MAX_ELEMENT_SYMBOL_LENGTH 3

struct element {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[MAX_ELEMENT_SYMBOL_LENGTH];
    int atomic_number;
    float atomic_weight;
};

struct element elements[MAX_ELEMENTS];

int load_elements() {
    FILE *fp;
    char line[100];
    int count = 0;

    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open elements file.\n");
        return 1;
    }

    while (fgets(line, 100, fp)!= NULL) {
        if (count >= MAX_ELEMENTS) {
            printf("Error: Too many elements in file.\n");
            fclose(fp);
            return 1;
        }

        int i = 0;
        char *token = strtok(line, " \t");
        strcpy(elements[count].name, token);

        token = strtok(NULL, " \t");
        strcpy(elements[count].symbol, token);

        elements[count].atomic_number = atoi(token);
        elements[count].atomic_weight = atof(token);

        count++;
    }

    fclose(fp);
    return 0;
}

int main() {
    srand(time(NULL));

    if (load_elements()!= 0) {
        return 1;
    }

    int score = 0;

    while (score < 10) {
        int random_index = rand() % MAX_ELEMENTS;
        struct element *random_element = &elements[random_index];

        printf("What is the atomic symbol for element #%d?\n", random_index + 1);
        char guess[MAX_ELEMENT_SYMBOL_LENGTH];
        scanf("%s", guess);

        if (strcmp(guess, random_element->symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", random_element->symbol);
        }
    }

    printf("Congratulations! You scored %d out of 10.\n", score);

    return 0;
}