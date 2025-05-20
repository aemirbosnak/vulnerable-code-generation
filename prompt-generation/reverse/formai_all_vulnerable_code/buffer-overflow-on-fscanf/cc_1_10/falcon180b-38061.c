//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
};

void read_elements(struct element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %f", elements[count].symbol, elements[count].name, &elements[count].atomic_number, &elements[count].atomic_weight) == 4) {
        count++;
    }

    fclose(file);
}

void shuffle_array(struct element *elements, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        struct element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    struct element elements[118];
    read_elements(elements);
    shuffle_array(elements, 118);

    int score = 0;
    int total_questions = 10;

    for (int i = 0; i < total_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("Symbol: %s\n", elements[i].symbol);
        printf("Name: %s\n", elements[i].name);
        printf("Atomic Number: ");
        int guess;
        scanf("%d", &guess);

        if (guess == elements[i].atomic_number) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", elements[i].atomic_number);
        }
    }

    printf("\nYour final score is %d out of %d.\n", score, total_questions);

    return 0;
}