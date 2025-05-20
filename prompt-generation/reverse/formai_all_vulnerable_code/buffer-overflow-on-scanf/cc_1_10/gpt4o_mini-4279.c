//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISHES 5
#define MAX_ATTEMPTS 3

const char *dishes[MAX_DISHES] = {
    "Spaghetti Monster",
    "Burrito of Doom",
    "Fried Chicken Catastrophe",
    "Salad of Sorrow",
    "Brownie Blast"
};

void print_instructions() {
    printf("Welcome to Chef Chaos!\n");
    printf("You are a clumsy pet chef trying to prepare dishes without causing trouble!\n");
    printf("Your goal is to successfully cook 3 dishes.\n");
    printf("But watch out! You can only mess up a dish 3 times or you'll burn down the kitchen!\n");
    printf("Let's get started!\n\n");
}

int main() {
    srand(time(0));
    
    print_instructions();

    int successful_dishes = 0; 
    while (successful_dishes < 3) {
        int random_dish = rand() % MAX_DISHES;
        int attempts_left = MAX_ATTEMPTS;

        printf("Cooking: %s\n", dishes[random_dish]);
        while (attempts_left > 0) {
            printf("Attempts remaining: %d. Do you want to (1) Try cooking or (2) Run away?\n", attempts_left);
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                int success = rand() % 2; // simulate success or failure
                if (success) {
                    printf("Chef successfully cooked %s! Yum!\n", dishes[random_dish]);
                    successful_dishes++;
                    printf("Total Successful Dishes: %d\n\n", successful_dishes);
                    break; // exit the attempts while loop
                } else {
                    attempts_left--;
                    printf("Oops! You made a mess! But don't give up, you can try again!\n");
                    if (attempts_left == 0) {
                        printf("You've burned the kitchen! Chef is banned from cooking! Game Over!\n");
                        exit(0);
                    }
                }
            } else if (choice == 2) {
                printf("Chef cowardly fled the kitchen! What a coward!\n");
                break;
            } else {
                printf("Invalid choice! Please select a valid option.\n");
            }
        }
    }

    printf("Congratulations! You've successfully cooked 3 delicious dishes!\n");
    printf("Chef Chaos is proud of you! Now, you can open your own chaotic restaurant!\n");
    printf("Thank you for playing Chef Chaos!\n");

    return 0;
}