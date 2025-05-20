//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    float atomic_weight;
};

void print_element(struct element e) {
    printf("%-3s %-30s %d %.2f\n", e.symbol, e.name, e.atomic_number, e.atomic_weight);
}

int main() {
    srand(time(NULL));
    int num_elements = rand() % 118 + 1; // randomly select number of elements to quiz on
    struct element elements[num_elements];
    int correct_answers = 0;
    int total_questions = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many elements would you like to be quizzed on? ");
    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        elements[i].symbol[0] = 'A' + rand() % 26;
        elements[i].symbol[1] = 'A' + rand() % 26;
        elements[i].symbol[2] = '\0';
        elements[i].name = 'A' + rand() % 26;
        elements[i].atomic_number = rand() % 118 + 1;
        elements[i].atomic_weight = rand() % 1000 / 10.0;
    }

    for (int i = 0; i < num_elements; i++) {
        printf("Question %d:\n", i+1);
        print_element(elements[i]);
        char answer[4];
        scanf("%s", answer);

        if (strcmp(answer, elements[i].symbol) == 0) {
            correct_answers++;
        }
        total_questions++;
    }

    printf("\nYou got %d out of %d correct!\n", correct_answers, total_questions);

    return 0;
}