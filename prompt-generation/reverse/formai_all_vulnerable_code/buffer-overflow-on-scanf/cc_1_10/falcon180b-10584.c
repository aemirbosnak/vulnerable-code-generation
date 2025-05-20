//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 1000

typedef struct {
    char name[20];
    int steps;
    int distance;
} User;

User users[10];

void init() {
    for (int i = 0; i < 10; i++) {
        strcpy(users[i].name, "User");
        users[i].steps = 0;
        users[i].distance = 0;
    }
}

void add_step(int id) {
    if (id >= 0 && id < 10) {
        users[id].steps++;
        if (users[id].steps % 100 == 0) {
            users[id].distance++;
        }
    }
}

void print_user(int id) {
    if (id >= 0 && id < 10) {
        printf("Name: %s\n", users[id].name);
        printf("Steps: %d\n", users[id].steps);
        printf("Distance: %d\n", users[id].distance);
    }
}

int main() {
    init();

    while (1) {
        printf("Enter command:\n");
        printf("1. Add step\n");
        printf("2. Print user\n");
        printf("3. Exit\n");

        int command;
        scanf("%d", &command);

        switch (command) {
            case 1: {
                int id;
                printf("Enter user ID:\n");
                scanf("%d", &id);
                add_step(id);
                break;
            }
            case 2: {
                int id;
                printf("Enter user ID:\n");
                scanf("%d", &id);
                print_user(id);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid command\n");
            }
        }
    }

    return 0;
}