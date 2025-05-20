//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 10

struct Element {
    char symbol[3];
    char name;
    int atomic_number;
    int group;
    int period;
};

void shuffle(struct Element elements[]) {
    int i, j, temp;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        for (j = 0; j < 3; j++) {
            elements[i].symbol[j] = elements[i].symbol[j] + rand() % 26 - 13;
        }
    }
}

int compare(const void *a, const void *b) {
    struct Element *e1 = (struct Element *)a;
    struct Element *e2 = (struct Element *)b;
    return strcmp(e1->symbol, e2->symbol);
}

int main() {
    struct Element elements[MAX_ELEMENTS];
    int i, j, k, l, m, n, o, p, q, attempts, correct_attempts, score;
    char input[4];
    char *ptr;
    FILE *fp;
    time_t start_time, end_time;

    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_ELEMENTS; i++) {
        fscanf(fp, "%s %c %d %d %d", elements[i].symbol, &elements[i].name, &elements[i].atomic_number, &elements[i].group, &elements[i].period);
    }

    fclose(fp);

    shuffle(elements);

    srand(time(NULL));
    for (i = 0; i < MAX_ELEMENTS; i++) {
        elements[i].symbol[2] = '\0';
    }

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given %d attempts to guess the correct element.\n", MAX_ATTEMPTS);
    printf("Type your guess and press Enter.\n");

    for (attempts = 0, correct_attempts = 0, score = 0; attempts < MAX_ATTEMPTS && correct_attempts < MAX_ELEMENTS; attempts++) {
        printf("Attempt %d:\n", attempts + 1);
        scanf("%s", input);
        ptr = strchr(input, '\n');
        if (ptr!= NULL) {
            *ptr = '\0';
        }

        qsort(elements, MAX_ELEMENTS, sizeof(struct Element), compare);

        for (j = 0; j < MAX_ELEMENTS; j++) {
            if (strcmp(input, elements[j].symbol) == 0) {
                correct_attempts++;
                score += 10;
                printf("Correct!\n");
                break;
            }
        }

        if (j == MAX_ELEMENTS) {
            printf("Incorrect.\n");
        }
    }

    end_time = time(NULL);
    printf("\nGame over.\n");
    printf("Your final score is %d out of %d.\n", score, MAX_ELEMENTS);
    printf("Time taken: %ld seconds.\n", end_time - start_time);

    return 0;
}