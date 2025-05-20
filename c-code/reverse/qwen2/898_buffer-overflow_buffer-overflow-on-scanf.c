#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char name[10];
    int choice;

    printf("Welcome to the Haunted House Adventure Game!\n");
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\nYou find yourself in a dark room with two doors.\n");
    printf("Which door do you choose? (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou enter a room filled with eerie paintings.\n");
        printf("Do you touch one of them? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nThe painting comes alive and attacks you!\n");
            printf("Game Over.\n");
        } else {
            printf("\nYou safely exit the room.\n");
        }
    } else if (choice == 2) {
        printf("\nYou step into a dimly lit corridor.\n");
        printf("Do you follow it? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou encounter a ghost who guides you to safety.\n");
            printf("Congratulations! You win!\n");
        } else {
            printf("\nYou turn back and find a trap door leading to a pit.\n");
            printf("Game Over.\n");
        }
    } else {
        printf("\nInvalid choice. Game Over.\n");
    }

    return 0;
}
