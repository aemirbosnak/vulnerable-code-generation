//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_ELEMENT_NAME_LENGTH 20
#define MAX_ELEMENT_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[MAX_ELEMENT_SYMBOL_LENGTH];
    int atomicNumber;
    int group;
    int period;
} Element;

Element elements[MAX_ELEMENTS];

void readElements() {
    FILE *file = fopen("elements.txt", "r");
    if (!file) {
        printf("Error: could not open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d", elements[count].name, elements[count].symbol, &elements[count].atomicNumber, &elements[count].group, &elements[count].period) == 5 && count < MAX_ELEMENTS) {
        count++;
    }

    fclose(file);
}

void printElement(int index) {
    printf("Name: %s\n", elements[index].name);
    printf("Symbol: %s\n", elements[index].symbol);
    printf("Atomic Number: %d\n", elements[index].atomicNumber);
    printf("Group: %d\n", elements[index].group);
    printf("Period: %d\n\n", elements[index].period);
}

void main() {
    readElements();

    int score = 0;
    int choice;
    char input[MAX_ELEMENT_NAME_LENGTH];

    do {
        printf("Periodic Table Quiz\n\n");
        printf("Enter the name of an element or type 'q' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        choice = -1;
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            if (strcmp(input, elements[i].name) == 0) {
                choice = i;
                break;
            }
        }

        if (choice == -1) {
            printf("Invalid element\n");
        } else {
            printElement(choice);
            score++;
        }

    } while (1);

    printf("Your final score is: %d\n", score);
}