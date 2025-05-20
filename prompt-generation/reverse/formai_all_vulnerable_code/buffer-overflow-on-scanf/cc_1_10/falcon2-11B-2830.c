//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_menu() {
    printf("1. Go left\n");
    printf("2. Go right\n");
    printf("3. Go forward\n");
    printf("4. Go backward\n");
    printf("5. Use item\n");
    printf("6. Quit\n");
}

int main() {
    srand(time(NULL));
    int choice = 0;
    char direction[10];
    char item[20];

    while (choice!= 6) {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You went left and found a chest.\n");
                break;
            case 2:
                printf("You went right and found a potion.\n");
                break;
            case 3:
                printf("You went forward and found a hidden room.\n");
                break;
            case 4:
                printf("You went backward and found a trap.\n");
                break;
            case 5:
                printf("You used your item.\n");
                break;
            case 6:
                printf("You quit the game.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid number.\n");
                break;
        }

        if (choice == 1) {
            printf("You found a key. Do you want to use it? (y/n): ");
            scanf("%s", item);
            if (strcmp(item, "y") == 0) {
                printf("You used the key and opened the chest. You found a treasure!\n");
            }
        }
    }
    return 0;
}