//FormAI DATASET v1.0 Category: Networking ; Style: multiplayer
// Multiplayer Tic Tac Toe game using C Networking

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define PORT 8080

int socket_desc, client_sock, c, *new_sock;
struct sockaddr_in server, client;
char *client_message;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int turn = 1, choice, win;

// Function to print Tic Tac Toe board
void print_board(){
    printf("\nTic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

// Function to check the status of the game
int check_win(){
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) return 1;
    else if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) return 1;
    else if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) return 1;
    else if(board[0][0] == board[1][0] && board[1][0] == board[2][0]) return 1;
    else if(board[0][1] == board[1][1] && board[1][1] == board[2][1]) return 1;
    else if(board[0][2] == board[1][2] && board[1][2] == board[2][2]) return 1;
    else if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    else if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' 
            && board[1][1] != '5' && board[1][2] != '6' && board[2][0] != '7' && board[2][1] 
            != '8' && board[2][2] != '9') return 0;
    else return -1;
}

// Function to handle player connection
void *handle_player(void *sock){
    int client_sock = *(int*)sock;
    int read_size;
    char *message, client_choice[2];

    while((read_size = recv(client_sock, client_choice, 2, 0)) > 0){
        choice = atoi(client_choice);
        if(turn == 1 && choice > 0 && choice < 10 && board[(choice-1)/3][(choice-1)%3] == (choice + '0')){
            board[(choice-1)/3][(choice-1)%3] = 'X';
            turn = 2;
            message = "Your turn";
            send(client_sock, message, strlen(message), 0);
            win = check_win();
            if(win == 1){
                printf("Player 1 wins!\n");
                exit(1);
            }
            else if(win == 0){
                printf("Game draw!\n");
                exit(1);
            }
        }
        else if(turn == 2 && choice > 0 && choice < 10 && board[(choice-1)/3][(choice-1)%3] == (choice + '0')){
            board[(choice-1)/3][(choice-1)%3] = 'O';
            turn = 1;
            message = "Your turn";
            send(client_sock, message, strlen(message), 0);
            win = check_win();
            if(win == 1){
                printf("Player 2 wins!\n");
                exit(1);
            }
            else if(win == 0){
                printf("Game draw!\n");
                exit(1);
            }
        }
        else{
            message = "Invalid move";
            send(client_sock, message, strlen(message), 0);
        }

        // Send updated board to both players
        print_board();
        send(client_sock, board, sizeof(board), 0);
        message = "Waiting for other player";
        send(client_sock, message, strlen(message), 0);
        memset(client_choice, 0, 2);
    }

    if(read_size == 0){
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1){
        perror("recv failed");
    }

    close(client_sock);
    free(sock);

    return 0;
}

// Main function
int main(int argc, char *argv[]){
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1){
        printf("Could not create socket");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if(bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0){
        perror("bind failed. Error");
        return 1;
    }
    puts("Game server started. Waiting for players...");

    listen(socket_desc, 2);

    c = sizeof(struct sockaddr_in);

    while((client_sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c))){
        puts("Player connected");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;

        if(pthread_create(&sniffer_thread, NULL, handle_player, (void*)new_sock) > 0){
            perror("could not create pthread");
            return 1;
        }
    }   

    if(client_sock < 0){
        perror("accept failed");
        return 1;
    }

    return 0;
}