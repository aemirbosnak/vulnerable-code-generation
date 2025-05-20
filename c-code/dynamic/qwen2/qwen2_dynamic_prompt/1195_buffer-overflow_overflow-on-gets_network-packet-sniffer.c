#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function(char *input) {
    char buffer[16];
    gets(buffer); // Vulnerability: Use of gets()
}

int main() {
    printf("Welcome to the Network Packet Sniffer\n");
    printf("Enter your packet data:\n");

    char input[200];
    fgets(input, sizeof(input), stdin);

    vulnerable_function(input);

    printf("Packet processed successfully.\n");
    return 0;
}
