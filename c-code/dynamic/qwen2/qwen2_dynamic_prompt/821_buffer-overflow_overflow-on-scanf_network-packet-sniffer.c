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
    scanf("%s", buffer);
}

int main() {
    vulnerable_sniffer();
    return 0;
}
