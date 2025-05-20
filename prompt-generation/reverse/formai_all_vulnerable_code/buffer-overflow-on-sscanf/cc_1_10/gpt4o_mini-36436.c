//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DRONES 10
#define COMMAND_BUFFER_SIZE 100

typedef struct {
    int id;
    char name[20];
    float altitude; // in meters
    float speed;    // in meters per second
    char status[20]; // e.g. "Active", "Inactive"
} Drone;

Drone drones[MAX_DRONES];
int droneCount = 0;

void addDrone(char *name) {
    if (droneCount >= MAX_DRONES) {
        printf("Maximum drone limit reached!\n");
        return;
    }
    drones[droneCount].id = droneCount + 1;
    strcpy(drones[droneCount].name, name);
    drones[droneCount].altitude = 0.0;
    drones[droneCount].speed = 0.0;
    strcpy(drones[droneCount].status, "Inactive");
    droneCount++;
    printf("Drone %s added with ID %d\n", name, drones[droneCount - 1].id);
}

void listDrones() {
    if (droneCount == 0) {
        printf("No drones available.\n");
        return;
    }

    printf("List of Drones:\n");
    for (int i = 0; i < droneCount; i++) {
        printf("ID: %d, Name: %s, Altitude: %.2f m, Speed: %.2f m/s, Status: %s\n",
            drones[i].id, drones[i].name, drones[i].altitude, drones[i].speed, drones[i].status);
    }
}

void setDroneStatus(int id, const char *status) {
    if (id <= 0 || id > droneCount) {
        printf("Invalid drone ID!\n");
        return;
    }
    strcpy(drones[id - 1].status, status);
    printf("Drone ID %d status set to %s\n", id, status);
}

void setDroneAltitude(int id, float altitude) {
    if (id <= 0 || id > droneCount) {
        printf("Invalid drone ID!\n");
        return;
    }
    drones[id - 1].altitude = altitude;
    printf("Drone ID %d altitude set to %.2f m\n", id, altitude);
}

void setDroneSpeed(int id, float speed) {
    if (id <= 0 || id > droneCount) {
        printf("Invalid drone ID!\n");
        return;
    }
    drones[id - 1].speed = speed;
    printf("Drone ID %d speed set to %.2f m/s\n", id, speed);
}

void getDroneInfo(int id) {
    if (id <= 0 || id > droneCount) {
        printf("Invalid drone ID!\n");
        return;
    }
    Drone d = drones[id - 1];
    printf("Drone ID: %d\nName: %s\nAltitude: %.2f m\nSpeed: %.2f m/s\nStatus: %s\n",
           d.id, d.name, d.altitude, d.speed, d.status);
}

void executeCommand(char *command) {
    char cmd[COMMAND_BUFFER_SIZE];
    int id;
    float value;

    if (sscanf(command, "add %s", cmd) == 1) {
        addDrone(cmd);
    } else if (strcmp(command, "list") == 0) {
        listDrones();
    } else if (sscanf(command, "set status %d %s", &id, cmd) == 2) {
        setDroneStatus(id, cmd);
    } else if (sscanf(command, "set altitude %d %f", &id, &value) == 2) {
        setDroneAltitude(id, value);
    } else if (sscanf(command, "set speed %d %f", &id, &value) == 2) {
        setDroneSpeed(id, value);
    } else if (sscanf(command, "info %d", &id) == 1) {
        getDroneInfo(id);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    char command[COMMAND_BUFFER_SIZE];

    printf("Drone Remote Control System\n");
    printf("Available commands: add <name>, list, set status <id> <status>, set altitude <id> <value>, set speed <id> <value>, info <id>\n");
    printf("Type 'exit' to quit the program.\n");

    while (1) {
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            continue; // handle EOF or error
        }
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the Drone Remote Control System.\n");
            break;
        }

        executeCommand(command);
    }

    return 0;
}