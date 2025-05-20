//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    int x = 0;
    int y = 0;
    int z = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing at the entrance of a haunted house.\n");
    printf("Do you want to go inside? (y/n)\n");
    scanf("%d", &choice);

    if (choice == 'y') {
        printf("You step inside the haunted house.\n");
        printf("The door slams shut behind you.\n");
        printf("You hear eerie sounds coming from all directions.\n");
        printf("You see a staircase leading up to the second floor.\n");
        printf("Do you want to go up the staircase? (y/n)\n");
        scanf("%d", &choice);

        if (choice == 'y') {
            printf("You climb up the staircase.\n");
            printf("You reach the second floor.\n");
            printf("You see a long hallway with many doors.\n");
            printf("Do you want to explore the hallway? (y/n)\n");
            scanf("%d", &choice);

            if (choice == 'y') {
                printf("You start walking down the hallway.\n");
                printf("You hear footsteps behind you.\n");
                printf("You turn around but there's no one there.\n");
                printf("You continue walking.\n");
                printf("You reach the end of the hallway.\n");
                printf("There's a door in front of you.\n");
                printf("Do you want to open the door? (y/n)\n");
                scanf("%d", &choice);

                if (choice == 'y') {
                    printf("You open the door.\n");
                    printf("You step inside the room.\n");
                    printf("The door slams shut behind you.\n");
                    printf("You're trapped!\n");
                } else {
                    printf("You decide not to open the door.\n");
                }
            } else {
                printf("You decide not to explore the hallway.\n");
            }
        } else {
            printf("You decide not to go up the staircase.\n");
        }
    } else {
        printf("You decide not to go inside the haunted house.\n");
    }

    return 0;
}