//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t lock;
int game_over = 0;
int score = 0;

typedef struct Player {
    char name[20];
    int health;
    int damage;
} Player;

typedef struct Enemy {
    char name[20];
    int health;
    int damage;
} Enemy;

void battle(Player* player, Enemy* enemy) {
    while (player->health > 0 && enemy->health > 0) {
        pthread_mutex_lock(&lock);
        printf("%s's health: %d\n", player->name, player->health);
        printf("%s's health: %d\n", enemy->name, enemy->health);
        pthread_mutex_unlock(&lock);
        int damage = rand() % player->damage;
        enemy->health -= damage;
        pthread_mutex_lock(&lock);
        printf("%s attacks %s for %d damage.\n", player->name, enemy->name, damage);
        pthread_mutex_unlock(&lock);
        if (enemy->health <= 0) {
            pthread_mutex_lock(&lock);
            printf("%s defeated %s!\n", player->name, enemy->name);
            score += 1;
            pthread_mutex_unlock(&lock);
            return;
        }
        damage = rand() % enemy->damage;
        player->health -= damage;
        pthread_mutex_lock(&lock);
        printf("%s attacks %s for %d damage.\n", enemy->name, player->name, damage);
        pthread_mutex_unlock(&lock);
        if (player->health <= 0) {
            pthread_mutex_lock(&lock);
            printf("%s's health reaches 0!\n", player->name);
            game_over = 1;
            pthread_mutex_unlock(&lock);
            return;
        }
    }
}

void* game_thread(void* arg) {
    Player* player = (Player*)arg;
    Enemy enemy = {"Goblin", 30, 10};
    while (!game_over) {
        battle(player, &enemy);
        pthread_mutex_lock(&lock);
        printf("%s's score: %d\n", player->name, score);
        pthread_mutex_unlock(&lock);
        if (!game_over) {
            player->health += 10;
            pthread_mutex_lock(&lock);
            printf("%s found a health potion and restored 10 health!\n", player->name);
            pthread_mutex_unlock(&lock);
        }
        if (score >= 5) {
            pthread_mutex_lock(&lock);
            printf("%s has won the game!\n", player->name);
            game_over = 1;
            pthread_mutex_unlock(&lock);
        }
        enemy.health = 30 + (score * 5);
        enemy.damage = 10 + (score * 2);
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t thread;
    Player player = {"Bob", 100, 20};
    pthread_mutex_init(&lock, NULL);
    pthread_create(&thread, NULL, game_thread, (void*)&player);
    while (!game_over) {
        char input[20];
        pthread_mutex_lock(&lock);
        printf("Enter a command: ");
        fgets(input, 20, stdin);
        pthread_mutex_unlock(&lock);
        if (input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
        if (strcmp(input, "exit") == 0) {
            pthread_mutex_lock(&lock);
            printf("Exiting game...\n");
            game_over = 1;
            pthread_mutex_unlock(&lock);
        }
        if (strcmp(input, "help") == 0) {
            pthread_mutex_lock(&lock);
            printf("Commands:\n");
            printf("help - displays this help message\n");
            printf("exit - exits the game\n");
            printf("score - displays your current score\n");
            printf("health - displays your current health\n");
            pthread_mutex_unlock(&lock);
        }
        if (strcmp(input, "score") == 0) {
            pthread_mutex_lock(&lock);
            printf("Score: %d\n", score);
            pthread_mutex_unlock(&lock);
        }
        if (strcmp(input, "health") == 0) {
            pthread_mutex_lock(&lock);
            printf("Health: %d\n", player.health);
            pthread_mutex_unlock(&lock);
        }
    }
    pthread_join(thread, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}