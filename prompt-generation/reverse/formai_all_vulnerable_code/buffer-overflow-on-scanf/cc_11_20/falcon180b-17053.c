//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int room = rand() % 4; // Randomly select a room to start in

    printf("Welcome to the Enchanted Castle!\n\n");

    while(1) {
        printf("You are in room %d.\n", room);
        printf("What would you like to do?\n");
        printf("1. Go north\n");
        printf("2. Go south\n");
        printf("3. Go east\n");
        printf("4. Go west\n");
        printf("5. Search the room\n");
        printf("6. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(room == 0) {
                    printf("You can't go any further north.\n");
                } else {
                    room--;
                }
                break;
            case 2:
                if(room == 3) {
                    printf("You can't go any further south.\n");
                } else {
                    room++;
                }
                break;
            case 3:
                if(room == 0) {
                    printf("You can't go any further east.\n");
                } else {
                    room--;
                }
                break;
            case 4:
                if(room == 3) {
                    printf("You can't go any further west.\n");
                } else {
                    room++;
                }
                break;
            case 5:
                printf("You search the room and find a key.\n");
                break;
            case 6:
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}