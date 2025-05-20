//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define SIZE 200
#define MAX_PLAYERS 4

struct Player {
    char name[20];
    int score;
};

void print_ascii_art(char image[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            putchar(image[i][j]);
        }
        putchar('\n');
    }
}

void convert_image_to_ascii(char image[SIZE][SIZE], char ascii[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] < 51) {
                ascii[i][j] = '@';
            } else if (image[i][j] < 102) {
                ascii[i][j] = '+';
            } else if (image[i][j] < 153) {
                ascii[i][j] = '-';
            } else {
                ascii[i][j] = ' ';
            }
        }
    }
}

void print_scores(struct Player players[MAX_PLAYERS], int num_players) {
    printf("\nLeaderboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s - %d\n", players[i].name, players[i].score);
    }
}

int main() {
    char image[SIZE][SIZE] = {
        {50, 50, 100, 100},
        {100, 153, 200, 102},
        {50, 100, 100, 50},
        {50, 100, 200, 50}
    };
    char ascii[SIZE][SIZE];
    struct Player players[MAX_PLAYERS];
    int num_players = 0;
    
    printf("Welcome to the Image to ASCII Art Converter Game!\n");
    printf("How many players will be playing (up to 4 players)? ");
    scanf("%d", &num_players);
    getchar(); // consume newline
    
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for Player %d: ", i+1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].score = 0;
    }
    
    printf("\nLet's play!\n");
    while (1) {
        printf("\nCurrent Image:\n");
        print_ascii_art(ascii);
        print_scores(players, num_players);
        
        int player_idx = (rand() % num_players);
        printf("\nIt's %s's turn!\n", players[player_idx].name);
        
        printf("Enter a row and column (separated by a space) to change a character: ");
        int row, col;
        scanf("%d %d", &row, &col);
        getchar(); // consume newline
        
        while (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid row or column. Try again: ");
            scanf("%d %d", &row, &col);
            getchar(); // consume newline
        }
        
        printf("Enter the new character: ");
        char c = getchar();
        ascii[row][col] = c;
        players[player_idx].score++;
        
        printf("Press Enter to continue or type 'quit' to end the game: ");
        char input[10];
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q') {
            break;
        }
    }
    
    printf("\nThe final image is:\n");
    print_ascii_art(ascii);
    print_scores(players, num_players);
    
    return 0;
}