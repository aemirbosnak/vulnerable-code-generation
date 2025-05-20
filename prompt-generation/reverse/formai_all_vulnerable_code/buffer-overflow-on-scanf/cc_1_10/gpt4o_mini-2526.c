//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 10
#define MAX_PLAYERS 5

typedef struct {
    char type[10]; // type of component: resistor or battery
    float value;   // value of the component, e.g., resistance in Ohms or voltage in Volts
} Component;

typedef struct {
    char name[20];
    Component components[MAX_COMPONENTS];
    int componentCount;
} Player;

void addComponent(Player* player);
void showCircuit(Player* player);
void displayMenu(Player* player);
int isCircuitValid(Player* player);
void displayGlobalState(Player players[], int playerCount);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0, choice;

    printf("Welcome to the Multiplayer Circuit Simulator!\n");
    while (1) {
        printf("\n1. Add Player\n2. Show Global State\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        
        if (choice == 1 && playerCount < MAX_PLAYERS) {
            printf("Enter player name: ");
            scanf("%s", players[playerCount].name);
            players[playerCount].componentCount = 0;
            playerCount++;
            printf("Player %s joined the game!\n", players[playerCount - 1].name);
        } else if (choice == 2) {
            displayGlobalState(players, playerCount);
        } else if (choice == 3) {
            printf("Exiting Game...\n");
            break;
        } else {
            printf("Invalid option or player limit reached!\n");
        }
    }
    return 0;
}

void addComponent(Player* player) {
    if (player->componentCount >= MAX_COMPONENTS) {
        printf("Max components reached for player %s!\n", player->name);
        return;
    }

    Component* comp = &player->components[player->componentCount];
    printf("Enter component type (resistor/battery): ");
    scanf("%s", comp->type);
    
    if (strcmp(comp->type, "resistor") == 0) {
        printf("Enter resistance (Ohms): ");
        scanf("%f", &comp->value);
    } else if (strcmp(comp->type, "battery") == 0) {
        printf("Enter voltage (Volts): ");
        scanf("%f", &comp->value);
    } else {
        printf("Invalid component type!\n");
        return;
    }
    
    player->componentCount++;
    printf("Component added to player %s's circuit!\n", player->name);
}

void showCircuit(Player* player) {
    printf("Circuit of player %s:\n", player->name);
    for (int i = 0; i < player->componentCount; i++) {
        printf("Component %d: %s with value %.2f\n", i + 1, player->components[i].type, player->components[i].value);
    }
}

void displayMenu(Player* player) {
    int choice;
    while (1) {
        printf("\nMenu for player %s:\n", player->name);
        printf("1. Add Component\n2. Show Circuit\n3. Return to Main Menu\nChoose an option: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            addComponent(player);
        } else if (choice == 2) {
            showCircuit(player);
            if (!isCircuitValid(player)) {
                printf("Warning: Circuit is invalid!\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid option!\n");
        }
    }
}

int isCircuitValid(Player* player) {
    int hasBattery = 0;
    for (int i = 0; i < player->componentCount; i++) {
        if (strcmp(player->components[i].type, "battery") == 0) {
            hasBattery = 1;
            break;
        }
    }
    return hasBattery;
}

void displayGlobalState(Player players[], int playerCount) {
    printf("\nGlobal Circuit State:\n");
    for (int i = 0; i < playerCount; i++) {
        showCircuit(&players[i]);
    }
}