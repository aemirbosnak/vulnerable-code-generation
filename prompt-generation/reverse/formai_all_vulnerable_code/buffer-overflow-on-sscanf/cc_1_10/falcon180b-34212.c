//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118 // maximum number of elements in the periodic table

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    int group;
    int period;
};

void load_elements(struct element elements[]) {
    FILE *file;
    char line[100];
    int count = 0;

    file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error opening elements file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        sscanf(line, "%s %s %d %d %d", elements[count].symbol, elements[count].name, &elements[count].atomic_number, &elements[count].group, &elements[count].period);
        count++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    struct element elements[MAX_ELEMENTS];
    load_elements(elements);

    int num_questions = rand() % 10 + 5; // generate a random number of questions between 5 and 14
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % MAX_ELEMENTS; // select a random element from the periodic table
        struct element question = elements[index];

        printf("Question %d: What is the symbol for the element with atomic number %d?\n", i+1, question.atomic_number);

        char answer[4];
        scanf("%s", answer);

        if (strcmp(answer, question.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", question.symbol);
        }
    }

    printf("Your final score is %d out of %d.\n", score, num_questions);

    return 0;
}