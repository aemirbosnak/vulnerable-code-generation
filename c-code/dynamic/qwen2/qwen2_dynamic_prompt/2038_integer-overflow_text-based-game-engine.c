#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void levelUp(int *level) {
    (*level)++;
}

int main() {
    int playerLevel = 1;
    printf("Player Level: %d\n", playerLevel);

    // Simulate leveling up multiple times to cause overflow
    for (int i = 0; i < 2000000000; i++) {
        levelUp(&playerLevel);
    }

    printf("Player Level: %d\n", playerLevel);

    return 0;
}
