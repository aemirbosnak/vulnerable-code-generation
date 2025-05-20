//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element {
    char symbol[3];
    char name[30];
    int atomic_number;
    int group;
    int period;
    char category[30];
};

void load_elements(struct element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d %s\n", elements[count].symbol, elements[count].name, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category) == 6) {
        count++;
    }

    fclose(file);
}

void print_element(struct element element) {
    printf("%-3s %-20s %d %d %d %s\n", element.symbol, element.name, element.atomic_number, element.group, element.period, element.category);
}

void quiz(struct element elements[]) {
    int num_questions = 10;
    int correct_answers = 0;
    int user_answer;

    srand(time(NULL));
    for (int i = 0; i < num_questions; i++) {
        int index = rand() % 118; // there are 118 elements in the periodic table
        struct element question = elements[index];

        printf("Question %d:\n", i + 1);
        print_element(question);

        printf("What is the atomic number of %s? ", question.name);
        scanf("%d", &user_answer);

        if (user_answer == question.atomic_number) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", question.atomic_number);
        }
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);
}

int main() {
    struct element elements[118];
    load_elements(elements);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? (1-10) ");
    int num_questions;
    scanf("%d", &num_questions);

    quiz(elements);

    return 0;
}