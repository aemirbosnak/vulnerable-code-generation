//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct game_object {
    int x;
    int y;
    int width;
    int height;
    char* name;
};

struct game_object player;
struct game_object bullet;
struct game_object power_up;

void init_game() {
    srand(time(NULL));
    player.x = 10;
    player.y = 10;
    player.width = 20;
    player.height = 20;
    player.name = "Player";
    bullet.x = player.x;
    bullet.y = player.y;
    bullet.width = 2;
    bullet.height = 2;
    bullet.name = "Bullet";
    power_up.x = 100;
    power_up.y = 100;
    power_up.width = 10;
    power_up.height = 10;
    power_up.name = "Power-Up";
}

void move_player(char dir) {
    if (dir == 'w') {
        player.y -= 1;
    } else if (dir =='s') {
        player.y += 1;
    } else if (dir == 'a') {
        player.x -= 1;
    } else if (dir == 'd') {
        player.x += 1;
    }
}

void shoot_bullet() {
    bullet.x = player.x;
    bullet.y = player.y;
}

void pickup_power_up() {
    power_up.x = player.x;
    power_up.y = player.y;
}

int is_game_over() {
    if (player.x > 100 || player.x < 0 || player.y > 100 || player.y < 0) {
        return 1;
    }
    if (bullet.x > 100 || bullet.x < 0 || bullet.y > 100 || bullet.y < 0) {
        return 1;
    }
    if (power_up.x > 100 || power_up.x < 0 || power_up.y > 100 || power_up.y < 0) {
        return 1;
    }
    return 0;
}

int is_game_won() {
    if (is_game_over()) {
        return 1;
    }
    if (power_up.x == player.x && power_up.y == player.y) {
        power_up.x = rand() % 100 + 1;
        power_up.y = rand() % 100 + 1;
        return 1;
    }
    return 0;
}

void display_screen() {
    printf("Player: %c %c\n", player.name[0], player.name[1]);
    printf("Bullet: %c %c\n", bullet.name[0], bullet.name[1]);
    printf("Power-Up: %c %c\n", power_up.name[0], power_up.name[1]);
}

int main() {
    init_game();
    while (!is_game_over()) {
        printf("Movements: w, s, a, d\n");
        printf("1. Move player\n");
        printf("2. Shoot bullet\n");
        printf("3. Pickup power-up\n");
        printf("4. Display screen\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Which direction do you want to move?\n");
                char dir;
                scanf(" %c", &dir);
                move_player(dir);
                break;
            case 2:
                shoot_bullet();
                break;
            case 3:
                pickup_power_up();
                break;
            case 4:
                display_screen();
                break;
        }
    }
    if (is_game_won()) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
    return 0;
}