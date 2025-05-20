#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void process_input(char *input) {
    char buffer[10];
    printf("Enter data: ");
    // Deliberate buffer overflow vulnerability using fscanf
    fscanf(stdin, "%s", buffer);
    printf("Data received: %s\n", buffer);
}

int main() {
    char user_input[20];
    printf("Welcome to the Encryption Library Interface\n");
    printf("Please enter your input:\n");
    fgets(user_input, sizeof(user_input), stdin);
    process_input(user_input);
    return 0;
}
