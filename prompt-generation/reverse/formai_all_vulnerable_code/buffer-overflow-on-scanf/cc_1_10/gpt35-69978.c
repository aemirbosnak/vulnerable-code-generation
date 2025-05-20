//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50 // Maximum number of available vehicles.

void printMenu() {
    printf("Choose an option: \n");
    printf("1. Create a new vehicle\n");
    printf("2. Control a vehicle\n");
    printf("3. Show available vehicles\n");
    printf("4. Exit\n");
}

typedef struct {
    int id;
    int x;
    int y;
    int speed;
} Vehicle;

void createNewVehicle(Vehicle* vehicles, int* numberOfVehicles) {
    if (*numberOfVehicles == MAX) {
        printf("There's not room for new vehicles.\n");
        return;
    }

    Vehicle newVehicle;
    newVehicle.id = *numberOfVehicles + 1;
    newVehicle.x = 0;
    newVehicle.y = 0;
    newVehicle.speed = 0;

    printf("New vehicle created with ID %d.\n", newVehicle.id);

    vehicles[*numberOfVehicles] = newVehicle;
    (*numberOfVehicles)++;
}

void controlVehicle(Vehicle* vehicles, int numberOfVehicles) {
    if (numberOfVehicles == 0) {
        printf("There aren't any available vehicles.\n");
        return;
    }

    printf("Which vehicle do you want to control? (Enter ID)\n");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < numberOfVehicles; i++) {
        if (vehicles[i].id == id) {
            printf("You are now controlling vehicle %d.\n", id);

            while (1) {
                printf("Enter speed (-10 to 10, 0 to stop): ");
                int speed;
                scanf("%d", &speed);

                if (speed < -10 || speed > 10) {
                    printf("Speed must be between -10 and 10.\n");
                } else {
                    vehicles[i].speed = speed;
                    break;
                }
            }

            while (1) {
                printf("Enter direction (N, S, E or W): ");
                char direction;
                scanf(" %c", &direction);

                switch (direction) {
                    case 'N':
                        vehicles[i].y++;
                        break;
                    case 'S':
                        vehicles[i].y--;
                        break;
                    case 'E':
                        vehicles[i].x++;
                        break;
                    case 'W':
                        vehicles[i].x--;
                        break;
                    default:
                        printf("Invalid direction. Choose N, S, E or W.\n");
                        continue;
                }

                printf("Vehicle is now at position (%d, %d).\n", vehicles[i].x, vehicles[i].y);

                break;
            }

            printf("Vehicle stopped. Speed and direction are set to 0.\n");
            vehicles[i].speed = 0;
            vehicles[i].x = 0;
            vehicles[i].y = 0;

            return;
        }
    }

    printf("Vehicle with ID %d not found.\n", id);
}

void showVehicles(Vehicle* vehicles, int numberOfVehicles) {
    if (numberOfVehicles == 0) {
        printf("There aren't any available vehicles.\n");
        return;
    }

    printf("Available vehicles:\n");

    for (int i = 0; i < numberOfVehicles; i++) {
        printf("ID: %d, Position: (%d, %d), Speed: %d\n", vehicles[i].id, vehicles[i].x, vehicles[i].y, vehicles[i].speed);
    }
}

int main() {
    srand(time(NULL));

    Vehicle vehicles[MAX];
    int numberOfVehicles = 0;

    while (1) {
        printMenu();

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                createNewVehicle(vehicles, &numberOfVehicles);
                break;
            case 2:
                controlVehicle(vehicles, numberOfVehicles);
                break;
            case 3:
                showVehicles(vehicles, numberOfVehicles);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option. Choose 1, 2, 3 or 4.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}