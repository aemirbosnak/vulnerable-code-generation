//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int randrange(int, int);
int calculate_score(int, int);
void print_description();
int play_game();

int main()
{
    srand(time(0)); // Seed the random number generator with current time
    print_description(); // Print the game description
    int total_score = 0;
    int num_games = 3; // Play 3 games
    for (int i = 1; i <= num_games; i++) {
        printf("Starting game %d...\n", i);
        int score = play_game(); // Play the game and get the score
        printf("Game %d score: %d\n", i, score);
        total_score += score;
    }
    printf("Your total score for all games is: %d\n", total_score);
    return 0;
}

// Generates a random number between start and end (inclusive)
int randrange(int start, int end)
{
    return (rand() % (end - start + 1)) + start;
}

// Calculates the score for a game
int calculate_score(int num_tries, int max_tries)
{
    return ((float)num_tries / max_tries) * 100;
}

// Prints the game description
void print_description()
{
    printf("Welcome to the Space Adventure game!\n");
    printf("You are the captain of a spaceship and your mission is to navigate through space and collect treasure.\n");
    printf("You are given a map that shows the location of the treasure, but it is hidden behind a mathematical equation.\n");
    printf("You need to solve the equation to find the location of the treasure.\n");
    printf("You have a limited number of tries to solve the equation, so use them wisely!\n");
    printf("Your score for each game is based on the number of tries you use, with a maximum score of 100.\n");
    printf("Let's get started!\n\n");
}

// Plays a single game
int play_game()
{
    int max_tries = 5; // Maximum number of tries
    int num_tries = 0;
    int a = randrange(1, 10); // Generate two random numbers
    int b = randrange(1, 10);
    int c = randrange(1, 10);
    int x, y;
    printf("Solve the following equation to find the treasure location:\n");
    printf("%d*x + %d*y = %d\n", a, b, c);
    while (num_tries < max_tries) {
        printf("Enter a value for x: ");
        scanf("%d", &x);
        printf("Enter a value for y: ");
        scanf("%d", &y);
        num_tries++;
        if (a * x + b * y == c) {
            printf("Congratulations! You found the treasure in %d tries.\n", num_tries);
            int score = calculate_score(num_tries, max_tries);
            printf("Your score for this game is: %d\n\n", score);
            return score;
        } else {
            printf("Sorry, that is not the correct answer. You have %d out of %d tries left.\n", max_tries - num_tries, max_tries);
        }
    }
    printf("Sorry, you did not find the treasure in time.\n\n");
    return 0;
}