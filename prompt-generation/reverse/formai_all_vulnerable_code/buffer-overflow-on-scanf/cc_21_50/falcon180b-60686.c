//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice, room = 1, flag = 0;

    printf("Welcome to the Haunted House!\n");

    while(1) {
        system("clear");
        printf("You are in room %d.\n", room);

        if(room == 1) {
            printf("There is a door in front of you. Do you want to open it? (y/n) ");
            scanf("%s", &choice);

            if(choice == 'y' || choice == 'Y') {
                room++;
            } else {
                printf("You decide to turn back.\n");
                return 0;
            }
        } else if(room == 2) {
            printf("There is a staircase leading up and a door to your right. Which one do you choose? (s/r) ");
            scanf("%s", &choice);

            if(choice =='s' || choice == 'S') {
                room++;
            } else if(choice == 'r' || choice == 'R') {
                room = 3;
            } else {
                printf("Invalid choice. You decide to turn back.\n");
                return 0;
            }
        } else if(room == 3) {
            printf("There is a passageway to your left and a door in front of you. Which one do you choose? (l/f) ");
            scanf("%s", &choice);

            if(choice == 'l' || choice == 'L') {
                room = 4;
            } else if(choice == 'f' || choice == 'F') {
                room++;
            } else {
                printf("Invalid choice. You decide to turn back.\n");
                return 0;
            }
        } else if(room == 4) {
            printf("You find a key on the floor. Do you want to pick it up? (y/n) ");
            scanf("%s", &choice);

            if(choice == 'y' || choice == 'Y') {
                printf("You picked up the key.\n");
            } else {
                printf("You leave the key on the floor.\n");
            }

            room++;
        } else if(room == 5) {
            printf("There is a locked door in front of you. Do you have the key? (y/n) ");
            scanf("%s", &choice);

            if(choice == 'y' || choice == 'Y') {
                printf("You unlock the door and enter the next room.\n");
                room++;
            } else {
                printf("You don't have the key. You decide to turn back.\n");
                return 0;
            }
        } else if(room == 6) {
            printf("Congratulations! You have reached the end of the haunted house.\n");
            flag = 1;
        } else {
            printf("You are lost in the haunted house. Game Over!\n");
            return 0;
        }
    }

    return 0;
}