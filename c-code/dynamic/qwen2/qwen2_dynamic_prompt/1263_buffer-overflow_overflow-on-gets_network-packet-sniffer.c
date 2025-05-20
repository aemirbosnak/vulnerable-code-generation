#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function(char *input) {
    char buffer[16];
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    printf("Welcome to the Network Packet Sniffer\n");
    printf("Enter your packet data: ");
    vulnerable_function(NULL);
    return 0;
}
