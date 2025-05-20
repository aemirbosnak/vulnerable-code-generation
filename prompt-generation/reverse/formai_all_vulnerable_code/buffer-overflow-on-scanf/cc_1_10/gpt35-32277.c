//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a creepy mansion.\n");
    printf("Do you dare to enter?\n");

    char response;
    printf("Type 'y' for yes or any other key for no: ");
    scanf("%c", &response);

    if (response != 'y') {
        printf("Thanks for playing. Goodbye!\n");
        return 0;
    }

    printf("You step into the house and the door slams shut behind you.\n");
    printf("The air is musty and you can hear strange noises coming from every direction.\n");
    printf("To your left is a long hallway with old portraits lining the walls.\n");
    printf("To your right is a dark staircase leading up to the second floor.\n");
    printf("Straight ahead is a closed door with a strange symbol etched into it.\n");

    int choice;
    printf("Where would you like to go?\n");
    printf("1. Left hallway\n");
    printf("2. Right staircase\n");
    printf("3. Straight door\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You walk down the hallway and suddenly the portraits begin to move!\n");
            printf("You run back to the entrance and the door is now locked!\n");
            printf("You are trapped and the ghosts have you captive.\n");
            break;
        case 2:
            printf("You ascend the staircase and reach the top floor.\n");
            printf("The hallway is long and dark with several doors on each side.\n");
            printf("As you walk, you begin to hear whispers and laughter coming from one of the rooms.\n");
            printf("You choose to either investigate or keep walking.\n");
            printf("Press 1 if you want to investigate or 2 to keep walking: ");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You enter the room and find nothing.\n");
                printf("Suddenly, the door slams shut behind you and you are locked in!\n");
                printf("Your only escape is through a window that leads to a steep drop.\n");
            } else {
                printf("You keep walking and eventually find the exit. Congratulations!\n");
            }
            break;
        case 3:
            printf("You push open the door and find a dark room with strange symbols on the walls.\n");
            printf("Suddenly, a ghostly figure appears and starts chasing you!\n");
            printf("You must choose to either run or hide.\n");
            printf("Press 1 if you want to run or 2 to hide: ");
            scanf("%d", &choice);
            if (choice == 1) {
                srand(time(NULL));
                int rand_num = rand() % 2;
                if (rand_num == 0) {
                    printf("You successfully outrun the ghost and find the exit. Congratulations!\n");
                } else {
                    printf("You run right into the arms of the ghost! You lose.\n");
                }
            } else {
                printf("You hide behind a chair and hold your breath.\n");
                printf("The ghost passes by you and you make a break for the exit. Congratulations!\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}