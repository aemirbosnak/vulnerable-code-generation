//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
/* Romeo and Juliet Intrusion Detection System Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONNECTIONS 100
#define MAX_USERS 50

typedef struct {
    char name[20];
    int age;
    char gender;
    char username[20];
    char password[20];
    int failed_attempts;
} User;

typedef struct {
    char user1[20];
    char user2[20];
    int num_messages;
} Connection;

int main() {
    User users[MAX_USERS];
    Connection connections[MAX_CONNECTIONS];
    int num_users = 0;
    int num_connections = 0;
    char input[20];
    int user_exists = 0;
    int connection_exists = 0;
    
    printf("Welcome to the Romeo and Juliet Intrusion Detection System!\n");

    while(1) {
        printf("\nEnter command: ");
        scanf("%s", input);

        if(strcmp(input, "new_user") == 0) {
            if(num_users >= MAX_USERS) {
                printf("Maximum number of users reached.\n");
                continue;
            }

            printf("Enter name: ");
            scanf("%s", users[num_users].name);

            printf("Enter age: ");
            scanf("%d", &users[num_users].age);

            printf("Enter gender (M/F): ");
            scanf("%s", &users[num_users].gender);

            printf("Enter username: ");
            scanf("%s", users[num_users].username);

            printf("Enter password: ");
            scanf("%s", users[num_users].password);

            users[num_users].failed_attempts = 0;
            num_users++;

        } else if(strcmp(input, "new_connection") == 0) {
            if(num_connections >= MAX_CONNECTIONS) {
                printf("Maximum number of connections reached.\n");
                continue;
            }

            char user1[20], user2[20];

            printf("Enter first user's name: ");
            scanf("%s", user1);

            printf("Enter second user's name: ");
            scanf("%s", user2);

            for(int i = 0; i < num_users; i++) {
                if(strcmp(users[i].name, user1) == 0 || strcmp(users[i].name, user2) == 0) {
                    if(strlen(connections[num_connections].user1) == 0) {
                        strcpy(connections[num_connections].user1, users[i].name);
                    } else {
                        strcpy(connections[num_connections].user2, users[i].name);
                    }
                }
            }

            connections[num_connections].num_messages = 0;
            num_connections++;

        } else if(strcmp(input, "send_message") == 0) {
            char sender[20], receiver[20];

            printf("Enter sender's name: ");
            scanf("%s", sender);

            printf("Enter receiver's name: ");
            scanf("%s", receiver);

            for(int i = 0; i < num_connections; i++) {
                if((strcmp(connections[i].user1, sender) == 0 && strcmp(connections[i].user2, receiver) == 0) ||
                    (strcmp(connections[i].user1, receiver) == 0 && strcmp(connections[i].user2, sender) == 0)) {
                    connections[i].num_messages++;

                    if(connections[i].num_messages >= 5) {
                        printf("\nINTRUSION DETECTED! %s and %s have exchanged more than 5 messages.\n", sender, receiver);
                    }

                    break;
                }
            }

        } else if(strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}