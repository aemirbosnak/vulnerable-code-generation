//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score1, score2, rating1, rating2, game_round = 1;

    // Initialize ratings
    rating1 = 1500;
    rating2 = 1800;

    // Game loop
    while (game_round <= 5)
    {
        // Get scores
        printf("Enter your score: ");
        scanf("%d", &score1);

        printf("Enter your opponent's score: ");
        scanf("%d", &score2);

        // Calculate ratings
        rating1 = calculate_rating(score1, score2, rating1);
        rating2 = calculate_rating(score2, score1, rating2);

        // Print ratings
        printf("Your new rating: %d\n", rating1);
        printf("Your opponent's new rating: %d\n", rating2);

        // Increment game round
        game_round++;
    }

    return 0;
}

int calculate_rating(int score, int opponent_score, int current_rating)
{
    int expected_score, deviation, change, new_rating;

    // Calculate expected score
    expected_score = calculate_expected_score(current_rating);

    // Calculate deviation
    deviation = score - expected_score;

    // Calculate change
    change = deviation * 32 / 1000;

    // Calculate new rating
    new_rating = current_rating + change;

    return new_rating;
}

int calculate_expected_score(int rating)
{
    return 1000 / (1 + 10 / (rating + 200));
}