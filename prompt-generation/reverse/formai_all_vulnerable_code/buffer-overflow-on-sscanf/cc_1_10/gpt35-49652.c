//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[30];
    int atomic_number;
    float atomic_weight;
    char state[15];
    char category[30];
} Element;

Element elements[NUM_ELEMENTS];

void initialize_table();
void print_table();
void quiz();

int main() {
    initialize_table();
    print_table();
    quiz();
    return 0;
}

void initialize_table() {
    FILE *fp = fopen("periodic_table.txt", "r");

    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[100];

    for(int i=0; i<NUM_ELEMENTS; i++) {
        fgets(buffer, sizeof buffer, fp);
        sscanf(buffer, "%s %s %d %f %s %s", elements[i].symbol, elements[i].name, &elements[i].atomic_number,
            &elements[i].atomic_weight, elements[i].state, elements[i].category);
    }

    fclose(fp);
}

void print_table() {
    printf("---------- Periodic Table of Elements ----------\n");

    for(int i=0; i<NUM_ELEMENTS; i++) {
        printf("%s\t%s\t%d\t%.2f\t%s\t%s\n", elements[i].symbol, elements[i].name, elements[i].atomic_number,
            elements[i].atomic_weight, elements[i].state, elements[i].category);
    }
}

void quiz() {
    printf("\n\n---------- PERIODIC TABLE QUIZ ----------\n");
    printf("You will be given the symbol and you must enter the corresponding element name.\n\n");

    int score = 0;

    for(int i=0; i<NUM_ELEMENTS; i++) {
        printf("What is the element with the symbol %s?\n", elements[i].symbol);

        char answer[30];
        fgets(answer, sizeof answer, stdin);
        answer[strlen(answer)-1] = '\0'; // remove trailing newline

        if(strcmp(answer, elements[i].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The element with the symbol %s is %s.\n", elements[i].symbol, elements[i].name);
        }
    }

    printf("\nYou scored %d out of %d.\n", score, NUM_ELEMENTS);
}