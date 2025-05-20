//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_civilizations, num_planets, num_invasions;
    double prob_invasion;
    char choice;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will help you determine the probability of an alien invasion.\n");
    printf("Please answer the following questions:\n");

    while (1) {
        printf("How many civilizations are there in the universe? ");
        if (scanf("%d", &num_civilizations)!= 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        if (num_civilizations <= 0) {
            printf("Invalid input. Please enter a positive number.\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("How many planets are there in the universe? ");
        if (scanf("%d", &num_planets)!= 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        if (num_planets <= 0) {
            printf("Invalid input. Please enter a positive number.\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("How many planets have been invaded by aliens? ");
        if (scanf("%d", &num_invasions)!= 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        if (num_invasions < 0) {
            printf("Invalid input. Please enter a non-negative number.\n");
            continue;
        }
        break;
    }

    prob_invasion = (double)num_invasions / (num_civilizations * num_planets);

    printf("The probability of an alien invasion is %.4f.\n", prob_invasion);

    while (1) {
        printf("Do you want to run the simulation again? (y/n) ");
        if (scanf(" %c", &choice)!= 1) {
            printf("Invalid input. Please enter y or n.\n");
            continue;
        }
        if (choice == 'y' || choice == 'Y') {
            break;
        } else if (choice == 'n' || choice == 'N') {
            exit(0);
        } else {
            printf("Invalid input. Please enter y or n.\n");
        }
    }
}