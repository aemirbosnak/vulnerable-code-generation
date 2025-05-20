//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    char choice = ' ';
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing outside a spooky old mansion.\n");
    printf("Do you dare to enter? (y/n)\n");
    scanf("%c", &choice);
    
    if (choice == 'y') {
        printf("As you enter the house, the door slams shut behind you.\n");
        printf("You hear creepy noises coming from the other rooms.\n");
        printf("You have to find a way out!\n");
        
        while (score < 5) {
            printf("\nChoose your next move:\n");
            printf("1. Go upstairs\n");
            printf("2. Explore the basement\n");
            printf("3. Investigate a mysterious noise\n");
            printf("4. Search for a key\n");
            printf("5. Quit\n");
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("\nYou climb the creaky stairs to the second floor.\n");
                printf("The air grows colder as you approach a dark room.\n");
                printf("You hear whispers coming from inside.\n");
                printf("Do you want to enter? (y/n)\n");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    printf("You enter the room and see a ghostly figure.\n");
                    printf("You scream and run back downstairs.\n");
                    score--;
                    printf("Your score is now %d.\n", score);
                }
                else {
                    printf("You decide to leave the room and head back downstairs.\n");
                    score++;
                    printf("Your score is now %d.\n", score);
                }
            }
            else if (choice == 2) {
                printf("\nYou make your way to the basement.\n");
                printf("It's very dark and you can barely see a thing.\n");
                printf("You hear something moving in the shadows.\n");
                printf("Do you want to investigate? (y/n)\n");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    printf("You walk towards the sound and suddenly a rat jumps out at you!\n");
                    printf("You scream and run back upstairs.\n");
                    score--;
                    printf("Your score is now %d.\n", score);
                }
                else {
                    printf("You decide to leave the basement and head back upstairs.\n");
                    score++;
                    printf("Your score is now %d.\n", score);
                }
            }
            else if (choice == 3) {
                printf("\nYou follow the sound of a mysterious noise.\n");
                printf("You find yourself in a small room with a single candle burning.\n");
                printf("You hear someone whispering your name.\n");
                printf("Do you want to investigate? (y/n)\n");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    printf("You walk towards the candle and suddenly it goes out.\n");
                    printf("You feel something cold touch your neck.\n");
                    printf("You scream and run out of the room.\n");
                    score--;
                    printf("Your score is now %d.\n", score);
                }
                else {
                    printf("You decide to leave the room and head back out to the hallway.\n");
                    score++;
                    printf("Your score is now %d.\n", score);
                }
            }
            else if (choice == 4) {
                printf("\nYou start searching the house for a key.\n");
                printf("You check all the drawers and cupboards, but can't find anything.\n");
                printf("You decide to check the attic.\n");
                printf("As you climb the ladder, you feel something grabbing your foot.\n");
                printf("Do you want to look down? (y/n)\n");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    printf("You look down and see a corpse grabbing your foot.\n");
                    printf("You scream and kick it off.\n");
                    score--;
                    printf("Your score is now %d.\n", score);
                }
                else {
                    printf("You manage to kick it off and find the key in the attic.\n");
                    score++;
                    printf("Your score is now %d.\n", score);
                }
            }
            else if (choice == 5) {
                printf("\nYou give up and try to find a way out of the house.\n");
                break;
            }
            else {
                printf("\nInvalid choice. Please try again.\n");
            }
        }
        
        if (score == 5) {
            printf("\nCongratulations! You made it out of the haunted house.\n");
        }
        else {
            printf("\nGame over. You were not able to escape the haunted house.\n");
        }
    }
    else {
        printf("You chicken out and decide to leave.\n");
    }
    
    return 0;
}