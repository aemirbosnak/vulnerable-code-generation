#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50

void get_player_name(char *name) {
    printf("Enter your name: ");
    fgets(name, NAME_LENGTH, stdin);
    // Remove newline character if present
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
}

int main() {
    char playerName[NAME_LENGTH];
    get_player_name(playerName);

    printf("\nWelcome, %s! You find yourself at the entrance of a dark and eerie house.\n", playerName);
    printf("Do you enter through the front door (1) or the back door (2)?\n");

    int choice;
    scanf("%d", &choice);
    getchar(); // Consume the newline character left by scanf

    switch (choice) {
        case 1:
            printf("\nYou enter the front door and find a locked room. Do you try to open it (1) or search for another way out (2)?\n");
            scanf("%d", &choice);
            getchar();
            if (choice == 1) {
                printf("\nThe door is too strong. You decide to search for another way out.\n");
            } else if (choice == 2) {
                printf("\nYou find a secret passage that leads to safety!\n");
            } else {
                printf("\nInvalid choice. The ghostly apparition appears and vanishes into thin air.\n");
            }
            break;
        case 2:
            printf("\nYou enter the back door and see a friendly ghost offering you a map. Do you take it (1) or leave it (2)?\n");
            scanf("%d", &choice);
            getchar();
            if (choice == 1) {
                printf("\nYou follow the map and discover hidden treasures!\n");
            } else if (choice == 2) {
                printf("\nThe ghost becomes upset and disappears, leaving you alone in the house.\n");
            } else {
                printf("\nInvalid choice. A spectral hand reaches out and grabs you!\n");
            }
            break;
        default:
            printf("\nInvalid choice. The house starts to shake and disappears into darkness.\n");
            break;
    }

    return 0;
}
