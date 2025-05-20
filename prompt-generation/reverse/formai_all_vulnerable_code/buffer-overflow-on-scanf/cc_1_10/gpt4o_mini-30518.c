//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_YEARS 100
#define MAX_EVENTS 10

typedef struct {
    char name[50];
    int year;
    char event[100];
} TimeEvent;

typedef struct {
    char username[50];
    int currentYear;
    TimeEvent events[MAX_EVENTS];
    int eventCount;
} User;

User users[MAX_USERS];
int userCount = 0;

void initializeUser(User *user, const char *username) {
    strcpy(user->username, username);
    user->currentYear = 2023; // Start in the current year
    user->eventCount = 0;
}

void addEvent(User *user, const char *eventName, int year) {
    if (user->eventCount < MAX_EVENTS) {
        strcpy(user->events[user->eventCount].event, eventName);
        user->events[user->eventCount].year = year;
        user->eventCount++;
    } else {
        printf("Event limit reached for user %s!\n", user->username);
    }
}

void displayEvents(const User *user) {
    printf("Events for %s:\n", user->username);
    for (int i = 0; i < user->eventCount; i++) {
        printf("Year: %d, Event: %s\n", user->events[i].year, user->events[i].event);
    }
}

int findUserIndex(const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void timeTravel(User *user, int targetYear) {
    if (targetYear < 1900 || targetYear > 2100) {
        printf("Invalid year: Must be between 1900 and 2100.\n");
        return;
    }
    
    user->currentYear = targetYear;
    printf("%s has traveled to the year %d.\n", user->username, user->currentYear);
}

void displayMenu(User *user) {
    printf("\nWelcome to the Time Travel Simulator, %s!\n", user->username);
    printf("Current Year: %d\n", user->currentYear);
    printf("1. Time Travel\n");
    printf("2. Add Event\n");
    printf("3. Display Events\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);

    int userIndex = findUserIndex(username);
    if (userIndex == -1) {
        initializeUser(&users[userCount], username);
        userIndex = userCount;
        userCount++;
    }

    User *currentUser = &users[userIndex];
    int option, targetYear;

    while (1) {
        displayMenu(currentUser);
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the year you want to travel to: ");
                scanf("%d", &targetYear);
                timeTravel(currentUser, targetYear);
                break;
            case 2:
                if (currentUser->currentYear != 2023) {
                    printf("You can only add events in the current year (2023).\n");
                } else {
                    char eventName[100];
                    printf("Enter event name: ");
                    scanf(" %[^\n]", eventName); // Read string with spaces
                    addEvent(currentUser, eventName, currentUser->currentYear);
                }
                break;
            case 3:
                displayEvents(currentUser);
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Goodbye, %s!\n", currentUser->username);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}