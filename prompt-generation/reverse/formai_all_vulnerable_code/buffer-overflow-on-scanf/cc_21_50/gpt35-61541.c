//FormAI DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Surrealist Table Game!\n\n");

    int choice, num = 0, guess = 0, count = 0;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("\n%s, your goal is to reach the end of the table by guessing the right number between 1 and 10.\n", name);
    printf("But beware, every time you guess wrong, you will be transported to a different surreal dimension where the rules may change and your life may be threatened.\n");
    printf("Are you ready to start the game?\n");
    printf("1. Yes\n2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice != 1) {
        printf("\nMaybe another time. Goodbye!\n");
        return 0;
    }

    srand(time(0));
    num = rand() % 10 + 1;

    printf("\nYou find yourself seated at a table in an empty room with no windows or doors.\n");
    printf("On the table, you see a small wooden box with a number pad attached to it.\n");
    printf("The number pad displays the number 0.\n");

    while (guess != num) {
        printf("\nEnter your guess (between 1 and 10): ");
        scanf("%d", &guess);

        if (guess == num) {
            printf("\nCongratulations, %s! You have reached the end of the table and won the game!\n", name);
            return 0;
        } else {
            count++;
            printf("\nSorry, that is not the correct number. You have been transported to a new dimension.\n");

            if (count == 1) {
                printf("You find yourself in a room filled with giant mushrooms and a man who calls himself the Mushroom King.\n");
                printf("He tells you that you must complete a riddle before you can leave his kingdom.\n");
                printf("The riddle is: What has a head and a tail, but no body?\n");
                printf("Enter your answer: ");
                char answer[20];
                scanf("%s", answer);

                if (strcmp(answer, "coin") == 0) {
                    printf("The Mushroom King is pleased with your answer and sends you back to the table.\n");
                } else {
                    printf("I'm sorry, that is not correct. You will have to stay here until you figure it out.\n");
                }
            } else if (count == 2) {
                printf("You find yourself in a room where gravity is reversed. You must make your way to the other side of the room to escape.\n");
                int x, y, fx, fy, tx, ty;
                x = y = fx = fy = tx = ty = 0;

                printf("Use the arrow keys to move around. Press 'q' to quit at any time.\n");

                while (1) {
                    printf("\nCurrent position: (%d,%d)\n", x, y);

                    if (x == fx && y == fy) {
                        printf("You have found the exit!\n");
                        break;
                    }

                    printf("Enter direction (up = 'w', down = 's', left = 'a', right = 'd'): ");
                    char direction = getchar();
                    getchar();

                    if (direction == 'q') {
                        printf("\n%s, you have quit the game. Goodbye!\n", name);
                        return 0;
                    }

                    switch (direction) {
                        case 'w':
                            ty = y - 1;
                            if (ty < 0) {
                                printf("You cannot move in that direction.\n");
                                break;
                            }
                            y = ty;
                            break;
                        case 's':
                            ty = y + 1;
                            if (ty > 10) {
                                printf("You cannot move in that direction.\n");
                                break;
                            }
                            y = ty;
                            break;
                        case 'a':
                            tx = x - 1;
                            if (tx < 0) {
                                printf("You cannot move in that direction.\n");
                                break;
                            }
                            x = tx;
                            break;
                        case 'd':
                            tx = x + 1;
                            if (tx > 10) {
                                printf("You cannot move in that direction.\n");
                                break;
                            }
                            x = tx;
                            break;
                        default:
                            printf("Invalid input. Please try again.\n");
                            break;
                    }
                }

                printf("You have managed to make your way to the other side of the room and escape.\n");
            } else if (count == 3) {
                printf("You find yourself in a dark room with strange noises echoing all around you.\n");
                printf("Suddenly, a spotlight shines on a table in the middle of the room.\n");
                printf("On the table, you see a message written on a piece of paper: 'To escape this room, you must solve the mystery of the missing letter.'\n");
                printf("You look around the room but cannot find any missing letters.\n");
                printf("However, you do notice that some of the furniture in the room seems to be out of place.\n");
                printf("Maybe rearranging the furniture will reveal something.\n");
                printf("Enter 'r' to rearrange the furniture. Enter anything else to leave it as it is: ");
                char input = getchar();
                getchar();

                if (input == 'r') {
                    printf("\nYou start rearranging the furniture in the room until finally, something clicks into place.\n");
                    printf("A trap door beneath the table opens up, revealing a staircase leading to the exit.\n");
                } else {
                    printf("\nYou decide not to rearrange the furniture and continue searching the room. However, you find nothing and are eventually transported to another dimension.\n");
                }
            } else if (count == 4) {
                printf("You find yourself in a room filled with water and no way out.\n");
                printf("Suddenly, a voice booms out from nowhere: 'To escape this room, you must solve the mystery of the three doors.'\n");
                printf("You look around the room and notice three doors, each with a different symbol on it: a sun, a moon, and a star.\n");
                printf("Which door do you choose? (1 = sun, 2 = moon, 3 = star): ");
                int door;
                scanf("%d", &door);

                switch (door) {
                    case 1:
                        printf("\nYou open the door with the sun symbol and are blinded by a bright light.\n");
                        printf("When your eyes adjust, you find yourself transported back to the table.\n");
                        break;
                    case 2:
                        printf("\nYou open the door with the moon symbol and are transported to another dimension.\n");
                        printf("This time, you find yourself in a room filled with mirrors.\n");
                        printf("You notice a message written in the condensation on one of the mirrors: 'To escape this room, you must break the mirror.'\n");
                        printf("You look around the room but cannot find anything to break the mirror with.\n");
                        printf("Then you remember the wooden box on the table and decide to use it to break the mirror.\n");
                        printf("You smash the mirror and are transported back to the table.\n");
                        break;
                    case 3:
                        printf("You open the door with the star symbol and are transported to another dimension.\n");
                        printf("This time, you find yourself in a room with a single light shining down on a pedestal with a knife on it.\n");
                        printf("You notice a message etched into the pedestal: 'To escape this room, you must cut the wire.'\n");
                        printf("You look around the room for a wire but cannot find one.\n");
                        printf("Then you notice that the knife is connected to a wire and decide to cut it.\n");
                        printf("As soon as you cut the wire, you are transported back to the table.\n");
                        break;
                    default:
                        printf("Invalid input. Please try again.\n");
                        break;
                }
            } else if (count == 5) {
                printf("You find yourself in a room with no exit and no apparent way out.\n");
                printf("Suddenly, the table in front of you starts to shake and a crack forms down the middle.\n");
                printf("Out of the crack emerges a creature with a hundred eyes and a thousand teeth.\n");
                printf("The creature speaks in a voice that sounds like it is coming from inside your mind: 'To escape this room, you must give me something I've never seen before.'\n");
                printf("What do you give the creature? ");
                char item[20];
                scanf("%s", item);
                printf("\nThe creature examines the item for a moment before swallowing it whole.\n");
                printf("Then, as suddenly as it appeared, the creature slinks back into the crack in the table and disappears.\n");
                printf("Moments later, the crack in the table seals up and you find yourself transported back to the original dimension.\n");
            } else if (count == 6) {
                printf("You find yourself in a room with no doors or windows, and a voice in your head tells you that in order to escape, you must perform a dance.\n");
                printf("Enter 'd' to dance (you can enter anything else to give up): ");
                char input = getchar();
                getchar();

                if (input == 'd') {
                    printf("\nYou start dancing as best you can in the confined space of the room, feeling ridiculous and embarrassed.");
                    printf("However, you slowly start to feel a sense of freedom and joy as you lose yourself in the dance.\n");
                    printf("Suddenly, the room starts to spin and you feel yourself lifted off the ground.\n");
                    printf("When you open your eyes, you find yourself back at the table.\n");
                } else {
                    printf("\nYou decide not to dance and eventually fall asleep on the floor.\n");
                    printf("When you wake up, you find yourself back at the original dimension.\n");
                }
            } else {
                printf("You have been transported to a new dimension but are unable to complete the challenge and are trapped there forever.\n");
                printf("Game over!\n");
                return 0;
            }
        }
    }

    return 0;
}