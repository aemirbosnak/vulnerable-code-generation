//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int room = 1;
    int choice;
    int ghost = 0;
    int skeleton = 0;
    int spider = 0;
    int treasure = 0;

    printf("Welcome to the Haunted House!\n\n");
    printf("You find yourself standing outside a large, old house.\n");
    printf("Do you dare to enter? (1: yes / 2: no): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You hesitantly push the door open and step inside.\n");
        printf("The door slams shut behind you, and you hear it lock.\n\n");

        while (room <= 6) {
            printf("You are in Room %d. Choose your next move: \n", room);
            printf("1: Go forward\n2: Turn left\n3: Turn right\n4: Go back\n\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("You move forward and enter Room %d.\n", room+1);
                    room++;
                    break;
                case 2:
                    printf("You turn left and enter Room %d.\n", room+3);
                    room += 3;
                    break;
                case 3:
                    printf("You turn right and enter Room %d.\n", room+2);
                    room += 2;
                    break;
                case 4:
                    printf("You turn around and enter Room %d.\n", room-1);
                    room--;
                    break;
                default:
                    printf("Invalid choice. Try again.\n\n");
            }

            if (ghost == 1 && skeleton == 1 && spider == 1 && treasure == 1) {
                printf("\nYou have completed the game!\nCongratulations, you have found the treasure and escaped alive!\n");
                exit(0);
            }

            int event = rand() % 10 + 1;
            if (event <= 4) {
                printf("You hear strange noises...\n");

                int creature = rand() % 3 + 1;
                switch (creature) {
                    case 1:
                        if (ghost == 0) {
                            printf("A ghost appears out of nowhere and scares you!\n");
                            ghost = 1;
                        } else {
                            printf("The ghost appears again, but you are no longer scared.\n");
                        }
                        break;
                    case 2:
                        if (skeleton == 0) {
                            printf("A skeleton rises from the ground and attacks you!\n");
                            skeleton = 1;
                        } else {
                            printf("The skeleton is still there, but you have already defeated it.\n");
                        }
                        break;
                    case 3:
                        if (spider == 0) {
                            printf("A giant spider drops down from the ceiling and attacks you!\n");
                            spider = 1;
                        } else {
                            printf("The spider is still there, but you have already defeated it.\n");
                        }
                        break;
                }
            } else if (event == 10) {
                if (treasure == 0) {
                    printf("Congratulations! You have found the treasure!\n");
                    treasure = 1;
                } else {
                    printf("You have already found the treasure in this room.\n");
                }
            }
        }

        printf("\nYou have been trapped in the house forever...\nGAME OVER.\n");
    } else {
        printf("You chicken out and leave.\nGAME OVER.\n");
    }

    return 0;
}