//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int room = 1;
    int ghostCount = 0;
    int playerHealth = 100;
    int scared = 0;

    printf("Welcome to the Haunted House!\n");
    printf("You are in room %d.\n", room);

    while(1) {
        system("clear");
        printf("What would you like to do?\n");
        printf("1. Move to the next room.\n");
        printf("2. Try to leave the house.\n");
        printf("3. Check your health.\n");
        printf("4. Check for ghosts.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(room == 10) {
                    printf("You have reached the end of the haunted house!\n");
                    break;
                }
                room++;
                printf("You are now in room %d.\n", room);
                break;
            case 2:
                if(room == 10) {
                    printf("You have successfully escaped the haunted house!\n");
                    break;
                }
                printf("The door is locked. You need to find the key.\n");
                break;
            case 3:
                printf("Your health is %d out of 100.\n", playerHealth);
                break;
            case 4:
                if(ghostCount == 0) {
                    printf("There are no ghosts in this room.\n");
                } else {
                    printf("There are %d ghosts in this room.\n", ghostCount);
                    if(scared == 1) {
                        playerHealth -= 10;
                        printf("You are scared and lose 10 health points.\n");
                    }
                }
                break;
        }

        if(room == 5 && ghostCount == 0) {
            ghostCount = rand() % 3 + 1;
        } else if(room == 5 && ghostCount > 0) {
            ghostCount--;
        }

        if(room == 3 && scared == 0) {
            scared = 1;
            printf("You hear a loud noise and get scared.\n");
        } else if(room == 3 && scared == 1) {
            scared = 0;
            printf("You calm down.\n");
        }
    }

    return 0;
}