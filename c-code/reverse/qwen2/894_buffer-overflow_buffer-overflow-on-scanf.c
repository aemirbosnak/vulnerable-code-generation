#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char name[10];
    int choice;

    printf("Welcome to the Haunted House Adventure Game!\n");
    printf("Enter your name: ");
    scanf("%9s", name); // Buffer overflow vulnerability here

    printf("\n%s, you find yourself in a dark room. There are two doors.\n", name);
    printf("Which door do you choose? (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou enter a room filled with treasure! You win!\n");
    } else if (choice == 2) {
        printf("\nYou encounter a ghost! Game over.\n");
    } else {
        printf("\nInvalid choice! Game over.\n");
    }

    return 0;
}
