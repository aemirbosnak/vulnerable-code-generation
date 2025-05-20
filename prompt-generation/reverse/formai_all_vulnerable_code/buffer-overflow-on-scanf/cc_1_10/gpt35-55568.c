//FormAI DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_LIGHTS 10

typedef struct Light {
    char* name;
    int brightness;
} Light;

typedef struct Room {
    char* name;
    Light lights[MAX_LIGHTS];
    int num_lights;
} Room;

Room rooms[MAX_ROOMS];
int num_rooms;

void create_room(char* name) {
    if (num_rooms == MAX_ROOMS) {
        printf("Error: Maximum number of rooms reached!\n");
        return;
    }
    
    Room new_room;
    new_room.name = strdup(name);
    new_room.num_lights = 0;
    
    rooms[num_rooms] = new_room;
    num_rooms++;
    
    printf("New room created: %s\n", name);
}

void add_light(char* room_name, char* light_name) {
    int room_index = -1;
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
            room_index = i;
            break;
        }
    }
    
    if (room_index == -1) {
        printf("Error: Room '%s' not found!\n", room_name);
        return;
    }
    
    Room* room = &rooms[room_index];
    if (room->num_lights == MAX_LIGHTS) {
        printf("Error: Maximum number of lights reached for room '%s'!\n", room_name);
        return;
    }
    
    Light new_light;
    new_light.name = strdup(light_name);
    new_light.brightness = 0;
    
    room->lights[room->num_lights] = new_light;
    room->num_lights++;
    
    printf("New light added to room '%s': %s\n", room_name, light_name);
}

void set_brightness(char* room_name, char* light_name, int brightness) {
    int room_index = -1;
    int light_index = -1;
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
            room_index = i;
            for (int j = 0; j < rooms[i].num_lights; j++) {
                if (strcmp(rooms[i].lights[j].name, light_name) == 0) {
                    light_index = j;
                    break;
                }
            }
            break;
        }
    }
    
    if (room_index == -1) {
        printf("Error: Room '%s' not found!\n", room_name);
        return;
    }
    
    Room* room = &rooms[room_index];
    if (light_index == -1) {
        printf("Error: Light '%s' not found in room '%s'!\n", light_name, room_name);
        return;
    }
    
    Light* light = &room->lights[light_index];
    light->brightness = brightness;
    
    printf("%s brightness in room '%s' set to %d\n", light_name, room_name, brightness);
}

void print_menu() {
    printf("\n===== Smart Home Light Control =====\n");
    printf("1. Create room\n");
    printf("2. Add light to room\n");
    printf("3. Set brightness of light in room\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;
    char room_name[50], light_name[50];
    int brightness;
    
    while (1) {
        print_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter room name: ");
                scanf("%s", room_name);
                create_room(room_name);
                break;
            case 2:
                printf("Enter room name: ");
                scanf("%s", room_name);
                printf("Enter light name: ");
                scanf("%s", light_name);
                add_light(room_name, light_name);
                break;
            case 3:
                printf("Enter room name: ");
                scanf("%s", room_name);
                printf("Enter light name: ");
                scanf("%s", light_name);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(room_name, light_name, brightness);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}