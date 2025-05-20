//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 10
#define MAX_QUESTIONS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    int group;
    int period;
};

void shuffle(struct element arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        int j = rand() % n;
        struct element temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    struct element elements[MAX_ELEMENTS];
    int num_elements = 0;
    FILE *fp;
    char line[100];

    // Read elements from file
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %c %d %d %d", elements[num_elements].symbol, &elements[num_elements].name, &elements[num_elements].atomic_number, &elements[num_elements].group, &elements[num_elements].period);
        num_elements++;
    }
    fclose(fp);

    // Shuffle elements
    shuffle(elements, num_elements);

    // Start quiz
    int score = 0;
    int attempts = 0;
    int i;
    for (i = 0; i < MAX_QUESTIONS && attempts < MAX_ATTEMPTS; i++) {
        int index = rand() % num_elements;
        struct element element = elements[index];
        printf("Question %d: What is the symbol for element %d?\n", i + 1, element.atomic_number);
        char input[4];
        scanf("%s", input);
        if (strcmp(input, element.symbol) == 0) {
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", element.symbol);
        }
        attempts++;
    }

    // Print score and exit
    printf("You scored %d out of %d.\n", score, MAX_QUESTIONS);
    return 0;
}