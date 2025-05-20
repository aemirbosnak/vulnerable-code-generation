//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char choice;
    int game_ending = 0;

    printf("Welcome to the Surrealist Adventure Game! \n");

    while(!game_ending) {


    printf("You find yourself in a dark room with no apparent exits, what do you do? \n");

    printf("a. Look for a light switch \n");
    printf("b. Yell for help \n");
    printf("c. Sit and wait \n");

    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch(tolower(choice)) {
        case 'a':
            printf("You find a light switch and turn on the lights, revealing a room filled with clocks ticking at different rates. \n");
            printf("What do you do next? \n");
            printf("a. Try to reset the clocks to the same time \n");
            printf("b. Smash all the clocks \n");
            printf("c. Ignore the clocks and look for another way out. \n");

            printf("Enter your choice: ");
            scanf(" %c", &choice);

            switch(tolower(choice)) {
                case 'a':
                    printf("You attempt to reset the clocks, but suddenly they all start spinning rapidly. The room becomes a whirlwind and you are sucked into a vortex. \n");
                    game_ending = 1;
                    break;

                case 'b':
                    printf("Something tells you it's a bad idea, but you can't resist the urge to smash all the clocks. Suddenly, the walls of the room start closing in on you. \n");
                    game_ending = 1;
                    break;

                case 'c':
                    printf("You ignore the clocks and start inspecting the walls. You find a hidden door behind one of them and manage to escape. \n");
                    game_ending = 1;
                    break;

                default:
                    printf("Invalid choice. Try again. \n");
                    break;

            }

            break;

        case 'b':
            printf("You shout for help, but the only response you get is an echo. You start walking around the room and find a small hole in one of the corners. \n");
            printf("What do you do next? \n");
            printf("a. Crawl through the hole \n");
            printf("b. Shout for help again \n");
            printf("c. Wait for someone to find you. \n");

            printf("Enter your choice: ");
            scanf(" %c", &choice);

            switch(tolower(choice)) {
                case 'a':
                    printf("You crawl through the hole and find yourself in a pitch black tunnel. After a few turns, you come out into a beautiful garden. \n");
                    game_ending = 1;
                    break;

                case 'b':
                    printf("This time, you hear a faint response. You keep shouting and eventually someone hears you and rescues you. \n");
                    game_ending = 1;
                    break;

                case 'c':
                    printf("You sit and wait, but nobody comes. After what seems like hours, you start feeling hungry and thirsty. \n");
                    printf("You realize you've been trapped in the room for a long time and there's no hope of escape. \n");
                    game_ending = 1;
                    break;

                default:
                    printf("Invalid choice. Try again. \n");
                    break;

            }

            break;

        case 'c':
            printf("You sit in the corner of the room and wait. After a few minutes, you start hearing strange noises from the walls. \n");
            printf("What do you do next? \n");
            printf("a. Investigate the noises \n");
            printf("b. Cover your ears and wait \n");
            printf("c. Try to escape through the ceiling \n");

            printf("Enter your choice: ");
            scanf(" %c", &choice);

            switch(tolower(choice)) {
                case 'a':
                    printf("You investigate the noises and find a secret passage behind one of the walls. You go through it and find yourself in a room filled with giant mushrooms. \n");
                    game_ending = 1;
                    break;

                case 'b':
                    printf("The noises become louder and louder until they become unbearable. You cover your ears, but it's no use. Suddenly, the walls start closing in on you. \n");
                    game_ending = 1;
                    break;

                case 'c':
                    printf("You look up and see a small opening in the ceiling. You start climbing up, but it's a long way up. After what seems like hours, you get to the top and find yourself in a beautiful garden. \n");
                    game_ending = 1;
                    break;

                default:
                    printf("Invalid choice. Try again. \n");
                    break;

            }

            break;

        default:
            printf("Invalid choice. Try again. \n");
            break;

    }


    }

    printf("Thanks for playing! \n");

    return 0;
}