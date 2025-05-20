//GEMINI-pro DATASET v1.0 Category: Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUSPECTS 10
#define MAX_CLUES 10

// The suspects
char *suspects[MAX_SUSPECTS] = {
    "Charles Augustus Milverton",
    "Irene Adler",
    "James Moriarty",
    "Mycroft Holmes",
    "Sigerson",
    "Colonel Sebastian Moran",
    "Inspector Lestrade",
    "Dr. Watson",
    "Mary Morstan",
    "Wiggins"
};

// The clues
char *clues[MAX_CLUES] = {
    "The dog did not bark in the night-time.",
    "The thief had a limp.",
    "The missing item was a valuable jewel.",
    "The crime occurred during a thunderstorm.",
    "The criminal was a woman.",
    "The criminal was a man of wealth and influence.",
    "The criminal was a foreigner.",
    "The criminal was a member of the criminal underworld.",
    "The criminal was motivated by revenge.",
    "The criminal was caught in the act."
};

// The player's guesses
char *guesses[MAX_SUSPECTS];

// The correct answers
char *answers[MAX_SUSPECTS];

// The number of suspects
int num_suspects = 0;

// The number of clues
int num_clues = 0;

// The number of guesses
int num_guesses = 0;

// The number of correct answers
int num_correct_answers = 0;

// The game loop
void game_loop() {
    // Print the instructions
    printf("Welcome to the Sherlock Holmes Mystery Game!\n");
    printf("Your goal is to identify the criminal who committed a series of crimes.\n");
    printf("You will be given a list of suspects and a list of clues.\n");
    printf("For each clue, you will need to guess which suspect it applies to.\n");
    printf("You will have a limited number of guesses.\n");
    printf("Good luck!\n\n");

    // Get the number of suspects and clues
    printf("How many suspects are there? ");
    scanf("%d", &num_suspects);
    printf("How many clues are there? ");
    scanf("%d", &num_clues);

    // Get the suspects
    for (int i = 0; i < num_suspects; i++) {
        printf("Enter the name of suspect %d: ", i + 1);
        scanf("%s", suspects[i]);
    }

    // Get the clues
    for (int i = 0; i < num_clues; i++) {
        printf("Enter the clue %d: ", i + 1);
        scanf("%s", clues[i]);
    }

    // Get the player's guesses
    for (int i = 0; i < num_clues; i++) {
        printf("Who committed the crime described in clue %d? ", i + 1);
        scanf("%s", guesses[i]);
    }

    // Check the player's guesses
    for (int i = 0; i < num_clues; i++) {
        if (strcmp(guesses[i], answers[i]) == 0) {
            num_correct_answers++;
        }
    }

    // Print the results
    printf("You guessed correctly on %d out of %d clues.\n", num_correct_answers, num_clues);

    if (num_correct_answers == num_clues) {
        printf("Congratulations! You have solved the mystery!\n");
    } else {
        printf("Better luck next time!\n");
    }
}

// The main function
int main() {
    // Set the correct answers
    answers[0] = "James Moriarty";
    answers[1] = "Irene Adler";
    answers[2] = "Charles Augustus Milverton";
    answers[3] = "Mycroft Holmes";
    answers[4] = "Mary Morstan";
    answers[5] = "Colonel Sebastian Moran";
    answers[6] = "Sigerson";
    answers[7] = "Inspector Lestrade";
    answers[8] = "Wiggins";
    answers[9] = "Dr. Watson";

    // Start the game loop
    game_loop();

    return 0;
}