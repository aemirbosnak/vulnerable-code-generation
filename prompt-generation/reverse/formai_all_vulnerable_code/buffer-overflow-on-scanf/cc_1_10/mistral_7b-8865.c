//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEALTH_MAX 100
#define SHOCK_MIN 10
#define SHOCK_MAX 30
#define DODGE_DELAY 100000

int health = HEALTH_MAX;
int shock;
int game_over = 0;

void print_health() {
    printf("Health: %d\n", health);
}

void shock_player() {
    shock = rand() % (SHOCK_MAX - SHOCK_MIN + 1) + SHOCK_MIN;
    health -= shock;
    printf("You received a shock of %d!\n", shock);
    if (health <= 0) {
        game_over = 1;
    }
}

int main() {
    srand(time(NULL));
    int key;

    printf("Welcome to Shockwave Survival!\n");
    printf("Press any key to start the game.\n");
    getchar();

    while (!game_over) {
        print_health();
        shock_player();
        if (health > 0) {
            printf("Press S to dodge a shock (delay %ld microseconds).\n", DODGE_DELAY);
            scanf("%c", &key);
            if (key == 'S') {
                printf("You dodged a shock!\n");
            } else {
                printf("You missed the shock!\n");
                shock_player();
            }
        }
        usleep(1000000); // pause for 1 second
    }

    printf("Game Over! Your final health was: %d\n", health);

    return 0;
}