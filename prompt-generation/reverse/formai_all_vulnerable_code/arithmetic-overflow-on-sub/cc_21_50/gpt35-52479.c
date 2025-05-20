//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random number generator
    
    // set up variables for player
    int health = 100;
    int coins = 0;
    int keys = 0;
    int flashlight = 0;
    int door_unlocked = 0;
    
    // set up variables for haunted house
    int power_on = 0;
    int front_door_locked = 1;
    int window_open = 0;
    int monster_present = 1;
    int treasure_collected = 0;
    int ghosts_encountered = 0;
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of an old, abandoned house.\n");
    printf("Do you want to enter? (y/n) ");
    char input = getchar();
    getchar(); // remove newline character from buffer
    
    if (input == 'y') {
        printf("You cautiously enter the house...\n");
    } else {
        printf("You decide not to enter the house and walk away.\n");
        return 0; // end program if player chooses not to enter
    }
    
    printf("You are standing in the entry way of the house. ");
    printf("It's dark and gloomy inside.\n");
    
    // loop until player leaves or encounters monster
    while (health > 0 && monster_present) {
        printf("What do you want to do? ");
        printf("(1) Search for treasure, (2) Look for a key, ");
        printf("(3) Turn on the power, (4) Try to open the front door, ");
        printf("(5) Open the window, (6) Leave the house\n");
        int choice = getchar() - '0';
        getchar(); // remove newline character from buffer
        
        switch (choice) {
            case 1: // search for treasure
                if (power_on && !treasure_collected) {
                    printf("You look around and find a hidden treasure chest!\n");
                    coins += 100;
                    treasure_collected = 1;
                } else if (treasure_collected) {
                    printf("You have already found the treasure.\n");
                } else {
                    printf("You can't see anything in the dark.\n");
                }
                break;
            case 2: // look for a key
                if (power_on && !keys) {
                    printf("You find a key sitting on a nearby table.\n");
                    keys = 1;
                } else if (keys) {
                    printf("You already have a key.\n");
                } else {
                    printf("You can't see anything in the dark.\n");
                }
                break;
            case 3: // turn on the power
                if (!power_on) {
                    printf("You flip on the power switch and lights come on!\n");
                    flashlight = 1;
                    power_on = 1;
                } else {
                    printf("The power is already on.\n");
                }
                break;
            case 4: // try to open the front door
                if (front_door_locked && keys) {
                    printf("You use the key to unlock the front door and enter the house.\n");
                    front_door_locked = 0;
                    door_unlocked = 1;
                } else if (front_door_locked && !keys) {
                    printf("You try to open the front door, but it's locked.\n");
                } else {
                    printf("The front door is already unlocked.\n");
                }
                break;
            case 5: // open the window
                if (!window_open) {
                    printf("You open the window and a spooky wind blows in.\n");
                    window_open = 1;
                } else {
                    printf("The window is already open.\n");
                }
                break;
            case 6: // leave the house
                printf("You decide it's best to leave the spooky house.\n");
                return 0;
                break;
            default: // invalid choice
                printf("That's not a valid choice.\n");
                break;
        }
        
        if (door_unlocked && !monster_present) {
            printf("Congratulations! You escaped the haunted house.\n");
            printf("You collected %d coins and encountered %d ghosts.\n", coins, ghosts_encountered);
            return 0;
        }
        
        int ghost_chance = rand() % 10; // random chance for ghost to appear
        
        if (flashlight && ghost_chance < 3) {
            printf("Oh no! A ghost appears and attacks you.\n");
            health -= 25;
            ghosts_encountered += 1;
        }
        
        if (health <= 0) {
            printf("You have been defeated by the haunted house.\n");
            return 0;
        }
    }
    
    return 0;
}