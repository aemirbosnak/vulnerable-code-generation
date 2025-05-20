//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, room1, room2, room3, room4, room5, room6, room7, room8;
    int flashlight = 0, scary_sound = 0, scared = 0, key = 0;
    srand(time(0));
    
    // Introduction
    printf("Welcome to the Haunted House Simulator\n");
    printf("You find yourself standing in front of a spooky old mansion.\n");
    printf("Do you dare to enter?\n");
    printf("1. Yes\n2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 2) {
        printf("You chicken out and leave.\n");
        return 0;
    }

    // Room 1
    printf("\nYou enter the house.\n");
    printf("You are in a dimly lit hallway. It's creepy!\n");
    printf("There are doors to your left and right.\n");
    printf("1. Open the left door\n2. Open the right door\n");
    printf("Enter your choice: ");
    scanf("%d", &room1);
    
    if (room1 == 1) {
        printf("\nYou open the left door and enter a dusty old room.\n");
        printf("There's an old chest in the corner.\n");
        printf("1. Search the chest\n2. Ignore the chest\n");
        printf("Enter your choice: ");
        scanf("%d", &room2);
        
        if (room2 == 1) {
            int loot = rand() % 2;
            if (loot == 0) {
                printf("You found a flashlight!\n");
                flashlight = 1;
            } else {
                printf("You found a note that reads 'Get out while you still can!'\n");
            }
        }
        
        printf("\nYou exit the room.\n");
    } else {
        printf("\nYou open the right door and enter a dark kitchen.\n");
        printf("There's a door to the basement and a fridge.\n");
        printf("1. Open the basement door\n2. Check the fridge\n");
        printf("Enter your choice: ");
        scanf("%d", &room3);
        
        if (room3 == 1) {
            printf("\nYou open the basement door.\n");
            printf("It's pitch black, you can't see anything.\n");
            if (flashlight == 0) {
                printf("You need a flashlight!\n");
            } else {
                printf("You turn on the flashlight and descend the stairs.\n");
                int basement = rand() % 2;
                if (basement == 0) {
                    printf("You find a key!\n");
                    key = 1;
                } else {
                    printf("You hear a scary sound and run back upstairs!\n");
                    scary_sound = 1;
                }
            }
        } else {
            printf("\nYou check the fridge.\n");
            printf("It's empty, except for a key!\n");
            key = 1;
        }
        
        printf("\nYou exit the kitchen.\n");
    }
    
    // Room 2
    printf("You are back in the hallway.\n");
    printf("There are doors to your left and right.\n");
    printf("1. Open the left door\n2. Open the right door\n");
    printf("Enter your choice: ");
    scanf("%d", &room4);
    
    if (room4 == 1) {
        printf("\nYou open the left door and enter a bedroom.\n");
        printf("The bed is made and there's a dresser.\n");
        printf("1. Search the dresser\n2. Ignore the room\n");
        printf("Enter your choice: ");
        scanf("%d", &room5);
        
        if (room5 == 1) {
            printf("You find a creepy doll that seems to be following you with its eyes.\n");
            printf("You politely put it back and leave.\n");
        }
        
        printf("\nYou exit the room.\n");
    } else {
        printf("\nYou open the right door and enter a bathroom.\n");
        printf("There's a mirror and a shower.\n");
        printf("1. Look in the mirror\n2. Check the shower\n");
        printf("Enter your choice: ");
        scanf("%d", &room6);
        
        if (room6 == 1) {
            printf("You look in the mirror and see a scary face looking back at you!\n");
            printf("You scream and run out of the bathroom!\n");
            scared = 1;
        } else {
            printf("You check the shower and find a note that reads 'You're almost there!'\n");
        }
        
        printf("\nYou exit the bathroom.\n");
    }
    
    // Room 3
    printf("You are back in the hallway.\n");
    printf("There are doors to your left and right.\n");
    printf("1. Open the left door\n2. Open the right door\n");
    printf("Enter your choice: ");
    scanf("%d", &room7);
    
    if (room7 == 1) {
        printf("\nYou open the left door and enter a small closet.\n");
        printf("There's a note that reads 'It's behind you!'\n");
        if (scary_sound == 1) {
            printf("You turn around and see a scary ghost!\n");
            printf("You quickly leave the closet and slam the door behind you!\n");
            scared = 1;
        }
        printf("\nYou exit the closet.\n");
    } else {
        printf("\nYou open the right door and enter a large living room.\n");
        printf("There's a fireplace and a piano.\n");
        printf("1. Check the fireplace\n2. Play the piano\n");
        printf("Enter your choice: ");
        scanf("%d", &room8);
        
        if (room8 == 1) {
            printf("You check the fireplace and find a key!\n");
            key = 1;
        } else {
            printf("You play a scary tune on the piano!\n");
            printf("You quickly stop playing and leave the room.\n");
            scared = 1;
        }
        
        printf("\nYou exit the living room.\n");
    }
    
    // Escape
    printf("You are back in the hallway.\n");
    printf("You see a door at the end of the hallway.\n");
    printf("1. Open the door and escape!\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (key == 0) {
        printf("\nYou try to open the door, but it's locked!\n");
        printf("You need a key!\n");
    } else {
        printf("\nYou unlock the door and escape the haunted house!\n");
        printf("Congratulations, you made it out alive!\n");
        if (scared == 1) {
            printf("You were scared a few times, but you made it!\n");
        } else {
            printf("You were very brave, you didn't get scared at all!\n");
        }
    }
    
    return 0;
}