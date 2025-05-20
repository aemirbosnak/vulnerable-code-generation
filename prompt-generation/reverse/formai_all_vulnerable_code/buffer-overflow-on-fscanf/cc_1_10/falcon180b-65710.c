//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118 // maximum number of elements in the periodic table
#define NUM_QUESTIONS 10 // number of questions to ask

typedef struct {
    char name[50];
    char symbol[3];
    int atomic_number;
    int group;
    int period;
    double atomic_weight;
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d %d %d %lf\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period, &elements[count].atomic_weight)!= EOF) {
        count++;
    }

    fclose(fp);
}

void shuffle_array(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    load_elements();
    shuffle_array(elements, MAX_ELEMENTS);

    int score = 0;
    char answer[50];

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for element %s?\n", i+1, elements[index].name);
        scanf("%s", answer);

        if (strcmp(answer, elements[index].symbol) == 0) {
            score++;
        }
    }

    printf("Your score is %d out of %d\n", score, NUM_QUESTIONS);

    return 0;
}