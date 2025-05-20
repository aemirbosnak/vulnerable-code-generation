//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice;
    char name[20];
    int room_num;
    char sound;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter the room number you want to visit: ");
    scanf("%d", &room_num);

    printf("You have entered room %d. Prepare for a fright!\n", room_num);

    switch (room_num)
    {
        case 1:
            sound = 'A';
            break;
        case 2:
            sound = 'B';
            break;
        case 3:
            sound = 'C';
            break;
        case 4:
            sound = 'D';
            break;
        case 5:
            sound = 'E';
            break;
    }

    printf("The sound you hear is: %c\n", sound);

    printf("Do you want to continue exploring the haunted house? (Y/N) ");
    scanf("%c", &choice);

    if (choice == 'Y')
    {
        main();
    }
    else
    {
        printf("Thank you for visiting the Haunted House Simulator. See you next time!\n");
    }
}