//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void showMenu();
void calculateCalories(int option);

int main() {
    srand(time(NULL)); // seed for random number generation
    int choice;
    
    printf("Welcome to C Fitness Tracker!\n\n");
    
    do {
        showMenu();
        scanf("%d", &choice);
        
        if (choice == 5) {
            break;
        } else if (choice > 0 && choice < 5) {
            calculateCalories(choice);
        } else {
            printf("Invalid option. Please choose again.\n\n");
        }
        
    } while (1);
    
    printf("Thank you for using C Fitness Tracker!\n");
    
    return 0;
}

void showMenu() {
    printf("\nPlease choose an option:\n");
    printf("1. Running\n");
    printf("2. Swimming\n");
    printf("3. Biking\n");
    printf("4. Weightlifting\n");
    printf("5. Quit\n\n");
}

void calculateCalories(int option) {
    int time, difficulty;
    int lower, upper;
    
    switch (option) {
        case 1:
            printf("\nFor running, how many minutes did you run? ");
            break;
        case 2:
            printf("\nFor swimming, how many minutes did you swim? ");
            break;
        case 3:
            printf("\nFor biking, how many minutes did you bike? ");
            break;
        case 4:
            printf("\nFor weightlifting, how many minutes did you lift weights? ");
            break;
    }
    
    scanf("%d", &time);
    printf("On a scale of 1-10, how difficult was it? ");
    scanf("%d", &difficulty);
    
    if (difficulty < 1) {
        difficulty = 1;
    } else if (difficulty > 10) {
        difficulty = 10;
    }
    
    lower = time * 10 * difficulty;
    upper = lower + (rand() % (10 * difficulty));
    
    printf("\nYou burned between %d and %d calories.\n\n", lower, upper);
}