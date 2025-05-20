//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char element[20];
    int correct = 0, incorrect = 0;
    int total = 0;
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n\n");

    while (1) {
        printf("Select an option:\n");
        printf("1. Start Quiz\n");
        printf("2. View Scores\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Starting Quiz...\n\n");
                while (total < 10) {
                    printf("Enter the name of an element: ");
                    scanf("%s", element);
                    if (strcmp(element, "Hydrogen") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Helium") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Lithium") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Beryllium") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Boron") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Carbon") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Nitrogen") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Oxygen") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Fluorine") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else if (strcmp(element, "Neon") == 0) {
                        printf("Correct!\n");
                        correct++;
                    } else {
                        printf("Incorrect!\n");
                        incorrect++;
                    }
                    total++;
                }
                printf("\nYour score is %d out of 10\n", score);
                break;

            case 2:
                printf("Your scores:\n");
                printf("Number of correct answers: %d\n", correct);
                printf("Number of incorrect answers: %d\n", incorrect);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}