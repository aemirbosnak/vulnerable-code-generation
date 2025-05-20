//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int score = 0;
    int currentRoom = 0;
    int choice = 0;
    int finalRoom = 3;
    char name[20];
    
    // Opening message
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("What is your name, adventurer?");
    scanf("%s", &name);
    printf("\n\nHello, %s. Your mission is to navigate through a series of rooms on a spaceship,\n", name);
    printf("and find the treasure. Be careful - there are dangers in some of the rooms!\n\n");
    printf("You start in room %d.\n\n", currentRoom);
    
    // Main game loop
    while (currentRoom != finalRoom) {
        printf("What do you want to do?\n");
        printf("1. Move to the next room.\n");
        printf("2. Search the current room.\n");
        printf("3. Quit game.\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Moving to the next room
                currentRoom++;
                printf("You move to room %d.\n", currentRoom);
                
                if (currentRoom == finalRoom) {
                    // End of game
                    printf("Congratulations, you found the treasure! Your final score is %d.\n", score);
                    break;
                }
                
                // Random events in some of the rooms
                if (currentRoom == 1) {
                    int eventChance = rand() % 5;
                    if (eventChance == 0) {
                        // Attacked by aliens
                        printf("Oh no! You've been attacked by aliens and lost 10 points!\n");
                        score -= 10;
                    }
                }
                else if (currentRoom == 2) {
                    int eventChance = rand() % 5;
                    if (eventChance == 0) {
                        // Found a laser gun
                        printf("You found a laser gun in the room and gained 5 points!\n");
                        score += 5;
                    }
                }
                break;
                
            case 2:
                // Searching current room
                if (currentRoom == 0) {
                    // Found key in the first room
                    printf("You found a key in the room and gained 10 points!\n");
                    score += 10;
                }
                else if (currentRoom == 2) {
                    // Trapped in the room
                    printf("Oh no! You've been trapped in a forcefield and lost 5 points!\n");
                    score -= 5;
                }
                else {
                    // Nothing found
                    printf("You search the room but find nothing.\n");
                }
                break;
                
            case 3:
                // Quit game
                printf("Thanks for playing, %s. Your final score is %d.\n", name, score);
                currentRoom = finalRoom;
                break;
                
            default:
                printf("Invalid input. Please select 1, 2, or 3.\n");
                break;
        }
    }
    
    return 0;
}