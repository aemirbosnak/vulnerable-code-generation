//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ghostEncounter();
void batEncounter();
void skeletonEncounter();
void zombieEncounter();

int main() {
    srand(time(0)); // set the seed for random numbers generator
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of an old mansion.\n");
    printf("Do you dare to enter? (0 for no, 1 for yes)\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice) {
        printf("You open the big wooden door and step inside.\n");
        printf("The door closes on its own behind you with a loud noise.\n");
        
        int steps = 0;
        while (steps < 10) {
            printf("You take a step forward.\n");
            int randomNumber = rand() % 10 + 1; // generate a random number between 1 and 10
            if (randomNumber <= 2) { // 20% chance of encountering a ghost
                ghostEncounter();
                break;
            }
            else if (randomNumber <= 5) { // 30% chance of encountering a bat
                batEncounter();
            }
            else if (randomNumber <= 8) { // 30% chance of encountering a skeleton
                skeletonEncounter();
            }
            else { // 20% chance of encountering a zombie
                zombieEncounter();
            }
            
            steps++;
        }
        
        if (steps == 10) {
            printf("You have successfully escaped from the haunted house!\n");
        }
    }
    else {
        printf("You decide not to take the risk and leave.\n");
    }
    
    return 0;
}

void ghostEncounter() {
    printf("You suddenly see a ghostly figure shimmering in front of you!\n");
    printf("It starts to approach you! Do you (0) fight or (1) run?\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice) {
        printf("You turn around and run as fast as you can!\n");
    }
    else {
        printf("You try to fight the ghost with all your might!\n");
        int randomNumber = rand() % 2;
        if (randomNumber) {
            printf("The ghost disappears into thin air, leaving you alone.\n");
        }
        else {
            printf("The ghost overpowers you and you fall to the ground.\n");
        }
    }
}

void batEncounter() {
    printf("You suddenly hear a screeching sound and see a bat flying towards you!\n");
    printf("Do you (0) duck or (1) try to catch the bat?\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice) {
        printf("You jump and try to catch the bat but miss it by inches.\n");
    }
    else {
        printf("You duck just in time and the bat flies over your head.\n");
    }
}

void skeletonEncounter() {
    printf("You see a skeleton lying on the ground, its bones rattling.\n");
    printf("Do you (0) ignore it or (1) try to inspect it?\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice) {
        printf("You approach the skeleton and try to see if there is anything valuable.\n");
        int randomNumber = rand() % 2;
        if (randomNumber) {
            printf("You find a small treasure hidden inside the skull!\n");
        }
        else {
            printf("The skeleton suddenly springs to life and attacks you!\n");
        }
    }
    else {
        printf("You decide to leave the skeleton alone and move on.\n");
    }
}

void zombieEncounter() {
    printf("You suddenly hear a moaning sound and see a zombie walking towards you!\n");
    printf("Do you (0) attack it or (1) try to sneak past?\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice) {
        printf("You prepare to fight the zombie!\n");
        int randomNumber = rand() % 2;
        if (randomNumber) {
            printf("You manage to defeat the zombie with your bare hands!\n");
        }
        else {
            printf("The zombie grabs you and bites your neck, turning you into a zombie too...\n");
        }
    }
    else {
        printf("You try to sneak past the zombie, praying it won't notice you.\n");
        int randomNumber = rand() % 2;
        if (randomNumber) {
            printf("You manage to sneak past it without being seen!\n");
        }
        else {
            printf("The zombie suddenly turns its head and spots you!\n");
        }
    }
}