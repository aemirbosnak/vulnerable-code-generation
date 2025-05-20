#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void game_init() {
    char name[BUFFER_SIZE];
    printf("Welcome to the SecureGame!\n");
    printf("Please enter your name: ");
    fscanf(stdin, "%s", name);
    printf("Hello, %s! You are now a proud player of SecureGame!\n");
}

void game_play() {
    char user_input[BUFFER_SIZE];
    printf("\nIt's time to play the game!\n");
    printf("Enter your move (type 'q' to quit): ");
    fgets(user_input, BUFFER_SIZE, stdin);
    // Exploit potential - overflow occurs here
    printf("You entered: %s\n", user_input);
}

int main() {
    game_init();
    game_play();
    return 0;
}
