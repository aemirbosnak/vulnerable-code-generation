//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro(){
    printf("\n***Welcome to the C Random Conspiracy Theory Generator***\n");
    printf("Generating your paranoia since %d...\n", 1900 + rand() % 121);
}

void printConspiracy(){

    //list of conspiracy theories
    char *conspiracies[] = {
            "The world is controlled by a secret society of reptilian aliens!",
            "The government is hiding evidence of UFOs!",
            "The moon landing was faked!",
            "The Illuminati is controlling every aspect of our lives!",
            "The CIA is behind the rise of terrorism!",
            "Mandela Effect proves we live in a multiverse!",
            "The Earth is flat and NASA is lying to us!",
            "Global warming is a hoax to control the population!",
            "The vaccines are causing autism!",
            "The New World Order is coming!"
    };

    //choose a random conspiracy theory
    int randomIndex = rand() % 10;
    char *conspiracy = conspiracies[randomIndex];

    printf("\n\n==============================================\n\n");
    printf("CONSPIRACY THEORY ALERT:\n\n%s\n\n", conspiracy);
    printf("==============================================\n\n");
}

int main(){
    srand(time(NULL)); //initialize random seed
    int keepGoing = 1; //keep generating conspiracies until user decides to stop

    printIntro(); //print intro

    while (keepGoing){ //keep generating conspiracies

        printConspiracy(); //print conspiracy theory

        //ask if user wants to continue
        char userInput;
        printf("Do you want to know more? (y/n): ");
        scanf(" %c", &userInput);

        if (userInput == 'n'){
            keepGoing = 0; //stop generating conspiracies
        }
    }

    printf("Stay paranoid, my friend!\n");

    return 0; //end program
}