//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_HEALTH 100
#define MAX_MONSTERS 3
#define MAX_NAME_LEN 20

void clear_screen() {
    printf("\033[H\033[J");
}

void show_title() {
    printf("===================================\n");
    printf("          WARRIOR ADVENTURE       \n");
    printf("===================================\n");
}

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
} Player;

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int damage;
} Monster;

void initialize_player(Player *player) {
    printf("Enter your character name: ");
    scanf("%s", player->name);
    player->health = MAX_HEALTH;
}

void initialize_monsters(Monster monsters[], int count) {
    const char *names[] = {"Goblin", "Orc", "Troll"};

    for (int i = 0; i < count; ++i) {
        strcpy(monsters[i].name, names[i]);
        monsters[i].health = rand() % 40 + 30;  // Random health between 30 and 70
        monsters[i].damage = rand() % 10 + 5;   // Random damage between 5 and 15
    }
}

void display_status(Player *player, Monster monsters[], int monster_count) {
    printf("\n=== Status ===\n");
    printf("Player: %s | Health: %d\n", player->name, player->health);
    for (int i = 0; i < monster_count; ++i) {
        printf("%s | Health: %d\n", monsters[i].name, monsters[i].health);
    }
    printf("=================\n");
}

void attack_monster(Player *player, Monster *monster) {
    int player_damage = rand() % 20 + 10; // Damage between 10 and 29
    monster->health -= player_damage;
    printf("%s attacks %s for %d damage!\n", player->name, monster->name, player_damage);
}

void monster_attacks(Player *player, Monster *monster) {
    player->health -= monster->damage;
    printf("%s attacks %s for %d damage!\n", monster->name, player->name, monster->damage);
}

int check_if_monster_is_alive(Monster *monster) {
    return monster->health > 0;
}

int check_if_player_is_alive(Player *player) {
    return player->health > 0;
}

void game_loop(Player *player, Monster monsters[], int monster_count) {
    while (check_if_player_is_alive(player) && monster_count > 0) {
        display_status(player, monsters, monster_count);
        
        printf("Choose a monster to attack (0 to %d): ", monster_count - 1);
        int monster_choice;
        scanf("%d", &monster_choice);
        
        if (monster_choice < 0 || monster_choice >= monster_count || !check_if_monster_is_alive(&monsters[monster_choice])) {
            printf("Invalid choice or monster already defeated. Try again!\n");
            continue;
        }

        attack_monster(player, &monsters[monster_choice]);
        if (!check_if_monster_is_alive(&monsters[monster_choice])) {
            printf("%s has been defeated!\n", monsters[monster_choice].name);
            monster_count--;
        }
        
        // Monsters attack the player
        for (int i = 0; i < MAX_MONSTERS; i++) {
            if (check_if_monster_is_alive(&monsters[i])) {
                monster_attacks(player, &monsters[i]);
            }
        }
    }

    if (!check_if_player_is_alive(player)) {
        printf("Alas, %s has fallen! Game Over!\n", player->name);
    } else {
        printf("Congratulations! You have defeated all the monsters!\n");
    }
}

int main() {
    srand(time(NULL));
    Player player;
    Monster monsters[MAX_MONSTERS];

    clear_screen();
    show_title();
    initialize_player(&player);
    initialize_monsters(monsters, MAX_MONSTERS);

    game_loop(&player, monsters, MAX_MONSTERS);

    return 0;
}