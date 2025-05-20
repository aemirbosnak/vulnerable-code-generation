//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char symbol[3];
    int atomic_number;
    char name[20];
    char group;
    int period;
} Element;

Element elements[118];

void load_elements() {
    FILE *fp;
    int i = 0;
    fp = fopen("elements.txt", "r");
    while (!feof(fp)) {
        fscanf(fp, "%s%d%s%s%d\n", elements[i].symbol, &elements[i].atomic_number, elements[i].name, &elements[i].group, &elements[i].period);
        i++;
    }
    fclose(fp);
}

void print_header() {
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-10s | %-20s | %-5s | %-5s | %-5s |\n", "No.", "Symbol", "Name", "Group", "Period", "Block");
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
}

void print_element(Element e) {
    printf("| %-2d | %-8s | %-20s | %-5s | %-5d | %-5s |\n", e.atomic_number, e.symbol, e.name, e.group, e.period, "Main");
}

void print_table(Element *elements, int length) {
    int i;
    print_header();
    for (i = 0; i < length; i++) {
        print_element(elements[i]);
    }
}

void play_quiz() {
    int score = 0;
    int i, j;
    Element question, answer;
    Element *shuffled_elements = malloc(sizeof(Element) * 10);

    load_elements();

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        j = rand() % 118;
        shuffled_elements[i] = elements[j];
    }

    for (i = 0; i < 10; i++) {
        question = shuffled_elements[i];
        answer = elements[question.atomic_number - 1];

        char user_answer[10];
        printf("Question %d: Which element has the symbol '%s' and is in group %c and period %d?\n", i + 1, question.symbol, question.group, question.period);
        scanf("%s", user_answer);
        user_answer[strlen(user_answer)] = '\0';

        if (strcasecmp(user_answer, answer.symbol) == 0) {
            score++;
            printf("Correct! Your current score is %d.\n", score);
        } else {
            printf("Sorry, the correct answer was %s. Your current score is %d.\n", answer.symbol, score);
        }
    }

    printf("Game over! Your final score is %d.\n", score);

    free(shuffled_elements);
}

int main() {
    play_quiz();
    return 0;
}