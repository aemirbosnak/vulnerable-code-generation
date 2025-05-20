//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PASSWORD_MAX_LENGTH 20
#define USERNAME_MAX_LENGTH 20

// Structure to store password and username
typedef struct {
    char password[PASSWORD_MAX_LENGTH];
    char username[USERNAME_MAX_LENGTH];
} user_info;

// Function to generate a strong password
void generate_password(user_info *user) {
    int i, j;
    char password[PASSWORD_MAX_LENGTH];
    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        password[i] = 'a' + (rand() % 26);
    }
    strcpy(user->password, password);
}

// Function to store password and username in a file
void store_username_password(user_info *user) {
    FILE *file = fopen("passwords.dat", "w");
    fprintf(file, "%s:%s\n", user->username, user->password);
    fclose(file);
}

// Function to retrieve password and username from file
user_info *retrieve_username_password() {
    FILE *file = fopen("passwords.dat", "r");
    char line[100];
    user_info *user = malloc(sizeof(user_info));
    while (fgets(line, 100, file)) {
        if (sscanf(line, "%s:%s", user->username, user->password) == 2) {
            break;
        }
    }
    fclose(file);
    return user;
}

int main() {
    srand(time(NULL));
    user_info user;
    generate_password(&user);
    store_username_password(&user);
    user_info *retrieved_user = retrieve_username_password();
    printf("Stored password: %s\n", retrieved_user->password);
    free(retrieved_user);
    return 0;
}