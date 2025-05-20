//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("What is your name, adventurer?\n");
    scanf("%s", name);
    printf("Welcome to the world of %s!\n", name);
    printf("You find yourself in a dark forest.\n");
    printf("What would you like to do?\n");
    printf("1. Explore\n");
    printf("2. Rest\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You begin to explore the forest.\n");
            printf("You come across a small stream.\n");
            printf("What would you like to do?\n");
            printf("1. Cross the stream\n");
            printf("2. Follow the stream\n");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("You cross the stream and continue your journey.\n");
                    printf("You come across a clearing in the forest.\n");
                    printf("What would you like to do?\n");
                    printf("1. Investigate the clearing\n");
                    printf("2. Keep exploring\n");
                    scanf("%d", &choice);
                    switch(choice) {
                        case 1:
                            printf("You investigate the clearing and find a hidden cave.\n");
                            printf("What would you like to do?\n");
                            printf("1. Enter the cave\n");
                            printf("2. Keep exploring\n");
                            scanf("%d", &choice);
                            switch(choice) {
                                case 1:
                                    printf("You enter the cave and find treasure!\n");
                                    break;
                                case 2:
                                    printf("You continue your journey through the forest.\n");
                                    break;
                                default:
                                    printf("Invalid choice.\n");
                            }
                            break;
                        case 2:
                            printf("You continue your journey through the forest.\n");
                            break;
                        default:
                            printf("Invalid choice.\n");
                    }
                    break;
                case 2:
                    printf("You follow the stream and come across a waterfall.\n");
                    printf("What would you like to do?\n");
                    printf("1. Climb the waterfall\n");
                    printf("2. Keep following the stream\n");
                    scanf("%d", &choice);
                    switch(choice) {
                        case 1:
                            printf("You climb the waterfall and find a hidden cave.\n");
                            printf("What would you like to do?\n");
                            printf("1. Enter the cave\n");
                            printf("2. Keep exploring\n");
                            scanf("%d", &choice);
                            switch(choice) {
                                case 1:
                                    printf("You enter the cave and find treasure!\n");
                                    break;
                                case 2:
                                    printf("You continue your journey through the forest.\n");
                                    break;
                                default:
                                    printf("Invalid choice.\n");
                            }
                            break;
                        case 2:
                            printf("You continue your journey through the forest.\n");
                            break;
                        default:
                            printf("Invalid choice.\n");
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        case 2:
            printf("You rest for a while.\n");
            printf("What would you like to do now?\n");
            printf("1. Keep exploring\n");
            printf("2. Quit\n");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("You continue your journey through the forest.\n");
                    break;
                case 2:
                    printf("Thanks for playing, %s!\n", name);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}