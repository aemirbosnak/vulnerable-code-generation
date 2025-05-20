//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector3;

typedef struct {
    char name[50];
    int age;
    int cargo_capacity;
} Spaceship;

int main() {
    Spaceship player_ship;
    Vector3 player_position;

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Enter your spaceship's name: ");
    scanf("%s", player_ship.name);
    printf("Enter your spaceship's age (in years): ");
    scanf("%d", &player_ship.age);
    printf("Enter your spaceship's cargo capacity (in tons): ");
    scanf("%d", &player_ship.cargo_capacity);

    player_position.x = 0;
    player_position.y = 0;
    player_position.z = 0;

    while (1) {
        printf("Your current position is: (%d, %d, %d)\n", player_position.x, player_position.y, player_position.z);
        printf("What do you want to do?\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Load cargo\n");
        printf("6. Unload cargo\n");
        printf("7. Check cargo capacity\n");
        printf("8. Quit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                player_position.x++;
                break;
            case 2:
                player_position.x--;
                break;
            case 3:
                player_position.y++;
                break;
            case 4:
                player_position.y--;
                break;
            case 5:
                player_ship.cargo_capacity = 10;
                break;
            case 6:
                player_ship.cargo_capacity -= 5;
                break;
            case 7:
                printf("Your spaceship's cargo capacity is: %d\n", player_ship.cargo_capacity);
                break;
            case 8:
                return 0;
        }
    }

    return 0;
}