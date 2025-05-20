//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(0));
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are standing outside a dark and eerie house on a stormy night...\n");
    printf("Do you dare enter? (y/n)\n");
    
    char choice;
    scanf("%c", &choice);
    
    if(choice == 'y') {
        printf("\nYou enter the creepy mansion and the door slams shut behind you...\n");
        printf("You are in a dimly-lit hallway with two doors in front of you.\n");
        
        int door_choice;
        int ghost;
        
        printf("Which door will you choose? (1 or 2)\n");
        scanf("%d", &door_choice);
        
        if(door_choice == 1) {
            printf("\nYou open the door and find yourself in a dusty library.\n");
            printf("Suddenly, you hear a faint whisper...\n");
            
            ghost = rand() % 10;
            
            if(ghost < 3) {
                printf("A ghostly figure appears and chases you out of the library!\n");
            } else {
                printf("You turn around but nobody is there. Strange...\n");
            }
            
            printf("\nYou make your way back to the hallway and approach the second door.\n");
            printf("Do you want to open it? (y/n)\n");
            
            char second_choice;
            scanf(" %c", &second_choice);
            
            if(second_choice == 'y') {
                printf("\nYou open the door and find a secret room!\n");
                printf("Inside, you find a chest filled with treasure and a note from a previous explorer.\n");
                printf("\"Beware, danger lurks around every corner in this haunted house.\"\n");
            } else {
                printf("\nYou decide not to open the door and make your way back outside.\n");
                printf("Thanks for playing the Haunted House Simulator!\n");
                return 0;
            }
        } else {
            printf("\nYou open the door and find yourself in a dark and musty room.\n");
            printf("You can barely see anything but you hear strange noises in the distance...\n");
            
            ghost = rand() % 10;
            
            if(ghost < 5) {
                printf("Suddenly, a ghostly apparition appears before you and begins to chase you!\n");
                printf("You run back to the hallway and quickly approach the second door.\n");
            } else {
                printf("You shine your flashlight around the room but there's nobody there. Whew...\n");
                printf("You approach the second door.\n");
            }
            
            printf("Do you want to open it? (y/n)\n");
            
            char second_choice;
            scanf(" %c", &second_choice);
            
            if(second_choice == 'y') {
                printf("\nYou open the door and find a room filled with cobwebs.\n");
                printf("In the center of the room, you see a chest filled with treasure!\n");
                printf("You cautiously approach the chest...\n");
                
                ghost = rand() % 10;
                
                if(ghost < 7) {
                    printf("Suddenly, a hand grabs your shoulder and you turn around to see a terrifying monster!\n");
                    printf("You run out of the room in terror and exit the haunted house.\n");
                    printf("Thanks for playing the Haunted House Simulator!\n");
                    return 0;
                } else {
                    printf("You open the chest to find the treasure...and also a note from a previous explorer.\n");
                    printf("\"You have survived the terrors of this house. Congratulations!\"\n");
                    printf("Thanks for playing the Haunted House Simulator!\n");
                    return 0;
                }
            } else {
                printf("\nYou decide not to open the door and make your way back outside.\n");
                printf("Thanks for playing the Haunted House Simulator!\n");
                return 0;
            }
        }
    } else {
        printf("\nYou decide not to enter the haunted house and go home.\n");
        printf("Thanks for playing the Haunted House Simulator!\n");
        return 0;
    }
}