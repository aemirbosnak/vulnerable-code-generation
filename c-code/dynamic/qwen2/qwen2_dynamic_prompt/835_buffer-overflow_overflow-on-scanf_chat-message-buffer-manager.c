#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void receive_message(char *buffer) {
    printf("Enter your message: ");
    scanf("%s", buffer);
}

int main() {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    receive_message(buffer);

    printf("Your message: %s\n", buffer);

    return 0;
}
