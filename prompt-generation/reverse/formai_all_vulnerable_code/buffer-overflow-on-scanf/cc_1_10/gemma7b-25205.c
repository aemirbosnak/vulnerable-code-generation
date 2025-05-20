//Gemma-7B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct SystemAdmin {
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    int accessLevel;
} SystemAdmin;

SystemAdmin admins[10] = {
    {"John Doe", "Secret", 3},
    {"Jane Doe", "Secret", 2},
    {"Admin", "Secret", 5}
};

void authenticate(SystemAdmin* admin) {
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, admin->username) == 0 && strcmp(password, admin->password) == 0) {
        printf("Authentication successful!\n");
    } else {
        printf("Authentication failed.\n");
    }
}

int main() {
    SystemAdmin* currentAdmin = NULL;

    printf("Enter admin username: ");
    char username[MAX_BUFFER_SIZE];
    scanf("%s", username);

    for (int i = 0; i < 10; i++) {
        if (strcmp(username, admins[i].username) == 0) {
            currentAdmin = &admins[i];
            break;
        }
    }

    if (currentAdmin) {
        authenticate(currentAdmin);
    } else {
        printf("User not found.\n");
    }

    return 0;
}