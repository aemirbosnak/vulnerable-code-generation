#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    char *message = "Received message: ";
    int index = 0;

    while (1) {
        printf("\n%s", message);
        gets(buffer);
        printf("Message received: %s\n", buffer);
        index = 0;
    }
}
