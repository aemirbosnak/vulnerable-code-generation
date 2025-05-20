#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game_input() {
    char buffer[10];
    printf("Enter your move (up/down/left/right): ");
    fgets(buffer, sizeof(buffer), stdin);

    int move;
    sscanf(buffer, "%d", &move);

    // Game logic here (ignored due to buffer overflow)
}

void main_menu() {
    printf("\nText-Based Game Engine\n");
    printf("1. Play Game\n");
    printf("2. Options\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    main_menu();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            game_input();
            break;
        case 2:
            // Options menu
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option.\n");
            main_menu();
    }

    return 0;
}
