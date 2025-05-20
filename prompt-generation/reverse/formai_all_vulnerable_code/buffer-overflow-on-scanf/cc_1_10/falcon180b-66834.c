//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int score = 0;
    int health = 100;
    char name[20];

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));

    while(1) {
        printf("\n%s, you are in a magical forest.\n", name);
        printf("What would you like to do?\n");
        printf("1. Explore the forest\n");
        printf("2. Rest\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou decide to explore the forest.\n");
                if(rand() % 2 == 0) {
                    printf("You find a hidden treasure! Your score increases by 10 points.\n");
                    score += 10;
                } else {
                    printf("You get lost in the forest. Your health decreases by 10 points.\n");
                    health -= 10;
                }
                break;
            case 2:
                printf("\nYou decide to rest.\n");
                printf("Your health increases by 5 points.\n");
                health += 5;
                break;
            case 3:
                printf("\n%s, thanks for playing! Your final score is %d points.\n", name, score);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if(health <= 0) {
            printf("\n%s, you have died in the forest.\n", name);
            return 0;
        }
    }

    return 0;
}