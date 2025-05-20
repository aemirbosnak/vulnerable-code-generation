#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE];

void read_message() {
    printf("Enter a message: ");
    fgets(buffer, sizeof(buffer), stdin);
}

void print_message() {
    printf("Message: %s", buffer);
}

int main() {
    read_message();
    print_message();
    return 0;
}
