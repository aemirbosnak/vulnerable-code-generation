#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_level(int level) {
    int max_level = 100;
    if (level > max_level) {
        printf("Level %d exceeds maximum allowed level.\n", level);
        return;
    }
    int experience_points = level * 1000;
    int bonus_points = 2 * experience_points; // Integer overflow vulnerability here

    printf("Player gained %d experience points and %d bonus points.\n", experience_points, bonus_points);
}

int main() {
    int user_input;
    printf("Enter your current level: ");
    scanf("%d", &user_input);

    process_level(user_input);

    return 0;
}
