//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define MAX_ATTEMPTS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    char category[20];
};

void load_elements(struct element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %c %d %s", elements[count].symbol, &elements[count].name, &elements[count].atomic_number, elements[count].category) == 4) {
        count++;
    }

    fclose(file);
}

void shuffle_array(struct element arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        struct element temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    struct element elements[NUM_ELEMENTS];
    load_elements(elements);

    srand(time(NULL));
    shuffle_array(elements, NUM_ELEMENTS);

    int score = 0;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter element symbol: ");
        char input[4];
        scanf("%s", input);

        int correct_index = -1;
        for (int i = 0; i < NUM_ELEMENTS; i++) {
            if (strcmp(elements[i].symbol, input) == 0) {
                correct_index = i;
                break;
            }
        }

        if (correct_index!= -1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[correct_index].symbol);
        }

        attempts++;
    }

    printf("Your final score is %d out of %d.\n", score, NUM_ELEMENTS);

    return 0;
}