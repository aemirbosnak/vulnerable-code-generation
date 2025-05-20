#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define USER_NUM 1000

char messages[USER_NUM][BUFFER_SIZE];
int num_users = 0;

void add_message(char* user, char* message) {
    if (num_users >= USER_NUM) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }
    strcpy(messages[num_users], user);
    strcpy(messages[num_users + 1], message);
    num_users += 2;
}

void print_messages() {
    for (int i = 0; i < num_users; i += 2) {
        printf("%s: %s\n", messages[i], messages[i + 1]);
    }
}

int main() {
    char input_user[BUFFER_SIZE];
    char input_msg[BUFFER_SIZE];

    while (1) {
        printf("Enter user name: ");
        fgets(input_user, BUFFER_SIZE, stdin);
        printf("Enter message: ");
        fgets(input_msg, BUFFER_SIZE, stdin);

        add_message(input_user, input_msg);
        print_messages();

        if (num_users > USER_NUM) {
            printf("Error: Trying to add more users.\n");
            free(messages);
            return 1;
        }
    }

    return 0;
}
