//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    printf("Welcome to the Periodic Table Quiz! \n");

    int num;
    printf("How many questions would you like to answer? ");
    scanf("%d", &num);

    int score = 0;

    for (int i = 1; i <= num; i++) {
        char element[10];
        int atomicNumber;
        printf("Question %d: What is the element with atomic number %d? ", i, i);
        scanf("%s %d", element, &atomicNumber);

        if (strcmp(element, "H") == 0) {
            score++;
        } else if (strcmp(element, "He") == 0) {
            score++;
        } else if (strcmp(element, "Li") == 0) {
            score++;
        } else if (strcmp(element, "Be") == 0) {
            score++;
        } else if (strcmp(element, "B") == 0) {
            score++;
        } else if (strcmp(element, "C") == 0) {
            score++;
        } else if (strcmp(element, "N") == 0) {
            score++;
        } else if (strcmp(element, "O") == 0) {
            score++;
        } else if (strcmp(element, "F") == 0) {
            score++;
        } else if (strcmp(element, "Ne") == 0) {
            score++;
        } else if (strcmp(element, "Na") == 0) {
            score++;
        } else if (strcmp(element, "Mg") == 0) {
            score++;
        } else if (strcmp(element, "Al") == 0) {
            score++;
        } else if (strcmp(element, "Si") == 0) {
            score++;
        } else if (strcmp(element, "P") == 0) {
            score++;
        } else if (strcmp(element, "S") == 0) {
            score++;
        } else if (strcmp(element, "Cl") == 0) {
            score++;
        } else if (strcmp(element, "Ar") == 0) {
            score++;
        } else {
            printf("Sorry, incorrect answer.\n");
        }
    }

    printf("Your score is %d/%d. \n", score, num);

    return 0;
}