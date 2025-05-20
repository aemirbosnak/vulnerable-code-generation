//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 35
#define MAX_SYMBOL_LEN 3
#define MAX_ATOMIC_NUMBER_LEN 5

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    int atomic_number;
} Element;

Element elements[MAX_ELEMENTS];

void read_elements_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number) == 3) {
        count++;
    }

    fclose(file);
}

void shuffle_elements(void) {
    srand(time(NULL));
    for (int i = 0; i < MAX_ELEMENTS - 1; i++) {
        int j = rand() % MAX_ELEMENTS;
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main(void) {
    read_elements_from_file("elements.txt");
    shuffle_elements();

    int num_questions = rand() % 10 + 1; // Ask between 1 and 10 questions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions do you want to answer? ");
    scanf("%d", &num_questions);

    int correct_answers = 0;
    for (int i = 0; i < num_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for element %s?\n", i+1, elements[index].name);
        char answer[MAX_SYMBOL_LEN];
        scanf("%s", answer);

        if (strcmp(answer, elements[index].symbol) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
        }
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}