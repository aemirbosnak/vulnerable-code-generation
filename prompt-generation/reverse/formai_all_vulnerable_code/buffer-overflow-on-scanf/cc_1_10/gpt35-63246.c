//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DRONES 4
#define MAX_PLAYERS 2

void display_menu();
void initialize_drones(int drones[MAX_DRONES]);
bool is_valid_input(int input);
bool is_valid_drone(int drone_id);
bool is_valid_player(int player_id);
void control_drone(int drones[MAX_DRONES], int player_id, int drone_id, int direction);
void display_map(int drones[MAX_DRONES]);

int main()
{
    int drones[MAX_DRONES];
    int player1_drones = MAX_DRONES / MAX_PLAYERS;
    int player2_drones = MAX_DRONES / MAX_PLAYERS;
    int player1_score = 0, player2_score = 0;
    int player1_input, player2_input;
    int i, j;

    initialize_drones(drones);

    while (true) {
        display_map(drones);

        printf("\nPlayer 1 Score: %d", player1_score);
        printf("\nPlayer 2 Score: %d", player2_score);

        printf("\n\nPlayer 1, Choose your drone (1-%d): ", player1_drones);
        scanf("%d", &player1_input);

        while (!is_valid_input(player1_input) || !is_valid_drone(player1_input - 1)) {
            printf("Invalid input! Please try again.\n\n");
            printf("Player 1, Choose your drone (1-%d): ", player1_drones);
            scanf("%d", &player1_input);
        }

        printf("\nPlayer 2, Choose your drone (%d-%d): ", player1_drones + 1, MAX_DRONES);
        scanf("%d", &player2_input);

        while (!is_valid_input(player2_input) || !is_valid_drone(player2_input - 1) ||
               ((player2_input - 1) < player1_drones)) {
            printf("Invalid input! Please try again.\n\n");
            printf("Player 2, Choose your drone (%d-%d): ", player1_drones + 1, MAX_DRONES);
            scanf("%d", &player2_input);
        }

        printf("\nPlayer 1, Choose direction (1-Up, 2-Down, 3-Left, 4-Right): ");
        scanf("%d", &player1_input);

        while (!is_valid_input(player1_input)) {
            printf("Invalid input! Please try again.\n\n");
            printf("Player 1, Choose direction (1-Up, 2-Down, 3-Left, 4-Right): ");
            scanf("%d", &player1_input);
        }

        printf("\nPlayer 2, Choose direction (1-Up, 2-Down, 3-Left, 4-Right): ");
        scanf("%d", &player2_input);

        while (!is_valid_input(player2_input)) {
            printf("Invalid input! Please try again.\n\n");
            printf("Player 2, Choose direction (1-Up, 2-Down, 3-Left, 4-Right): ");
            scanf("%d", &player2_input);
        }

        control_drone(drones, 0, player1_input - 1, player1_input);
        control_drone(drones, 1, player2_input - 1, player2_input);

        for (i = 0; i < MAX_DRONES; i++)
            for (j = i + 1; j < MAX_DRONES; j++)
                if (abs(drones[i] - drones[j]) == 1)
                    if (i < player1_drones && j < player1_drones) {
                        player1_score++;
                        drones[i] = drones[j] = -1;
                    } else if (i >= player1_drones && j >= player1_drones) {
                        player2_score++;
                        drones[i] = drones[j] = -1;
                    }

        if (player1_score + player2_score == MAX_DRONES / 2)
            break;
    }

    display_map(drones);
    printf("\n\nFinal Score:\n");
    printf("Player 1: %d\n", player1_score);
    printf("Player 2: %d\n", player2_score);
    printf("\n%s is the winner!\n\n", player1_score > player2_score ? "Player 1" : "Player 2");

    return 0;
}

void display_menu()
{
    printf("\nMultiplayer Drone Control\n");
    printf("-------------------------\n");
    printf("Controls:\n");
    printf("1-Up\n");
    printf("2-Down\n");
    printf("3-Left\n");
    printf("4-Right\n");
    printf("-------------------------\n");
}

void initialize_drones(int drones[MAX_DRONES])
{
    int i;

    for (i = 0; i < MAX_DRONES; i++)
        drones[i] = i;
}

bool is_valid_input(int input)
{
    return (input >= 1 && input <= 4);
}

bool is_valid_drone(int drone_id)
{
    return (drone_id >= 0 && drone_id < MAX_DRONES);
}

bool is_valid_player(int player_id)
{
    return (player_id >= 0 && player_id < MAX_PLAYERS);
}

void control_drone(int drones[MAX_DRONES], int player_id, int drone_id, int direction)
{
    switch (direction) {
        case 1: // Up
            if (drones[drone_id] > 3)
                drones[drone_id] -= 4;
            break;
        case 2: // Down
            if (drones[drone_id] < 8)
                drones[drone_id] += 4;
            break;
        case 3: // Left
            if (drones[drone_id] % 4 != 0)
                drones[drone_id]--;
            break;
        case 4: // Right
            if ((drones[drone_id] + 1) % 4 != 0)
                drones[drone_id]++;
            break;
        default:
            break;
    }
}

void display_map(int drones[MAX_DRONES])
{
    int i;

    system("clear");

    display_menu();

    printf("\n");
    printf("|---|---|---|---|\n");

    for (i = 0; i < MAX_DRONES; i++) {
        if (i % 4 == 0)
            printf("|");
        if (drones[i] == -1)
            printf(" X |");
        else if (drones[i] < 10)
            printf(" %d |", drones[i]);
        else
            printf(" %d|", drones[i]);
        if (i % 4 == 3)
            printf("\n|---|---|---|---|\n");
    }

    printf("\n");
}