//FormAI DATASET v1.0 Category: Client Server Application ; Style: retro
/*
 Retro C Client-Server Application: Tic Tac Toe
 Based on the classic pencil and paper game.
 Enjoy this retro game with your friends online!
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define PORT 8080

char board[3][3]; // Tic Tac Toe board

// Function to initialize the board
void init_board() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' '; // Empty cell
        }
    }
}

// Function to print the board
void print_board() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if a player has won
bool check_win(char player) {
    bool row, col, diag;

    // Check rows
    for(int i = 0; i < 3; i++) {
        row = true;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != player) {
                row = false;
            }
        }
        if(row) {
            return true;
        }
    }

    // Check columns
    for(int i = 0; i < 3; i++) {
        col = true;
        for(int j = 0; j < 3; j++) {
            if(board[j][i] != player) {
                col = false;
            }
        }
        if(col) {
            return true;
        }
    }

    // Check diagonals
    diag = true;
    for(int i = 0; i < 3; i++) {
        if(board[i][i] != player) {
            diag = false;
        }
    }
    if(diag) {
        return true;
    }

    diag = true;
    for(int i = 0; i < 3; i++) {
        if(board[i][2-i] != player) {
            diag = false;
        }
    }
    if(diag) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool check_full() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return false; // Empty cell found
            }
        }
    }
    return true; // Board is full
}

// Function to handle a player's turn
bool make_move(char player, int row, int col) {
    if(board[row][col] == ' ') {
        board[row][col] = player; // Mark cell with player's symbol
        return true;
    } else {
        return false; // Cell is already occupied
    }
}

int main() {
    // Initialize the board
    init_board();

    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating the server socket\n");
        exit(1);
    }

    // Create the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        printf("Error binding the server socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if(listen(server_socket, 2) == -1) {
        printf("Error listening for incoming connections\n");
        exit(1);
    }

    // Accept the first client connection
    int client_socket1 = accept(server_socket, NULL, NULL);
    if(client_socket1 == -1) {
        printf("Error accepting the first client connection\n");
        exit(1);
    }

    // Send the start game message to the first client
    char start_msg[] = "Start Game";
    send(client_socket1, start_msg, strlen(start_msg), 0);

    // Accept the second client connection
    int client_socket2 = accept(server_socket, NULL, NULL);
    if(client_socket2 == -1) {
        printf("Error accepting the second client connection\n");
        exit(1);
    }

    // Send the start game message to the second client
    send(client_socket2, start_msg, strlen(start_msg), 0);

    // Play the game
    int row, col;
    char buffer[BUFFER_SIZE];
    bool win, full, valid_move;

    while(true) {
        // Player 1's turn
        // Receive move coordinates from player 1
        memset(buffer, 0, BUFFER_SIZE);
        recv(client_socket1, buffer, BUFFER_SIZE, 0);
        sscanf(buffer, "%d %d", &row, &col);

        // Make the move on the board
        valid_move = make_move('X', row, col);

        // Send the updated board to both players
        print_board();
        sprintf(buffer, "%c %d %d", 'X', row, col);
        send(client_socket1, buffer, strlen(buffer), 0);
        send(client_socket2, buffer, strlen(buffer), 0);

        // Check if player 1 has won
        win = check_win('X');
        if(win) {
            sprintf(buffer, "Player 1 (X) wins!");
            send(client_socket1, buffer, strlen(buffer), 0);
            send(client_socket2, buffer, strlen(buffer), 0);
            break;
        }

        // Check if the board is full
        full = check_full();
        if(full) {
            sprintf(buffer, "Draw!");
            send(client_socket1, buffer, strlen(buffer), 0);
            send(client_socket2, buffer, strlen(buffer), 0);
            break;
        }

        // Player 2's turn
        // Receive move coordinates from player 2
        memset(buffer, 0, BUFFER_SIZE);
        recv(client_socket2, buffer, BUFFER_SIZE, 0);
        sscanf(buffer, "%d %d", &row, &col);

        // Make the move on the board
        valid_move = make_move('O', row, col);

        // Send the updated board to both players
        print_board();
        sprintf(buffer, "%c %d %d", 'O', row, col);
        send(client_socket1, buffer, strlen(buffer), 0);
        send(client_socket2, buffer, strlen(buffer), 0);

        // Check if player 2 has won
        win = check_win('O');
        if(win) {
            sprintf(buffer, "Player 2 (O) wins!");
            send(client_socket1, buffer, strlen(buffer), 0);
            send(client_socket2, buffer, strlen(buffer), 0);
            break;
        }

        // Check if the board is full
        full = check_full();
        if(full) {
            sprintf(buffer, "Draw!");
            send(client_socket1, buffer, strlen(buffer), 0);
            send(client_socket2, buffer, strlen(buffer), 0);
            break;
        }
    }

    // Close the client sockets and server socket
    close(client_socket1);
    close(client_socket2);
    close(server_socket);

    return 0;
}