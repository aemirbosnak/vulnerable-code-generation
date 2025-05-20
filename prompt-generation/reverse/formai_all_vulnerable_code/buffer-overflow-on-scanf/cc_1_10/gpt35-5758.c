//FormAI DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_OF_USERS 10
#define MAX_NUM_OF_LIGHTS 10

int numOfUsers, numOfLights;

typedef struct {
    char* username;
    int userId;
    int lightsAccess[MAX_NUM_OF_LIGHTS];
} User;

typedef struct {
    char* lightName;
    int lightId;
    int state; // 1 - ON, 0 - OFF
} Light;

User users[MAX_NUM_OF_USERS];
Light lights[MAX_NUM_OF_LIGHTS];

void initializeUsers() {
    users[0].username = "Alice";
    users[0].userId = 0;
    users[0].lightsAccess[0] = 1;
    users[0].lightsAccess[1] = 1;

    users[1].username = "Bob";
    users[1].userId = 1;
    users[1].lightsAccess[1] = 1;
    users[1].lightsAccess[2] = 1;

    numOfUsers = 2;
}

void initializeLights() {
    lights[0].lightName = "Living Room";
    lights[0].lightId = 0;
    lights[0].state = 0;

    lights[1].lightName = "Bedroom";
    lights[1].lightId = 1;
    lights[1].state = 0;

    lights[2].lightName = "Kitchen";
    lights[2].lightId = 2;
    lights[2].state = 0;

    numOfLights = 3;
}

int getUserId(char* username) {
    for(int i=0;i<numOfUsers;i++) {
        if(strcmp(users[i].username, username) == 0) {
            return users[i].userId;
        }
    }
    return -1; // User not found
}

int getLightId(char* lightName) {
    for(int i=0;i<numOfLights;i++) {
        if(strcmp(lights[i].lightName, lightName) == 0) {
            return lights[i].lightId;
        }
    }
    return -1; // Light not found
}

void printLightsState() {
    for(int i=0;i<numOfLights;i++) {
        printf("%s is %s\n", lights[i].lightName, lights[i].state ? "ON" : "OFF");
    }
}

int main() {
    initializeUsers();
    initializeLights();

    char input[100];

    while(1) {
        printf("Enter your username (or 'exit' to quit): ");
        scanf("%s", input);
        if(strcmp(input, "exit") == 0) {
            break;
        }
        int userId = getUserId(input);

        if(userId == -1) {
            printf("User not found.\n");
            continue;
        }

        while(1) {
            printf("Enter the name of the light you want to control (or 'back' to go back): ");
            scanf("%s", input);

            if(strcmp(input, "back") == 0) {
                break;
            }

            int lightId = getLightId(input);

            if(lightId == -1) {
                printf("Light not found.\n");
                continue;
            }

            if(users[userId].lightsAccess[lightId] == 0) {
                printf("You don't have access to control this light.\n");
                continue;
            }

            printf("Enter the state of the light (0 = OFF, 1 = ON): ");
            int state;
            scanf("%d", &state);

            lights[lightId].state = state;

            printf("%s is turned %s.\n", lights[lightId].lightName, state ? "ON" : "OFF");
            printf("Current lights state:\n");
            printLightsState();
        }
    }
    return 0;
}