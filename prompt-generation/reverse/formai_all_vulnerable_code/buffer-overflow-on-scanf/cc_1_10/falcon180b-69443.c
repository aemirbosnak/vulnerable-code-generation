//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
};

void read_elements(struct element *elements, int count) {
    FILE *file = fopen("elements.txt", "r");
    char line[100];
    int i = 0;

    while (fgets(line, 100, file)!= NULL && i < count) {
        char *token = strtok(line, ",");
        strcpy(elements[i].symbol, token);
        token = strtok(NULL, ",");
        strcpy(elements[i].name, token);
        token = strtok(NULL, ",");
        elements[i].atomic_number = atoi(token);
        token = strtok(NULL, ",");
        elements[i].atomic_weight = atof(token);
        i++;
    }

    fclose(file);
}

void print_element(struct element element) {
    printf("Symbol: %s\n", element.symbol);
    printf("Name: %s\n", element.name);
    printf("Atomic Number: %d\n", element.atomic_number);
    printf("Atomic Weight: %.2f\n\n", element.atomic_weight);
}

int main() {
    int count, choice;
    struct element elements[120];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many elements do you want to quiz on? (Max 120): ");
    scanf("%d", &count);

    read_elements(elements, count);

    int score = 0;
    while (score < count) {
        int index = rand() % count;
        printf("Element %d:\n", score + 1);
        print_element(elements[index]);
        printf("What is the atomic number of this element? ");
        scanf("%d", &choice);
        if (choice == elements[index].atomic_number) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("You got %d out of %d correct!\n", score, count);

    return 0;
}