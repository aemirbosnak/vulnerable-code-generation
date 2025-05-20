//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    
    srand(time(0)); //Initializes random number generator
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are a brave adventurer who has entered a haunted house!\n");
    printf("Your goal is to explore the house and make it out alive!\n\n");
    
    printf("You are in a dimly lit hallway and can go left or right.\n");
    printf("Enter 1 to go left. Enter 2 to go right: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou enter a creepy room with cobwebs covering the walls.\n");
        printf("Suddenly, a ghostly figure appears before you!\n");
        printf("Enter 1 to run away. Enter 2 to fight the ghost: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nYou run back into the hallway and head to the right.\n");
        }
        else if (choice == 2) {
            printf("\nYou charge at the ghost, swinging your fists wildly.\n");
            printf("The ghost disappears and you are left panting and sweating.\n");
        }
        else {
            printf("\nInvalid choice. You stand frozen in fear as the ghost approaches.\n");
            printf("GAME OVER.\n");
            
            return 0;
        }
    }
    else if (choice == 2) {
        printf("\nYou enter a dusty old library filled with cobweb-covered books.\n");
        printf("As you are looking around, you notice something written on one of the covers.\n");
        printf("Enter 1 to take the book. Enter 2 to leave it and continue exploring: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nYou take the book from the shelf and open it.\n");
            printf("Suddenly, a cloud of dust erupts from the pages and engulfs you.\n");
            printf("When it clears, you find yourself in a different part of the house.\n");
        }
        else if (choice == 2) {
            printf("\nYou decide to leave the book and continue exploring.\n");
            printf("As you leave the library, you hear a strange whispering behind you.\n");
        }
        else {
            printf("\nInvalid choice. You stand frozen in terror as the walls close in around you.\n");
            printf("GAME OVER.\n");
            
            return 0;
        }
    }
    else {
        printf("\nInvalid choice. You stand frozen in fear as a shadowy figure looms before you.\n");
        printf("GAME OVER.\n");
        
        return 0;
    }
    
    printf("\nYou continue through the house, determined to make it out alive.\n");
    printf("You come across a grand ballroom with a piano in the corner.\n");
    printf("Enter 1 to play the piano. Enter 2 to keep moving: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou sit down at the piano and begin playing a haunting melody.\n");
        printf("As you play, the room begins to come alive with spectral dancers.\n");
        printf("After a few minutes, the dancers disappear and the room is silent once again.\n");
    }
    else if (choice == 2) {
        printf("\nYou decide to keep moving and head towards the staircase.\n");
        printf("As you ascend the stairs, you feel a cold breeze blowing past you.\n");
    }
    else {
        printf("\nInvalid choice. You stand frozen in terror as the floor beneath you gives way.\n");
        printf("GAME OVER.\n");
        
        return 0;
    }
    
    printf("\nYou reach the top of the stairs and find yourself in a dark hallway.\n");
    printf("Enter 1 to use your flashlight. Enter 2 to try to navigate by touch: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou turn on your flashlight and shine it down the hallway.\n");
        printf("As you move forward, you see strange symbols etched into the walls.\n");
    }
    else if (choice == 2) {
        printf("\nYou try to navigate the hallway in the dark, but stumble and fall.\n");
        printf("As you get up, you notice a strange symbol glowing faintly on the wall.\n");
    }
    else {
        printf("\nInvalid choice. You stand frozen in terror as a pair of glowing eyes appear in the darkness.\n");
        printf("GAME OVER.\n");
        
        return 0;
    }
    
    printf("\nAs you walk down the hallway, you hear strange whispers coming from behind a door.\n");
    printf("Enter 1 to open the door. Enter 2 to keep moving: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou slowly open the door and peek inside.\n");
        printf("To your surprise, you find a cozy reading nook with a fire burning in the fireplace.\n");
    }
    else if (choice == 2) {
        printf("\nYou decide to keep moving and head towards the door at the end of the hallway.\n");
        printf("As you approach the door, you feel a strange energy emanating from behind it.\n");
    }
    else {
        printf("\nInvalid choice. You stand frozen in terror as the whispers grow louder.\n");
        printf("GAME OVER.\n");
        
        return 0;
    }
    
    printf("\nYou reach the door and slowly open it, bracing yourself for what lies ahead.\n");
    printf("To your surprise, you find yourself outside the house, safe and sound!\n");
    printf("Congratulations! You have successfully completed the Haunted House Simulator!\n");
    
    return 0;
}