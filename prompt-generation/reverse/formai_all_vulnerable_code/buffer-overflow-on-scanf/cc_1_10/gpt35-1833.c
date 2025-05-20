//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void intro(){
    printf("         ____  _______     ___   ____    ____   __   ______   .__   __. \n");
    printf("         |   \/   _  \   /   \  \   \  /   /  |  | |      |  |  \ |  | \n");
    printf("         |  \ /  \  |  \/  ^  \  \   \/   /   |  | |  ,----'  |   \|  | \n");
    printf("         |  |    | |  /  /_\  \  \      /    |  | |  |       |  . `  | \n");
    printf("         |  |    | | /  _____  \  \    /     |  | |  `----.  |  |\   | \n");
    printf("         |__|    |_|/__/     \__\  \__/      |__| |_______| |__| \__| \n");
    printf("\nWelcome to the mysterious cave adventure!\n");
    printf("You find yourself standing in front of a dark, ominous cave.  Your heart is racing as you consider whether or not you're brave enough to enter. Do you dare? \n");
}

void win(){
    printf("\nYou found the treasure! Congratulations on your successful adventure.\n");
    printf("      .---.\n");
    printf("     / .-\"\"-.\\\n");
    printf("    / /                                     \\ \\\n");
    printf("   / /                                       \\ \\\n");
    printf("  / /                                       \\ \\\n");
    printf(" \\ \\                                         / /\n");
    printf("  \\ `-._______,-----,_______,-.\"/\n");
    printf("   `._,-----' '\\   /`'-----,_.\"\n");
    printf("                 `\"\"`\n");
}

void lose(){
    printf("\nOh no! Your adventure was unsuccessful. You lost.\n");
    printf("     ,--.\n");
    printf(" ,--.|__| ,--.,--,--,  ,---.   \n");
    printf("|  ||  || |  ||      \\'   /    \n");
    printf("|  ||  || |  ||  ||  |\\  \\     \n");
    printf(" `--'`--'`--'`--''--' `--'     \n");
}

void adventure(){
    int treasureLocation = rand() % 3 + 1;
    int guess;
    int guessCount = 0;
    int maxGuesses = 3;
    printf("Inside the cave, you see three tunnels.\n");
    printf("Which tunnel do you choose? Enter 1, 2, or 3: ");
    scanf("%d", &guess);
    while(guessCount < maxGuesses){
        if(guess == treasureLocation){
            win();
            return;
        }else{
            printf("Wrong guess! Please try again.\n");
            guessCount++;
            if(guessCount == maxGuesses){
                break;
            }
            printf("Which tunnel do you choose now? Enter 1, 2, or 3: ");
            scanf("%d", &guess);
        }
    }
    lose();
}

int main(){
    srand(time(NULL));
    char playAgain;
    do{
        intro();
        adventure();
        printf("Would you like to play again? Enter y for yes, or n for no: ");
        scanf(" %c", &playAgain);
    }while(playAgain == 'y' || playAgain == 'Y');
    printf("Thank you for playing the mysterious cave adventure! Goodbye.\n");
    return 0;
}