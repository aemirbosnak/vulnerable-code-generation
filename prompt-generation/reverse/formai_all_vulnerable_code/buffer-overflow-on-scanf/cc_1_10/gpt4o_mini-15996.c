//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SECTORS 5
#define SHAPES 4

typedef enum {
    ASTEROID,
    ALIEN,
    BLACK_HOLE,
    SPACE_CLOUD
} Obstacle;

typedef enum {
    HUMAN,
    ROBOT,
    SPACESHIP,
    ALIEN_BEING
} Shape;

const char* shape_names[] = {
    "Human",
    "Robot",
    "Spaceship",
    "Alien Being"
};

const char* obstacle_names[] = {
    "Asteroid Field",
    "Alien Encounter",
    "Black Hole",
    "Space Cloud"
};

void print_welcome() {
    printf("Welcome to Space Adventure!\n");
    printf("You are a shape-shifter navigating through space.\n");
    printf("Choose your shape wisely to overcome obstacles!\n\n");
}

void print_current_sector(int sector) {
    printf("You have entered sector %d.\n", sector);
}

int encounter_obstacle() {
    return rand() % SHAPES;
}

void choose_shape(Shape* player_shape) {
    printf("Choose your shape:\n");
    for (int i = 0; i < SHAPES; i++) {
        printf("%d. %s\n", i + 1, shape_names[i]);
    }
    int choice;
    printf("Enter choice (1-%d): ", SHAPES);
    scanf("%d", &choice);
    *player_shape = (Shape)(choice - 1);
}

int resolve_obstacle(Shape player_shape, Obstacle obstacle) {
    switch (obstacle) {
        case ASTEROID:
            return player_shape == SPACESHIP;
        case ALIEN:
            return player_shape == HUMAN || player_shape == ROBOT;
        case BLACK_HOLE:
            return player_shape == SPACESHIP;
        case SPACE_CLOUD:
            return player_shape == ALIEN_BEING || player_shape == SPACESHIP;
        default:
            return 0;
    }
}

int main() {
    srand(time(NULL));
    Shape player_shape;
    int survived = 1;

    print_welcome();

    for (int sector = 1; sector <= SECTORS && survived; sector++) {
        print_current_sector(sector);
        
        choose_shape(&player_shape);
        
        Obstacle obstacle = encounter_obstacle();
        printf("You encountered a %s!\n", obstacle_names[obstacle]);

        if (resolve_obstacle(player_shape, obstacle)) {
            printf("You successfully navigated through the %s!\n\n", obstacle_names[obstacle]);
        } else {
            printf("You couldn't survive the encounter... Game Over!\n");
            survived = 0;
        }
    } 

    if (survived) {
        printf("Congratulations! You navigated through all sectors successfully!\n");
    }

    return 0;
}