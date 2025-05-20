//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print game logo
void print_logo() {
    printf("\n");
    printf("  ______                     _   _               _             \n");
    printf(" / _____)                   (_) | |             (_)            \n");
    printf("( (____   ___   ____  ____   _  | |  _   _  ___  _  _ __   ___\n");
    printf(" \\____ \\ / _ \\ |    \\|  _ \\ | | | | | | | |/___)| || '_ \\ /___)\n");
    printf(" _____) ) |_| || | | | | | || | | | |_| |___ | || | | |___ |\n");
    printf("(__)___/ \\___/ |_|_|_|_| |_||_| |_|(____/(___/ |_| |_|___/\n");
    printf("\n");
}

// Function to generate random number between min and max
int random_number(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

// Function to print player status
void print_status(int score, int health, int ammo, int aliens_killed) {
    printf("SCORE: %d     HEALTH: %d     AMMO: %d     ALIENS KILLED: %d\n", score, health, ammo, aliens_killed);
}

// Function to handle player's attack
void attack(int* health, int* ammo, int* aliens_killed) {
    int hit_chance = random_number(1, 10);
    if (hit_chance <= 7) {
        printf("Your attack was successful! You killed an alien.\n");
        (*aliens_killed)++;
    } else {
        printf("Oh no! Your attack missed.\n");
    }
    (*ammo)--;
    if (*ammo == 0) {
        printf("You are out of ammo!\n");
    }
}

// Function to handle alien's attack
void alien_attack(int* health) {
    int hit_chance = random_number(1, 10);
    if (hit_chance <= 7) {
        printf("You were hit by the alien! You lose 10 health.\n");
        (*health) -= 10;
    } else {
        printf("Phew! The alien's attack missed.\n");
    }
}

int main() {
    // Set up random seed
    srand(time(NULL));
    
    // Print game logo
    print_logo();
    
    // Set up player status
    int score = 0;
    int health = 100;
    int ammo = 10;
    int aliens_killed = 0;
    
    // Start game loop
    while (health > 0) {
        // Print player status
        print_status(score, health, ammo, aliens_killed);
        
        // Ask player for input
        printf("What do you want to do? (a=attack, r=run) ");
        char choice;
        scanf("%c", &choice);
        
        // Handle player's choice
        switch (choice) {
            case 'a':
                if (ammo > 0) {
                    printf("You aim your laser gun at the alien...\n");
                    attack(&health, &ammo, &aliens_killed);
                    if (aliens_killed % 5 == 0) {
                        printf("Congratulations! You have reached a new level.\n");
                        score += 100;
                        health += 30;
                        ammo += 5;
                    }
                } else {
                    printf("You are out of ammo!\n");
                }
                break;
            case 'r':
                printf("You turn and run away. Coward!\n");
                score -= 50;
                aliens_killed = 0;
                break;
            default:
                printf("Invalid choice. You lost your turn.\n");
        }
        
        // Alien's turn
        printf("An alien starts running towards you...\n");
        alien_attack(&health);
    }
    
    // Game over
    printf("\n");
    printf("GAME OVER\n");
    print_status(score, health, ammo, aliens_killed);
    printf("Better luck next time!\n");
    
    return 0;
}