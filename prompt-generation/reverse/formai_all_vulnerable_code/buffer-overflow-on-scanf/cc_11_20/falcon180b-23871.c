//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, room = 1, found_key = 0;
    char name[20];

    printf("Welcome to the Haunted House!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));
    printf("\n%s, you find yourself in room %d.\n", name, room);

    while (room <= 10 &&!found_key) {
        printf("\nYou can:\n");
        printf("1. Look around the room.\n");
        printf("2. Search for a key.\n");
        printf("3. Go to the next room.\n");
        printf("4. Quit.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nThe room is dark and eerie, with cobwebs covering the corners.");
                break;
            case 2:
                if (room == 10) {
                    printf("\nYou found the key! Congratulations, %s, you escaped the haunted house!", name);
                    found_key = 1;
                } else {
                    printf("\nYou search the room but find nothing.");
                }
                break;
            case 3:
                if (room <= 10) {
                    room++;
                } else {
                    printf("\nYou reached the end of the haunted house, but you didn't find the key.");
                    exit(0);
                }
                break;
            case 4:
                printf("\n%s, are you sure you want to quit? (y/n)", name);
                char quit;
                scanf(" %c", &quit);
                if (quit == 'y' || quit == 'Y') {
                    exit(0);
                }
                break;
            default:
                printf("\nInvalid choice, please try again.");
        }
    }

    return 0;
}