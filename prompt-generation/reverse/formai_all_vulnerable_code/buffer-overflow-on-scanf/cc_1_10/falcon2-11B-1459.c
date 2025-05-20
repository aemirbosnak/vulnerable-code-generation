//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x;
    int y;
    int direction;
} Player;

typedef struct {
    int x;
    int y;
} Food;

typedef struct {
    int x;
    int y;
    int score;
} Score;

typedef struct {
    Player player;
    Food food[10];
    Score score[10];
} Game;

void init_game(Game *game) {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        game->food[i].x = rand() % WIDTH;
        game->food[i].y = rand() % HEIGHT;
    }

    game->player.x = rand() % WIDTH;
    game->player.y = rand() % HEIGHT;
    game->player.direction = 0;
    game->score[0].score = 0;
}

void draw_game(Game *game) {
    printf("    A B C D E F G H I J\n");
    printf("  +---------+---------+\n");
    printf("  | %d | %d | %d | %d | %d | %d |\n", game->player.x, game->player.y, game->food[0].x, game->food[0].y, game->food[1].x, game->food[1].y);
    printf("  +---------+---------+\n");
    printf("  | %d | %d | %d | %d | %d | %d |\n", game->food[2].x, game->food[2].y, game->food[3].x, game->food[3].y, game->food[4].x, game->food[4].y);
    printf("  +---------+---------+\n");
    printf("  | %d | %d | %d | %d | %d | %d |\n", game->food[5].x, game->food[5].y, game->food[6].x, game->food[6].y, game->food[7].x, game->food[7].y);
    printf("  +---------+---------+\n");
    printf("  | %d | %d | %d | %d | %d | %d |\n", game->food[8].x, game->food[8].y, game->food[9].x, game->food[9].y, game->player.x, game->player.y);
    printf("  +---------+---------+\n");
    printf("    A B C D E F G H I J\n");
}

int main() {
    Game game;
    init_game(&game);

    while (1) {
        draw_game(&game);
        printf("Score: %d\n", game.score[0].score);
        printf("Enter your command: ");
        char command[10];
        scanf("%s", command);

        if (command[0] == 'w') {
            if (game.player.y - 1 >= 0) {
                game.player.y--;
                game.player.direction = 0;
            }
        } else if (command[0] == 'a') {
            if (game.player.x - 1 >= 0) {
                game.player.x--;
                game.player.direction = 1;
            }
        } else if (command[0] =='s') {
            if (game.player.y + 1 < HEIGHT) {
                game.player.y++;
                game.player.direction = 0;
            }
        } else if (command[0] == 'd') {
            if (game.player.x + 1 < WIDTH) {
                game.player.x++;
                game.player.direction = 1;
            }
        } else {
            printf("Invalid command!\n");
        }

        for (int i = 0; i < 10; i++) {
            if (game.food[i].x == game.player.x && game.food[i].y == game.player.y) {
                game.score[0].score++;
                printf("Score: %d\n", game.score[0].score);
            }
        }
    }

    return 0;
}