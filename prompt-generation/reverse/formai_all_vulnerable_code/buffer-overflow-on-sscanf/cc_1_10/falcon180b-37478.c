//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element {
    char name[50];
    char symbol[10];
    int atomic_number;
    float atomic_weight;
};

struct element elements[118];

void load_elements() {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("elements.txt", "r");

    if (fp == NULL) {
        printf("Error loading elements.\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        sscanf(line, "%s %s %d %f", elements[i].name, elements[i].symbol, &elements[i].atomic_number, &elements[i].atomic_weight);
        i++;
    }

    fclose(fp);
}

int main() {
    srand(time(0));
    load_elements();

    int user_score = 0;
    int total_questions = 10;

    for (int i = 0; i < total_questions; i++) {
        int random_index = rand() % 118;
        struct element random_element = elements[random_index];

        printf("Question %d:\n", i + 1);
        printf("What is the symbol for the element with the name %s?\n", random_element.name);

        char user_answer[10];
        scanf("%s", user_answer);

        if (strcmp(user_answer, random_element.symbol) == 0) {
            printf("Correct!\n");
            user_score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("You scored %d out of %d.\n", user_score, total_questions);

    return 0;
}