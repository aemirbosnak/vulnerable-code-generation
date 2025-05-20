//FormAI DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum number of players */
#define MAX_PLAYERS 4

/* Define the number of rooms in the house */
#define NUM_ROOMS 5

/* Define the structure for each room in the house */
typedef struct {
    char* name;
    int light_state;
    int temperature;
} room_t;

/* Define the structure for each player */
typedef struct {
    char* name;
    int current_room;
} player_t;

/* Define the array for all the rooms in the house */
room_t house[NUM_ROOMS] = {
    { "Living Room", 0, 75 },
    { "Kitchen", 0, 70 },
    { "Bedroom", 0, 68 },
    { "Bathroom", 0, 72 },
    { "Garage", 0, 60 }
};

/* Define the array for all the players in the game */
player_t players[MAX_PLAYERS] = {
    { "Player1", 0 },
    { "Player2", 1 },
    { "Player3", 2 },
    { "Player4", 3 }
};

/* Define the function to turn on/off the light in a room */
void toggle_light(int room) {
    if (house[room].light_state == 0) {
        house[room].light_state = 1;
        printf("%s is now lit.\n", house[room].name);
    } else {
        house[room].light_state = 0;
        printf("%s is now dark.\n", house[room].name);
    }
}

/* Define the function to set the temperature in a room */
void set_temperature(int room, int temperature) {
    house[room].temperature = temperature;
    printf("%s temperature set to %d degrees.\n", house[room].name, temperature);
}

int main() {
    int player_count = MAX_PLAYERS;
    int current_player = 0;

    /* Loop through players and let them make their moves */
    for (int i = 0; i < player_count; i++) {
        current_player = i % MAX_PLAYERS;

        printf("%s's turn\n", players[current_player].name);
        printf("Enter a room number between 0 and 4: ");
        int room_number;
        scanf("%d", &room_number);

        if (room_number < 0 || room_number >= NUM_ROOMS) {
            printf("Invalid room number. Skipping turn.\n");
            continue;
        }

        printf("What would you like to do in %s?\n", house[room_number].name);
        printf("1. Turn light on/off\n");
        printf("2. Set temperature\n");
        printf("Enter an option: ");
        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                toggle_light(room_number);
                break;
            case 2:
                printf("Enter temperature: ");
                int temp;
                scanf("%d", &temp);
                set_temperature(room_number, temp);
                break;
            default:
                printf("Invalid option. Skipping turn.\n");
        }
    }

    return 0;
}