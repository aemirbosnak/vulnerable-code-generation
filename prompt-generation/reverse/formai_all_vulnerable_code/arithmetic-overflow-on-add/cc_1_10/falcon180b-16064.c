//Falcon-180B DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a random insult
void insult(int level) {
    const char* insults[] = {
        "Thou art a knave!",
        "I scorn thee, varlet!",
        "Thy mother was a hamster!",
        "Thou hast the brain of a donkey!",
        "Thou art a base-court apple-john!",
        "Thou art as tedious as a twice-told tale!",
        "Thou art a saucy, impudent varlet!",
        "Thou art a foul, reeky, ill-favored worm!",
        "Thou art a currish, rude, unmannerly knave!",
        "Thou art a fool-born, cuckoldly rogue!"
    };

    printf("Level %d insult: %s\n", level, insults[random_int(0, 9)]);
}

// Recursive function to play a game of medieval insults
void play_game(int player_level, int computer_level) {
    srand(time(NULL)); // Seed the random number generator with the current time

    int player_score = 0;
    int computer_score = 0;

    while (player_score < 5 && computer_score < 5) {
        insult(computer_level); // Computer insults the player
        if (random_int(0, 1) == 0) { // 50% chance of hitting or missing
            player_score++;
            printf("Thou hast scored a hit on the varlet!\n");
        } else {
            printf("Thou hast missed the varlet.\n");
        }

        insult(player_level); // Player insults the computer
        if (random_int(0, 1) == 0) { // 50% chance of hitting or missing
            computer_score++;
            printf("The varlet hath scored a hit on thee!\n");
        } else {
            printf("The varlet hath missed thee.\n");
        }
    }

    if (player_score == 5) {
        printf("Thou hast won the game of insults, thou noble sir!\n");
    } else {
        printf("The varlet hath bested thee in this game of insults.\n");
    }
}

int main(void) {
    int player_level, computer_level;

    printf("Welcome to the game of medieval insults!\n");
    printf("Please choose thy level of difficulty (1-10): ");
    scanf("%d", &player_level);

    computer_level = player_level + 1; // Computer is one level higher than the player

    play_game(player_level, computer_level);

    return 0;
}