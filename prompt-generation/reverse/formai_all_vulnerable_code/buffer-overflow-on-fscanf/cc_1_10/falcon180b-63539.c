//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118 // maximum number of elements in the periodic table
#define MAX_ATTEMPTS 10 // maximum number of attempts per question

struct element {
    char name[50];
    char symbol[3];
    int atomic_number;
    int group;
    int period;
};

void shuffle_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    int num_elements = 0;
    FILE *fp = fopen("elements.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open elements.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %d %d %d", elements[num_elements].name, elements[num_elements].symbol, &elements[num_elements].atomic_number, &elements[num_elements].group, &elements[num_elements].period)!= EOF) {
        num_elements++;
    }

    fclose(fp);

    srand(time(NULL));
    shuffle_array(elements, num_elements);

    int score = 0;
    int attempts = 0;

    for (int i = 0; i < num_elements; i++) {
        printf("Question %d: What is the symbol for %s?\n", i+1, elements[i].name);
        char input[4];
        scanf("%s", input);

        if (strcmp(input, elements[i].symbol) == 0) {
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[i].symbol);
        }

        attempts++;

        if (attempts == MAX_ATTEMPTS) {
            break;
        }
    }

    printf("Your final score is %d out of %d.\n", score, num_elements);

    return 0;
}