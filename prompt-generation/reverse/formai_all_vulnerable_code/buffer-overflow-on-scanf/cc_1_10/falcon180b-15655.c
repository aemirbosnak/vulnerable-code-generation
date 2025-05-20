//Falcon-180B DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player {
    char name[20];
    int score;
};

void init_game(struct Player* players) {
    srand(time(NULL));
    for (int i = 0; i < 2; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

void roll_dice() {
    int dice = rand() % 6 + 1;
    printf("Dice rolled: %d\n", dice);
}

void move_player(struct Player* players, int steps) {
    int current_position = 0;
    printf("Enter your name: ");
    scanf("%s", players[0].name);
    while (current_position < steps) {
        roll_dice();
        current_position += steps;
        if (current_position > 100) {
            printf("You reached the end! Congratulations!\n");
            break;
        }
        printf("You moved %d steps.\n", steps);
    }
}

void play_game(struct Player* players) {
    init_game(players);
    int choice;
    while (1) {
        printf("Choose an option:\n1. Roll the dice\n2. Move player\n3. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                roll_dice();
                break;
            case 2:
                move_player(players, 5);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    struct Player players[2];
    play_game(players);
    return 0;
}