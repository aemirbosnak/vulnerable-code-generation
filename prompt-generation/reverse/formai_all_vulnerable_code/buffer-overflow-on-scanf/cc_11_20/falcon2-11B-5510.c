//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Create a room
    int room = 0;

    // Enter the room
    printf("Enter a room: ");
    scanf("%d", &room);

    // Generate a random number for a spooky event
    srand(time(NULL));
    int spooky_event = rand() % 10 + 1;

    // Print the spooky event
    switch (spooky_event) {
        case 1:
            printf("A ghost appears and scares you.\n");
            break;
        case 2:
            printf("A skeleton jumps out from behind a door.\n");
            break;
        case 3:
            printf("A creepy clown laughs at you.\n");
            break;
        case 4:
            printf("A giant spider crawls across your face.\n");
            break;
        case 5:
            printf("A witch cackles at you from the shadows.\n");
            break;
        case 6:
            printf("A werewolf howls in the distance.\n");
            break;
        case 7:
            printf("A mummy wraps itself around you.\n");
            break;
        case 8:
            printf("A demon taunts you.\n");
            break;
        case 9:
            printf("A vampire bites you.\n");
            break;
        case 10:
            printf("A zombie shambles towards you.\n");
            break;
        default:
            printf("Nothing happens.\n");
            break;
    }

    // Exit the room
    printf("Leave the room? (y/n): ");
    char response;
    scanf(" %c", &response);
    if (response == 'y') {
        printf("You exit the room and find yourself back in the main hall.\n");
    } else {
        printf("You stay in the room and wait for something to happen.\n");
    }

    return 0;
}