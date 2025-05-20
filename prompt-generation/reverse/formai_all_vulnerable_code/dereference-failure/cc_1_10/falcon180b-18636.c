//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random string of length n
char* rand_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[n] = '\0';
    return str;
}

int main() {
    srand(time(NULL));

    // Generate a random character
    char* name = rand_string(rand_range(3, 6));
    printf("Your name is %s.\n", name);

    // Generate a random dungeon
    int width = rand_range(10, 20);
    int height = rand_range(5, 10);
    char** dungeon = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        dungeon[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            dungeon[i][j] = rand() % 2? '#' : '.';
        }
    }

    // Print the dungeon
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < height; i++) {
        free(dungeon[i]);
    }
    free(dungeon);

    return 0;
}