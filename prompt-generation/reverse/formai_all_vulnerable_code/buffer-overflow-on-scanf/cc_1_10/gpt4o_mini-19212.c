//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define ROOM_NAME_LENGTH 20

typedef struct {
    char name[ROOM_NAME_LENGTH];
    int is_on;
} Room;

Room rooms[MAX_ROOMS];
int room_count = 0;

void add_room();
void toggle_light();
void show_status();
void display_menu();

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            getchar(); // clear invalid input
            printf("Invalid choice! Please enter a number.\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                toggle_light();
                break;
            case 3:
                show_status();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

void add_room() {
    if (room_count >= MAX_ROOMS) {
        printf("Room capacity reached! Cannot add more rooms.\n");
        return;
    }
    printf("Enter the name of the room: ");
    getchar(); // clear input buffer
    fgets(rooms[room_count].name, ROOM_NAME_LENGTH, stdin);
    rooms[room_count].name[strcspn(rooms[room_count].name, "\n")] = 0; // remove newline
    rooms[room_count].is_on = 0; // lights are off by default
    room_count++;
    printf("Room '%s' added successfully!\n", rooms[room_count - 1].name);
}

void toggle_light() {
    char room_name[ROOM_NAME_LENGTH];
    printf("Enter the name of the room to toggle lights: ");
    getchar(); // clear input buffer
    fgets(room_name, ROOM_NAME_LENGTH, stdin);
    room_name[strcspn(room_name, "\n")] = 0; // remove newline

    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
            rooms[i].is_on = !rooms[i].is_on; // toggle light state
            printf("Lights in '%s' are now %s.\n", rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Room '%s' not found!\n", room_name);
}

void show_status() {
    if (room_count == 0) {
        printf("No rooms added yet!\n");
        return;
    }
    printf("\n--- Light Status ---\n");
    for (int i = 0; i < room_count; i++) {
        printf("Room: %s - Lights are %s\n", rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
    }
    printf("---------------------\n");
}

void display_menu() {
    printf("\n--- Smart Home Light Control ---\n");
    printf("1. Add Room\n");
    printf("2. Toggle Light\n");
    printf("3. Show Light Status\n");
    printf("4. Exit\n");
}