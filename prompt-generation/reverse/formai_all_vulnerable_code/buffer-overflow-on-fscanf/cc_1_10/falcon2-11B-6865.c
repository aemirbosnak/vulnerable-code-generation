//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum direction { NORTH, SOUTH, EAST, WEST };

int main() {
    char choice;
    char name[20];
    char* verb = "look";
    char* noun = "room";

    puts("Welcome to the Text-Based Adventure Game!");
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    printf("Hello, %s! Welcome to the Text-Based Adventure Game.\n", name);
    printf("You find yourself in a dark room. There are four doors in front of you, each leading to a different direction.\n");
    printf("Which direction would you like to go? ");

    while (1) {
        fscanf(stdin, "%c", &choice);

        if (isalpha(choice)) {
            printf("I'm sorry, I don't understand that direction.\n");
        } else {
            if (choice == 'q') {
                break;
            }

            switch (choice) {
                case 'n':
                    printf("You go north.\n");
                    break;
                case's':
                    printf("You go south.\n");
                    break;
                case 'e':
                    printf("You go east.\n");
                    break;
                case 'w':
                    printf("You go west.\n");
                    break;
                default:
                    printf("I'm sorry, I don't understand that direction.\n");
            }
        }
    }

    puts("Thank you for playing the Text-Based Adventure Game!");
    return 0;
}