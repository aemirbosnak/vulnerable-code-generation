#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define MAX_USERS 10

struct user {
    char name[20];
    char message[BUFFER_SIZE];
};

struct user users[MAX_USERS];
int num_users = 0;

void add_user(char *name, char *message) {
    if (num_users >= MAX_USERS) {
        printf("No more room for users.\n");
        return;
    }
    strcpy(users[num_users].name, name);
    strcpy(users[num_users].message, message);
    num_users++;
}

void display_messages() {
    for (int i = 0; i < num_users; i++) {
        printf("%s: %s\n", users[i].name, users[i].message);
    }
}

int main() {
    char input_name[20];
    char input_message[BUFFER_SIZE];
    int user_index;

    while (1) {
        printf("Enter your name: ");
        scanf("%s", input_name);

        printf("Enter your message (press enter to exit): ");
        getchar();
        fgets(input_message, BUFFER_SIZE, stdin);

        user_index = num_users - 1;
        if (num_users > 0) {
            strcat(users[user_index].message, input_message);
        } else {
            strcpy(users[0].message, input_message);
        }
        add_user(input_name, input_message);

        display_messages();
    }

    return 0;
}
