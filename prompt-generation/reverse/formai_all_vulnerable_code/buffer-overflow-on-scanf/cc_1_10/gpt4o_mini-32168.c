//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS 5

typedef struct {
    char name[30];
    int intensity; // Range: 0 (off) to 100 (full brightness)
} Light;

typedef struct {
    char name[30];
    Light lights[MAX_LIGHTS];
    int light_count;
} Room;

Room rooms[MAX_ROOMS];
int room_count = 0;

void addRoom(char *name) {
    if (room_count < MAX_ROOMS) {
        strncpy(rooms[room_count].name, name, sizeof(rooms[room_count].name)-1);
        rooms[room_count].light_count = 0;
        room_count++;
        printf("Room %s added.\n", name);
    } else {
        printf("Maximum room limit reached.\n");
    }
}

void addLightToRoom(char *roomName, char *lightName) {
    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].name, roomName) == 0) {
            if (rooms[i].light_count < MAX_LIGHTS) {
                strncpy(rooms[i].lights[rooms[i].light_count].name, lightName, sizeof(rooms[i].lights[rooms[i].light_count].name) - 1);
                rooms[i].lights[rooms[i].light_count].intensity = 0; // Off by default
                rooms[i].light_count++;
                printf("Light %s added to room %s.\n", lightName, roomName);
            } else {
                printf("Maximum light limit in room %s reached.\n", roomName);
            }
            return;
        }
    }
    printf("Room %s not found.\n", roomName);
}

void setLightIntensity(char *roomName, char *lightName, int intensity) {
    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].name, roomName) == 0) {
            for (int j = 0; j < rooms[i].light_count; j++) {
                if (strcmp(rooms[i].lights[j].name, lightName) == 0) {
                    if (intensity >= 0 && intensity <= 100) {
                        rooms[i].lights[j].intensity = intensity;
                        printf("Light %s in room %s set to %d%%.\n", lightName, roomName, intensity);
                    } else {
                        printf("Intensity must be between 0 and 100.\n");
                    }
                    return;
                }
            }
            printf("Light %s not found in room %s.\n", lightName, roomName);
            return;
        }
    }
    printf("Room %s not found.\n", roomName);
}

void getRoomStatus(char *roomName) {
    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].name, roomName) == 0) {
            printf("Status of room %s:\n", roomName);
            for (int j = 0; j < rooms[i].light_count; j++) {
                printf("- Light %s: %d%% brightness\n", rooms[i].lights[j].name, rooms[i].lights[j].intensity);
            }
            return;
        }
    }
    printf("Room %s not found.\n", roomName);
}

void simulateSchedule() {
    printf("Simulating light schedules:\n");
    srand(time(NULL));
    
    for (int i = 0; i < room_count; i++) {
        printf("Room %s's schedule:\n", rooms[i].name);
        for (int j = 0; j < rooms[i].light_count; j++) {
            int randomIntensity = rand() % 101; // Random intensity between 0 and 100
            rooms[i].lights[j].intensity = randomIntensity;
            printf("- Light %s randomly set to %d%% brightness\n", rooms[i].lights[j].name, randomIntensity);
        }
    }
}

int main() {
    int choice;
    char roomName[30], lightName[30];
    int intensity;

    while(1) {
        printf("\nSmart Home Light Control\n");
        printf("1. Add Room\n");
        printf("2. Add Light to Room\n");
        printf("3. Set Light Intensity\n");
        printf("4. Get Room Status\n");
        printf("5. Simulate Schedule\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character
        
        switch (choice) {
            case 1:
                printf("Enter room name: ");
                fgets(roomName, sizeof(roomName), stdin);
                roomName[strcspn(roomName, "\n")] = 0; // Remove newline
                addRoom(roomName);
                break;
            case 2:
                printf("Enter room name: ");
                fgets(roomName, sizeof(roomName), stdin);
                roomName[strcspn(roomName, "\n")] = 0; // Remove newline
                printf("Enter light name: ");
                fgets(lightName, sizeof(lightName), stdin);
                lightName[strcspn(lightName, "\n")] = 0; // Remove newline
                addLightToRoom(roomName, lightName);
                break;
            case 3:
                printf("Enter room name: ");
                fgets(roomName, sizeof(roomName), stdin);
                roomName[strcspn(roomName, "\n")] = 0; // Remove newline
                printf("Enter light name: ");
                fgets(lightName, sizeof(lightName), stdin);
                lightName[strcspn(lightName, "\n")] = 0; // Remove newline
                printf("Set intensity: ");
                scanf("%d", &intensity);
                setLightIntensity(roomName, lightName, intensity);
                break;
            case 4:
                printf("Enter room name: ");
                fgets(roomName, sizeof(roomName), stdin);
                roomName[strcspn(roomName, "\n")] = 0; // Remove newline
                getRoomStatus(roomName);
                break;
            case 5:
                simulateSchedule();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}