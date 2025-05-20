//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_COMPONENTS 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int resistance; // in ohms
} Resistor;

typedef struct {
    char name[NAME_LENGTH];
    int intensity; // 0 (off) or 1 (on)
} LightBulb;

typedef struct {
    Resistor resistors[MAX_COMPONENTS];
    LightBulb bulbs[MAX_COMPONENTS];
    int resistor_count;
    int bulb_count;
} Circuit;

void initialize_circuit(Circuit *circuit) {
    circuit->resistor_count = 0;
    circuit->bulb_count = 0;
}

void add_resistor(Circuit *circuit, const char *name, int resistance) {
    if (circuit->resistor_count < MAX_COMPONENTS) {
        strncpy(circuit->resistors[circuit->resistor_count].name, name, NAME_LENGTH);
        circuit->resistors[circuit->resistor_count].resistance = resistance;
        circuit->resistor_count++;
        printf("%s added a resistor: %s (%d ohms)\n", name, name, resistance);
    } else {
        printf("Cannot add more resistors. Max limit reached!\n");
    }
}

void add_lightbulb(Circuit *circuit, const char *name) {
    if (circuit->bulb_count < MAX_COMPONENTS) {
        strncpy(circuit->bulbs[circuit->bulb_count].name, name, NAME_LENGTH);
        circuit->bulbs[circuit->bulb_count].intensity = 0; // Initially off
        circuit->bulb_count++;
        printf("%s added a lightbulb: %s\n", name, name);
    } else {
        printf("Cannot add more lightbulbs. Max limit reached!\n");
    }
}

void turn_on_lightbulb(Circuit *circuit, const char *name) {
    for (int i = 0; i < circuit->bulb_count; i++) {
        if (strcmp(circuit->bulbs[i].name, name) == 0) {
            circuit->bulbs[i].intensity = 1; // Turn on
            printf("%s is turned on\n", name);
            return;
        }
    }
    printf("Lightbulb %s not found!\n", name);
}

void display_circuit(const Circuit *circuit) {
    printf("Current Circuit State:\n");
    printf("Resistors:\n");
    for (int i = 0; i < circuit->resistor_count; i++) {
        printf(" - %s: %d ohms\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }
    printf("LightBulbs:\n");
    for (int i = 0; i < circuit->bulb_count; i++) {
        printf(" - %s: %s\n", circuit->bulbs[i].name, circuit->bulbs[i].intensity ? "On" : "Off");
    }
}

int main() {
    Circuit circuit;
    initialize_circuit(&circuit);

    char player_name[NAME_LENGTH];
    int option, resistance;
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player name (Player %d): ", i + 1);
        scanf("%s", player_name);
        printf("Player %s, choose an option:\n", player_name);
        printf("1. Add Resistor\n");
        printf("2. Add LightBulb\n");
        printf("3. Turn On LightBulb\n");
        printf("4. Display Circuit\n");
        printf("0. Exit\n");
        
        while (1) {
            scanf("%d", &option);
            switch (option) {
                case 1:
                    printf("Enter resistor name: ");
                    char resistor_name[NAME_LENGTH];
                    scanf("%s", resistor_name);
                    printf("Enter resistor resistance (ohms): ");
                    scanf("%d", &resistance);
                    add_resistor(&circuit, resistor_name, resistance);
                    break;
                case 2:
                    printf("Enter lightbulb name: ");
                    char bulb_name[NAME_LENGTH];
                    scanf("%s", bulb_name);
                    add_lightbulb(&circuit, bulb_name);
                    break;
                case 3:
                    printf("Enter lightbulb name to turn on: ");
                    char lightbulb_name[NAME_LENGTH];
                    scanf("%s", lightbulb_name);
                    turn_on_lightbulb(&circuit, lightbulb_name);
                    break;
                case 4:
                    display_circuit(&circuit);
                    break;
                case 0:
                    return 0;
                default:
                    printf("Invalid option! Try again.\n");
            }
        }
    }

    return 0;
}