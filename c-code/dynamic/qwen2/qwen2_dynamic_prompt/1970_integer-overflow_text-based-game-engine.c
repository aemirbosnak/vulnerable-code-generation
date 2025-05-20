#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void levelUp(int experience) {
    int requiredExperience = 100;
    int newLevel = experience / requiredExperience + 1;

    // Integer overflow vulnerability
    int nextRequiredExperience = requiredExperience * newLevel;

    if (nextRequiredExperience < requiredExperience) {
        printf("Congratulations! You have leveled up to %d!\n", newLevel);
    } else {
        printf("Not enough experience yet.\n");
    }
}

int main() {
    int playerExperience = -2147483648; // INT_MIN

    while (playerExperience < 2147483647) { // INT_MAX
        levelUp(playerExperience);
        playerExperience++;
    }

    return 0;
}
