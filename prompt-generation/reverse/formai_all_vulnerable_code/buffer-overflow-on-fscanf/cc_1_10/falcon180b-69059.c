//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ELEMENT_NAME_LENGTH 20
#define MAX_ELEMENT_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[MAX_ELEMENT_SYMBOL_LENGTH];
    int atomic_number;
} Element;

Element elements[MAX_ELEMENTS];

void initialize_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: could not open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_ELEMENTS && fscanf(file, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number) == 3) {
        count++;
    }

    fclose(file);
}

void shuffle_elements() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

void print_element(Element element) {
    printf("Name: %s\nSymbol: %s\nAtomic Number: %d\n", element.name, element.symbol, element.atomic_number);
}

int main() {
    initialize_elements();
    shuffle_elements();

    int num_questions = 10;
    int correct_answers = 0;

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        Element element = elements[index];

        printf("Question %d:\n", i+1);
        print_element(element);

        char answer[MAX_ELEMENT_NAME_LENGTH];
        printf("Enter the name of the element: ");
        scanf("%s", answer);

        if (strcmp(answer, element.name) == 0) {
            correct_answers++;
        }
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}