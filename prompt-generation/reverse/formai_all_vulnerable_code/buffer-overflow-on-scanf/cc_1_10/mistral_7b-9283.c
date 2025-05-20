//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10
#define MIN_NUMBER 1

void print_menu() {
    printf("\n*** Welcome to the Number Guessing Game! ***\n");
    printf("1. Start the game\n");
    printf("2. Quit\n");
}

int generate_random_number() {
    srand(time(NULL));
    int random_number = rand() % (MAX_NUMBER + 1) + MIN_NUMBER;
    return random_number;
}

int get_user_input() {
    int user_input;
    scanf("%d", &user_input);
    return user_input;
}

int check_guess(int computer_number, int user_guess) {
    int result;

    if (computer_number > user_guess) {
        printf("Your guess is too low. Try again.\n");
        result = -1;
    } else if (computer_number < user_guess) {
        printf("Your guess is too high. Try again.\n");
        result = -1;
    } else {
        printf("Congratulations! You have guessed the number correctly.\n");
        result = 0;
    }

    return result;
}

int main() {
    int computer_number, user_guess, game_over = 0;

    while (!game_over) {
        print_menu();
        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                computer_number = generate_random_number();
                user_guess = get_user_input();

                while (user_guess != computer_number) {
                    int check_result = check_guess(computer_number, user_guess);
                    user_guess = get_user_input();

                    if (check_result == -1) {
                        continue;
                    }
                }

                break;

            case 2:
                printf("Thanks for playing the game. Goodbye!\n");
                game_over = 1;
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}