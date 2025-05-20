//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 6

void printIntroduction();
void printRoomDescription(int roomNumber);
void printRoomOptions(int currentRoom, int doors[MAX_ROOMS]);
void printMonsterEncounter();
int moveRooms(int currentRoom, int doors[MAX_ROOMS]);
int generateRandomNumber(int min, int max);

int main()
{
    int currentRoom = 0; // starting room
    int doors[MAX_ROOMS] = {-1, -1, -1, -1, -1, -1}; // doors for each room

    srand(time(NULL)); // initialize random seed

    printIntroduction();

    while (currentRoom != -1)
    {
        printRoomDescription(currentRoom);
        printRoomOptions(currentRoom, doors);

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                currentRoom = moveRooms(currentRoom, doors);
                break;
            case 2:
                printf("\nYou exit the house.\n");
                currentRoom = -1;
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    printf("\nThank you for playing!\n");

    return 0;
}

void printIntroduction()
{
    printf("Welcome to the Happy Haunted House Simulator!\n");
    printf("You have entered a haunted house. Your goal is to find the treasure chest.\n");
    printf("You can explore different rooms and discover clues to help you locate the treasure.\n");
    printf("But watch out for monsters lurking in the shadows!\n");
}

void printRoomDescription(int roomNumber)
{
    switch (roomNumber)
    {
        case 0:
            printf("\n%s\n", "You are in the entrance hall. There are three doors in front of you.");
            break;
        case 1:
            printf("\n%s\n", "You are in the living room. The room is dark and spooky.");
            break;
        case 2:
            printf("\n%s\n", "You are in the kitchen. The room smells of rotten food.");
            break;
        case 3:
            printf("\n%s\n", "You are in the dining room. The table is set with old plates and silverware.");
            break;
        case 4:
            printf("\n%s\n", "You are in the bedroom. The bed looks like it hasn't been slept in for years.");
            break;
        case 5:
            printf("\n%s\n", "You are in the bathroom. The room is covered in cobwebs.");
            break;
        default:
            printf("\n%s\n", "You are in a secret room. The room is filled with gold and treasure!");
            break;
    }
}

void printRoomOptions(int currentRoom, int doors[MAX_ROOMS])
{
    printf("\nWhat do you want to do?\n");
    printf("1. Open a door\n");
    printf("2. Leave the house\n");

    switch (currentRoom)
    {
        case 0:
            if (doors[1] == -1) doors[1] = generateRandomNumber(2, MAX_ROOMS);
            if (doors[2] == -1) doors[2] = generateRandomNumber(2, MAX_ROOMS);
            if (doors[3] == -1) doors[3] = generateRandomNumber(2, MAX_ROOMS);
            printf("3. Look for clues in the room\n");
            break;
        case 1:
            if (doors[0] == -1) doors[0] = generateRandomNumber(2, MAX_ROOMS);
            if (doors[2] == -1) doors[2] = generateRandomNumber(2, MAX_ROOMS);
            printf("3. Look under the sofa\n");
            break;
        case 2:
            if (doors[0] == -1) doors[0] = generateRandomNumber(2, MAX_ROOMS);
            if (doors[1] == -1) doors[1] = generateRandomNumber(2, MAX_ROOMS);
            if (doors[4] == -1) doors[4] = generateRandomNumber(2, MAX_ROOMS);
            printf("3. Look in the fridge\n");
            break;
        case 3:
            if (doors[0] == -1) doors[0] = generateRandomNumber(2, MAX_ROOMS);
            if (doors[4] == -1) doors[4] = generateRandomNumber(2, MAX_ROOMS);
            if (doors[5] == -1) doors[5] = generateRandomNumber(2, MAX_ROOMS);
            printf("3. Look at the painting on the wall\n");
            break;
        case 4:
            if (doors[2] == -1) doors[2] = generateRandomNumber(2, MAX_ROOMS);
            if (doors[3] == -1) doors[3] = generateRandomNumber(2, MAX_ROOMS);
            printf("3. Look in the dresser\n");
            break;
        case 5:
            if (doors[3] == -1) doors[3] = generateRandomNumber(2, MAX_ROOMS);
            printf("3. Look in the medicine cabinet\n");
            break;
        default:
            break;
    }
}

void printMonsterEncounter()
{
    printf("\n%s\n", "Beware! A monster has appeared!");
}

int moveRooms(int currentRoom, int doors[MAX_ROOMS])
{
    int roomNumber = doors[generateRandomNumber(0, MAX_ROOMS-1)]; // pick a random door
    printf("\nYou open the door and enter room %d.\n", roomNumber);

    if (currentRoom == 0 && roomNumber == MAX_ROOMS) // found the secret room
    {
        printf("\nCongratulations! You have found the treasure chest!\n");
        return -1;
    }
    else if (generateRandomNumber(0, 1)) // 50% chance of encountering a monster
    {
        printMonsterEncounter();
        return moveRooms(currentRoom, doors); // try again
    }
    else
    {
        return roomNumber;
    }
}

int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}