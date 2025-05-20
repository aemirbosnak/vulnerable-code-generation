//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_ROOM_NAME_LENGTH 30

typedef struct {
    char name[MAX_ROOM_NAME_LENGTH];
    int brightness; // Range from 0 to 100
    int is_on; // 1 means on, 0 means off
} Room;

Room rooms[MAX_ROOMS];
int room_count = 0;

void add_room(const char *name) {
    if (room_count >= MAX_ROOMS) {
        printf("Cannot add more rooms. Maximum limit reached!\n");
        return;
    }
    strcpy(rooms[room_count].name, name);
    rooms[room_count].brightness = 100; // Default brightness
    rooms[room_count].is_on = 0; // Initially off
    room_count++;
    printf("Room '%s' added successfully!\n", name);
}

void toggle_light(const char *name) {
    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].name, name) == 0) {
            rooms[i].is_on = !rooms[i].is_on; // Toggle
            printf("The light in '%s' is now %s.\n", rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Room '%s' not found!\n", name);
}

void set_brightness(const char *name, int brightness) {
    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].name, name) == 0) {
            if (brightness < 0 || brightness > 100) {
                printf("Brightness level should be between 0 and 100.\n");
                return;
            }
            rooms[i].brightness = brightness;
            printf("Brightness of room '%s' set to %d%%.\n", rooms[i].name, brightness);
            return;
        }
    }
    printf("Room '%s' not found!\n", name);
}

void show_status() {
    for (int i = 0; i < room_count; i++) {
        printf("Room: %s | Status: %s | Brightness: %d%%\n",
               rooms[i].name,
               rooms[i].is_on ? "ON" : "OFF",
               rooms[i].brightness);
    }
}

void help() {
    printf("Commands:\n");
    printf("  add <room_name>          - Add a new room.\n");
    printf("  toggle <room_name>       - Toggle the light on/off in a specified room.\n");
    printf("  set <room_name> <value>  - Set brightness for the specified room (0-100).\n");
    printf("  status                   - Show the status of all rooms.\n");
    printf("  exit                     - Exit the program.\n");
}

int main() {
    char command[100];
    char room_name[MAX_ROOM_NAME_LENGTH];
    int brightness;

    printf("Welcome to the Smart Home Light Control System!\n");
    help();

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strncmp(command, "add ", 4) == 0) {
            sscanf(command + 4, "%s", room_name);
            add_room(room_name);
        } else if (strncmp(command, "toggle ", 7) == 0) {
            sscanf(command + 7, "%s", room_name);
            toggle_light(room_name);
        } else if (strncmp(command, "set ", 4) == 0) {
            sscanf(command + 4, "%s %d", room_name, &brightness);
            set_brightness(room_name, brightness);
        } else if (strcmp(command, "status") == 0) {
            show_status();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Light Control System. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Type 'help' for the list of commands.\n");
        }
    }
    return 0;
}