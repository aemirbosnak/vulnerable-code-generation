//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TURNS 5
#define MAX_NUM 9

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void surprise(int turns) {
    printf("Get ready for a surprise! You have %d number(s) to remember.\n", turns);
}

void generate_sequence(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_NUM + 1);
    }
}

void play_game() {
    int turns = 1;
    int sequence[MAX_TURNS];
    int player_input[MAX_TURNS];
    
    srand(time(NULL));

    while (turns <= MAX_TURNS) {
        surprise(turns);
        generate_sequence(sequence, turns);

        printf("Memorize this sequence: ");
        print_array(sequence, turns);

        printf("Press Enter to continue...");
        getchar();

        system("clear");  // Clear the screen (similar to cls for Windows)

        printf("Now, enter the sequence: \n");
        for (int i = 0; i < turns; i++) {
            scanf("%d", &player_input[i]);
        }

        if (memcmp(sequence, player_input, turns * sizeof(int)) == 0) {
            printf("Wow! You remembered it correctly!\n\n");
            turns++;
        } else {
            printf("Oh no! You remembered incorrectly. The correct sequence was: ");
            print_array(sequence, turns);
            printf("\nGame Over! Better luck next time.\n");
            break;
        }
    }

    if (turns > MAX_TURNS) {
        printf("Congratulations! You've mastered the game!\n");
    }
}

int main() {
    printf("Welcome to the Memory Game! Are you ready to test your memory?\n");
    printf("You will be shown a sequence of numbers. Memorize them and enter them back!\n");

    play_game();

    return 0;
}