#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void vulnerable_function(char *input) {
    char buffer[BUFFER_SIZE];
    printf("Input: %s\n", input);
    strcpy(buffer, input); // Potential buffer overflow here
}

int main() {
    char user_input[256];
    printf("Enter data to synchronize: ");
    scanf("%255s", user_input); // Vulnerable to buffer overflow
    vulnerable_function(user_input);
    return 0;
}
