//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_ATTEMPTS 1000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point location;
    int health;
} Alien;

Alien aliens[MAX_ALIENS];
int num_aliens;

void init_aliens() {
    srand(time(NULL));
    num_aliens = rand() % MAX_ALIENS + 1;
    for (int i = 0; i < num_aliens; i++) {
        aliens[i].location.x = rand() % 1000;
        aliens[i].location.y = rand() % 1000;
        aliens[i].health = rand() % 100 + 1;
    }
}

int attack_alien(int x, int y) {
    for (int i = 0; i < num_aliens; i++) {
        if (aliens[i].location.x == x && aliens[i].location.y == y) {
            aliens[i].health--;
            if (aliens[i].health <= 0) {
                return 1;
            }
            return 0;
        }
    }
    return -1;
}

int main() {
    init_aliens();

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        int x, y;
        printf("Enter coordinates to attack (0-999): ");
        scanf("%d %d", &x, &y);
        int result = attack_alien(x, y);
        if (result == 1) {
            printf("Alien destroyed!\n");
        } else if (result == 0) {
            printf("Alien damaged.\n");
        } else {
            printf("No alien found.\n");
        }
        attempts++;
    }

    return 0;
}