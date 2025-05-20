//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USER 10
#define MAX_PASSWORD_LENGTH 20
#define HASH_SIZE 32

typedef struct {
    char username[MAX_USER];
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_SIZE];
} User;

void generateHash(char* password, char* hash) {
    unsigned int i;
    for (i = 0; i < strlen(password); i++) {
        hash[i] = password[i] ^ (i + 1);
    }
    hash[strlen(password)] = '\0';
}

int compareHash(char* password, char* hash) {
    unsigned int i;
    for (i = 0; i < strlen(password); i++) {
        if (hash[i]!= password[i] ^ (i + 1)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    User user[MAX_USER];
    int numOfUsers = 0;
    char choice;
    int index;

    do {
        printf("Enter your choice:\n");
        printf("1. Add user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter username: ");
            scanf("%s", user[numOfUsers].username);
            printf("Enter password: ");
            scanf("%s", user[numOfUsers].password);
            generateHash(user[numOfUsers].password, user[numOfUsers].hash);
            numOfUsers++;
            printf("User added successfully!\n");
            break;
        case '2':
            printf("Enter username: ");
            scanf("%s", user[0].username);
            printf("Enter password: ");
            scanf("%s", user[0].password);
            generateHash(user[0].password, user[0].hash);
            index = 0;

            while (index < numOfUsers) {
                if (compareHash(user[index].password, user[0].hash)) {
                    printf("Login successful!\n");
                    break;
                }
                index++;
            }

            if (index == numOfUsers) {
                printf("Invalid username or password!\n");
            }

            break;
        case '3':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= '3');

    return 0;
}