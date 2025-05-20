#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char username[20];
    char message[200];
} ChatMessage;

int main(int argc, char *argv[]) {
    ChatMessage chat;

    printf("Enter username: ");
    scanf("%s", chat.username);
    printf("Enter message: ");
    scanf("%s", chat.message);

    printf("\n\nUsername: %s\nMessage: %s\n", chat.username, chat.message);

    return 0;
}
