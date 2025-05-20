//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

typedef struct {
    char name[50];
    int score;
} Player;

void print_instructions() {
    printf("Welcome to the Dungeon Escape Game!\n");
    printf("Your mission is to escape the dungeon by guessing the secret number.\n");
    printf("You have %d attempts to guess the number between 1 and 100.\n", MAX_ATTEMPTS);
    printf("Good luck!\n\n");
}

int get_random_number() {
    return rand() % 100 + 1; // Random number between 1 and 100
}

int is_guess_correct(int guess, int secret_number) {
    return guess == secret_number;
}

void update_score(Player* player, int attempts_left) {
    player->score += (attempts_left * 20); // Each attempt gives 20 points
}

void play_game(Player* player) {
    int secret_number = get_random_number();
    int guess, attempts = MAX_ATTEMPTS;

    while (attempts > 0) {
        printf("You have %d attempts left. Enter your guess: ", attempts);
        scanf("%d", &guess);

        if (is_guess_correct(guess, secret_number)) {
            printf("Congratulations, %s! You've guessed the correct number: %d\n", player->name, secret_number);
            update_score(player, attempts);
            return;
        } else {
            attempts--;
            if (guess < secret_number) {
                printf("The secret number is higher than %d.\n\n", guess);
            } else {
                printf("The secret number is lower than %d.\n\n", guess);
            }
        }
    }

    printf("Sorry, %s! You've exhausted all attempts. The secret number was: %d\n", player->name, secret_number);
}

void display_score(Player player) {
    printf("Thank you for playing, %s! Your final score is: %d\n", player.name, player.score);
}

int main() {
    Player player;
    int choice;

    srand(time(NULL)); // Seed the random number generator

    printf("Enter your name: ");
    fgets(player.name, sizeof(player.name), stdin);
    player.name[strcspn(player.name, "\n")] = 0; // Remove newline character from string
    player.score = 0;

    print_instructions();

    do {
        play_game(&player);
        display_score(player);

        printf("\nDo you want to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        printf("\n");
    } while (choice == 1);

    printf("Goodbye, %s! Thanks for playing!\n", player.name);
    return 0;
}