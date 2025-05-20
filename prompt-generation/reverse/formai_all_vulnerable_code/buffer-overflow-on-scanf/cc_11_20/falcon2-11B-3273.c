//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    char decision[50];
    printf("You find yourself standing at the entrance to a dark and mysterious cave. What do you do?\n");
    printf("1. Go inside the cave.\n");
    printf("2. Turn back and leave.\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("As you step inside the cave, the entrance closes behind you. You hear a faint sound of water dripping in the distance. What do you do?\n");
            printf("1. Explore the cave.\n");
            printf("2. Try to find your way out.\n");
            printf("Enter your choice (1 or 2): ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("You start exploring the cave and come across a narrow passage. What do you do?\n");
                    printf("1. Go through the passage.\n");
                    printf("2. Turn back and explore another part of the cave.\n");
                    printf("Enter your choice (1 or 2): ");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("You go through the passage and find yourself in a large room. In the center of the room is a large chest. What do you do?\n");
                            printf("1. Open the chest.\n");
                            printf("2. Leave the room.\n");
                            printf("Enter your choice (1 or 2): ");
                            scanf("%d", &choice);
                            switch (choice) {
                                case 1:
                                    printf("You open the chest and find a shiny gold coin. As you reach for it, the chest suddenly closes and traps you inside. You are doomed to spend eternity in the cave.\n");
                                    break;
                                case 2:
                                    printf("You decide to leave the room and continue exploring the cave.\n");
                                    break;
                            }
                        case 2:
                            printf("You turn back and explore another part of the cave. You come across a fork in the path. Which way do you go?\n");
                            printf("1. Left.\n");
                            printf("2. Right.\n");
                            printf("Enter your choice (1 or 2): ");
                            scanf("%d", &choice);
                            switch (choice) {
                                case 1:
                                    printf("You go left and find a dead end. You hear a faint voice whispering, \"You should have gone right.\"\n");
                                    break;
                                case 2:
                                    printf("You go right and find a hidden passage. You follow the passage and come across a small room. In the center of the room is a mysterious book. What do you do?\n");
                                    printf("1. Read the book.\n");
                                    printf("2. Leave the room.\n");
                                    printf("Enter your choice (1 or 2): ");
                                    scanf("%d", &choice);
                                    switch (choice) {
                                        case 1:
                                            printf("As you read the book, it transports you to a different world. You explore the world and have an amazing adventure.\n");
                                            break;
                                        case 2:
                                            printf("You decide to leave the room and continue exploring the cave.\n");
                                            break;
                                    }
                            }
                    }
                case 2:
                    printf("You decide to try and find your way out of the cave. After exploring for a while, you come across a faint light in the distance. You follow the light and find yourself back at the entrance of the cave. You are free to leave.\n");
                    break;
            }
        case 2:
            printf("You decide to turn back and leave the cave. As you walk away, you hear a faint voice whispering, \"You should have gone inside.\"\n");
            break;
    }
    printf("Thanks for playing!\n");
    return 0;
}