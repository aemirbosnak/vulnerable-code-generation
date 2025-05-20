//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 30
#define DATE_STRING_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t dateJoined;
} Player;

void displayWelcomeMessage() {
    printf("Welcome to the Multiplayer Natural Language Date Converter!\n");
    printf("Join the game and see what dates mean in a fun way!\n");
}

void getPlayerName(char* name) {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character
}

void addPlayer(Player* players, int* playerCount) {
    if (*playerCount < MAX_PLAYERS) {
        getPlayerName(players[*playerCount].name);
        players[*playerCount].dateJoined = time(NULL);
        (*playerCount)++;
        printf("Player %s joined the game!\n", players[*playerCount - 1].name);
    } else {
        printf("Maximum player limit reached!\n");
    }
}

void displayPlayers(Player* players, int playerCount) {
    printf("\nCurrent players in the game:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%d. %s (Joined on: %s)\n", i + 1, players[i].name, ctime(&players[i].dateJoined));
    }
}

void getDateFromPlayer(char* dateInput) {
    printf("Enter a date in natural language (e.g., 'yesterday', '2 weeks ago', 'next Saturday'): ");
    fgets(dateInput, DATE_STRING_LENGTH, stdin);
    dateInput[strcspn(dateInput, "\n")] = 0; // Remove newline character
}

void convertDate(const char* dateInput) {
    struct tm tm = {0};
    time_t now = time(NULL);
    time_t resultTime;

    if (strstr(dateInput, "yesterday")) {
        resultTime = now - 86400; // 86400 seconds in a day
    } else if (strstr(dateInput, "today")) {
        resultTime = now;
    } else if (strstr(dateInput, "tomorrow")) {
        resultTime = now + 86400;
    } else if (sscanf(dateInput, "%d days ago", &tm.tm_mday)) {
        resultTime = now - (tm.tm_mday * 86400);
    } else if (sscanf(dateInput, "%d days", &tm.tm_mday)) {
        resultTime = now + (tm.tm_mday * 86400);
    } else {
        printf("Date not recognized!\n");
        return;
    }
    
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", localtime(&resultTime));
    printf("The converted date is: %s\n", buffer);
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    char dateInput[DATE_STRING_LENGTH];

    displayWelcomeMessage();

    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Join Game\n");
        printf("2. Display Players\n");
        printf("3. Natural Language Date Conversion\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                addPlayer(players, &playerCount);
                break;
            case 2:
                displayPlayers(players, playerCount);
                break;
            case 3:
                getDateFromPlayer(dateInput);
                convertDate(dateInput);
                break;
            case 4:
                printf("Exiting the game. Thank you for playing!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}