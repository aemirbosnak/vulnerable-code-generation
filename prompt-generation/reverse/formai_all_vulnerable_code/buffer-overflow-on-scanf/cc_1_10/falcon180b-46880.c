//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice, health = 100, score = 0;
    
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You find yourself in a dark, mysterious forest.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the forest\n");
    printf("2. Rest\n");
    printf("3. Quit\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("You begin to explore the forest.\n");
            printf("You come across a clearing and see a small cottage.\n");
            printf("Do you want to enter the cottage? (y/n)\n");
            char answer;
            scanf(" %c", &answer);
            
            if(answer == 'y' || answer == 'Y') {
                printf("You enter the cottage and find an old book.\n");
                printf("Reading the book increases your knowledge.\n");
                score += 10;
            } else {
                printf("You decide not to enter the cottage.\n");
            }
            break;
            
        case 2:
            printf("You rest for a while.\n");
            printf("Your health increases.\n");
            health += 10;
            if(health > 100) {
                health = 100;
            }
            break;
            
        case 3:
            printf("You decide to quit the game.\n");
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}