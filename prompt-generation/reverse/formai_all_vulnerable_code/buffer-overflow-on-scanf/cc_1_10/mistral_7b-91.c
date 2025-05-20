//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_smiley(int happy) {
    if (happy) {
        printf("\033[38;5;202m"); // bright green
        printf("  _____        _____ _____ ");
        printf(" / ____|  |  / ____|  _  |");
        printf("| (___  |_|_| |  __| | | |");
        printf(" \\___  \\    | |  |_| |_| |");
        printf(" _____| |__| |__||__||__|_|");
        printf("|_____|________| |___|_____|");
        printf("\033[0m");
    } else {
        printf("Sorry, I'll keep trying!\n");
    }
}

int main() {
    srand(time(NULL));
    int secret_number = random_number(MIN_NUMBER, MAX_NUMBER);
    int guess, tries = 0;

    printf("\033[38;5;214m"); // bright blue
    printf("\n _____ _____ ____ _____ ____ \n");
    printf("| ____|  ___|  _  |  __|_  _ \n");
    printf("| (___  |__  |_| |_| |  | |_) |\n");
    printf("| ___|____|  _  _   _| |  | |_| \n");
    printf("|_____|_____|_|_|_|  |_|  |_| \n");
    printf("\033[0m\n");

    printf("Welcome to Happy Number Guess!\n");
    printf("I have chosen a number between %d and %d. Can you guess it?\n", MIN_NUMBER, MAX_NUMBER);

    while (tries < MAX_TRIES) {
        scanf("%d", &guess);

        if (guess == secret_number) {
            print_smiley(1);
            printf("Congratulations! You've guessed the number in %d tries.\n", tries + 1);
            break;
        } else {
            tries++;
            print_smiley(0);
            if (tries < MAX_TRIES) {
                printf("Try again! Number %d is incorrect. \n", guess);
            }
        }
    }

    if (tries >= MAX_TRIES) {
        printf("Sorry, you have run out of tries. The number was %d.\n", secret_number);
    }

    return 0;
}