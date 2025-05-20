//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_OPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int energy;
    int happiness;
} Player;

void welcome(Player *player) {
    printf("Welcome to the Peaceful Journey Adventure!\n");
    printf("Please enter your name: ");
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = '\0'; // Remove the newline
    player->energy = 100;
    player->happiness = 100;
}

void take_a_walk(Player *player) {
    printf("\nYou decide to take a walk in the serene forest.\n");
    printf("As you stroll, you feel the gentle breeze and hear the birds singing.\n");
    player->energy -= 10;
    player->happiness += 20;
    printf("Your energy: %d\nYour happiness: %d\n", player->energy, player->happiness);
}

void have_a_picnic(Player *player) {
    printf("\nYou find a beautiful spot and set up a lovely picnic.\n");
    printf("You enjoy fresh fruits and your favorite sandwich while basking in the sun.\n");
    player->energy -= 15;
    player->happiness += 30;
    printf("Your energy: %d\nYour happiness: %d\n", player->energy, player->happiness);
}

void meditate(Player *player) {
    printf("\nYou sit cross-legged and start meditating.\n");
    printf("You feel your mind becoming tranquil and your heart light.\n");
    player->energy += 20;
    player->happiness += 10;
    printf("Your energy: %d\nYour happiness: %d\n", player->energy, player->happiness);
}

void rest(Player *player) {
    printf("\nYou find a nice spot to rest under the shade of a tree.\n");
    printf("You close your eyes and listen to the soothing sounds of nature.\n");
    player->energy += 30;
    player->happiness += 5;
    printf("Your energy: %d\nYour happiness: %d\n", player->energy, player->happiness);
}

void display_menu(Player *player) {
    printf("\n--- Menu ---\n");
    printf("1. Take a Walk\n");
    printf("2. Have a Picnic\n");
    printf("3. Meditate\n");
    printf("4. Rest\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    Player player;
    int option;

    welcome(&player);

    while (1) {
        display_menu(&player);
        scanf("%d", &option);
        
        if (option < 1 || option > 5) {
            printf("Invalid option. Please select a valid number.\n");
            continue;
        }
        
        if (option == 5) {
            printf("Thank you for playing, %s! Have a peaceful day!\n", player.name);
            break;
        }

        if (player.energy <= 0) {
            printf("You are too tired to continue. Please rest.\n");
            continue;
        }

        switch (option) {
            case 1:
                take_a_walk(&player);
                break;
            case 2:
                have_a_picnic(&player);
                break;
            case 3:
                meditate(&player);
                break;
            case 4:
                rest(&player);
                break;
        }

        if (player.happiness >= 150) {
            printf("Congratulations! You are truly happy and at peace! Thank you for playing.\n");
            break;
        }
    }

    return 0;
}