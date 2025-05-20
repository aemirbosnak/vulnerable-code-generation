//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define QUESTIONS 10
#define MIN_ATOMIC_NUMBER 1
#define MAX_ATOMIC_NUMBER 118
#define MIN_GUESS 1
#define MAX_GUESS 118

typedef struct {
    int atomic_number;
    char symbol[3];
    char name[50];
    int group;
    int period;
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("periodic_table.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open periodic_table.txt\n");
        exit(1);
    }

    int i = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %2s %s %d %d", &elements[i].atomic_number, elements[i].symbol, elements[i].name, &elements[i].group, &elements[i].period);
        i++;
    }

    fclose(file);
}

void print_element(Element e) {
    printf("\n%s (%d) %s - Group %d, Period %d", e.symbol, e.atomic_number, e.name, e.group, e.period);
}

int check_guess(int guess) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].atomic_number == guess) {
            return 1;
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));

    load_elements();

    int questions_answered = 0;
    int score = 0;

    while (questions_answered < QUESTIONS) {
        int random_element = rand() % (MAX_ATOMIC_NUMBER - MIN_ATOMIC_NUMBER + 1) + MIN_ATOMIC_NUMBER;
        Element target_element;

        for (int i = 0; i < MAX_ELEMENTS; i++) {
            if (elements[i].atomic_number == random_element) {
                target_element = elements[i];
                break;
            }
        }

        int guess;
        int is_correct = 0;

        printf("\n%s, I love you with all my %s-%s heart! Guess which element I'm thinking of?\n", target_element.symbol, target_element.period > 1 ? "Period" : "Period and Group", target_element.group > 1 ? target_element.group == 18 ? "Noble" : "Group" : "");
        scanf("%d", &guess);

        if (check_guess(guess)) {
            print_element(target_element);
            printf(" Correct answer! I'm so proud of you!\n");
            score++;
            is_correct = 1;
        } else {
            printf(" Wrong answer, try again! I believe in you!\n");
        }

        questions_answered++;

        if (is_correct) {
            printf("\nI love the way you think! Let's continue our quiz...\n");
        } else {
            printf("\nI still believe in you! Let's try another question...\n");
        }
    }

    printf("\nOur quiz is over! You answered %d out of %d questions correctly. I'm so proud of you!", score, QUESTIONS);

    return 0;
}