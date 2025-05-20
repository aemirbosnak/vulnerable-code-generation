//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ROOMS 10
#define ROOM_NAME_LENGTH 30

typedef struct {
    char name[ROOM_NAME_LENGTH];
    int brightness; // brightness level from 0 to 100
    int status; // 0 = OFF, 1 = ON
} Room;

Room rooms[MAX_ROOMS];
int room_count = 0;

void addRoom(const char *room_name) {
    if(room_count < MAX_ROOMS) {
        strncpy(rooms[room_count].name, room_name, ROOM_NAME_LENGTH);
        rooms[room_count].brightness = 0;
        rooms[room_count].status = 0;
        room_count++;
        printf("Room '%s' added.\n", room_name);
    } else {
        printf("Maximum room limit reached.\n");
    }
}

void listRooms() {
    if(room_count == 0) {
        printf("No rooms available.\n");
        return;
    }
    printf("Rooms:\n");
    for(int i = 0; i < room_count; i++) {
        printf("%d. %s - Status: %s, Brightness: %d%%\n", i + 1, rooms[i].name, 
               rooms[i].status ? "ON" : "OFF", rooms[i].brightness);
    }
}

void toggleLight(int room_index) {
    if(room_index < 0 || room_index >= room_count) {
        printf("Invalid room index.\n");
        return;
    }
    rooms[room_index].status = !rooms[room_index].status;
    printf("Light in room '%s' is now %s.\n", rooms[room_index].name, 
           rooms[room_index].status ? "ON" : "OFF");
}

void setBrightness(int room_index, int brightness) {
    if(room_index < 0 || room_index >= room_count) {
        printf("Invalid room index.\n");
        return;
    }
    if(brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    rooms[room_index].brightness = brightness;
    printf("Brightness of room '%s' set to %d%%.\n", rooms[room_index].name, brightness);
}

void scheduleLights() {
    printf("Scheduling lights to turn ON and OFF.\n");
    for(int i = 0; i < room_count; i++) {
        if(rooms[i].status) {
            // Simulate light ON for 2 seconds
            printf("Room '%s' is ON.\n", rooms[i].name);
            sleep(2);
        } else {
            printf("Room '%s' is OFF.\n", rooms[i].name);
        }
    }
}

int main() {
    int choice, room_index, brightness;
    char room_name[ROOM_NAME_LENGTH];
    
    while(1) {
        printf("\nSmart Home Light Control System\n");
        printf("1. Add Room\n");
        printf("2. List Rooms\n");
        printf("3. Toggle Light\n");
        printf("4. Set Brightness\n");
        printf("5. Schedule Lights\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter room name: ");
                scanf("%s", room_name);
                addRoom(room_name);
                break;
            case 2:
                listRooms();
                break;
            case 3:
                printf("Enter room index to toggle light: ");
                scanf("%d", &room_index);
                toggleLight(room_index - 1);
                break;
            case 4:
                printf("Enter room index to set brightness: ");
                scanf("%d", &room_index);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                setBrightness(room_index - 1, brightness);
                break;
            case 5:
                scheduleLights();
                break;
            case 6:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}