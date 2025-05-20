#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define MAX_USERS 10

typedef struct User {
    char name[20];
    char message[BUFFER_SIZE];
} User;

User users[MAX_USERS];
int num_users = 0;

void add_user(const char* name, const char* message) {
    if (num_users == MAX_USERS) {
        printf("Max number of users reached.\n");
        return;
    }
    strcpy(users[num_users].name, name);
    strcpy(users[num_users].message, message);
    num_users++;
}

void print_chat() {
    for (int i = 0; i < num_users; i++) {
        printf("%s: %s\n", users[i].name, users[i].message);
    }
}

int main() {
    char input_name[20];
    char input_message[BUFFER_SIZE];

    while (1) {
        printf("Enter your name: ");
        scanf("%s", input_name);
        printf("Enter your message (max %d chars): ", BUFFER_SIZE);
        scanf("%s", input_message);

        add_user(input_name, input_message);
        print_chat();
    }

    return 0;
}
