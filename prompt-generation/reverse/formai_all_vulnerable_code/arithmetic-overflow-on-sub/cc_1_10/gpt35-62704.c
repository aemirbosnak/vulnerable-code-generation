//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termio.h>

#define SENTENCE_LENGTH 50
// The length of the sentence to type.
#define MAX_TIME 60
// Maximum time allotted for typing test in seconds

char* sentences[] = {
// List of sentences for typing test.
    "The quick brown fox jumps over the lazy dog.",
    "A stitch in time saves nine.",
    "All that glitters is not gold.",
    "An apple a day keeps the doctor away.",
    "Beauty is in the eye of the beholder.",
    "Better late than never.",
    "Curiosity killed the cat, but satisfaction brought it back.",
    "Don't count your chickens before they hatch.",
    "Every dog has its day.",
    "Fortune favors the brave."
};

// Function to read a character from the console without waiting for a newline.
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Function to randomize the sentence for typing test.
int rand_sentence() {
    srand(time(NULL));  // Initialize the random seed.
    return rand() % 10;  // Return a random number from 0 to 9.
}

int main() {
    printf("Welcome to the Typing Speed Test.\n");
    printf("You will be given a sentence to type.\n");
    printf("Press 'Enter' to start the test.\n");
    getchar();
    // Wait for the user to press enter to start the test.

    int sentence_index = rand_sentence();
    printf("Type the following sentence:\n\n%s\n\n", sentences[sentence_index]);
    fflush(stdout);
    // Print the randomized sentence for typing test.

    char input[SENTENCE_LENGTH];
    time_t start_time = time(NULL);
    time_t elapsed_time = 0;
    // Variables for counting time elapsed and keeping track of input.

    int i = 0;
    char c = getch();
    while (c != '\n' && elapsed_time < MAX_TIME) {
        time_t current_time = time(NULL);
        elapsed_time = current_time - start_time;
        if (elapsed_time >= MAX_TIME) break;
        if (isalpha(c)) {
            input[i] = c;
            i++;
        }
        c = getch();
    }
    // Read characters from the console and store them in 'input' array.

    double time_taken = (double)elapsed_time;
    int words_typed = 0;
    int mistakes = 0;

    for (int j = 0; j < i; j++) {
        if (input[j] == ' ') {
            words_typed += 1;
        }
        if (input[j] != sentences[sentence_index][j]) {
            mistakes += 1;
        }
    }
    // Count the number of words typed and mistakes made.

    printf("\n\n");
    if (words_typed == 0) {
        printf("Oops! You did not type anything.\n");
    } else {
        double wpm = (words_typed/(time_taken/60));
        double accuracy = ((i - mistakes)/(double)i) * 100;
        printf("You typed %d words in %.2lf seconds.\n", words_typed, time_taken);
        printf("Your typing speed is %.2lf words per minute.\n", wpm);
        printf("You made %d mistakes.\n", mistakes);
        printf("Your typing accuracy is %.2lf%%.\n", accuracy);
    }
    // Print the results of the typing test.

    return 0;
}