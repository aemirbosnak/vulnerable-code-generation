//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define NUM_ROOMS 3
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int status; // 0 for OFF, 1 for ON
} Room;

void toggleLight(Room *room) {
    room->status = !room->status;
    printf("The light in %s is now %s.\n", room->name, room->status ? "ON" : "OFF");
}

void displayStatus(Room rooms[], int numRooms) {
    printf("\nLight Status:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("- %s: %s\n", rooms[i].name, rooms[i].status ? "ON" : "OFF");
    }
    printf("\n");
}

void commandHandler(char *command, Room rooms[], int numRooms) {
    if (strcmp(command, "status") == 0) {
        displayStatus(rooms, numRooms);
    } else if (strncmp(command, "toggle ", 7) == 0) {
        char roomName[MAX_NAME_LEN];
        sscanf(command + 7, "%s", roomName);
        for (int i = 0; i < numRooms; i++) {
            if (strcmp(rooms[i].name, roomName) == 0) {
                toggleLight(&rooms[i]);
                return;
            }
        }
        printf("Room %s not found!\n", roomName);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void getTime(char *buffer, int bufferSize) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(buffer, bufferSize, "%04d-%02d-%02d %02d:%02d:%02d", 
              tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
              tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void logAction(char *action) {
    FILE *logFile = fopen("light_control_log.txt", "a");
    if (logFile != NULL) {
        char timeStamp[20];
        getTime(timeStamp, sizeof(timeStamp));
        fprintf(logFile, "[%s] %s\n", timeStamp, action);
        fclose(logFile);
    }
}

int main() {
    Room rooms[NUM_ROOMS] = {
        {"LivingRoom", 0},
        {"Bedroom", 0},
        {"Kitchen", 0},
    };
    
    char command[100];
    
    printf("Welcome to the Smart Home Light Control System!\n");
    
    while (1) {
        printf("Enter command (toggle <RoomName>, status, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the Smart Home Light Control System.\n");
            break;
        }
        
        logAction(command);
        commandHandler(command, rooms, NUM_ROOMS);
    }
    
    return 0;
}