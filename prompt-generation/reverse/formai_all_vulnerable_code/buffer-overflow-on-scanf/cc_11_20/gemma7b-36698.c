//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, room = 1, inventory[] = {0, 0, 0}, flag = 0;
    char name[20];

    printf("Welcome to the Mysterious Mansion.\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while (room != 6)
    {
        switch (room)
        {
            case 1:
                printf("You are in the grand hall.\n");
                printf("You see a portrait of a mysterious figure.\n");
                printf("You hear a shuffling sound coming from the east wing.\n");
                break;
            case 2:
                printf("You are in the library.\n");
                printf("You see a bookshelf with many books.\n");
                printf("You hear a tapping sound coming from the south wing.\n");
                break;
            case 3:
                printf("You are in the dining hall.\n");
                printf("You see a table with a feast.\n");
                printf("You hear a buzzing sound coming from the north wing.\n");
                break;
            case 4:
                printf("You are in the study.\n");
                printf("You see a desk with a computer.\n");
                printf("You hear a ringing sound coming from the west wing.\n");
                break;
            case 5:
                printf("You are in the secret room.\n");
                printf("You see a hidden treasure.\n");
                flag = 1;
                break;
            case 6:
                printf("You have escaped the mansion.\n");
                break;
        }

        printf("What do you want to do? (1, 2, 3, 4, 5): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                room = 2;
                break;
            case 2:
                room = 3;
                break;
            case 3:
                room = 4;
                break;
            case 4:
                room = 5;
                break;
            case 5:
                if (flag == 0)
                {
                    printf("You need to find the secret key first.\n");
                }
                else
                {
                    printf("You have found the secret key and escaped the mansion.\n");
                    room = 6;
                }
                break;
        }

        inventory[room] = 1;
    }

    return 0;
}