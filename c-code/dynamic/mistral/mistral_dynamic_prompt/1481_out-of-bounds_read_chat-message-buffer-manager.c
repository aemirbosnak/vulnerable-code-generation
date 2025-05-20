#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void chat_msg(char *buffer, int size, char *msg) {
    char chat[1024];
    strcpy(chat, buffer);
    strcat(chat, msg);
    write(STDOUT_FILENO, chat, strlen(chat));
}

int main(int argc, char **argv) {
    char buffer[16];
    char *message = "Hello, World!\n";

    printf("Enter your chat name (up to 15 characters): ");
    fgets(buffer, sizeof(buffer), stdin);
    chat_msg(buffer, sizeof(buffer), message);

    return 0;
}
