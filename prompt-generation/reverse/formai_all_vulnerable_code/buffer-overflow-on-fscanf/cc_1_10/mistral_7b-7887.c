//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118

typedef struct {
    char name[50];
    char symbol[10];
    int atomic_number;
} Element;

Element elements[NUM_ELEMENTS];

void load_elements() {
    FILE *file;
    int i;

    file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements file.\n");
        exit(1);
    }

    for (i = 0; i < NUM_ELEMENTS; i++) {
        fscanf(file, "%[^,],%s,%d\n", elements[i].name, elements[i].symbol, &elements[i].atomic_number);
    }

    fclose(file);
}

void display_element(Element e) {
    printf("Name: %s\n", e.name);
    printf("Symbol: %s\n", e.symbol);
    printf("Atomic Number: %d\n", e.atomic_number);
}

int main() {
    int score = 0;
    int i, random_index;
    Element chosen_element;
    char user_answer[10];

    srand(time(NULL));

    load_elements();

    for (i = 0; i < 10; i++) {
        random_index = rand() % NUM_ELEMENTS;
        chosen_element = elements[random_index];

        printf("Question %d:\n", i + 1);
        display_element(chosen_element);
        printf("Enter the symbol of the element: ");
        scanf("%s", user_answer);

        if (strcmp(user_answer, chosen_element.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", chosen_element.symbol);
        }

        printf("\n");
    }

    printf("Your final score is: %d\n", score);

    return 0;
}