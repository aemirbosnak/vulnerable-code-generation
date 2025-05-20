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
    // Vulnerability here: no bounds checking on input length
    scanf("%s", buffer);
}

int main() {
    char user_input[256];
    printf("Enter data to synchronize: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // Remove newline character
    vulnerable_function(user_input);
    return 0;
}
