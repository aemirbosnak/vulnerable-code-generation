//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// function prototypes
void startGame();
void introduction();
void play();
void endGame();
void clearInput();

// main function
int main() {
    startGame();
    return 0;
}

// function to start the game
void startGame() {
    introduction();

    printf("\nYou find yourself in the streets of Neo-Tokyo. You are a hacker on the run, trying to stay one step ahead of the law.");
    printf("\nThere is a job waiting for you that could make you rich, but it won't be easy.");
    printf("\nDo you accept the job? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if(tolower(choice) == 'y') {
        play();
    }
    else if(tolower(choice) == 'n') {
        printf("\nYou decide the risk is too high and choose to lay low for a while.");
        endGame();
    }
    else {
        printf("\nInvalid choice.");
        startGame();
    }
}

// function to introduce the game
void introduction() {
    printf("\nWelcome to Cyberpunk Adventure!");
    printf("\n------------------------------");
    printf("\nIn this game, you will take on the role of a hacker in a futuristic and dystopian world.");
    printf("\nYour choices will determine the outcome of the game.");
}

// function to play the game
void play() {
    printf("\nYou meet your contact, a shadowy figure in a dark alley. They tell you about a corporation that has been stealing from innocent people by hacking into their cybernetic implants.");
    printf("\nYour job is to hack into their servers and expose them for the criminals they are.");
    printf("\nDo you accept the job? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    clearInput();

    if(tolower(choice) == 'y') {
        printf("\nYour contact hands you a device that will help you break into the corporation's servers.");
        printf("\nYou make your way to the corporation's headquarters, sneaking past security and avoiding drones patrolling the area.");

        printf("\n\nYou arrive at the entrance to the server room. It's guarded by two heavily armed guards.");
        printf("\nWhat do you do? (1. Try to sneak past them/2. Take them out/3. Hack the security system): ");
        int action;
        scanf("%d", &action);

        switch(action) {
            case 1: // sneak past guards
                printf("\nYou try to sneak past the guards, but they spot you and sound the alarm.");
                printf("\nYou run for it, but you are quickly surrounded by security forces.");
                endGame();
                break;
            case 2: // take out guards
                printf("\nYou take out the guards quietly and enter the server room.");
                printf("\nYou find the device your contact gave you and start hacking into the system.");

                printf("\n\nThe hack is going smoothly, but you hear footsteps approaching.");
                printf("\nWhat do you do? (1. Keep hacking/2. Hide/3. Confront them): ");
                int choice2;
                scanf("%d", &choice2);
                clearInput();

                switch(choice2) {
                    case 1: // keep hacking
                        printf("\nYou keep hacking, desperately trying to finish before it's too late.");
                        printf("\nYou hear the footsteps getting closer, but you're almost there.");
                        printf("\nFinally, you succeed in copying the incriminating data from the server.");
                        printf("\nYou make a hasty exit before you're caught.");
                        printf("\nCongratulations, you've successfully completed the mission!");
                        endGame();
                        break;
                    case 2: // hide
                        printf("\nYou quickly hide behind a server rack, hoping they won't find you.");
                        printf("\nThe footsteps get louder and you can see a flashlight sweeping across the room.");
                        printf("\nYou hold your breath, hoping they won't find you.");
                        printf("\nAfter a few tense moments, the footsteps recede and you're safe for now.");
                        printf("\nYou continue hacking, but it takes longer than you planned.");
                        printf("\nWhen you finally finish and leave the server room, you're late for the rendezvous with your contact.");
                        printf("\nThey're not happy, but you still get paid.");
                        printf("\nCongratulations, you've completed the mission!");
                        endGame();
                        break;
                    case 3: // confront them
                        printf("\nYou confront the security guard, but they are heavily armed and your skills aren't enough to take them down.");
                        printf("\nYou're quickly overpowered and captured.");
                        endGame();
                        break;
                    default:
                        printf("\nInvalid choice.");
                        play();
                        break;
                }
                break;
            case 3: // hack the security system
                printf("\nYou hack the security system and disable all alarms and cameras in the area.");
                printf("\nYou enter the server room and start hacking the system.");

                printf("\n\nEverything is going smoothly, but you hear footsteps approaching.");
                printf("\nWhat do you do? (1. Ignore them/2. Hide/3. Confront them): ");
                int choice3;
                scanf("%d", &choice3);
                clearInput();

                switch(choice3) {
                    case 1: // ignore them
                        printf("\nYou ignore the footsteps and keep hacking.");
                        printf("\nFinally, you succeed in copying the incriminating data from the server.");
                        printf("\nYou exit the server room and leave the building unnoticed.");
                        printf("\nCongratulations, you've successfully completed the mission!");
                        endGame();
                        break;
                    case 2: // hide
                        printf("\nYou quickly hide behind a server rack, hoping they won't find you.");
                        printf("\nThe footsteps get louder and you can see a flashlight sweeping across the room.");
                        printf("\nYou hold your breath, hoping they won't find you.");
                        printf("\nAfter a few tense moments, the footsteps recede and you're safe for now.");
                        printf("\nYou continue hacking, but it takes longer than you planned.");
                        printf("\nWhen you finally finish and leave the server room, you're late for the rendezvous with your contact.");
                        printf("\nThey're not happy, but you still get paid.");
                        printf("\nCongratulations, you've completed the mission!");
                        endGame();
                        break;
                    case 3: // confront them
                        printf("\nYou confront the security guard, but they are heavily armed and your skills aren't enough to take them down.");
                        printf("\nYou're quickly overpowered and captured.");
                        endGame();
                        break;
                    default:
                        printf("\nInvalid choice.");
                        play();
                        break;
                }
                break;
            default:
                printf("\nInvalid choice.");
                play();
                break;
        }
    }
    else if(tolower(choice) == 'n') {
        printf("\nYou decide the risk is too high and choose to lay low for a while.");
        endGame();
    }
    else {
        printf("\nInvalid choice.");
        play();
    }
}

// function to end the game
void endGame() {
    printf("\n\nGame over.");
    printf("\nWould you like to play again? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    clearInput();

    if(tolower(choice) == 'y') {
        startGame();
    }
    else if(tolower(choice) == 'n') {
        printf("\nThanks for playing!");
    }
    else {
        printf("\nInvalid choice.");
        endGame();
    }
}

// function to clear input buffer
void clearInput() {
    while(getchar() != '\n');
}