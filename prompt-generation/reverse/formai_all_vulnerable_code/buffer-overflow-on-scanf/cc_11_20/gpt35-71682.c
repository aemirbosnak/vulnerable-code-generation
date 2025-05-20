//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>

int main(void) {
    int choice;
    
    printf("Welcome to the Escape Room game.\n");
    printf("You find yourself in a room with four doors.\n");
    printf("Each door leads to a different room. Choose wisely.\n");
    printf("Which door would you like to open?\n");
    printf("1. Door 1\n");
    printf("2. Door 2\n");
    printf("3. Door 3\n");
    printf("4. Door 4\n");
    
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You open the door and enter a room.\n");
        printf("There is a note on the wall that says, 'To escape, you must solve the riddle.'\n");
        printf("What has a head, a tail, is brown, and has no legs?\n");
        char answer[20];
        scanf("%s", answer);
        if (strcmp(answer, "penny") == 0) {
            printf("Congratulations! You solved the riddle and escaped the room.\n");
        } else {
            printf("Sorry, that is incorrect. The room locks and you are stuck forever.\n");
        }
    } else if (choice == 2) {
        printf("You open the door and enter a room.\n");
        printf("The room is pitch black and you can't see anything.\n");
        printf("You feel around for a light switch and finally find one.\n");
        printf("As you turn it on, you see a large spider on the wall in front of you.\n");
        printf("What do you do?\n");
        printf("1. Squish the spider\n");
        printf("2. Ignore the spider and search the room\n");
        printf("3. Try to catch the spider and release it outside\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("The spider was venomous. You die a painful death.\n");
        } else if (choice == 2) {
            printf("You search the room and find a key that unlocks the door to freedom.\n");
            printf("Congratulations! You escaped the room.\n");
        } else if (choice == 3) {
            printf("The spider bites you and you die a slow death.\n");
        } else {
            printf("Invalid choice. The room locks and you are stuck forever.\n");
        }
    } else if (choice == 3) {
        printf("You open the door and enter a room.\n");
        printf("The room is filled with poisonous gas.\n");
        printf("You have a gas mask with you. What do you do?\n");
        printf("1. Put on the gas mask\n");
        printf("2. Try to hold your breath and run through the room\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("You put on the gas mask and safely navigate through the room.\n");
            printf("Congratulations! You escaped the room.\n");
        } else if (choice == 2) {
            printf("You hold your breath and try to run through the room.\n");
            printf("Unfortunately, you take a breath of the poisonous gas and die.\n");
        } else {
            printf("Invalid choice. The room locks and you are stuck forever.\n");
        }
    } else if (choice == 4) {
        printf("You open the door and enter a room.\n");
        printf("The room is empty except for a computer on a desk.\n");
        printf("You sit down at the computer and see that it requires a password.\n");
        printf("You see a note on the desk that says, 'The password is a fruit.'\n");
        char password[20];
        scanf("%s", password);
        if (strcmp(password, "banana") == 0) {
            printf("You enter the correct password and the computer displays a message.\n");
            printf("The message says, 'Congratulations! You have escaped the room.'\n");
        } else {
            printf("You enter the wrong password. The room locks and you are stuck forever.\n");
        }
    } else {
        printf("Invalid choice. The room locks and you are stuck forever.\n");
    }
    
    return 0;
}