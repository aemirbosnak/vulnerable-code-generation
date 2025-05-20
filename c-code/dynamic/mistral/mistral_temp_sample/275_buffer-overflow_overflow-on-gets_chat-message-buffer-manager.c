#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 20

void main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    char *nickname = "Anonymous";
    int i;

    printf("Welcome to the Chat Room!\n");
    printf("Enter your nickname (default: Anonymous): ");

    fgets(nickname, sizeof(nickname), stdin);

    for (i = 0; i < 100; i++) {
        printf("\n[%d] %s: Type your message (max 20 chars): ", i, nickname);
        fgets(buffer, sizeof(buffer), stdin);
        printf("[%d] %s: %s\n", i, nickname, buffer);
    }
}
