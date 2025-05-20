//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, inventory[] = {0, 0, 0}, current_room = 1;
    char name[20];

    printf("Welcome to the Quantum Realm, %s. Please choose a path:\n", name);

    // Branch 1: The Quantum Path
    printf("1. Travel through the Quantum Tunnel.\n");

    // Branch 2: The Quantum Bridge
    printf("2. Cross the Quantum Bridge.\n");

    // Branch 3: The Quantum Spiral
    printf("3. Spin through the Quantum Spiral.\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            inventory[0] = 1;
            current_room = 2;
            break;
        case 2:
            inventory[1] = 1;
            current_room = 3;
            break;
        case 3:
            inventory[2] = 1;
            current_room = 4;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    // Room 2: The Quantum Chamber
    if (current_room == 2)
    {
        printf("You have entered the Quantum Chamber. You have a quantum key in your inventory.\n");
    }

    // Room 3: The Quantum Garden
    else if (current_room == 3)
    {
        printf("You have entered the Quantum Garden. You have a quantum flower in your inventory.\n");
    }

    // Room 4: The Quantum Temple
    else if (current_room == 4)
    {
        printf("You have entered the Quantum Temple. You have a quantum stone in your inventory.\n");
    }

    return 0;
}