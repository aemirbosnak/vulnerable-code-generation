//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    char symbol[3];
    char name[20];
    int group;
    int period;
} Element;

Element elements[] = {
    {1, "H", "Hydrogen", 1, 1},
    {2, "He", "Helium", 2, 2},
    {3, "Li", "Lithium", 3, 2},
    // Add more elements here...
};

int main() {
    int choice, num, i;

    printf("Welcome to the Periodic Table Quiz!\n");

    do {
        printf("1. Play Quiz\n");
        printf("2. View Elements\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < 8; i++) {
                    printf("Question %d:\n", i + 1);
                    printf("What is the symbol for element %d in the periodic table?\n", i + 1);
                    scanf("%s", elements[i].symbol);
                    printf("Correct!\n");
                }
                break;

            case 2:
                for (i = 0; i < 8; i++) {
                    printf("%d. %d\t%s\t%s\n", i + 1, elements[i].num, elements[i].symbol, elements[i].name);
                }
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}