//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include <stdio.h>

int main() {
    int choice;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Choose one of the following options:\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
    scanf("%d", &choice);
    if (choice == 1) {
        int score = 0;
        char element[10];
        printf("Enter the name of an element:\n");
        scanf("%s", element);
        printf("What is the atomic number of %s?\n", element);
        int atomicNumber;
        scanf("%d", &atomicNumber);
        if (atomicNumber == 1) {
            printf("Correct! %s has an atomic number of 1.\n", element);
            score++;
        } else {
            printf("Incorrect. The atomic number of %s is not 1.\n", element);
        }
        printf("Enter the name of another element:\n");
        scanf("%s", element);
        printf("What is the symbol of %s?\n", element);
        char symbol[10];
        scanf("%s", symbol);
        if (strcmp(symbol, "H") == 0) {
            printf("Correct! The symbol for %s is H.\n", element);
            score++;
        } else {
            printf("Incorrect. The symbol for %s is not H.\n", element);
        }
        printf("Enter the name of another element:\n");
        scanf("%s", element);
        printf("What is the atomic weight of %s?\n", element);
        double atomicWeight;
        scanf("%lf", &atomicWeight);
        if (atomicWeight == 1.008) {
            printf("Correct! The atomic weight of %s is 1.008.\n", element);
            score++;
        } else {
            printf("Incorrect. The atomic weight of %s is not 1.008.\n", element);
        }
        printf("You scored %d out of 3.\n", score);
    } else if (choice == 2) {
        printf("Exiting program...\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
    return 0;
}