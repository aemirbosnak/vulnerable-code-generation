//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 256

typedef struct {
    char name[MAX_NAME_LEN];
    int credits;
    int health;
} Player;

typedef struct {
    char description[MAX_DESC_LEN];
    int risk;
    int reward;
} Location;

void clear_screen() {
    printf("\033[H\033[J");
}

void show_intro() {
    printf("****************************************\n");
    printf("*          WELCOME TO NEO CITY!        *\n");
    printf("****************************************\n");
    printf("In a world where mega-corporations reign, you must\n");
    printf("navigate through the neon-lit streets to survive.\n");
    printf("Acquire credits to escape Neo City before it's too late!\n");
    printf("****************************************\n\n");
}

void initialize_player(Player *player) {
    printf("Enter your name: ");
    fgets(player->name, MAX_NAME_LEN, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline character
    player->credits = 0;
    player->health = 100;
}

void show_status(Player player) {
    printf("\n---- Player Status ----\n");
    printf("Name: %s\n", player.name);
    printf("Credits: %d\n", player.credits);
    printf("Health: %d\n", player.health);
    printf("-----------------------\n");
}

Location generate_location() {
    Location loc;
    int rand_value = rand() % 3;

    switch(rand_value) {
        case 0:
            strcpy(loc.description, "Black Market - Risky dealings may yield high rewards.");
            loc.risk = 30;
            loc.reward = 100;
            break;
        case 1:
            strcpy(loc.description, "Corporate Tower - Infiltrate for some serious cash.");
            loc.risk = 50;
            loc.reward = 200;
            break;
        case 2:
            strcpy(loc.description, "Cybernetic Clinic - Upgrade yourself for a price.");
            loc.risk = 20;
            loc.reward = 50;
            break;
    }
    return loc;
}

void explore(Player *player) {
    Location loc = generate_location();
    printf("\nYou arrive at: %s\n", loc.description);
    printf("Risk Level: %d \t Potential Reward: %d\n", loc.risk, loc.reward);
    printf("What will you do? (1: Risk It, 2: Leave): ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        int outcome = rand() % 100;
        if (outcome < loc.risk) {
            player->health -= 20;
            printf("You faced a dangerous situation! Your health is now %d.\n", player->health);
        } else {
            player->credits += loc.reward;
            printf("You succeeded! You earned %d credits.\n", loc.reward);
        }
    } else {
        printf("You chose to leave the area unscathed.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Player player;
    char choice;

    clear_screen();
    show_intro();
    initialize_player(&player);

    while (player.health > 0) {
        clear_screen();
        show_status(player);
        printf("Do you want to explore? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            explore(&player);
        } else {
            printf("You decide to stay safe for now.\n");
        }
        
        if (player.credits >= 500) {
            printf("Congratulations! You have enough credits to escape Neo City!\n");
            break;
        }

        if (player.health <= 0) {
            printf("You have lost all your health. Game Over!\n");
            break;
        }
    }

    printf("Thank you for playing, %s. See you next time!\n", player.name);
    return 0;
}