//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char symbol;
    char name[20];
    int atomic_number;
} Element;

Element elements[] = {
    {'H', "Hydrogen", 1},
    {'C', "Carbon", 6},
    {'O', "Oxygen", 8},
    {'N', "Nitrogen", 7},
    {'S', "Sulfur", 16},
    {'Cl', "Chlorine", 17},
    {'Na', "Sodium", 11},
    {'Mg', "Magnesium", 12},
    {'Al', "Aluminum", 13},
    {'Fe', "Iron", 26}
};

void display_table() {
    int i;
    printf("\n%-10s %-20s %-10d\n", "Symbol", "Name", "Atomic Number");
    for (i = 0; i < 10; i++) {
        printf("%-10c %-20s %-10d\n", elements[i].symbol, elements[i].name, elements[i].atomic_number);
    }
}

void quiz() {
    int i, j, k, selected[3];
    Element answer[3];
    int score = 0;

    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        do {
            j = rand() % 10;
        } while (selected[i] || elements[j].atomic_number == answer[i].atomic_number);

        selected[i] = 1;
        answer[i] = elements[j];
    }

    printf("\nQuiz:\n");
    for (i = 0; i < 3; i++) {
        printf("\nElement %d:\nAtomic Number: ", i + 1);
        scanf("%d", &k);

        if (k == answer[i].atomic_number) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s (%d).\n", elements[j].name, elements[j].atomic_number);
        }
    }

    printf("\nYour score is: %d\n", score);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Display Periodic Table\n2. Quiz\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_table();
                break;
            case 2:
                quiz();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}