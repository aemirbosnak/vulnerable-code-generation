//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define MAX_TEXT_LENGTH 512
#define MAX_INPUT_LENGTH 512

char *get_surreal_text() {
    char *texts[] = {
        "The moon danced with the trees as whispers of forgotten dreams fluttered.",
        "A cat in a tuxedo recited Shakespeare, while a fish rode a bicycle.",
        "Clouds spilled colors onto the ground, where time melted like butter.",
        "The clock sang lullabies to the falling stars, wrapped in paper cranes.",
        "Rainbows submerged themselves in coffee cups, inviting squirrels to tea."
    };
    int random_index = rand() % 5; // Randomly selects one surreal text
    return texts[random_index];
}

void display_instructions(char *text) {
    printf("\nType the following text as swiftly as you can:\n");
    printf("\n\"%s\"\n\n", text);
    printf("Press Enter when you're ready, then start typing...\n");
    getchar(); // Wait for the user to press Enter
}

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable echo and canonical mode
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void measure_typing_speed(char *original_text) {
    char user_input[MAX_INPUT_LENGTH];
    time_t start, end;
    double seconds;

    printf("Begin typing now...\n");

    start = time(NULL);
    
    int idx = 0;
    while (idx < strlen(original_text)) {
        char ch = getch(); // Get a character from user
        if (ch == original_text[idx]) {
            user_input[idx++] = ch; // Correct character
            putchar(ch); // Echo the character
        } else {
            printf("\033[31m%c\033[0m", ch); // Incorrect character in red
            // Provide feedback for the incorrect input
        }
    }
    user_input[idx] = '\0'; // Null-terminate the string

    end = time(NULL);
    seconds = difftime(end, start);

    if (strcmp(original_text, user_input) == 0) {
        printf("\n\nWell done, brave typist! Your fingers have danced gracefully!\n");
    } else {
        printf("\n\nAh, but the whispers of errors take flight like butterflies.\n");
    }

    int words = (idx / 5) + 1; // Approximate word count
    double wpm = (words / seconds) * 60; // Words per minute

    printf("Time taken: %.2f seconds\n", seconds);
    printf("Your typing speed: %.2f WPM\n", wpm);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Surreal Typing Speed Test!\n");
    printf("Prepare to liberate your essence into the ether of words...\n");
    
    char *surreal_text = get_surreal_text();
    display_instructions(surreal_text);
    
    measure_typing_speed(surreal_text);

    printf("\nThe journey of your fingers has come to an end. Thank you!\n");
    return 0;
}