//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

void clearScreen() {
    system("clear");
}

void printTitle() {
    printf("\n");
    printf("   _     _ _ _ \n");
    printf("  (_)___| | | |\n");
    printf(" | | ___| |_| |\n");
    printf(" | |/ __| __| |\n");
    printf(" | |\\__ \\ |_| |\n");
    printf(" |_|\\___/\\__,_|\n");
    printf("\n");
}

void printHelp() {
    printf("\n");
    printf("   _     _ _ _ \n");
    printf("  (_)___| | | |\n");
    printf(" | | ___| |_| |\n");
    printf(" | |/ __| __| |\n");
    printf(" | |\\__ \\ |_| |\n");
    printf(" |_|\\___/\\__,_|\n");
    printf("\n");
    printf("Welcome to the futuristic game!\n");
    printf("Instructions:\n");
    printf("1. Type 'help' to show this message.\n");
    printf("2. Type 'quit' to exit the game.\n");
    printf("3. Type anything else to play the game.\n");
}

void playGame(char* input) {
    int randomNumber = rand() % 100;
    int userGuess = -1;

    while (userGuess!= randomNumber) {
        printf("\n");
        printf("Guess a number between 1 and 100:\n");
        scanf("%d", &userGuess);

        if (userGuess < 1 || userGuess > 100) {
            printf("Invalid input! Please try again.\n");
        }
    }

    printf("\n");
    printf("Congratulations! You guessed the number correctly.\n");
    printf("The number was %d.\n", randomNumber);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    printTitle();
    printHelp();

    char input[100];

    while (1) {
        printf("\n");
        printf("Enter your choice:\n");
        scanf("%s", input);

        if (strcmp(input, "help") == 0) {
            printHelp();
        } else if (strcmp(input, "quit") == 0) {
            printf("\n");
            printf("Goodbye!\n");
            break;
        } else {
            playGame(input);
        }
    }

    return 0;
}