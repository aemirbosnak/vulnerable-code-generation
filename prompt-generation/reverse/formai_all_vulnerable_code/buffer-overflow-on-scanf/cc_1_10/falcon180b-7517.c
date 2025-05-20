//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Initialize random seed
    int choice;
    char input[100];

    // Prompt user to enter their name
    printf("Enter your name: ");
    scanf("%s", input);
    printf("\nWelcome, %s! I am the Automated Fortune Teller.\n", input);
    printf("I will predict your future based on the choices you make.\n");

    // Prompt user to choose their path
    printf("\nYou are standing at a crossroads. Which path will you take?\n");
    printf("1. The path to the left\n");
    printf("2. The path to the right\n");
    printf("3. The path straight ahead\n");
    scanf("%d", &choice);

    // Predict the future based on the user's choice
    switch(choice) {
        case 1:
            printf("\nYou have chosen the path to the left.\n");
            printf("This path leads to a dark and mysterious forest.\n");
            printf("You will encounter many challenges and obstacles,\n");
            printf("but if you persevere, you will find great rewards.\n");
            break;
        case 2:
            printf("\nYou have chosen the path to the right.\n");
            printf("This path leads to a bright and sunny meadow.\n");
            printf("You will experience joy and happiness,\n");
            printf("but you must be careful not to become complacent.\n");
            break;
        case 3:
            printf("\nYou have chosen the path straight ahead.\n");
            printf("This path leads to a vast and open ocean.\n");
            printf("You will embark on a journey of self-discovery,\n");
            printf("but you must be prepared for the unknown.\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            return 0;
    }

    return 0;
}