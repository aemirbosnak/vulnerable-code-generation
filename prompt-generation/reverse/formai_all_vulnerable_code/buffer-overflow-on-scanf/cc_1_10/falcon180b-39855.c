//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 20
#define MAX_GHOSTS 5

typedef struct {
    char name[50];
    int health;
} Player;

typedef struct {
    char name[50];
    int health;
} Ghost;

typedef struct {
    char name[50];
    int value;
} Item;

typedef struct {
    char name[50];
    int health;
    int speed;
} Room;

Player player;
Ghost ghosts[MAX_GHOSTS];
Item items[MAX_ITEMS];
Room rooms[MAX_ROOMS];

void init() {
    player.health = 100;
    for (int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].health = 50;
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].value = rand() % 100;
    }
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].health = rand() % 100;
        rooms[i].speed = rand() % 10;
    }
}

void move(int direction) {
    printf("You move %s...\n", direction == 1? "forward" : "backward");
}

void attack(int target) {
    if (target >= 0 && target < MAX_GHOSTS) {
        printf("You attack the %s!\n", ghosts[target].name);
        ghosts[target].health -= player.health / 2;
    } else {
        printf("You missed.\n");
    }
}

void pickUp(int target) {
    if (target >= 0 && target < MAX_ITEMS) {
        printf("You picked up the %s.\n", items[target].name);
        player.health += items[target].value;
        items[target].value = 0;
    } else {
        printf("There's nothing here.\n");
    }
}

void enterRoom(int target) {
    if (target >= 0 && target < MAX_ROOMS) {
        printf("You entered the %s.\n", rooms[target].name);
        if (rooms[target].health > 0) {
            printf("You found a treasure worth %d gold coins!\n", rooms[target].health);
            player.health += rooms[target].health;
            rooms[target].health = 0;
        } else if (rooms[target].health < 0) {
            printf("You were ambushed by a %s!\n", ghosts[rooms[target].health * -1].name);
            attack(rooms[target].health * -1);
        } else {
            printf("There's nothing here.\n");
        }
    } else {
        printf("You can't go there.\n");
    }
}

int main() {
    init();
    int room = 0;
    while (player.health > 0) {
        printf("You are in the %s.\n", rooms[room].name);
        printf("Your health is %d.\n", player.health);
        printf("There are %d ghosts left.\n", MAX_GHOSTS - player.health / 50);
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            move(1);
            room++;
            if (room >= MAX_ROOMS) {
                room = 0;
            }
        } else if (choice == 2) {
            move(-1);
            room--;
            if (room < 0) {
                room = MAX_ROOMS - 1;
            }
        } else if (choice == 3) {
            attack(0);
        } else if (choice == 4) {
            pickUp(0);
        } else if (choice == 5) {
            enterRoom(room);
        } else {
            printf("Invalid choice.\n");
        }
    }
    printf("You died.\n");
    return 0;
}