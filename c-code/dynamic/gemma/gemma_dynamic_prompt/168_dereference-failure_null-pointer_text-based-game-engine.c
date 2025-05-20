#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **game_map = NULL;
    game_map = malloc(10 * sizeof(char *));
    for (int x = 0; x < 10; x++)
    {
        game_map[x] = malloc(10 * sizeof(char));
    }

    game_map[0][0] = 'A';
    game_map[0][1] = 'B';
    game_map[1][0] = 'C';

    char character = 'H';
    game_map[0][0] = character;

    printf("%c", game_map[0][0]);
    printf("%c", game_map[0][1]);
    printf("%c", game_map[1][0]);

    free(game_map);
    return 0;
}
