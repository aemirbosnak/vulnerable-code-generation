//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum {
    EMPTY, GHOST, ZOMBIE, VAMPIRE, WEREWOLF
} Monster;

typedef struct {
    char name[50];
    int health;
    int score;
} Player;

void print_haunted_house(Monster house[5][5]) {
    printf("\nHaunted House Layout:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            switch(house[i][j]) {
                case EMPTY:   printf("[ ]"); break;
                case GHOST:   printf("[G]"); break;
                case ZOMBIE:  printf("[Z]"); break;
                case VAMPIRE: printf("[V]"); break;
                case WEREWOLF:printf("[W]"); break;
            }
        }
        printf("\n");
    }
}

void setup_game(Player *player, Monster house[5][5]) {
    printf("Enter your hero's name: ");
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline

    player->health = 100;
    player->score = 0;

    // Randomly fill the haunted house with monsters
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            house[i][j] = rand() % 5; // random monster
        }
    }
}

void encounter_monster(Player *player, Monster monster) {
    switch(monster) {
        case GHOST: 
            printf("%s encounters a GHOST! Boo!\n", player->name);
            player->health -= 10;
            player->score += 20;
            break;
        case ZOMBIE: 
            printf("%s sees a ZOMBIE! Brainssss!\n", player->name);
            player->health -= 20;
            player->score += 30;
            break;
        case VAMPIRE: 
            printf("%s meets a VAMPIRE! Fangs out!\n", player->name);
            player->health -= 30;
            player->score += 40;
            break;
        case WEREWOLF: 
            printf("%s is chased by a WEREWOLF! Run!\n", player->name);
            player->health -= 40;
            player->score += 50;
            break;
        case EMPTY: 
            printf("%s has found an EMPTY ROOM! What a bore...\n", player->name);
            break;
    }
}

int main() {
    Player player;
    Monster house[5][5];

    setup_game(&player, house);
    print_haunted_house(house);

    while (player.health > 0) {
        int x, y;
        printf("\nChoose your next room! Enter coordinates (row column): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= 5 || y < 0 || y >= 5) {
            printf("That's not a valid room! Try again.\n");
            continue;
        }

        encounter_monster(&player, house[x][y]);
        house[x][y] = EMPTY; // Clear the room after entering

        printf("%s's Status: Health = %d, Score = %d\n", player.name, player.health, player.score);

        if (player.health <= 0) {
            printf("%s has gone to the great haunted house in the sky...\n", player.name);
            break;
        }

        char choice;
        printf("Do you want to keep exploring? (y/n): ");
        getchar(); // to consume the newline character left by scanf
        choice = getchar();

        if (choice == 'n') {
            printf("You decided to leave the haunted house. Good for your health!\n");
            break;
        }
    }

    printf("Thank you for playing, %s! Your final score is %d.\n", player.name, player.score);
    return 0;
}