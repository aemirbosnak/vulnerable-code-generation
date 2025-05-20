//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 1000
#define MAX_TRADES 10000
#define MAX_USERS 100

typedef struct {
    char symbol[10];
    double price;
    int volume;
    time_t timestamp;
} Trade;

typedef struct {
    char username[20];
    char password[20];
} User;

Trade trades[MAX_TRADES];
User users[MAX_USERS];

int num_trades = 0;
int num_users = 0;

void add_trade(char symbol[10], double price, int volume) {
    if (num_trades >= MAX_TRADES) {
        printf("Error: Maximum number of trades reached.\n");
        return;
    }

    strcpy(trades[num_trades].symbol, symbol);
    trades[num_trades].price = price;
    trades[num_trades].volume = volume;
    trades[num_trades].timestamp = time(NULL);

    num_trades++;
}

void add_user(char username[20], char password[20]) {
    if (num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);

    num_users++;
}

int login(char username[20], char password[20]) {
    int i;

    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }

    return -1;
}

void logout(int user_id) {
    // TODO: Implement logout functionality
}

void view_trades(int user_id) {
    int i;

    for (i = 0; i < num_trades; i++) {
        printf("Trade #%d: %s @ $%.2f (%d shares)\n", i+1, trades[i].symbol, trades[i].price, trades[i].volume);
    }
}

int main() {
    int choice;
    char username[20];
    char password[20];
    int user_id;

    printf("Welcome to the stock market tracker!\n");
    printf("Please enter your username and password to login:\n");
    scanf("%s %s", username, password);

    user_id = login(username, password);

    if (user_id == -1) {
        printf("Invalid username or password.\n");
        return 1;
    }

    do {
        printf("\nPlease choose an option:\n");
        printf("1. View trades\n");
        printf("2. Logout\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_trades(user_id);
                break;
            case 2:
                logout(user_id);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}