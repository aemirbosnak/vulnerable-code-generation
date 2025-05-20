//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118 // maximum number of elements in the periodic table
#define MAX_NAME_LENGTH 100 // maximum length of element name
#define MAX_SYMBOL_LENGTH 3 // maximum length of element symbol

typedef struct {
    char name[MAX_NAME_LENGTH]; // name of the element
    char symbol[MAX_SYMBOL_LENGTH]; // symbol of the element
    int atomic_number; // atomic number of the element
} element;

void read_elements(element* elements) {
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: could not open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_ELEMENTS && fscanf(file, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number)!= EOF) {
        count++;
    }

    fclose(file);
}

void shuffle_elements(element* elements) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;
        element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    element elements[MAX_ELEMENTS];
    read_elements(elements);
    shuffle_elements(elements);

    int score = 0;
    int total_questions = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions do you want to answer? (1-10): ");
    scanf("%d", &total_questions);

    for (int i = 0; i < total_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for %s?\n", i+1, elements[index].name);
        char answer[MAX_SYMBOL_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, elements[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
        }
    }

    printf("You got %d out of %d questions correct.\n", score, total_questions);

    return 0;
}