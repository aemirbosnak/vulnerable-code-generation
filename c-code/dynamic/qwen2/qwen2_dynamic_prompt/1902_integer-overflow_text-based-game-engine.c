#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_user_input(int input) {
    int buffer[10];
    int i = 0;
    while (i < input) {
        buffer[i] = i * 2; // Integer overflow vulnerability here
        i++;
    }
}

int main() {
    printf("Welcome to the Text-Based Game Engine!\n");
    printf("Enter a number: ");
    int user_input;
    scanf("%d", &user_input);
    process_user_input(user_input);
    printf("Processing complete.\n");
    return 0;
}
