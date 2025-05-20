#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 10

void vulnerable_function(char *input) {
    char buffer[MAX_INPUT_SIZE];
    printf("Enter your input: ");
    scanf("%s", buffer);
    printf("You entered: %s\n", buffer);
}

int main() {
    char user_input[20];
    printf("Welcome to the Text Editor!\n");
    printf("Please enter a file name: ");
    scanf("%s", user_input);
    vulnerable_function(user_input);
    return 0;
}
