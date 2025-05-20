#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 100
#define MAX_NAME 32

void print_menu();
void play_game();
void create_character();
void attack_monster();

char name[MAX_NAME];
int health, level, exp, gold;
char mon_health, mon_name[MAX_NAME];

int main() {
    print_menu();
    play_game();
    return 0;
}

void print_menu() {
    printf("**** ADVENTURE GAME ****\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Exit\n");
}

void play_game() {
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1: create_character(); break;
        case 2: printf("Load Game not implemented.\n"); break;
        case 3: exit(0);
        default: printf("Invalid option, try again.\n"); play_game();
    }
}

void create_character() {
    printf("Enter your name: ");
    scanf("%s", name);
    strcpy(mon_name, "Dragon");
    health = 100;
    mon_health = 200;
}

void attack_monster() {
    int damage = 5 * level;
    mon_health -= damage;
    printf("%s attacks %s with %d damage.\n", name, mon_name, damage);
    printf("%s has %d health left.\n", mon_name, mon_health);

    if (mon_health <= 0) {
        printf("%s has been defeated!\n", mon_name);
        gold += 100;
        printf("You have gained 100 gold.\n");
    }
}
