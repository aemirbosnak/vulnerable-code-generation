//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator
    
    printf("You find yourself standing in front of a dilapidated mansion.\n");
    printf("You can hear strange noises coming from inside. Do you dare to enter? (y/n)\n");
    
    char choice;
    scanf("%c", &choice);
    printf("\n");
    
    if (choice == 'y') {
        printf("You cautiously push open the creaky door and step inside.\n");
        
        int room = 1;
        int ghost = rand() % 4 + 1; // random number between 1 and 4
        
        while (room <= 10) { // explore 10 rooms
            printf("You are in room %d.\n", room);
            
            if (room == ghost) {
                printf("Suddenly, a ghostly apparition appears before you!\n");
                printf("Press any key to try to escape... ");
                
                fflush(stdin); // clear input buffer
                getchar();
                printf("\n");
                
                int escape = rand() % 2; // random 0 or 1
                
                if (escape) {
                    printf("You narrowly escape the ghost and move on to the next room.\n");
                } else {
                    printf("The ghost captures you and drags you to a nearby closet. You are trapped!\n");
                    printf("Press any key to continue... ");
                    
                    fflush(stdin);
                    getchar();
                    printf("\n");
                    
                    printf("You search frantically and find a hidden button. Do you press it? (y/n)\n");
                    
                    scanf(" %c", &choice); // space before %c to eat newline
                    
                    if (choice == 'y') {
                        printf("You press the button and the closet door swings open. You can continue exploring the house.\n");
                    } else {
                        printf("You choose not to press the button and remain trapped in the closet. GAME OVER.\n");
                        return 0; // end game
                    }
                }
                
                ghost = rand() % 4 + 1; // generate new random ghost room
            } else {
                printf("There are no ghosts here. You move on to the next room.\n");
                
                room++;
            }
        }
        
        printf("You have explored all 10 rooms and found no ghosts!\n");
        printf("Congratulations! You have survived the haunted house!\n");
    } else {
        printf("You choose not to enter the haunted house. GAME OVER.\n");
    }
    
    return 0;
}