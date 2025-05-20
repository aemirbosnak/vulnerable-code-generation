//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 10
#define MAX_NAME_LENGTH 80
#define MAX_SYMBOL_LENGTH 3

struct Element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
};

void load_elements(struct Element *elements) {
    FILE *file;
    char line[MAX_NAME_LENGTH];
    int count = 0;

    file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements.\n");
        exit(1);
    }

    while (fgets(line, MAX_NAME_LENGTH, file)!= NULL) {
        sscanf(line, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number);
        count++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));
    struct Element elements[MAX_ELEMENTS];
    load_elements(elements);

    int num_questions = rand() % MAX_ELEMENTS + 1;
    int correct_answers = 0;
    int attempts_left = MAX_ATTEMPTS;

    while (attempts_left > 0) {
        int index = rand() % MAX_ELEMENTS;
        struct Element question = elements[index];
        int answer = rand() % 3;

        printf("Question %d/%d:\n", correct_answers + 1, num_questions);
        printf("Name: %s\n", question.name);
        printf("Symbol: %s\n", question.symbol);
        printf("Atomic Number: %d\n", question.atomic_number);

        char answer_str[MAX_NAME_LENGTH];
        switch (answer) {
            case 0:
                sprintf(answer_str, "Name");
                break;
            case 1:
                sprintf(answer_str, "Symbol");
                break;
            case 2:
                sprintf(answer_str, "Atomic Number");
                break;
        }

        char input[MAX_NAME_LENGTH];
        printf("Enter your answer: ");
        scanf("%s", input);

        if (strcmp(input, answer_str) == 0) {
            correct_answers++;
        } else {
            printf("Incorrect answer.\n");
        }

        attempts_left--;
    }

    printf("You got %d out of %d correct.\n", correct_answers, num_questions);

    return 0;
}