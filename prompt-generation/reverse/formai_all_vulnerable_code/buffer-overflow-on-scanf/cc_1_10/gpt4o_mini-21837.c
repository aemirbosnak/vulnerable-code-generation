//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5

typedef enum {
    ROOM_LIVING_ROOM,
    ROOM_KITCHEN,
    ROOM_BEDROOM,
    ROOM_BATHROOM,
    ROOM_ATTIC
} Room;

typedef struct {
    Room current_room;
    int health;
    int has_flashlight;
} Player;

void display_room_description(Room room) {
    switch (room) {
        case ROOM_LIVING_ROOM:
            printf("You enter the living room. The air is thick with dust, and cobwebs hang from every corner.\n");
            break;
        case ROOM_KITCHEN:
            printf("You step into the kitchen. The smell of something rotten fills your nostrils.\n");
            break;
        case ROOM_BEDROOM:
            printf("You find yourself in the bedroom. An old bed creaks ominously under its own weight.\n");
            break;
        case ROOM_BATHROOM:
            printf("You walk into the bathroom. The mirror is cracked, and there's a strange flickering light.\n");
            break;
        case ROOM_ATTIC:
            printf("You climb into the attic. It’s dark, and you might hear whispers echoing around you.\n");
            break;
        default:
            printf("This room is unremarkable.\n");
    }
}

void encounter_event(Player* player) {
    int event_type = rand() % 3;
    switch (event_type) {
        case 0:
            printf("You found a flashlight!\n");
            player->has_flashlight = 1;
            break;
        case 1:
            printf("A ghost appears and scares you! You lose 1 health.\n");
            player->health--;
            break;
        case 2:
            printf("You found a hidden stash of supplies! You regain 1 health.\n");
            player->health++;
            break;
    }
}

Room next_room(Room current_room) {
    if (current_room == ROOM_ATTIC) {
        return ROOM_LIVING_ROOM; // Loop back to the living room if in the attic
    }
    return (Room)(current_room + 1);
}

int check_game_over(Player player) {
    if (player.health <= 0) {
        printf("You have lost all your health. Game Over!\n");
        return 1;
    }
    return 0;
}

void print_player_status(Player player) {
    printf("Health: %d\n", player.health);
    if (player.has_flashlight) {
        printf("You have a flashlight.\n");
    } else {
        printf("You do not have a flashlight.\n");
    }
}

void simulate_haunted_house() {
    Player player = {ROOM_LIVING_ROOM, 3, 0};
    srand(time(NULL));

    while (1) {
        display_room_description(player.current_room);
        print_player_status(player);
        encounter_event(&player);

        if (check_game_over(player)) {
            break;
        }

        printf("You can move to the next room (1: Yes, 0: No): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            player.current_room = next_room(player.current_room);
        } else {
            printf("You chose to stay in the room. The haunting intensifies...\n");
        }
    }
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will explore a haunted house filled with ghosts and surprises.\n");
    simulate_haunted_house();
    return 0;
}