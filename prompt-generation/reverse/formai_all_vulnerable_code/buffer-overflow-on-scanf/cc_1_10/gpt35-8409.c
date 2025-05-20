//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t player_thread; // thread for player actions
pthread_t enemy_thread; // thread for enemy actions

int player_health = 100; // initialize player health
int enemy_health = 50; // initialize enemy health
int player_attack = 20; // player attack value
int enemy_attack = 10; // enemy attack value

// function for player actions
void* player_actions(void* arg) {
    while (player_health > 0 && enemy_health > 0) {
        printf("Select an action:\n1. Attack\n2. Heal\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Player attacks enemy!\n");
                enemy_health -= player_attack;
                break;
            case 2:
                printf("Player heals!\n");
                player_health += 20;
                if (player_health > 100) {
                    player_health = 100;
                }
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    pthread_exit(NULL);
}

// function for enemy actions
void* enemy_actions(void* arg) {
    while (player_health > 0 && enemy_health > 0) {
        printf("Enemy attacks player!\n");
        player_health -= enemy_attack;
        if (player_health <= 0) {
            printf("Game over! Enemy wins!\n");
            exit(0);
        }
    }
    pthread_exit(NULL);
}

int main() {
    printf("Welcome to the adventure game!\n");
    pthread_create(&player_thread, NULL, player_actions, NULL);
    pthread_create(&enemy_thread, NULL, enemy_actions, NULL);
    pthread_join(player_thread, NULL);
    pthread_join(enemy_thread, NULL);
    printf("Game over! Player wins!\n");
    return 0;
}