//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maximum number of players
#define MAX_PLAYERS 4 

// Maximum size of the game board
#define MAX_SIZE 10 

// Number of pairs to be matched
#define NUM_PAIRS 10 

// Structure for the game board
typedef struct {
    int value;
    int visible;
} Card;

// Structure for a player
typedef struct {
    int id;
    int score;
    int turn;
} Player;

// Function prototypes
void create_board(Card board[][MAX_SIZE], int size);
void display_board(Card board[][MAX_SIZE], int size);
void shuffle_cards(Card cards[], int num_pairs);
void reset_board(Card board[][MAX_SIZE], int size);
void start_game(Player players[], Card board[][MAX_SIZE], int size, int num_players);
int get_choice(int size);
void print_scores(Player players[], int num_players);

int main() {
    int size, num_players;
    printf("Enter the size of the square board: ");
    scanf("%d", &size);
    printf("Enter the number of players (2-4): ");
    scanf("%d", &num_players);
    printf("\n");

    // Validate inputs
    if (size > MAX_SIZE) {
        printf("Error: Maximum board size exceeded.\n");
        return 1;
    }
    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Error: Invalid number of players.\n");
        return 1;
    }

    // Seed random number generator
    srand(time(NULL));

    // Create game board
    Card board[MAX_SIZE][MAX_SIZE];
    create_board(board, size);

    // Initialize players
    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        players[i].id = i + 1;
        players[i].score = 0;
        players[i].turn = 0;
    }

    // Start the game
    start_game(players, board, size, num_players);

    return 0;
}

/*
 * Create the game board with randomly shuffled cards
 */
void create_board(Card board[][MAX_SIZE], int size) {
    // Initialize cards
    Card cards[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i += 2) {
        cards[i].value = cards[i + 1].value = i / 2 + 1;
        cards[i].visible = cards[i + 1].visible = 0;
    }

    // Shuffle cards
    shuffle_cards(cards, NUM_PAIRS);

    // Fill board with cards
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = cards[count++];
        }
    }
}

/*
 * Display the game board
 */
void display_board(Card board[][MAX_SIZE], int size) {
    printf("   ");
    for (int i = 0; i < size; i++) {
        printf("%2d%c", i + 1, (i < size - 1) ? ' ' : '\n');
    }
    printf("  ");
    for (int i = 0; i < size * 2 - 1; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%2d|", i + 1);
        for (int j = 0; j < size; j++) {
            if (board[i][j].visible) {
                printf("%2d", board[i][j].value);
            } else {
                printf("  ");
            }
            printf("%c", (j < size - 1) ? ' ' : '\n');
        }
    }
}

/*
 * Shuffle the cards randomly
 */
void shuffle_cards(Card cards[], int num_pairs) {
    // Copy cards to temporary array
    Card temp[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        temp[i] = cards[i];
    }

    // Shuffle cards
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        Card tempcard = temp[i];
        temp[i] = temp[j];
        temp[j] = tempcard;
    }

    // Copy shuffled cards back to original array
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        cards[i] = temp[i];
    }
}

/*
 * Reset the game board
 */
void reset_board(Card board[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j].visible = 0;
        }
    }
}

/*
 * Start the game
 */
void start_game(Player players[], Card board[][MAX_SIZE], int size, int num_players) {
    int num_turns = 0;
    int match_found = 0;
    int prev_choice[2] = {-1, -1};

    while (num_turns < size * size) {
        // Determine current player
        int current_player = num_turns % num_players;

        // Display game board
        printf("Player %d's turn:\n", players[current_player].id);
        display_board(board, size);

        // Get player's choice of card
        int choice[2];
        do {
            choice[0] = get_choice(size) - 1;
            choice[1] = get_choice(size) - 1;
        } while (board[choice[0]][choice[1]].visible);

        // Reveal card and check for match
        board[choice[0]][choice[1]].visible = 1;
        if (prev_choice[0] != -1 && prev_choice[1] != -1) {
            num_turns++;
            if (board[choice[0]][choice[1]].value == board[prev_choice[0]][prev_choice[1]].value) {
                printf("Match found!\n");
                match_found = 1;
                players[current_player].score++;
                if (players[current_player].score == NUM_PAIRS) {
                    // Game over
                    printf("Player %d wins!\n\n", players[current_player].id);
                    print_scores(players, num_players);
                    return;
                }
            } else {
                printf("No match.\n");
                // Switch turn to next player
                players[current_player].turn = 0;
                do {
                    current_player = (current_player + 1) % num_players;
                } while (players[current_player].turn == 0);
            }
            reset_board(board, size);
            match_found = 0;
            prev_choice[0] = prev_choice[1] = -1;
        } else {
            prev_choice[0] = choice[0];
            prev_choice[1] = choice[1];
        }
        players[current_player].turn = 1;
    }

    // Use tiebreaker if players have same score
    int max_score = 0, max_player = 0, tie = 0;
    for (int i = 0; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            max_player = i;
            tie = 0;
        } else if (players[i].score == max_score) {
            tie = 1;
        }
    }

    // Display winner(s)
    if (tie) {
        printf("Game is tied!\n\n");
    } else {
        printf("Player %d wins!\n\n", players[max_player].id);
    }
    print_scores(players, num_players);
}

/*
 * Get player's choice of card
 */
int get_choice(int size) {
    int choice;
    do {
        printf("Enter row and column numbers: ");
        scanf("%d%d", &choice, &choice);
        if (choice < 1 || choice > size) {
            printf("Error: Invalid choice.\n");
        }
    } while (choice < 1 || choice > size);
    return choice;
}

/*
 * Print the scores of all players
 */
void print_scores(Player players[], int num_players) {
    printf("Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", players[i].id, players[i].score);
    }
}