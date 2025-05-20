//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define MAX_FORTUNES 10

void display_fortune(const char *name, const char *fortune) {
    printf("%s, your fortune is:\n%s\n", name, fortune);
}

const char* get_random_fortune() {
    const char* fortunes[MAX_FORTUNES] = {
        "You will find a hidden treasure soon.",
        "A great opportunity lies ahead; seize it!",
        "Expect the unexpected this week.",
        "Your passion will lead you to success.",
        "Someone close to you will offer wise counsel.",
        "Adventure awaits you; don't be afraid to explore!",
        "A new friendship will develop into something special.",
        "Change is coming; embrace it.",
        "Your intuition is strong; trust it.",
        "Love is in the air; keep your heart open."
    };
    
    return fortunes[rand() % MAX_FORTUNES];
}

int main() {
    srand(time(NULL));

    char player_names[MAX_PLAYERS][MAX_NAME_LENGTH];
    int number_of_players = 0;
    char continue_game;

    printf("Welcome to the Multiplayer Fortune Teller!\n");
    printf("You can add a maximum of %d players.\n", MAX_PLAYERS);

    // Getting player names
    do {
        if (number_of_players >= MAX_PLAYERS) {
            printf("Player limit reached.\n");
            break;
        }
        
        printf("Enter player %d name (or type 'done' to finish): ", number_of_players + 1);
        fgets(player_names[number_of_players], MAX_NAME_LENGTH, stdin);
        player_names[number_of_players][strcspn(player_names[number_of_players], "\n")] = 0; // Remove newline

        if (strcmp(player_names[number_of_players], "done") == 0) {
            break;
        } else {
            number_of_players++;
        }
    } while (1);

    // Display fortunes
    printf("\nGame Starting! Here are the fortunes:\n");
    for (int i = 0; i < number_of_players; i++) {
        display_fortune(player_names[i], get_random_fortune());
    }

    // Option to continue or end the game
    printf("\nWould you like to play again? (y/n): ");
    scanf(" %c", &continue_game);

    if (continue_game == 'y' || continue_game == 'Y') {
        main();
    } else {
        printf("Thank you for playing! Goodbye!\n");
    }

    return 0;
}