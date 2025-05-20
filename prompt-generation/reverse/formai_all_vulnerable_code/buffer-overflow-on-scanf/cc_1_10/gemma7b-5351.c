//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age, room, choice;
    srand(time(NULL));

    printf("Welcome to the Haunted Thornfield Manor, Mr. Holmes.\n");
    printf("Please provide your name: ");
    scanf("%s", name);

    printf("And your age: ");
    scanf("%d", &age);

    room = rand() % 3 + 1;
    printf("You have been assigned to room %d.\n", room);

    printf("There are three possible sources of ghostly activity in the manor:\n");
    printf("1. The grand hall\n");
    printf("2. The dining hall\n");
    printf("3. The library\n");

    printf("Please choose a source of ghostly activity: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You hear footsteps in the grand hall, followed by a chilling scream.\n");
            break;
        case 2:
            printf("You hear a ghostly moan in the dining hall.\n");
            break;
        case 3:
            printf("You hear a book slamming shut and a disembodied voice whispering your name in the library.\n");
            break;
    }

    printf("Do you want to investigate further? (Y/N): ");
    char answer;
    scanf("%c", &answer);

    if (answer == 'Y')
    {
        printf("You search the area, but find nothing. The ghostly presence has vanished.\n");
    }
    else
    {
        printf("You flee the manor in terror.\n");
    }

    return 0;
}