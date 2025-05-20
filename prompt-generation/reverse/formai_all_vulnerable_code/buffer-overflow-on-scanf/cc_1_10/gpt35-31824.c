//FormAI DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_EVENTS 100

// Structure to store event information
typedef struct
{
    char player_name[20];
    char event_desc[100];
    time_t timestamp;
} event_t;

// Function to generate a random event description
char *generate_event_description()
{
    static char *events[] = {
        "collected a power-up",
        "defeated an enemy",
        "completed a level",
        "found a secret area",
        "picked up a coin",
    };
    int i = rand() % 5;
    return events[i];
}

int main()
{
    // Initialize random number generator
    srand(time(NULL));

    // Initialize event log
    event_t event_log[MAX_EVENTS];
    int num_events = 0;

    // Initialize player array
    char player_names[MAX_PLAYERS][20] = {"Player 1", "Player 2", "Player 3", "Player 4"};
    int num_players = 2;

    int choice, player_choice;

    do
    {
        printf("Select an option:\n");
        printf("1. Add player\n");
        printf("2. Remove player\n");
        printf("3. Log event\n");
        printf("4. View log\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Add a player
            if (num_players == MAX_PLAYERS)
            {
                printf("Maximum number of players reached.\n");
            }
            else
            {
                printf("Enter player name: ");
                scanf("%s", player_names[num_players]);
                num_players++;
            }
            break;
        case 2:
            // Remove a player
            if (num_players == 0)
            {
                printf("No players to remove.\n");
            }
            else
            {
                printf("Select a player to remove:\n");
                for (int i = 0; i < num_players; i++)
                {
                    printf("%d. %s\n", i + 1, player_names[i]);
                }
                scanf("%d", &player_choice);
                if (player_choice < 1 || player_choice > num_players)
                {
                    printf("Invalid choice.\n");
                }
                else
                {
                    for (int i = player_choice - 1; i < num_players - 1; i++)
                    {
                        // Shift remaining players left to fill the gap
                        strcpy(player_names[i], player_names[i + 1]);
                    }
                    num_players--;
                }
            }
            break;
        case 3:
            // Log an event
            if (num_players < 2)
            {
                printf("Not enough players to log an event.\n");
            }
            else if (num_events == MAX_EVENTS)
            {
                printf("Event log is full. No more events can be logged.\n");
            }
            else
            {
                printf("Select a player:\n");
                for (int i = 0; i < num_players; i++)
                {
                    printf("%d. %s\n", i + 1, player_names[i]);
                }
                scanf("%d", &player_choice);
                if (player_choice < 1 || player_choice > num_players)
                {
                    printf("Invalid choice.\n");
                }
                else
                {
                    strcpy(event_log[num_events].player_name, player_names[player_choice - 1]);
                    strcpy(event_log[num_events].event_desc, generate_event_description());
                    event_log[num_events].timestamp = time(NULL);
                    num_events++;
                }
            }
            break;
        case 4:
            // View event log
            printf("Event log:\n");
            for (int i = 0; i < num_events; i++)
            {
                printf("%s %s at %s", event_log[i].player_name, event_log[i].event_desc, ctime(&event_log[i].timestamp));
            }
            break;
        case 5:
            // Quit
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}