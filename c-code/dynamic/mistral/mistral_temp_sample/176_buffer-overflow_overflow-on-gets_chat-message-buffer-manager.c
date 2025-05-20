#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void echo_message(char *message) {
    write(STDOUT_FILENO, message, strlen(message));
}

int main(int argc, char *argv[]) {
    char buffer[10];
    printf("Chat Message Buffer Manager v1.0\n");
    printf("Enter your message (up to 10 characters): ");
    gets(buffer);
    echo_message(buffer);
    return 0;
}
