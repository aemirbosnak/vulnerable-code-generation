//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 5
#define MAX_NAME_LENGTH 30
#define MAX_SYMBOL_LENGTH 3

struct Element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
    char category[MAX_NAME_LENGTH];
};

void load_elements(struct Element* elements) {
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d %s\n", &elements[count].name, &elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category) == 6) {
        count++;
    }

    fclose(file);
}

void shuffle_elements(struct Element* elements) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;
        struct Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    struct Element elements[MAX_ELEMENTS];
    load_elements(elements);
    shuffle_elements(elements);

    int score = 0;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter element name or symbol: ");
        char input[MAX_NAME_LENGTH];
        scanf("%s", input);

        int found = 0;
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            if (strcmp(elements[i].name, input) == 0 || strcmp(elements[i].symbol, input) == 0) {
                found = 1;
                printf("Element: %s\n", elements[i].name);
                printf("Symbol: %s\n", elements[i].symbol);
                printf("Atomic Number: %d\n", elements[i].atomic_number);
                printf("Group: %d\n", elements[i].group);
                printf("Period: %d\n", elements[i].period);
                printf("Category: %s\n", elements[i].category);

                if (strcmp(input, elements[i].name) == 0) {
                    score += 3;
                } else if (strcmp(input, elements[i].symbol) == 0) {
                    score += 2;
                } else {
                    score += 1;
                }

                break;
            }
        }

        if (!found) {
            printf("Element not found.\n");
            attempts++;
        }
    }

    printf("Final score: %d out of %d\n", score, MAX_ELEMENTS * 3);

    return 0;
}