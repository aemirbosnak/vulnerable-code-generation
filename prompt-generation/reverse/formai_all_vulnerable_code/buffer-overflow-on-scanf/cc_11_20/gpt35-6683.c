//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    int choice = 0;
    int health = 100;
    int ammo = 5;
    int food = 2;
    
    printf("Welcome to the Post-Apocalyptic Adventure Game!\n");
    printf("You find yourself in a barren wasteland, surrounded by rubble and debris.\n");
    printf("Your objective is to survive and find a way to a safe haven.\n");
    
    while(choice != 4) {
        printf("\n\nWhat would you like to do?\n");
        printf("1. Search for supplies\n");
        printf("2. Explore the area\n");
        printf("3. Rest and recover\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("\nYou start scavenging for supplies...\n");
            int random = rand() % 3;
            if(random == 0) {
                printf("You found a can of beans!\n");
                food++;
            } else if(random == 1) {
                printf("You found a bottle of water!\n");
                health += 10;
            } else {
                printf("You found a box of ammo!\n");
                ammo += 5;
            }
        } else if(choice == 2) {
            printf("\nYou start exploring the area...\n");
            int random = rand() % 3;
            if(random == 0) {
                printf("You encounter a group of raiders!\n");
                if(ammo > 0) {
                    printf("You have ammo and can defend yourself!\n");
                    ammo--;
                    printf("You killed one raider and scared off the rest.\n");
                } else {
                    printf("You have no ammo and are defenseless!\n");
                    printf("The raiders steal your remaining supplies and leave you wounded.\n");
                    health -= 25;
                }
            } else if(random == 1) {
                printf("You come across an abandoned building...\n");
                printf("You find some medical supplies and apply them to your wounds.\n");
                health += 50;
            } else {
                printf("You stumble upon a hidden cave...\n");
                printf("Inside, you find a map that shows the direction to a safe haven!\n");
            }
        } else if(choice == 3) {
            printf("\nYou rest and recover...\n");
            health += 25;
        } else if(choice == 4) {
            break;
        } else {
            printf("\nInvalid choice, please try again.\n");
        }
        
        if(health <= 0) {
            printf("\nYou have died.\n");
            break;
        } else if(food <= 0) {
            printf("\nYou have run out of food and cannot survive.\n");
            break;
        } else if(ammo <= 0) {
            printf("\nYou have run out of ammo and are defenseless.\n");
        } else if(health >= 150) {
            printf("\nYou have fully recovered.\n");
        }
    }
    
    printf("\nThank you for playing!\n");
    return 0;
}