//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
/*
 * A unique C Haunted House Simulator example program in a happy style
 *
 * This program will simulate a haunted house experience for the user.
 * It will ask the user for their name and age, and then generate a random
 * sequence of events that the user will experience in the haunted house.
 * The program will also provide the user with a chance to interact with
 * the ghosts and other inhabitants of the haunted house.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 10

typedef struct {
    char name[20];
    int age;
} User;

typedef struct {
    char name[20];
    char description[100];
} Event;

// Function prototypes
void getUserInfo(User *user);
void generateEvents(Event events[], int *num_events);
void printEvents(Event events[], int num_events);

int main() {
    User user;
    Event events[MAX_EVENTS];
    int num_events = 0;

    // Get user information
    getUserInfo(&user);

    // Generate a sequence of events
    generateEvents(events, &num_events);

    // Print the events
    printEvents(events, num_events);

    return 0;
}

void getUserInfo(User *user) {
    printf("Welcome to the haunted house simulator!\n");
    printf("Please enter your name: ");
    scanf("%s", user->name);
    printf("Please enter your age: ");
    scanf("%d", &user->age);
}

void generateEvents(Event events[], int *num_events) {
    // Generate a random sequence of events
    srand(time(NULL));
    for (int i = 0; i < MAX_EVENTS; i++) {
        events[i].name[0] = rand() % 26 + 'A';
        events[i].description[0] = rand() % 26 + 'A';
        (*num_events)++;
    }
}

void printEvents(Event events[], int num_events) {
    printf("You are in a haunted house. You have the following events:\n");
    for (int i = 0; i < num_events; i++) {
        printf(" - %s: %s\n", events[i].name, events[i].description);
    }
}