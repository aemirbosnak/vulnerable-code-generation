#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void vulnerable_sniffer() {
    char buffer[BUFFER_SIZE];
    printf("Enter a string: ");
    scanf("%s", buffer); // Vulnerability here
}

int main() {
    printf("Welcome to the Network Packet Sniffer\n");
    vulnerable_sniffer();
    printf("Sniffing complete.\n");
    return 0;
}
