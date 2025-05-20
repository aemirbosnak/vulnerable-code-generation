//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void start_game();
void play_game();
void end_game();
void cave();
void forest();
void mountain();
void boss();

int health = 100;
int random_damage;
int has_sword = 0;
char name[20];

int main() {
    start_game();
    return 0;
}

void start_game() {
    printf("\nWelcome to the adventure game!\n");
    printf("\nWhat is your name? ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("\nHello, %s! Let's begin the game!\n", name);
    play_game();
}

void play_game() {
    int choice;
    printf("\nYou are in the middle of a forest.\n");
    printf("\nWhat do you want to do?\n");
    printf("1. Go to the cave\n");
    printf("2. Go to the mountain\n");
    printf("3. Stay in the forest\n");
    printf("4. End the game\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            cave();
            break;
        case 2:
            mountain();
            break;
        case 3:
            forest();
            break;
        case 4:
            end_game();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            play_game();
    }
}

void cave() {
    printf("\nYou have entered a dark cave.\n");
    if (has_sword == 0) {
        printf("\nYou see a sword lying on the ground. Do you want to pick it up?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nYou have picked up the sword!\n");
                has_sword = 1;
                break;
            case 2:
                printf("\nYou have chosen not to pick up the sword.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                cave();
        }
    }
    printf("\nYou hear a noise coming from the back of the cave. Do you want to investigate?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            if (has_sword == 1) {
                printf("\nYou encounter a monster!\n");
                while (health > 0) {
                    printf("\nYour health: %d\n", health);
                    printf("The monster's health: 100\n");
                    printf("\nWhat do you want to do?\n");
                    printf("1. Attack\n");
                    printf("2. Defend\n");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            srand(time(0));
                            random_damage = rand() % 20 + 1;
                            printf("\nYou attack the monster and deal %d damage!\n", random_damage);
                            health -= 10;
                            printf("The monster attacks you and deals 10 damage!\n");
                            break;
                        case 2:
                            printf("\nYou block the monster's attack and take no damage.\n");
                            break;
                        default:
                            printf("\nInvalid choice. Please try again.\n");
                    }
                }
                printf("\nYou have defeated the monster!\n");
                play_game();
            } else {
                printf("\nYou encounter a monster!\n");
                printf("\nYou don't have any weapon. You can't defend yourself!\n");
                printf("\nThe monster kills you!\n");
                end_game();
            }
            break;
        case 2:
            printf("\nYou chose not to investigate the noise.\n");
            play_game();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            cave();
    }
}

void forest() {
    printf("\nYou are staying in the forest.\n");
    printf("\nNothing interesting happens.\n");
    play_game();
}

void mountain() {
    printf("\nYou have climbed up the mountain.\n");
    printf("\nYou find a treasure chest!\n");
    printf("1. Open the chest\n");
    printf("2. Ignore it and climb back down\n");
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\nYou open the chest and find a health potion! Your health is now restored to 100.\n");
            health = 100;
            play_game();
            break;
        case 2:
            printf("\nYou have chosen not to open the chest.\n");
            play_game();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            mountain();
    }
}

void end_game() {
    printf("\nThank you for playing the game!\n");
    printf("Your final health: %d\n", health);
    exit(0);
}