//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_ROOMS 10
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int scare_factor;
} Room;

void initialize_rooms(Room rooms[], int count) {
    const char* names[] = {
        "The Dark Hallway", "Ghostly Library", "Creepy Basement", 
        "Eerie Kitchen", "Haunting Living Room", "Spooky Attic",
        "The Abandoned Bedroom", "Shadowy Bathroom", "Mystic Garden", "Chilling Corridor"
    };

    for (int i = 0; i < count; i++) {
        snprintf(rooms[i].name, MAX_NAME, "%s", names[i]);
        rooms[i].scare_factor = rand() % 10 + 1; // Scare factor between 1 and 10
    }
}

void enter_room(const Room* room) {
    printf("\nYou have entered: %s\n", room->name);
    sleep(1);
    
    // Simulating a scare effect based on the room's scare factor
    for (int i = 0; i < room->scare_factor; i++) {
        printf("A spooky sound echoes! ");
        fflush(stdout);
        sleep(1);
    }

    printf("\nYou managed to survive the room!\n");
    sleep(1);
}

void play_game() {
    Room rooms[MAX_ROOMS];
    int room_count = 10;

    srand(time(NULL));
    initialize_rooms(rooms, room_count);

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will explore different rooms filled with scares.\n");

    for (int i = 0; i < room_count; i++) {
        printf("\n-------------------------------------------------\n");
        enter_room(&rooms[i]);
        printf("-------------------------------------------------\n");
        
        if (i < room_count - 1) {
            char choice;
            printf("Do you wish to continue to the next room? (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'N' || choice == 'n') {
                printf("You have decided to exit the haunted house. Goodbye!\n");
                break;
            }
        }
    }
    printf("\nThank you for playing the Haunted House Simulator!\n");
}

int main() {
    play_game();
    return 0;
}