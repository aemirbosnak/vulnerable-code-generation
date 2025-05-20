//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef enum { LIVING_ROOM, KITCHEN, HALLWAY, BATHROOM, BEDROOM, ATTIC, BASEMENT, EXIT } RoomType;

typedef struct {
    RoomType type;
    const char* description;
    const char* monster;
} Room;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int escape_attempts;
} Player;

void initializeRooms(Room rooms[]) {
    rooms[LIVING_ROOM] = (Room){ LIVING_ROOM, "You are in a spooky living room. Shadows dance across the walls.", "Ghost" };
    rooms[KITCHEN] = (Room){ KITCHEN, "The kitchen is filled with rotten food and a feeling of dread.", "Zombie" };
    rooms[HALLWAY] = (Room){ HALLWAY, "Dimly lit hallway stretches before you, echoes of footsteps can be heard.", "Vampire" };
    rooms[BATHROOM] = (Room){ BATHROOM, "A creepy bathroom with flickering lights and a moldy mirror.", "Skeleton" };
    rooms[BEDROOM] = (Room){ BEDROOM, "An unkempt bedroom, the bed creaks as though someone just got up.", "Werewolf" };
    rooms[ATTIC] = (Room){ ATTIC, "You find yourself in a dusty, cobweb-filled attic. Things whisper in the darkness.", "Mummy" };
    rooms[BASEMENT] = (Room){ BASEMENT, "The basement is dark and damp, you can hear chains rattling.", "Demon" };
    rooms[EXIT] = (Room){ EXIT, "You see the light of the outside world! A safe escape lies ahead.", "" };
}

void printRoomDescription(Room room) {
    printf("%s\n", room.description);
    if (strlen(room.monster) > 0) {
        printf("A %s is lurking here! Beware!\n", room.monster);
    }
}

void escape(Player* player) {
    if (player->health > 0) {
        printf("%s makes a valiant escape!\n", player->name);
        player->escape_attempts += 1;
    } else {
        printf("%s is too weak to escape!\n", player->name);
    }
}

void encounterMonster(Player* player, Room room) {
    printf("You encounter a %s!\n", room.monster);
    player->health -= 20;

    if (player->health <= 0) {
        printf("%s has succumbed to the monster!\n", player->name);
    } else {
        printf("%s is still standing, but with %d health left!\n", player->name, player->health);
    }
}

void startGame(Player* player) {
    Room rooms[MAX_ROOMS];
    initializeRooms(rooms);
    
    Room* currentRoom = &rooms[LIVING_ROOM];
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Welcome, brave soul, %s!\n", player->name);

    while (currentRoom->type != EXIT) {
        printRoomDescription(*currentRoom);
        
        char action[10];
        printf("Do you want to (e)scape or (m)ove to the next room? ");
        scanf("%s", action);

        if (strcmp(action, "e") == 0) {
            escape(player);
        } else {
            if (currentRoom->type != BASEMENT) {
                currentRoom += 1;  // Move to the next room
                if (rand() % 2 == 0) {
                    encounterMonster(player, *currentRoom);
                }
            } else {
                printf("You reached the basement. No way to go but up!\n");
                currentRoom = &rooms[EXIT]; // Directly go to EXIT
            }
        }

        if (player->health <= 0) {
            printf("Game Over! %s did not survive the haunted house.\n", player->name);
            break;
        }
    }
    
    if (currentRoom->type == EXIT && player->health > 0) {
        printf("Congratulations! %s escaped the haunted house with %d health remaining!\n", player->name, player->health);
        printf("You made it out in %d escape attempts.\n", player->escape_attempts);
    }
}

int main() {
    srand(time(NULL));

    Player player;
    printf("Enter your name (max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", player.name);
    
    player.health = 100;
    player.escape_attempts = 0;
    
    startGame(&player);
    
    return 0;
}