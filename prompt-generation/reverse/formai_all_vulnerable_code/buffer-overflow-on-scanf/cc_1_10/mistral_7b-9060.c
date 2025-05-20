//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118 // Max number of elements in the periodic table
#define QUESTIONS 10 // Number of questions to ask

typedef struct {
    char name[30];
    int atomic_number;
    int group;
    int period;
} Element;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", 1, 1, 1},
    {"Helium", 2, 1, 1},
    // Add the remaining elements here...
};

void print_table() {
    printf("\n%-10s %-15s %-10s %-10s", "Element", "Group", "Period", "Atomic Number");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("\n%-10s %-15s %-10d %-10d", elements[i].name, "Group " + elements[i].group, elements[i].period, elements[i].atomic_number);
    }
}

void ask_questions() {
    int score = 0;

    for (int i = 0; i < QUESTIONS; i++) {
        int index;
        int answer;

        do {
            index = rand() % MAX_ELEMENTS;
            printf("\nWhich element is in group %d and period %d? ", elements[index].group, elements[index].period);
            scanf("%d", &answer);
        } while (answer != elements[index].atomic_number);

        score++;
    }

    printf("\nCongratulations! You scored %d out of %d.", score, QUESTIONS);
}

int main() {
    int config_group, config_period;

    printf("Enter the group number to display elements from that group: ");
    scanf("%d", &config_group);

    printf("Enter the period number to display elements from that period: ");
    scanf("%d", &config_period);

    print_table();

    printf("\nNow let's test your knowledge with some questions.\n");
    ask_questions();

    return 0;
}