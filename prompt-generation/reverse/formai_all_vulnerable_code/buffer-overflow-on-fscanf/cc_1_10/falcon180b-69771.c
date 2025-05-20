//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element {
    char name[30];
    char symbol[3];
    int atomic_number;
    float atomic_weight;
};

struct element elements[118];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to load elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %f", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].atomic_weight) == 4) {
        count++;
    }

    fclose(file);
}

void print_elements() {
    printf("Element\tSymbol\tAtomic Number\tAtomic Weight\n");
    for (int i = 0; i < 118; i++) {
        printf("%s\t%s\t%d\t%.2f\n", elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].atomic_weight);
    }
}

int main() {
    srand(time(NULL));

    load_elements();

    int score = 0;
    char answer[3];

    while (score < 10) {
        int index = rand() % 118;
        printf("Question %d: What is the symbol for element %s?\n", score + 1, elements[index].name);

        scanf("%s", answer);

        if (strcmp(answer, elements[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
        }
    }

    printf("Congratulations! You scored %d out of 10.\n", score);

    return 0;
}