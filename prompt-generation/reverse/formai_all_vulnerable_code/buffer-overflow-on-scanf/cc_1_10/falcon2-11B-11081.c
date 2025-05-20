//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_ELEMENTS 100
#define MAX_RANK 100

struct element {
    char name[11];
    char symbol[3];
    char group[5];
    char period[5];
    int rank;
};

struct element elements[NUM_ELEMENTS];

void display_elements() {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%s\t%c\t%s\t%s\t%d\n", elements[i].name, elements[i].symbol,
               elements[i].group, elements[i].period, elements[i].rank);
    }
}

int main() {
    int num_elements;

    printf("How many elements do you want to include in the quiz? ");
    scanf("%d", &num_elements);

    if (num_elements < 1 || num_elements > NUM_ELEMENTS) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    for (int i = 0; i < num_elements; i++) {
        printf("Enter element name: ");
        scanf("%s", elements[i].name);

        printf("Enter element symbol: ");
        scanf(" %c", &elements[i].symbol[0]);

        printf("Enter element group: ");
        scanf(" %s", elements[i].group);

        printf("Enter element period: ");
        scanf(" %s", elements[i].period);

        printf("Enter element rank (0-100): ");
        scanf("%d", &elements[i].rank);
    }

    display_elements();

    return 0;
}