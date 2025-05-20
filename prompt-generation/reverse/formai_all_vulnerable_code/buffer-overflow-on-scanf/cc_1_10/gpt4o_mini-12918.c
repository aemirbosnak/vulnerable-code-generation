//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 5
#define MAX_Y 5

typedef struct {
    int x, y;
} Player;

typedef struct {
    int x, y;
    char icon;
} Monster;

void initialize_game(Player *player, Monster *monster) {
    player->x = 0;
    player->y = 0;

    monster->x = rand() % MAX_X;
    monster->y = rand() % MAX_Y;
    monster->icon = 'M';
}
 
void print_map(Player player, Monster monster) {
    printf("\n");
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (player.x == j && player.y == i) {
                printf("P ");
            } else if (monster.x == j && monster.y == i) {
                printf("%c ", monster.icon);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int move_player(Player *player, char direction) {
    switch (direction) {
        case 'w': // up
            if (player->y > 0) player->y--;
            break;
        case 's': // down
            if (player->y < MAX_Y - 1) player->y++;
            break;
        case 'a': // left
            if (player->x > 0) player->x--;
            break;
        case 'd': // right
            if (player->x < MAX_X - 1) player->x++;
            break;
        default:
            printf("Invalid move! Use w/a/s/d.\n");
            return 0;
    }
    return 1;
}

int check_collision(Player player, Monster monster) {
    return player.x == monster.x && player.y == monster.y;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    Player player;
    Monster monster;

    initialize_game(&player, &monster);

    printf("Welcome to the Quest for the Lost Jewel!\n");
    printf("Navigate the maze using 'w' (up), 's' (down), 'a' (left), 'd' (right)\n");
    printf("Avoid the monster while searching for the lost jewel!\n\n");

    while (1) {
        print_map(player, monster);
        
        char input;
        printf("Enter your move: ");
        scanf(" %c", &input);

        if (move_player(&player, input)) {
            if (check_collision(player, monster)) {
                printf("\nOh no! You have been caught by the monster! Game Over!\n");
                break;
            }
            if (player.x == MAX_X - 1 && player.y == MAX_Y - 1) {
                printf("\nCongratulations! You've found the Lost Jewel! You Win!\n");
                break;
            }
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}