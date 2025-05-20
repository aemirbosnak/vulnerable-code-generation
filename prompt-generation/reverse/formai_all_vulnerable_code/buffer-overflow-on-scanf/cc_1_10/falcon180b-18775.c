//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_menu() {
    printf("\n");
    printf("    Welcome to the Space Adventure!\n");
    printf("    Choose your option:\n");
    printf("    1. Start a new game\n");
    printf("    2. Load game\n");
    printf("    3. Quit\n");
    printf("\n");
}

void start_game() {
    int player_health = 100;
    int enemy_health = 50;

    printf("\n");
    printf("    You have started a new game!\n");
    printf("    You have %d health points.\n", player_health);
    printf("    The enemy has %d health points.\n", enemy_health);

    int player_attack = rand() % 10 + 1;
    int enemy_attack = rand() % 10 + 1;

    if (player_attack > enemy_attack) {
        enemy_health -= (player_attack - enemy_attack);
        printf("    You attacked the enemy and reduced its health by %d points.\n", player_attack - enemy_attack);
    } else if (enemy_attack > player_attack) {
        player_health -= (enemy_attack - player_attack);
        printf("    The enemy attacked you and reduced your health by %d points.\n", enemy_attack - player_attack);
    } else {
        printf("    Both you and the enemy have the same attack power.\n");
    }

    if (player_health <= 0) {
        printf("\n");
        printf("    Game Over! You lost.\n");
        exit(0);
    } else if (enemy_health <= 0) {
        printf("\n");
        printf("    Congratulations! You won.\n");
        exit(0);
    }
}

void load_game() {
    printf("\n");
    printf("    Loading game...\n");
    sleep(1);
    start_game();
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        system("clear");
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_game();
                break;
            case 2:
                load_game();
                break;
            case 3:
                printf("\n");
                printf("    Exiting...\n");
                sleep(1);
                exit(0);
            default:
                printf("\n");
                printf("    Invalid choice! Try again.\n");
                sleep(1);
        }
    } while (1);

    return 0;
}