//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CAVALIERS 10
#define MAX_COMMAND_SIZE 100

typedef struct {
    char name[30];
    int position;
    int speed; // Speed defines how much the cavalier moves in one turn
} Cavalier;

void traverseTerrain(Cavalier *cavalier) {
    cavalier->position += cavalier->speed;
    printf("%s travels forth! Current position: %d\n", cavalier->name, cavalier->position);
}

void showStatus(Cavalier *cavalier) {
    printf("Name: %s - Current Position: %d - Speed: %d\n", cavalier->name, cavalier->position, cavalier->speed);
}

void printInstructions() {
    printf("Commands:\n");
    printf("1. Move <CavalierName> <Distance>\n");
    printf("2. Status <CavalierName>\n");
    printf("3. SetSpeed <CavalierName> <Speed>\n");
    printf("4. Exit\n");
}

Cavalier *findCavalier(Cavalier *cavaliers, int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(cavaliers[i].name, name) == 0) {
            return &cavaliers[i];
        }
    }
    return NULL;
}

int main() {
    Cavalier cavaliers[MAX_CAVALIERS] = {
        {"Sir Lancelot", 0, 2},
        {"Lady Guinevere", 0, 3},
        {"Sir Gawain", 0, 2},
        {"Sir Bedivere", 0, 1},
        {"Sir Percival", 0, 4},
        {"Lady Morgana", 0, 2},
        {"Sir Kay", 0, 3},
        {"Sir Tristan", 0, 3},
        {"Lady Elaine", 0, 1},
        {"Sir Agravain", 0, 4},
    };

    char command[MAX_COMMAND_SIZE];
    int running = 1;

    printf("Welcome to the Noble Cavalier's Remote Control Simulation!\n");

    while (running) {
        printInstructions();
        printf("Enter your command: ");
        fgets(command, MAX_COMMAND_SIZE, stdin);
        command[strcspn(command, "\n")] = 0; // Remove the trailing newline

        char action[30];
        char name[30];
        int value;

        if (sscanf(command, "%s %s %d", action, name, &value) >= 2) {
            Cavalier *cavalier = findCavalier(cavaliers, MAX_CAVALIERS, name);
            if (cavalier == NULL) {
                printf("Cavalier not found: %s\n", name);
                continue;
            }

            if (strcmp(action, "Move") == 0) {
                cavalier->position += value;
                printf("%s moves forward by %d units! New Position: %d\n", cavalier->name, value, cavalier->position);
            } else if (strcmp(action, "Status") == 0) {
                showStatus(cavalier);
            } else if (strcmp(action, "SetSpeed") == 0) {
                cavalier->speed = value;
                printf("%s's speed updated to %d.\n", cavalier->name, cavalier->speed);
            } else {
                printf("Unknown action: %s\n", action);
            }
        } else if (strcmp(command, "Exit") == 0) {
            running = 0;
        } else {
            printf("Invalid command format.\n");
        }
    }

    printf("Farewell, noble lords and ladies of the realm!\n");
    return 0;
}