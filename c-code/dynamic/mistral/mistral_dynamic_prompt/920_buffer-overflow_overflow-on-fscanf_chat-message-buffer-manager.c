#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void handle_chat(char *name, char *buffer) {
    char input[BUFFER_SIZE];
    printf("%s: %s, type your message: ", name, buffer);
    fgets(input, BUFFER_SIZE, stdin);
    strcpy(buffer, input);
}

int main() {
    char user1[BUFFER_SIZE];
    char user2[BUFFER_SIZE];
    char message1[BUFFER_SIZE];
    char message2[BUFFER_SIZE];

    printf("Welcome to SecChat!\n");

    printf("Enter user1 name: ");
    fscanf(stdin, "%s", user1);
    printf("Enter user2 name: ");
    fscanf(stdin, "%s", user2);

    while (1) {
        handle_chat(user1, message1);
        printf("%s: %s\n", user2, message2);
        handle_chat(user2, message2);
        printf("%s: %s\n", user1, message1);
    }

    return 0;
}
