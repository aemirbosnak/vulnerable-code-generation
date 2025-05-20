//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_COLORS 6
#define MAX_LENGTH 100

// Color definitions
const char *colors[MAX_COLORS] = {"Red", "Green", "Blue", "Yellow", "Magenta", "Cyan"};

// Function prototypes
void generate_sequence(int *sequence, int length);
void display_sequence(int *sequence, int length);
int get_user_input(int *user_sequence, int length);
void play_game();

int main() {
    printf("Welcome to the Memory Game!\n");
    play_game();
    return 0;
}

// Function to generate a random sequence of colors
void generate_sequence(int *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % MAX_COLORS;
    }
}

// Function to display the sequence to the player
void display_sequence(int *sequence, int length) {
    printf("Remember this sequence:\n");
    for (int i = 0; i < length; i++) {
        printf("%s ", colors[sequence[i]]);
        fflush(stdout);
        usleep(1000000); // Display each color for 1 second
    }
    printf("\n");
    sleep(2); // Give player some time before hiding the sequence
    printf("\033[2J\033[H"); // Clear screen (ANSI escape codes)
}

// Function to get user input for the sequence
int get_user_input(int *user_sequence, int length) {
    printf("Enter the sequence (0 for Red, 1 for Green, 2 for Blue, 3 for Yellow, 4 for Magenta, 5 for Cyan):\n");
    for (int i = 0; i < length; i++) {
        printf("Color %d: ", i + 1);
        if (scanf("%d", &user_sequence[i]) != 1 || user_sequence[i] < 0 || user_sequence[i] >= MAX_COLORS) {
            printf("Invalid input! Please enter numbers between 0 and %d.\n", MAX_COLORS - 1);
            // Clear the input buffer
            while (getchar() != '\n');
            return 0;
        }
    }
    return 1;
}

// Function to play the game
void play_game() {
    srand(time(0)); // Seed for random number generation
    int length = 1;
    
    while (1) {
        int sequence[MAX_LENGTH];
        int user_sequence[MAX_LENGTH];

        generate_sequence(sequence, length);
        display_sequence(sequence, length);
        
        if (!get_user_input(user_sequence, length)) {
            printf("Exiting the game due to invalid input.\n");
            break;
        }

        // Compare user input with generated sequence
        if (memcmp(sequence, user_sequence, length * sizeof(int)) == 0) {
            printf("Correct! Get ready for the next round.\n");
            length++; // Increase the length for the next round
            sleep(2);
        } else {
            printf("Wrong sequence! The correct sequence was:\n");
            for (int i = 0; i < length; i++) {
                printf("%s ", colors[sequence[i]]);
            }
            printf("\nGame Over!\n");
            break;
        }
    }
}