//Code Llama-13B DATASET v1.0 Category: Password management ; Style: modular
// Modules
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char* username;
    char* password;
} User;

typedef struct {
    char* name;
    char* password;
} Account;

// Functions
void prompt_user(User* user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
}

void prompt_account(Account* account) {
    printf("Enter account name: ");
    scanf("%s", account->name);
    printf("Enter account password: ");
    scanf("%s", account->password);
}

void save_user(User* user, char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "%s\n%s", user->username, user->password);
    fclose(file);
}

void save_account(Account* account, char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "%s\n%s", account->name, account->password);
    fclose(file);
}

void load_user(User* user, char* filename) {
    FILE* file = fopen(filename, "r");
    fscanf(file, "%s\n%s", user->username, user->password);
    fclose(file);
}

void load_account(Account* account, char* filename) {
    FILE* file = fopen(filename, "r");
    fscanf(file, "%s\n%s", account->name, account->password);
    fclose(file);
}

void delete_user(User* user, char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "");
    fclose(file);
}

void delete_account(Account* account, char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "");
    fclose(file);
}

// Main function
int main() {
    User user;
    Account account;
    char filename[50];

    prompt_user(&user);
    prompt_account(&account);

    printf("Enter filename: ");
    scanf("%s", filename);

    save_user(&user, filename);
    save_account(&account, filename);

    load_user(&user, filename);
    load_account(&account, filename);

    delete_user(&user, filename);
    delete_account(&account, filename);

    return 0;
}