//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed
    srand(time(0));
    
    // Initialize variables
    int room = 1;
    int flashlight = 0;
    int ghost_encounter = 0;
    int trap_encounter = 0;
    
    printf("Welcome to the Haunted House Simulator\n");
    printf("You find yourself in a dark room. You can barely see your hands in front of you.\n");
    printf("You need to find your way out before you get trapped in the house forever.\n");
    printf("Type 'help' for a list of commands.\n\n");
    
    // Game loop
    while(1) {
        printf("You are in room %d\n", room);
        
        // Check for flashlight
        if(!flashlight && room != 4) {
            printf("You can't see anything in this dark room.\n");
        }
        
        // Check for encounters
        if(room == 3 && !ghost_encounter) {
            printf("You feel a chill run down your spine. You might not be alone in this room.\n");
            ghost_encounter = 1;
        } else if(room == 5 && !trap_encounter) {
            printf("You hear a strange noise coming from the floor. You should be careful.\n");
            trap_encounter = 1;
        }
        
        // Prompt user for input
        printf("What do you want to do? ");
        char input[10];
        scanf("%s", input);
        
        // Handle input
        if(strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("'help' - Display this list of commands\n");
            printf("'look' - Inspect your surroundings\n");
            printf("'move <direction>' - Move to the specified direction\n");
            printf("'grab <item>' - Grab the specified item\n");
            printf("'use <item>' - Use the specified item\n");
            printf("'quit' - Quit the game\n\n");
        } else if(strcmp(input, "look") == 0) {
            // Describe the room
            switch(room) {
                case 1:
                    printf("You are in a dusty hallway. The walls are covered in cobwebs.\n");
                    break;
                case 2:
                    printf("You are in a living room. The furniture is covered in a thick layer of dust.\n");
                    break;
                case 3:
                    printf("You are in a bedroom. The bed is unmade and the sheets are stained.\n");
                    break;
                case 4:
                    printf("You are in a store room. There are shelves filled with dusty objects.\n");
                    break;
                case 5:
                    printf("You are in a kitchen. The counters are littered with dirty dishes.\n");
                    break;
            }
            
            if(room == 4) {
                printf("There is a flashlight on one of the shelves.\n");
            }
            
        } else if(strncmp(input, "move", 4) == 0) {
            // Parse the direction
            char direction[10];
            sscanf(input, "move %s", direction);
            
            // Move to the specified direction
            if(strcmp(direction, "north") == 0) {
                if(room == 1 || room == 2 || room == 5) {
                    room--;
                } else {
                    printf("You can't go that way.\n");
                }
            } else if(strcmp(direction, "south") == 0) {
                if(room == 1 || room == 3 || room == 4) {
                    room++;
                } else {
                    printf("You can't go that way.\n");
                }
            } else if(strcmp(direction, "east") == 0) {
                if(room == 1) {
                    room = 5;
                } else if(room == 2) {
                    room = 3;
                } else if(room == 4) {
                    room = 2;
                } else {
                    printf("You can't go that way.\n");
                }
            } else if(strcmp(direction, "west") == 0) {
                if(room == 2) {
                    room = 4;
                } else if(room == 3) {
                    room = 2;
                } else if(room == 5) {
                    room = 1;
                } else {
                    printf("You can't go that way.\n");
                }
            } else {
                printf("Invalid direction\n");
            }
            
        } else if(strncmp(input, "grab", 4) == 0) {
            // Parse the item
            char item[10];
            sscanf(input, "grab %s", item);
            
            // Grab the specified item
            if(strcmp(item, "flashlight") == 0) {
                if(room == 4) {
                    printf("You picked up the flashlight\n");
                    flashlight = 1;
                } else {
                    printf("There is no flashlight in this room\n");
                }
            } else {
                printf("Invalid item\n");
            }
            
        } else if(strncmp(input, "use", 3) == 0) {
            // Parse the item
            char item[10];
            sscanf(input, "use %s", item);
            
            // Use the specified item
            if(strcmp(item, "flashlight") == 0) {
                if(flashlight) {
                    printf("You turned on the flashlight. You can see the room clearly now.\n");
                } else {
                    printf("You don't have a flashlight\n");
                }
            } else {
                printf("Invalid item\n");
            }
            
        } else if(strcmp(input, "quit") == 0) {
            printf("Are you sure you want to quit? (y/n) ");
            char confirm;
            scanf(" %c", &confirm);
            
            if(confirm == 'y' || confirm == 'Y') {
                printf("Thanks for playing. Goodbye!\n");
                return 0;
            }
            
        } else {
            printf("Invalid command\n");
        }
        
        // Check for game over conditions
        if(room == 6) {
            printf("You made it out of the haunted house!\n");
            printf("Congratulations! You win!\n");
            return 0;
        } else if(room == 0) {
            printf("You fell into a trap and died a gruesome death.\n");
            printf("Game over.\n");
            return 0;
        }
    }
}