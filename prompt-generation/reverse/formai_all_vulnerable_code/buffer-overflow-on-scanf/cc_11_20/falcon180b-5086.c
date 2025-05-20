//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;

    printf("Welcome to the Haunted House!\n");
    printf("What would you like to do?\n");
    printf("1. Explore the house\n");
    printf("2. Leave the house\n");
    scanf("%d", &choice);

    if(choice == 1) {
        int room = rand() % 10 + 1;
        printf("You enter room %d.\n", room);

        if(room == 1) {
            printf("This room is filled with cobwebs and spiders.\n");
        } else if(room == 2) {
            printf("This room has a creepy portrait that seems to follow you with its eyes.\n");
        } else if(room == 3) {
            printf("This room has a ghostly apparition that floats in the air.\n");
        } else if(room == 4) {
            printf("This room has a hidden passage behind a bookshelf.\n");
        } else if(room == 5) {
            printf("This room has a dusty old piano that plays itself.\n");
        } else if(room == 6) {
            printf("This room has a cursed mirror that shows your worst fears.\n");
        } else if(room == 7) {
            printf("This room has a secret door that leads to a hidden room.\n");
        } else if(room == 8) {
            printf("This room has a creepy doll that seems to move on its own.\n");
        } else if(room == 9) {
            printf("This room has a haunted fireplace that flickers with ghostly flames.\n");
        } else {
            printf("This room is empty.\n");
        }

        int event = rand() % 5 + 1;

        if(event == 1) {
            printf("You hear a strange noise coming from the next room.\n");
        } else if(event == 2) {
            printf("The door behind you suddenly slams shut.\n");
        } else if(event == 3) {
            printf("You feel a cold breeze brush past you.\n");
        } else if(event == 4) {
            printf("You see a shadowy figure disappear around the corner.\n");
        } else {
            printf("Nothing happens.\n");
        }

        printf("Do you want to explore another room? (y/n)\n");
        char answer;
        scanf("%c", &answer);

        if(answer == 'y' || answer == 'Y') {
            main();
        } else {
            printf("You leave the haunted house.\n");
        }
    } else if(choice == 2) {
        printf("You leave the haunted house.\n");
    } else {
        printf("Invalid choice.\n");
        main();
    }

    return 0;
}