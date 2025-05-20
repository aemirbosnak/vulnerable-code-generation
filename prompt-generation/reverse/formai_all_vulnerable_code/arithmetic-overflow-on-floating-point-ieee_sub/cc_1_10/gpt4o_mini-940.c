//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int account_number;
    char owner_name[100];
    float balance;
} BankAccount;

BankAccount accounts[MAX_CLIENTS];
int account_count = 0;

void create_account(int client_socket) {
    BankAccount new_account;
    recv(client_socket, &new_account, sizeof(new_account), 0);
    accounts[account_count++] = new_account;
    send(client_socket, "Account created successfully.", 29, 0);
}

void view_account(int client_socket) {
    int account_number;
    recv(client_socket, &account_number, sizeof(account_number), 0);
    
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            send(client_socket, &accounts[i], sizeof(accounts[i]), 0);
            return;
        }
    }
    send(client_socket, "Account not found.", 18, 0);
}

void deposit(int client_socket) {
    int account_number;
    float amount;
    recv(client_socket, &account_number, sizeof(account_number), 0);
    recv(client_socket, &amount, sizeof(amount), 0);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            send(client_socket, "Deposit successful.", 20, 0);
            return;
        }
    }
    send(client_socket, "No such account.", 16, 0);
}

void withdraw(int client_socket) {
    int account_number;
    float amount;
    recv(client_socket, &account_number, sizeof(account_number), 0);
    recv(client_socket, &amount, sizeof(amount), 0);

    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                send(client_socket, "Withdrawal successful.", 21, 0);
            } else {
                send(client_socket, "Insufficient funds.", 19, 0);
            }
            return;
        }
    }
    send(client_socket, "No such account.", 16, 0);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Waiting for connections...\n");
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            exit(EXIT_FAILURE);
        }
        
        printf("Connection established with client.\n");
        int choice;
        recv(client_socket, &choice, sizeof(choice), 0);

        switch (choice) {
            case 1:
                create_account(client_socket);
                break;
            case 2:
                view_account(client_socket);
                break;
            case 3:
                deposit(client_socket);
                break;
            case 4:
                withdraw(client_socket);
                break;
            default:
                send(client_socket, "Invalid choice.", 16, 0);
                break;
        }
        
        close(client_socket);
    }

    return 0;
}