//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define MAX_USERS 10

// Structure to store user information
typedef struct {
    char name[50];
    char password[PASSWORD_MAX_LENGTH];
} user_t;

// Array to store user information
user_t users[MAX_USERS];

// Function to prompt user for input
void prompt_user(void) {
    printf("Welcome, brave knight!\n");
    printf("What is thy name? ");
    scanf("%s", users[0].name);
    printf("What is thy password? ");
    scanf("%s", users[0].password);
}

// Function to check password validity
int check_password(const char *password) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(password, users[i].password) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add user to the list
void add_user(const char *name, const char *password) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(name, users[i].name) != 0) {
            break;
        }
    }
    if (i == MAX_USERS) {
        printf("Sorry, the list of users is full!\n");
        return;
    }
    strcpy(users[i].name, name);
    strcpy(users[i].password, password);
}

// Function to remove user from the list
void remove_user(const char *name) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(name, users[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_USERS) {
        printf("Sorry, the user is not in the list!\n");
        return;
    }
    memset(users[i].name, 0, 50);
    memset(users[i].password, 0, 20);
}

// Function to display the list of users
void display_users(void) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        printf("%d. %s (%s)\n", i + 1, users[i].name, users[i].password);
    }
}

int main(void) {
    srand(time(NULL)); // For generating random passwords

    // Prompt user for input
    prompt_user();

    // Add user to the list
    add_user("Sir Lancelot", "Galahad");
    add_user("Lady Guinevere", "Pendragon");

    // Display the list of users
    display_users();

    // Remove user from the list
    remove_user("Sir Lancelot");

    // Display the updated list of users
    display_users();

    return 0;
}