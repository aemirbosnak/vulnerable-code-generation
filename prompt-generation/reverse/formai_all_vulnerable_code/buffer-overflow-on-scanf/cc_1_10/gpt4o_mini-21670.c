//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int alive;
    int level;
    char name[50];
} Player;

void* adventure(void* arg);
void display_intro();
void handle_choice(int choice, Player* player);
void game_over(Player* player);
void victory(Player* player);

int main() {
    pthread_t thread;
    Player player;

    player.alive = TRUE;
    player.level = 1;

    printf("Enter your character's name: ");
    scanf("%s", player.name);

    display_intro();

    if (pthread_create(&thread, NULL, adventure, (void*)&player) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }

    pthread_join(thread, NULL);
    return EXIT_SUCCESS;
}

void* adventure(void* arg) {
    Player* player = (Player*)arg;
    int choice;
    
    while (player->alive) {
        printf("\nYou are in the haunted castle (Level %d).\n", player->level);
        printf("You can: 1) Explore a room  2) Go down a corridor  3) Check your inventory\n");
        
        printf("What will you do? ");
        scanf("%d", &choice);

        handle_choice(choice, player);
    }

    game_over(player);
    return NULL;
}

void display_intro() {
    printf("Welcome to the Haunted Castle!\n");
    printf("You must navigate through various levels to escape. Good luck!\n");
}

void handle_choice(int choice, Player* player) {
    switch (choice) {
        case 1:
            printf("You explore a room filled with mysterious artifacts.\n");
            if (rand() % 2 == 0) {
                printf("You find a potion that makes you stronger!\n");
                player->level++;
            } else {
                printf("A ghost appears! You lose a life.\n");
                player->alive = FALSE;
            }
            break;
        case 2:
            printf("You go down a dimly lit corridor.\n");
            if (rand() % 2 == 0) {
                printf("You discover a hidden passage that leads you to the next level.\n");
                player->level++;
            } else {
                printf("You fall into a trap and get injured!\n");
                player->alive = FALSE;
            }
            break;
        case 3:
            printf("You check your inventory. It's empty!\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}

void game_over(Player* player) {
    printf("\nGame Over! %s, you didn't make it out of the castle.\n", player->name);
    printf("You reached Level: %d\n", player->level);
}

void victory(Player* player) {
    printf("\nCongratulations %s! You have successfully escaped the haunted castle!\n", player->name);
    printf("You reached Level: %d\n", player->level);
}