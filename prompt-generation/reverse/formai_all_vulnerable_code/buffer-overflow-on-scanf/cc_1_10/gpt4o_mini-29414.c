//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    char name[20];
    char symbol[3];
    int atomic_number;
    float atomic_weight;
} Element;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.008},
    {"Helium", "He", 2, 4.0026},
    {"Lithium", "Li", 3, 6.94},
    {"Beryllium", "Be", 4, 9.0122},
    {"Boron", "B", 5, 10.81},
    {"Carbon", "C", 6, 12.011},
    {"Nitrogen", "N", 7, 14.007},
    {"Oxygen", "O", 8, 15.999},
    {"Fluorine", "F", 9, 18.998},
    {"Neon", "Ne", 10, 20.180},
    // More elements to be filled up to 118
    {"Oganesson", "Og", 118, 294},
};

void romanticMessage() {
    printf("In the dance of love, just like the elements, \n");
    printf("Each pair combines, fates entwined, creating brilliance. \n");
    printf("With each atomic bond, our hearts grow fonder,\n");
    printf("Shall we spark an element of romance and ponder?\n\n");
}

void displayElement(Element e) {
    printf("Element Name: %s\n", e.name);
    printf("Symbol: %s\n", e.symbol);
    printf("Atomic Number: %d\n", e.atomic_number);
    printf("Atomic Weight: %.3f\n", e.atomic_weight);
    printf("---------------------\n");
}

void searchElement() {
    char input[20];
    printf("Oh dear seeker of knowledge, enter the element's name or symbol (or type 'exit' to leave): ");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            printf("May your heart be filled with elements of joy! Farewell.\n");
            break;
        }
        
        int found = 0;
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            if (strcasecmp(input, elements[i].name) == 0 || strcasecmp(input, elements[i].symbol) == 0) {
                displayElement(elements[i]);
                printf("Ah, the chemistry of love is in the air!\n");
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Oh, sweet soul, I cannot find this element.\n");
            printf("Please try again or whisper 'exit' to escape.\n");
        }
    }
}

int main() {
    romanticMessage();
    searchElement();
    return 0;
}