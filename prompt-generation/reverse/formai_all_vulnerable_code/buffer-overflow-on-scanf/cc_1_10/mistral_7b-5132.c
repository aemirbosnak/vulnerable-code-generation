//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct Element {
    char symbol[3];
    int atomic_number;
    char name[20];
    int group_number;
    int period;
} Element;

Element elements[118];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    int i = 0;

    if (file == NULL) {
        printf("Error: Unable to open elements file.\n");
        exit(1);
    }

    while (!feof(file)) {
        fscanf(file, "%s %d %s %d %d", elements[i].symbol, &elements[i].atomic_number, elements[i].name, &elements[i].group_number, &elements[i].period);
        i++;
    }

    fclose(file);
}

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    int score = 0;
    int questions_answered = 0;

    load_elements();

    printf("\n*********************************************************\n");
    printf("*                   PERIODIC TABLE QUIZ                   *\n");
    printf("*                                                       *\n");
    printf("*                                                       *\n");
    printf("*********************************************************\n\n");

    while (questions_answered < 10) {
        int random_element = random_number(0, 117);
        char question[50];
        sprintf(question, "What is the symbol for element %d (%s)?", elements[random_element].atomic_number, elements[random_element].name);

        printf("%s, ", question);
        char answer[3];
        scanf("%s", answer);

        if (strcmp(answer, elements[random_element].symbol) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[random_element].symbol);
        }

        questions_answered++;
    }

    printf("\nYour final score is %d out of 10.\n", score);

    return 0;
}