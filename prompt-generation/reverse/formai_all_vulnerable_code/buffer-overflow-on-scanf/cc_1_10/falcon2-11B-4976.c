//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void exit_handler(int sig) {
    printf("\nGoodbye!\n");
    exit(0);
}

void start_game() {
    char* choices[] = { "rock", "paper", "scissors" };
    int choice = 0;

    srand(time(NULL));

    while (1) {
        printf("\nChoose your weapon:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %s\n", i+1, choices[i]);
        }

        printf("Enter your choice (1-%d): ", 3);
        scanf("%d", &choice);

        if (choice > 0 && choice <= 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nComputer's choice: %s\n", choices[rand() % 3]);

    if (choice == 1 && ((rand() % 3) == 1 || ((rand() % 3) == 0 && choice == 2))) {
        printf("You win!\n");
    } else if (choice == 2 && ((rand() % 3) == 2 || ((rand() % 3) == 0 && choice == 1))) {
        printf("You win!\n");
    } else if (choice == 3 && ((rand() % 3) == 3 || ((rand() % 3) == 0 && choice == 2))) {
        printf("You win!\n");
    } else {
        printf("Computer wins.\n");
    }
}

int main() {
    signal(SIGINT, exit_handler);
    start_game();
    return 0;
}