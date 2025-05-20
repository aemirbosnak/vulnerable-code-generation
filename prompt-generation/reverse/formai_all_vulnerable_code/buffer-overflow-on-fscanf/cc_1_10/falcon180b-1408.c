//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 5
#define MAX_QUESTIONS 10
#define MAX_ANSWER_LENGTH 3

typedef struct {
    char symbol[MAX_ANSWER_LENGTH + 1];
    char name[MAX_ANSWER_LENGTH + 1];
} Element;

Element elements[MAX_ELEMENTS];
int num_elements;

void load_elements() {
    FILE *fp;
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    char line[MAX_ANSWER_LENGTH + 1];
    int i = 0;
    while (fscanf(fp, "%s %s", line, line) == 2) {
        strcpy(elements[i].symbol, line);
        strcpy(elements[i].name, line);
        i++;
    }
    num_elements = i;

    fclose(fp);
}

void shuffle_elements() {
    srand(time(NULL));
    for (int i = 0; i < num_elements; i++) {
        int j = rand() % num_elements;
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

void display_element(Element e) {
    printf("Symbol: %s\n", e.symbol);
    printf("Name: %s\n\n", e.name);
}

int main() {
    load_elements();
    shuffle_elements();

    int score = 0;
    int attempts = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int index = rand() % num_elements;
        Element e = elements[index];

        printf("Question %d:\n", i + 1);
        display_element(e);

        char answer[MAX_ANSWER_LENGTH + 1];
        int len = 0;
        while (len < MAX_ANSWER_LENGTH && (answer[len] = getchar())!= '\n') {
            len++;
        }
        answer[len] = '\0';

        if (strcmp(answer, e.symbol) == 0 || strcmp(answer, e.name) == 0) {
            score++;
        } else {
            printf("Incorrect answer. The correct answer is: %s\n", e.symbol);
        }

        attempts++;
        if (attempts >= MAX_ATTEMPTS) {
            printf("You have reached the maximum number of attempts.\n");
            break;
        }
    }

    printf("Your final score is: %d out of %d\n", score, MAX_QUESTIONS);

    return 0;
}