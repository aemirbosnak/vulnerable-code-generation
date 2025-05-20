//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10
#define MIN_DIFFICULTY 1
#define MAX_DIFFICULTY 4

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    int group;
    int period;
    char category[10];
};

struct question {
    char text[100];
    int answer;
    int difficulty;
};

struct element elements[MAX_ELEMENTS];
struct question questions[MAX_QUESTIONS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    int count = 0;

    while (fscanf(file, "%s %c %d %d %d %s", elements[count].symbol, &elements[count].name, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category)!= EOF) {
        count++;
    }

    fclose(file);
}

void load_questions() {
    FILE *file = fopen("questions.txt", "r");
    int count = 0;

    while (fscanf(file, "%s %d %d", questions[count].text, &questions[count].answer, &questions[count].difficulty)!= EOF) {
        count++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    load_elements();
    load_questions();

    int num_questions = rand() % MAX_QUESTIONS + 1;
    int total_score = 0;

    for (int i = 0; i < num_questions; i++) {
        int question_index = rand() % MAX_QUESTIONS;
        printf("%s\n", questions[question_index].text);

        char answer[10];
        scanf("%s", answer);

        if (strcmp(answer, elements[questions[question_index].answer - 1].symbol) == 0) {
            total_score++;
        }
    }

    printf("Your final score is %d out of %d.\n", total_score, num_questions);

    return 0;
}