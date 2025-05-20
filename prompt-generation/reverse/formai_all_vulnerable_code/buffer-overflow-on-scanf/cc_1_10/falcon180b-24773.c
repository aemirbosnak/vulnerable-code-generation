//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int player_health = 100;
int enemy_health = 50;
int player_attack = 10;
int enemy_attack = 5;
int choice;
int random_number;

// Function prototypes
void start_game();
void display_menu();
void move_player(int direction);
void fight_enemy();
void check_health();

int main() {
    srand(time(0));
    start_game();
    return 0;
}

void start_game() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave warrior on a quest to defeat the evil enemy.\n");
    printf("Use the arrow keys to move and press enter to attack.\n");
    display_menu();
}

void display_menu() {
    printf("\n");
    printf("1. Move Up\n");
    printf("2. Move Down\n");
    printf("3. Move Left\n");
    printf("4. Move Right\n");
    printf("5. Attack\n");
    printf("6. Quit\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            move_player(1);
            break;
        case 2:
            move_player(2);
            break;
        case 3:
            move_player(3);
            break;
        case 4:
            move_player(4);
            break;
        case 5:
            fight_enemy();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void move_player(int direction) {
    printf("\n");
    printf("You moved %s.\n", direction == 1? "up" : direction == 2? "down" : direction == 3? "left" : "right");
    check_health();
}

void fight_enemy() {
    printf("\n");
    printf("You attacked the enemy!\n");
    int damage = player_attack - enemy_attack;
    if(damage > 0) {
        printf("You dealt %d damage to the enemy.\n", damage);
        enemy_health -= damage;
        check_health();
    } else {
        printf("The enemy blocked your attack.\n");
    }
}

void check_health() {
    printf("\n");
    if(player_health <= 0) {
        printf("You died. Game over.\n");
        exit(0);
    } else if(enemy_health <= 0) {
        printf("You defeated the enemy! You win!\n");
        exit(0);
    }
}