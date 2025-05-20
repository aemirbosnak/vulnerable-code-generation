//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define HASH_LENGTH 64

// User structure
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];
} User;

// Hash function
void hash(char* password, char* hash) {
    for (int i = 0; i < strlen(password); i++) {
        hash[i * 2] = password[i];
    }
    hash[strlen(password) * 2] = '\0';
}

// Compare function
int compare(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

// Sort function
void sort(User* users, int n) {
    qsort(users, n, sizeof(User), compare);
}

// Write function
void write(User* user) {
    printf("Username: %s\n", user->username);
    printf("Password: %s\n", user->password);
    printf("Hash: %s\n\n", user->hash);
}

// Read function
void read(User* user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
    hash(user->password, user->hash);
}

// Main function
int main() {
    User users[MAX_USERS];
    int n = 0;

    // Read users
    while (n < MAX_USERS) {
        User user;
        printf("Enter username: ");
        scanf("%s", user.username);
        if (strcmp(user.username, "exit") == 0) {
            break;
        }
        read(&user);
        users[n] = user;
        n++;
    }

    // Sort users
    sort(users, n);

    // Write users
    printf("Sorted list of users:\n");
    for (int i = 0; i < n; i++) {
        write(&users[i]);
    }

    return 0;
}