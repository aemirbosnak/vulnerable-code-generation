//FormAI DATASET v1.0 Category: Client Server Application ; Style: retro
// Retro-style Client-Server Tic-Tac-Toe game

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000  // port number
#define BOARD_SIZE 9  // size of the game board

// set up the game board
char board[BOARD_SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// print the current state of the board
void print_board() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// check if there is a winner
char check_winner() {
    // check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i+1] && board[i] == board[i+2]) {
            return board[i];
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i+3] && board[i] == board[i+6]) {
            return board[i];
        }
    }
    // check diagonals
    if (board[0] == board[4] && board[0] == board[8]) {
        return board[0];
    }
    if (board[2] == board[4] && board[2] == board[6]) {
        return board[2];
    }
    // check if there is a tie
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return ' ';
        }
    }
    return 'T';
}

int main(int argc, char **argv) {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // create the server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    // set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind the server socket to the address
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind() error");
        exit(EXIT_FAILURE);
    }

    // start listening for incoming connections
    if (listen(server_sockfd, 1) < 0) {
        perror("listen() error");
        exit(EXIT_FAILURE);
    }

    printf("Server waiting for connection...\n");

    // accept the incoming connection
    client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_len);

    if (client_sockfd < 0) {
        perror("accept() error");
        exit(EXIT_FAILURE);
    }

    printf("Client connected! Starting game...\n");

    bool player_turn = true;
    bool game_over = false;
    char winner;
    int choice;

    while (!game_over) {
        char message[100];

        if (player_turn) {
            sprintf(message, "Your move (X): ");
        } else {
            sprintf(message, "Your move (O): ");
        }

        // send the message to the client
        if (send(client_sockfd, message, sizeof(message), 0) < 0) {
            perror("send() error");
            exit(EXIT_FAILURE);
        }

        // receive the player's choice
        if (recv(client_sockfd, &choice, sizeof(choice), 0) < 0) {
            perror("recv() error");
            exit(EXIT_FAILURE);
        }

        if (player_turn) {
            board[choice-1] = 'X';
        } else {
            board[choice-1] = 'O';
        }

        print_board();

        winner = check_winner();
        if (winner != ' ') {
            game_over = true;
        } else {
            player_turn = !player_turn;
        }
    }

    printf("Game over!\n");

    if (winner == 'T') {
        printf("It's a tie!\n");
    } else {
        printf("Winner: %c\n", winner);
    }

    // close the sockets
    close(client_sockfd);
    close(server_sockfd);

    return 0;
}