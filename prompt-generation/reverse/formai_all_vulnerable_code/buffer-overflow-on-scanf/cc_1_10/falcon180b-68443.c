//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char name[50];
    int temperature;
    int humidity;
} Room;

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;

    while (num_rooms < MAX_ROOMS) {
        printf("Enter room name (or press enter to finish): ");
        fgets(rooms[num_rooms].name, sizeof(rooms[num_rooms].name), stdin);

        if (strcmp(rooms[num_rooms].name, "") == 0) {
            break;
        }

        num_rooms++;
    }

    while (1) {
        printf("\nSelect a room:\n");
        for (int i = 0; i < num_rooms; i++) {
            printf("%d. %s\n", i+1, rooms[i].name);
        }

        int choice;
        scanf("%d", &choice);

        if (choice < 1 || choice > num_rooms) {
            printf("Invalid choice.\n");
            continue;
        }

        printf("Enter temperature (in Celsius): ");
        scanf("%d", &rooms[choice-1].temperature);

        printf("Enter humidity (in %%): ");
        scanf("%d", &rooms[choice-1].humidity);
    }

    return 0;
}