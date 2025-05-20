//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int room = 1;
    int scared = 0;

    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in room %d. What do you want to do?\n", room);
    printf("1. Look around\n2. Open the door\n3. Scream\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You look around and see...\n");
        if (rand() % 2 == 0) {
            printf("Nothing out of the ordinary.\n");
        } else {
            printf("A ghostly figure staring back at you!\n");
            scared = 1;
        }
    } else if (choice == 2) {
        if (rand() % 2 == 0) {
            printf("The door is locked. You can't leave.\n");
        } else {
            printf("You open the door and find yourself in room %d.\n", room + 1);
            room++;
        }
    } else if (choice == 3) {
        printf("You let out a blood-curdling scream!\n");
    }

    if (scared == 1) {
        printf("You're too scared to continue. Game over.\n");
    } else {
        printf("Do you want to continue? (y/n)\n");
        char cont;
        scanf(" %c", &cont);
        if (cont == 'n') {
            printf("Thanks for playing!\n");
        } else {
            main();
        }
    }

    return 0;
}