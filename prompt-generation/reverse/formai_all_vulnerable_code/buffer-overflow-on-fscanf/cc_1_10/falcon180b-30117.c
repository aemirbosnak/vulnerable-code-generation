//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 5

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    int atomic_weight;
    char category[10];
};

void generate_table() {
    FILE *fp;
    struct element elements[MAX_ELEMENTS];

    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %c %d %d %s", elements[count].symbol, &elements[count].name, &elements[count].atomic_number, &elements[count].atomic_weight, elements[count].category)!= EOF) {
        count++;
    }

    fclose(fp);

    srand(time(NULL));
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        int index = rand() % count;
        printf("What is the symbol for %s? ", elements[index].name);
        char guess[3];
        scanf("%s", guess);

        if (strcmp(guess, elements[index].symbol) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. Try again.\n");
        }

        attempts++;
    }
}

int main() {
    generate_table();
    return 0;
}