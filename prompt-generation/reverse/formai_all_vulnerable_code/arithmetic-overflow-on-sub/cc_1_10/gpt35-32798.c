//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Typing Speed Test game!\n");
    printf("Instructions: You will be given a random word and you need to type it as fast as you can within the given time limit.\n");
    printf("Are you ready to play the game?\n");
    printf("Press any key to start the game.\n");

    getchar();
    system("clear");

    printf("Game started!\n");

    int count = 0;
    int time_left = 60;

    char words[10][50] = {
        "algorithm",
        "language",
        "keyboard",
        "computer",
        "mouse",
        "trackpad",
        "monitor",
        "program",
        "memory",
        "Internet"
    };

    srand(time(0));

    while(time_left > 0)
    {
        int random_index = rand() % 10;
        printf("Type the word: %s\n", words[random_index]);

        time_t start = time(NULL);

        char user_input[50];
        scanf("%s", user_input);

        time_t end = time(NULL);

        if(strcmp(user_input, words[random_index]) == 0)
        {
            count++;
            printf("Correct! Your score is: %d\n", count);
        }
        else
        {
            printf("Incorrect! Try again.\n");
        }

        time_left -= difftime(end, start);
        printf("Time left %d seconds.\n", time_left);
    }

    printf("Time is up!\n");
    printf("Your final score is: %d\n", count);

    return 0;
}