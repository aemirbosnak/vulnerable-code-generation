//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    //Introduction and character setup
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name?\n");
    char playerName[20];
    scanf("%s", playerName);
    printf("Welcome %s, let's begin your adventure!\n", playerName);
    printf("You find yourself in a dimly lit room. All you can see is a door in front of you and a window to your left.\n");
    printf("What do you do? Enter 1 to open the door, or 2 to look out the window.\n");
    int firstChoice;
    scanf("%d", &firstChoice);

    //First choice: door or window
    switch(firstChoice){
        case 1:
            printf("You try to open the door, but it's locked. You hear a noise coming from behind you. What do you do?\n");
            printf("Enter 1 to turn around or 2 to keep trying to open the door.\n");
            int secondChoice;
            scanf("%d", &secondChoice);

            //Second choice: turn around or keep trying door
            switch(secondChoice){
                case 1:
                    printf("You turn around to see a ghostly figure standing in front of you! It reaches out and grabs you, pulling you into darkness.\n");
                    break;
                case 2:
                    printf("You keep trying to open the door, and it finally opens. You step into a hallway.\n");
                    printf("You notice two hallways branching off to your left and right. Which one do you take? Enter 1 for left or 2 for right.\n");
                    int thirdChoice;
                    scanf("%d", &thirdChoice);

                    //Third choice: left or right hallway
                    switch(thirdChoice){
                        case 1:
                            printf("You walk down the left hallway and come to a dead end. Suddenly, a trap door opens beneath your feet and you fall into a pit of spikes!\n");
                            break;
                        case 2:
                            printf("You walk down the right hallway and come to a room with a chest in the center. Do you open it?\n");
                            printf("Enter 1 for yes or 2 for no.\n");
                            int fourthChoice;
                            scanf("%d", &fourthChoice);

                            //Fourth choice: open chest or not
                            switch(fourthChoice){
                                case 1:
                                    printf("You open the chest to find a key inside. You pick it up and notice another door on the opposite side of the room.\n");
                                    printf("You use the key to unlock the door and step through into a courtyard. You see the exit in front of you!\n");
                                    printf("As you approach the exit, a monster jumps out and attacks you. Do you fight or run?\n");
                                    printf("Enter 1 to fight or 2 to run.\n");
                                    int fifthChoice;
                                    scanf("%d", &fifthChoice);

                                    //Fifth choice: fight or run
                                    switch(fifthChoice){
                                        case 1:
                                            printf("You fight the monster and defeat it with a final blow. You escape the courtyard and win the game!\n");
                                            break;
                                        case 2:
                                            printf("You run away from the monster, but it catches up to you and eats you alive. GAME OVER.\n");
                                            break;
                                        default:
                                            printf("Invalid input. GAME OVER.\n");
                                            break;
                                    }
                                    break;
                                case 2:
                                    printf("You leave the chest alone and continue through the room to the door on the opposite side. You step through into a courtyard.\n");
                                    printf("As you approach the exit, a monster jumps out and attacks you. Do you fight or run?\n");
                                    printf("Enter 1 to fight or 2 to run.\n");
                                    int fifthChoice2;
                                    scanf("%d", &fifthChoice2);

                                    //Fifth choice: fight or run
                                    switch(fifthChoice2){
                                        case 1:
                                            printf("You fight the monster and defeat it with a final blow. You escape the courtyard and win the game!\n");
                                            break;
                                        case 2:
                                            printf("You run away from the monster, but it catches up to you and eats you alive. GAME OVER.\n");
                                            break;
                                        default:
                                            printf("Invalid input. GAME OVER.\n");
                                            break;
                                    }
                                    break;
                                default:
                                    printf("Invalid input. GAME OVER.\n");
                                    break;
                            }
                            break;
                        default:
                            printf("Invalid input. GAME OVER.\n");
                            break;
                    }
                    break;
                default:
                    printf("Invalid input. GAME OVER.\n");
                    break;
            }
            break;
        case 2:
            printf("You look out the window to see a beautiful garden. Suddenly, a giant spider crawls through the window and attacks you. Do you fight or run?\n");
            printf("Enter 1 to fight or 2 to run.\n");
            int secondChoice2;
            scanf("%d", &secondChoice2);

            //Second choice: fight or run
            switch(secondChoice2){
                case 1:
                    printf("You fight the spider and manage to kill it with a few well-placed hits. You notice a door on the other side of the garden.\n");
                    printf("You approach the door and try to open it, but it's locked. What do you do?\n");
                    printf("Enter 1 to break the door down or 2 to look for a key.\n");
                    int thirdChoice2;
                    scanf("%d", &thirdChoice2);

                    //Third choice: break down door or find key
                    switch(thirdChoice2){
                        case 1:
                            printf("You try to break the door down, but it's too strong. Suddenly, the spider's family appears and attacks you. GAME OVER.\n");
                            break;
                        case 2:
                            printf("You look around the garden and find a key hidden behind a bush. You use it to unlock the door and step through into a dark hallway.\n");
                            printf("You can barely see anything in front of you. Do you use your lighter or continue walking blindly?\n");
                            printf("Enter 1 to use your lighter or 2 to continue walking blindly.\n");
                            int fourthChoice2;
                            scanf("%d", &fourthChoice2);

                            //Fourth choice: use lighter or continue blindly
                            switch(fourthChoice2){
                                case 1:
                                    printf("You use your lighter to light the way and notice a tripwire on the ground in front of you. Do you step over it or try to disarm it?\n");
                                    printf("Enter 1 to step over it or 2 to try to disarm it.\n");
                                    int fifthChoice3;
                                    scanf("%d", &fifthChoice3);

                                    //Fifth choice: step over or disarm tripwire
                                    switch(fifthChoice3){
                                        case 1:
                                            printf("You step over the tripwire and continue down the hallway. You find a ladder leading up, and climb it to escape the darkness.\n");
                                            printf("You emerge outside and see the exit in front of you. As you approach, a monster jumps out and attacks you. Do you fight or run?\n");
                                            printf("Enter 1 to fight or 2 to run.\n");
                                            int sixthChoice;
                                            scanf("%d", &sixthChoice);

                                            //Sixth choice: fight or run
                                            switch(sixthChoice){
                                                case 1:
                                                    printf("You fight the monster and defeat it with a final blow. You escape the courtyard and win the game!\n");
                                                    break;
                                                case 2:
                                                    printf("You run away from the monster, but it catches up to you and eats you alive. GAME OVER.\n");
                                                    break;
                                                default:
                                                    printf("Invalid input. GAME OVER.\n");
                                                    break;
                                            }
                                            break;
                                        case 2:
                                            printf("You try to disarm the tripwire, but accidentally set it off. Poison darts shoot out of the walls and kill you instantly. GAME OVER.\n");
                                            break;
                                        default:
                                            printf("Invalid input. GAME OVER.\n");
                                            break;
                                    }
                                    break;
                                case 2:
                                    printf("You continue walking blindly and fall into a trap, injuring yourself badly. You manage to crawl your way out, but die from your injuries. GAME OVER.\n");
                                    break;
                                default:
                                    printf("Invalid input. GAME OVER.\n");
                                    break;
                            }
                            break;
                        default:
                            printf("Invalid input. GAME OVER.\n");
                            break;
                    }
                    break;
                case 2:
                    printf("You try to run away, but the spider catches up to you and kills you. GAME OVER.\n");
                    break;
                default:
                    printf("Invalid input. GAME OVER.\n");
                    break;
            }
            break;
        default:
            printf("Invalid input. GAME OVER.\n");
            break;
    }

    return 0;
}