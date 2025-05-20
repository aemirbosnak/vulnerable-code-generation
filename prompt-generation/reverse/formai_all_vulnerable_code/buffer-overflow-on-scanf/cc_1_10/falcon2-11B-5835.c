//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice[20];
    char treasure[20];
    char* choices[] = {"Enter the cave", "Stay outside", "Look for clues"};
    char* outcomes[] = {"You find the treasure!", "You get eaten by a bear", "You discover a map leading to the treasure"};

    printf("You come across a cave. What do you do?\n");
    printf("1. Enter the cave\n2. Stay outside\n3. Look for clues\n");
    printf("Enter your choice: ");
    scanf("%s", choice);

    if (strcmp(choice, "1") == 0) {
        printf("You enter the cave and find a treasure chest!\n");
        printf("Congratulations! You've found the treasure!\n");
        printf("Do you want to open it? (y/n): ");
        scanf("%s", treasure);
        if (strcmp(treasure, "y") == 0) {
            printf("Inside the chest you find gold, jewels, and a note.\n");
            printf("The note reads: \"Congratulations! You have found my treasure!\"");
        }
    } else if (strcmp(choice, "2") == 0) {
        printf("You decide to stay outside and continue exploring.\n");
        printf("Suddenly, you hear a growl behind you. A bear is chasing you!\n");
        printf("Do you run or fight? (r/f): ");
        scanf("%s", treasure);
        if (strcmp(treasure, "r") == 0) {
            printf("You run as fast as you can but the bear catches up to you.\n");
            printf("You get eaten by a bear.\n");
        } else if (strcmp(treasure, "f") == 0) {
            printf("You stand your ground and fight the bear.\n");
            printf("The bear runs away, leaving you unharmed.\n");
        }
    } else if (strcmp(choice, "3") == 0) {
        printf("You search for clues and find a map leading to the treasure.\n");
        printf("Do you follow the map? (y/n): ");
        scanf("%s", treasure);
        if (strcmp(treasure, "y") == 0) {
            printf("You follow the map and find the treasure!\n");
            printf("Congratulations! You've found the treasure!\n");
        } else {
            printf("You decide to leave the map behind and continue exploring.\n");
            printf("Suddenly, you hear a growl behind you. A bear is chasing you!\n");
            printf("Do you run or fight? (r/f): ");
            scanf("%s", treasure);
            if (strcmp(treasure, "r") == 0) {
                printf("You run as fast as you can but the bear catches up to you.\n");
                printf("You get eaten by a bear.\n");
            } else if (strcmp(treasure, "f") == 0) {
                printf("You stand your ground and fight the bear.\n");
                printf("The bear runs away, leaving you unharmed.\n");
            }
        }
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}