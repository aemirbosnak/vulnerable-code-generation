//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "12345"

struct drone {
    int drone_id;
    int x_pos;
    int y_pos;
    int z_pos;
};

int authenticate() {
    char password[10];
    printf("Enter password to access remote control: ");
    scanf("%s", password);
    if (strcmp(password, PASSWORD) == 0) {
        return 1;
    }
    return 0;
}

void move_drone(struct drone *drone, int x, int y, int z) {
    drone->x_pos += x;
    drone->y_pos += y;
    drone->z_pos += z;
}

void update_drone(struct drone *drones, int num_drones, int id) {
    int i;
    for (i = 0; i < num_drones; i++) {
        if (drones[i].drone_id == id) {
            int x, y, z;
            printf("Drone %d found. Enter new coordinates.\n", id);
            printf("X position: ");
            scanf("%d", &x);
            printf("Y position: ");
            scanf("%d", &y);
            printf("Z position: ");
            scanf("%d", &z);
            move_drone(&drones[i], x, y, z);
            printf("Drone %d updated!\n", id);
            return;
        }
    }
    printf("Drone %d not found.\n", id);
}

int main() {
    struct drone drones[] = {{1, 0, 0, 0}, {2, 5, 5, 5}, {3, 10, 10, 10}};
    int num_drones = sizeof(drones) / sizeof(struct drone);
    if (!authenticate()) {
        printf("Access denied.\n");
        return 1;
    }
    printf("Access granted. You may now control %d drones.\n", num_drones);
    int id;
    while (1) {
        printf("Enter drone id to update or 0 to exit.\n");
        scanf("%d", &id);
        if (id == 0) {
            break;
        }
        update_drone(drones, num_drones, id);
    }
    return 0;
}