//FormAI DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_TRANSACTIONS 1000

struct user {
    char username[20];
    char password[20];
    float balance;
};

struct transaction {
    char sender[20];
    char receiver[20];
    float amount;
};

struct user users[MAX_USERS];
int num_users = 0;

struct transaction transactions[MAX_TRANSACTIONS];
int num_transactions = 0;

void register_user() {
    char username[20], password[20];
    printf("Enter desired username: ");
    scanf("%s", username);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0) {
            printf("Username already taken. Try again.\n");
            return;
        }
    }
    printf("Enter desired password: ");
    scanf("%s", password);
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    users[num_users].balance = 0.0;
    printf("Account created!\n");
    num_users++;
}

int login_user() {
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && 
            strcmp(password, users[i].password) == 0) {
            printf("Logged in successfully!\n");
            return i;
        }
    }
    printf("Invalid username or password.\n");
    return -1;
}

void deposit(struct user *u) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    u->balance += amount;
    printf("Deposit successful. New balance: %.2f\n", u->balance);
    strcpy(transactions[num_transactions].sender, "N/A");
    strcpy(transactions[num_transactions].receiver, u->username);
    transactions[num_transactions].amount = amount;
    num_transactions++;
}

void withdraw(struct user *u) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > u->balance || amount < 0) {
        printf("Invalid amount.\n");
        return;
    }
    u->balance -= amount;
    printf("Withdrawal successful. New balance: %.2f\n", u->balance);
    strcpy(transactions[num_transactions].sender, u->username);
    strcpy(transactions[num_transactions].receiver, "N/A");
    transactions[num_transactions].amount = amount;
    num_transactions++;
}

void transfer(struct user *u) {
    char recipient[20];
    float amount;
    struct user *rec = NULL;
    printf("Enter recipient's username: ");
    scanf("%s", recipient);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(recipient, users[i].username) == 0) {
            rec = &users[i];
            break;
        }
    }
    if (rec == NULL) {
        printf("Recipient not found.\n");
        return;
    }
    printf("Enter amount to transfer: ");
    scanf("%f", &amount);
    if (amount > u->balance || amount < 0) {
        printf("Invalid amount.\n");
        return;
    }
    u->balance -= amount;
    rec->balance += amount;
    printf("Transfer successful. New balance: %.2f\n", u->balance);
    strcpy(transactions[num_transactions].sender, u->username);
    strcpy(transactions[num_transactions].receiver, rec->username);
    transactions[num_transactions].amount = amount;
    num_transactions++;
}

void view_history(struct user *u) {
    printf("--------------------\n");
    for (int i = 0; i < num_transactions; i++) {
        if (strcmp(transactions[i].sender, u->username) == 0 ||
            strcmp(transactions[i].receiver, u->username) == 0) {
            printf("Transaction %d:\n", i+1);
            printf("Sender: %s\n", transactions[i].sender);
            printf("Receiver: %s\n", transactions[i].receiver);
            printf("Amount: %.2f\n", transactions[i].amount);
            printf("--------------------\n");
        }
    }
}

int main() {
    int choice = 0;
    int current_user = -1;
    while (1) {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Transfer\n");
        printf("6. View Transaction History\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                current_user = login_user();
                break;
            case 3:
                if (current_user == -1) {
                    printf("Please log in.\n");
                } else {
                    deposit(&users[current_user]);
                }
                break;
            case 4:
                if (current_user == -1) {
                    printf("Please log in.\n");
                } else {
                    withdraw(&users[current_user]);
                }
                break;
            case 5:
                if (current_user == -1) {
                    printf("Please log in.\n");
                } else {
                    transfer(&users[current_user]);
                }
                break;
            case 6:
                if (current_user == -1) {
                    printf("Please log in.\n");
                } else {
                    view_history(&users[current_user]);
                }
                break;
            case 7:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}