//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#define MAX_ELEMENTS 118

struct Element {
    char symbol[3];
    char name[25];
    int atomic_number;
    float atomic_mass;
};

void initialize_elements(struct Element *elements) {
    FILE *fptr;
    fptr = fopen("elements.txt", "r");
    for (int i=0; i<MAX_ELEMENTS; i++) {
        fscanf(fptr, "%s\t%s\t%d\t%f", elements[i].symbol, elements[i].name, &elements[i].atomic_number, &elements[i].atomic_mass);
    }
    fclose(fptr);
}

void print_menu() {
    printf("\n\nMenu:\n");
    printf("1. Guess the symbol for the given element\n");
    printf("2. Guess the name for the given symbol\n");
    printf("3. Exit\n");
}

void quiz_by_symbol(struct Element *elements) {
    int random_index = rand() % MAX_ELEMENTS;
    printf("What is the symbol for the element %s (Atomic Number: %d, Atomic Mass: %.4f)?\n", elements[random_index].name, elements[random_index].atomic_number, elements[random_index].atomic_mass);
    char guess[3];
    scanf("%s", guess);
    if (strcmp(guess, elements[random_index].symbol) == 0) {
        printf("Correct answer!\n");
    } else {
        printf("Incorrect. The correct answer is %s.\n", elements[random_index].symbol);
    }
}

void quiz_by_name(struct Element *elements) {
    int random_index = rand() % MAX_ELEMENTS;
    printf("What is the name for the symbol %s (Atomic Number: %d, Atomic Mass: %.4f)?\n", elements[random_index].symbol, elements[random_index].atomic_number, elements[random_index].atomic_mass);
    char guess[25];
    scanf("%s", guess);

    // search for comma
    char *pos;
    if ((pos=strchr(guess, ',')) != NULL)
        *pos = '\0';

    if (strcmp(guess, elements[random_index].name) == 0) {
        printf("Correct answer!\n");
    } else {
        printf("Incorrect. The correct answer is %s.\n", elements[random_index].name);
    }
}

int main() {
    struct Element elements[MAX_ELEMENTS];
    initialize_elements(elements);
    srand(time(NULL));

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                quiz_by_symbol(elements);
                break;
            case 2:
                quiz_by_name(elements);
                break;
            case 3:
                printf("Thank you for playing the periodic table quiz!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 3);

    return 0;
}