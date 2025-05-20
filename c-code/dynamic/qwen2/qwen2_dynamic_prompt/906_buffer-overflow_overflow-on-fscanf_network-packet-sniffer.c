#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void read_packet() {
    char buffer[BUFFER_SIZE];
    printf("Enter packet data: ");
    fscanf(stdin, "%s", buffer);
}

int main() {
    while (1) {
        read_packet();
    }
    return 0;
}
