//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the legendary treasure of the lost city.\n");
    
    srand(time(NULL));
    int random = rand() % 2;
    
    if (random == 0) {
        printf("You start your journey in a dense forest. The air is thick with the scent of pine and earth.\n");
    } else {
        printf("You start your journey on the outskirts of a bustling city. The sound of merchants and travelers fills the air.\n");
    }
    
    while (1) {
        printf("What do you want to do?\n");
        printf("1. Explore\n");
        printf("2. Rest\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (random == 0) {
                    printf("As you venture deeper into the forest, you come across a clearing with a crystal-clear stream.\n");
                    printf("Do you want to follow the stream?\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    scanf("%d", &choice);
                    
                    switch (choice) {
                        case 1:
                            printf("You follow the stream and eventually come across a hidden cave.\n");
                            printf("Do you want to explore the cave?\n");
                            printf("1. Yes\n");
                            printf("2. No\n");
                            scanf("%d", &choice);
                            
                            switch (choice) {
                                case 1:
                                    printf("As you explore the cave, you find a treasure chest filled with gold and jewels!\n");
                                    printf("Congratulations, you have found the legendary treasure of the lost city!\n");
                                    break;
                                case 2:
                                    printf("You leave the cave empty-handed.\n");
                                    break;
                            }
                            break;
                        case 2:
                            printf("You continue through the forest.\n");
                            break;
                    }
                } else {
                    printf("As you explore the city, you come across a bustling marketplace.\n");
                    printf("Do you want to shop at the marketplace?\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    scanf("%d", &choice);
                    
                    switch (choice) {
                        case 1:
                            printf("You find a rare artifact that is said to grant its owner immense power!\n");
                            printf("Congratulations, you have found the legendary treasure of the lost city!\n");
                            break;
                        case 2:
                            printf("You continue through the city.\n");
                            break;
                    }
                }
                break;
            case 2:
                printf("You rest for a while.\n");
                break;
            case 3:
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}