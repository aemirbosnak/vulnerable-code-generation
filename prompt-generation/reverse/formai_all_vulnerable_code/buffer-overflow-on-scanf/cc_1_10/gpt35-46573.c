//FormAI DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_EVENTS 100

typedef struct {
    char playerName[50];
    char eventDescription[100];
    time_t eventTime;
} Event;

typedef struct {
    char name[50];
    int totalEvents;
    int eventsIndex[MAX_EVENTS];
} Player;

int numPlayers = 0;
Player players[MAX_PLAYERS];
Event events[MAX_EVENTS];
int numEvents = 0;

void addPlayer(char *name) {
    strcpy(players[numPlayers].name, name);
    players[numPlayers].totalEvents = 0;
    numPlayers++;
    printf("%s has joined the game!\n", name);
}

void addEvent(char *name, char *description) {
    int index = -1;
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: player not found\n");
        return;
    }
    
    Event newEvent;
    strcpy(newEvent.playerName, name);
    strcpy(newEvent.eventDescription, description);
    newEvent.eventTime = time(NULL);
    events[numEvents] = newEvent;
    players[index].eventsIndex[players[index].totalEvents] = numEvents;
    players[index].totalEvents++;
    numEvents++;
    printf("%s: %s\n", name, description);
}

void printEvents() {
    printf("Event log:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("%s (%s): %s\n", events[i].playerName, ctime(&events[i].eventTime), events[i].eventDescription);
    }
}

void printPlayerEvents(char *name) {
    int index = -1;
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: player not found\n");
        return;
    }
    
    printf("%s's events:\n", name);
    for (int i = 0; i < players[index].totalEvents; i++) {
        int eventIndex = players[index].eventsIndex[i];
        printf("(%s) %s\n", ctime(&events[eventIndex].eventTime), events[eventIndex].eventDescription);
    }
}

int main() {
    char playerName[50];
    char eventDescription[100];
    int selection;
    
    printf("Welcome to the event logger game!\n");
    printf("Players must add events to the event log.\n");
    printf("Type 1 to add a player, 2 to add an event, 3 to print the event log, 4 to print a player's events, or 5 to quit.\n");
    
    do {
        printf("Selection: ");
        scanf("%d", &selection);
        
        switch (selection) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", playerName);
                addPlayer(playerName);
                break;
            case 2:
                printf("Enter player name: ");
                scanf("%s", playerName);
                printf("Enter event description: ");
                scanf("%s", eventDescription);
                addEvent(playerName, eventDescription);
                break;
            case 3:
                printEvents();
                break;
            case 4:
                printf("Enter player name: ");
                scanf("%s", playerName);
                printPlayerEvents(playerName);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    } while (selection != 5);
    
    return 0;
}