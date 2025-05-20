#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GameData {
    char* map;
    int width, height;
} GameData;

void load_map(GameData* game) {
    FILE* file = fopen("level.txt", "r");
    fscanf(file, "%d %d\n", &game->width, &game->height);
    game->map = (char*) malloc(game->width * game->height * sizeof(char));
    fgets(game->map, game->width * game->height, file);
    fclose(file);
}

void print_map(GameData game) {
    for (int y = 0; y < game.height; ++y) {
        for (int x = 0; x < game.width; ++x) {
            printf("%c ", game.map[y * game.width + x]);
        }
        printf("\n");
    }
}

int main() {
    GameData game;
    load_map(&game);
    print_map(game);
    return 0;
}
