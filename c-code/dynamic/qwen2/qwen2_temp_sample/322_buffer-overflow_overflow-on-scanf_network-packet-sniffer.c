#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    char buffer[16];
    printf("Enter input: ");
    scanf("%s", buffer); // Vulnerable to buffer overflow
}

int main() {
    printf("Starting packet sniffer...\n");
    while (1) {
        vulnerable_function();
    }
    return 0;
}
