//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Define size constants.
#define ROWS 7
#define COLUMNS 80
#define MAX_CLIENTS 10

// Define ASCII art for a player.
const char ascii_player[ROWS][COLUMNS + 1] = {
    {" .-. "},
    {"(o.o)"},
    {("|_|\\")},
    {"   /\\"},
    {"  / /"},
    {" (_/"},
    {"     "}
};

// Define struct to hold client information.
typedef struct {
    int id;
    char name[20];
    int row;
    int column;
} Client;

// Define function to convert text to ASCII art.
void text_to_ascii(char* text, char out[ROWS][COLUMNS + 1]) {
    // First copy the ASCII art for a blank space.
    char ascii_blank[ROWS][COLUMNS + 1];
    memcpy(ascii_blank, ascii_player, sizeof(char) * ROWS * COLUMNS);

    // Replace the character in the center of the blank space with the input text.
    ascii_blank[2][2] = *text;

    // Copy the modified blank space into the output array.
    memcpy(out, ascii_blank, sizeof(char) * ROWS * COLUMNS);
}

// Define function to print the upper border of the game board.
void print_border_top() {
    printf("/");
    for (int i = 0; i < COLUMNS - 2; i++) {
        printf("-");
    }
    printf("\\\n");
}

// Define function to print the lower border of the game board.
void print_border_bottom() {
    printf("\\");
    for (int i = 0; i < COLUMNS - 2; i++) {
        printf("-");
    }
    printf("/\n");
}

// Define function to print a single row of the game board.
void print_row(char row[ROWS][COLUMNS + 1]) {
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", row[i]);
    }
}

// Define function to print the entire game board.
void print_board(Client clients[MAX_CLIENTS], int num_clients) {
    // First print the upper border.
    print_border_top();

    // Then print each row of the game board.
    for (int row = 0; row < ROWS; row++) {
        printf("|");
        for (int column = 0; column < COLUMNS - 2; column++) {
            // Check if there is a player at the current position.
            int player_found = 0;
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].row == row && clients[i].column == column) {
                    // Print the player's name instead of the ASCII art.
                    printf(" %s ", clients[i].name);
                    player_found = 1;
                    break;
                }
            }

            // If there is no player at the current position, print the corresponding ASCII art.
            if (!player_found) {
                printf(" %s ", ascii_player[row][column]);
            }
        }
        printf("|\n");
    }

    // Finally print the lower border.
    print_border_bottom();
}

int main() {
    // Initialize the list of clients.
    Client clients[MAX_CLIENTS];
    int num_clients = 0;

    // Ask the user for their name.
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    // Add the new client to the list.
    clients[0].id = 0;
    strcpy(clients[0].name, name);
    clients[0].row = 0;
    clients[0].column = 0;
    num_clients++;

    // Print the starting game board.
    print_board(clients, num_clients);

    // Keep listening for input from the player.
    while (1) {
        // Ask the player for a direction to move in.
        char direction;
        printf("Enter a direction to move in (w/a/s/d): ");
        scanf(" %c", &direction);

        // Move the player's position according to the input direction.
        switch (direction) {
            case 'w':
                clients[0].row--;
                break;
            case 'a':
                clients[0].column--;
                break;
            case 's':
                clients[0].row++;
                break;
            case 'd':
                clients[0].column++;
                break;
        }

        // Make sure the player's position is within the boundaries of the game board.
        if (clients[0].row < 0) {
            clients[0].row = 0;
        }
        if (clients[0].row >= ROWS) {
            clients[0].row = ROWS - 1;
        }
        if (clients[0].column < 0) {
            clients[0].column = 0;
        }
        if (clients[0].column >= COLUMNS - 2) {
            clients[0].column = COLUMNS - 3;
        }

        // Print the updated game board.
        print_board(clients, num_clients);
    }

    return 0;
}