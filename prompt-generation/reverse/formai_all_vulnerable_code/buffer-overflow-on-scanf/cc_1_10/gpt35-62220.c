//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int ms = 1000 * seconds;
    clock_t t = clock();
    while (clock() < t + ms);
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a spooky old house. The doors slam shut behind you, and you hear eerie noises from all around.\n");
    printf("You need to find your way out before it's too late!\n\n");

    int room = 1;
    while (room != 0) {
        switch (room) {
            case 1:
                printf("You are in the foyer. There are two doors in front of you.\n");
                printf("Do you want to go through Door 1 or Door 2?\n");
                printf("> ");
                int door;
                scanf("%d", &door);
                if (door == 1) {
                    printf("You have entered the living room. It's full of cobwebs and dusty old furniture.\n");
                    printf("Do you want to look around, or go back to the foyer?\n");
                    printf("> ");
                    char choice[10];
                    scanf("%s", choice);
                    if (strcmp(choice, "look") == 0) {
                        printf("You find a key!\n");
                        printf("Do you want to take the key with you, or leave it?\n");
                        printf("> ");
                        char choice2[10];
                        scanf("%s", choice2);
                        if (strcmp(choice2, "take") == 0) {
                            printf("You take the key with you.\n");
                            room = 3;
                        } else {
                            printf("You leave the key behind.\n");
                            room = 2;
                        }
                    } else {
                        room = 2;
                    }
                } else {
                    printf("You have entered the kitchen. It's a mess, with dirty dishes piled high. You hear a noise coming from the pantry.\n");
                    printf("Do you want to investigate the noise, or leave the kitchen?\n");
                    printf("> ");
                    char choice[10];
                    scanf("%s", choice);
                    if (strcmp(choice, "investigate") == 0) {
                        printf("You open the pantry door, and a skeleton jumps out at you!\n");
                        printf("You faint, and wake up back in the foyer.\n");
                        delay(3);
                    } else {
                        room = 2;
                    }
                }
                break;
            case 2:
                printf("You are back in the foyer. There is still one unexplored door.\n");
                printf("Do you want to go through Door 1 or Door 2?\n");
                printf("> ");
                int door2;
                scanf("%d", &door2);
                if (door2 == 1) {
                    printf("You have entered the bedroom. It's a mess, with clothes and papers scattered all over the floor.\n");
                    printf("Do you want to look around, or go back to the foyer?\n");
                    printf("> ");
                    char choice[10];
                    scanf("%s", choice);
                    if (strcmp(choice, "look") == 0) {
                        printf("You find a flashlight!\n");
                        printf("Do you want to take the flashlight with you, or leave it?\n");
                        printf("> ");
                        char choice2[10];
                        scanf("%s", choice2);
                        if (strcmp(choice2, "take") == 0) {
                            printf("You take the flashlight with you.\n");
                            room = 3;
                        } else {
                            printf("You leave the flashlight behind.\n");
                            room = 1;
                        }
                    } else {
                        room = 1;
                    }
                } else {
                    printf("You have entered the study. It's dusty and unused, with a bookshelf lining one wall.\n");
                    printf("Do you want to look around, or go back to the foyer?\n");
                    printf("> ");
                    char choice[10];
                    scanf("%s", choice);
                    if (strcmp(choice, "look") == 0) {
                        printf("You find a book with a strange symbol on the cover!\n");
                        printf("Do you want to take the book with you, or leave it?\n");
                        printf("> ");
                        char choice2[10];
                        scanf("%s", choice2);
                        if (strcmp(choice2, "take") == 0) {
                            printf("You take the book with you.\n");
                            room = 3;
                        } else {
                            printf("You leave the book behind.\n");
                            room = 1;
                        }
                    } else {
                        room = 1;
                    }
                }
                break;
            case 3:
                printf("You have found a mysterious door in the foyer. It requires a key to unlock. Do you want to use the key?\n");
                printf("> ");
                char choice3[10];
                scanf("%s", choice3);
                if (strcmp(choice3, "yes") == 0) {
                    printf("The door creaks open, revealing a staircase leading down into darkness.\n");
                    printf("Do you want to go down the stairs, or explore the rest of the house first?\n");
                    printf("> ");
                    char choice4[10];
                    scanf("%s", choice4);
                    if (strcmp(choice4, "go") == 0) {
                        printf("You descend into the unknown depths below the house...\n");
                        delay(3);
                        printf("...\n");
                        delay(3);
                        printf("...\n");
                        delay(3);
                        printf("You have reached the end of the Haunted House Simulator.\n");
                        delay(3);
                        printf("Thanks for playing!\n");
                        room = 0;
                    } else {
                        room = 1;
                    }
                } else {
                    printf("You need a key to unlock this door.\n");
                    room = 1;
                }
                break;
        }
    }

    return 0;
}