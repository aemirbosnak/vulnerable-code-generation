//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 16
#define MAX_QUERY_LENGTH 256

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int balance;
} User;

typedef struct {
    char query[MAX_QUERY_LENGTH];
    int user_id;
} Query;

void print_menu();
int login(User users[], int n_users);
int create_user(User users[], int n_users);
int process_query(Query queries[], int n_queries, User users[], int n_users);

int main() {
    User users[MAX_USERS];
    Query queries[MAX_USERS];
    int n_users = 0;
    int n_queries = 0;

    srand(time(NULL));

    print_menu();

    while (1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login(users, n_users);
                break;
            case 2:
                create_user(users, n_users);
                break;
            case 3:
                process_query(queries, n_queries, users, n_users);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("Welcome to the C Database Simulation Program\n");
    printf("1. Login\n");
    printf("2. Create User\n");
    printf("3. Process Query\n");
    printf("4. Exit\n");
}

int login(User users[], int n_users) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < n_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Successfully logged in as user %d\n", i);
            return i;
        }
    }

    printf("Invalid username or password\n");
    return -1;
}

int create_user(User users[], int n_users) {
    if (n_users >= MAX_USERS) {
        printf("Cannot create user, maximum number of users reached\n");
        return -1;
    }

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);

    printf("Enter a password: ");
    scanf("%s", password);

    for (int i = 0; i < n_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already taken\n");
            return -1;
        }
    }

    User user;
    strcpy(user.username, username);
    strcpy(user.password, password);
    user.balance = 0;
    users[n_users++] = user;

    printf("User created successfully\n");
    return n_users - 1;
}

int process_query(Query queries[], int n_queries, User users[], int n_users) {
    if (n_queries >= MAX_USERS) {
        printf("Cannot process query, maximum number of queries reached\n");
        return -1;
    }

    char query[MAX_QUERY_LENGTH];

    printf("Enter a query: ");
    scanf("%s", query);

    for (int i = 0; i < n_users; i++) {
        if (strcmp(users[i].username, query) == 0) {
            printf("User %d has a balance of $%d\n", i, users[i].balance);
            return i;
        }
    }

    printf("Invalid query\n");
    return -1;
}