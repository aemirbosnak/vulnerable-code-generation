//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void display_joke() {
    const char* jokes[] = {
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "I told my computer I needed a break, and now it won't stop sending me Kit Kat ads!",
        "Why don’t scientists trust atoms? Because they make up everything!",
        "I just burned 1200 calories. I forgot the pizza in the oven!",
        "What do you call fake spaghetti? An impasta!"
    };
    
    int joke_count = sizeof(jokes) / sizeof(jokes[0]);
    int index = rand() % joke_count;
    printf("[Joke]: %s\n", jokes[index]);
    printf("Press Enter to continue...\n");
    while (getchar() != '\n') {} // Wait for the user to press enter
}

void typing_speed_test() {
    const char* sentence = "The quick brown fox jumps over the lazy dog.";
    char input[256];
    clock_t start, end;

    printf("Typing Speed Test!\n");
    printf("You will have to type the following sentence as fast as you can:\n");
    printf("\"%s\"\n\n", sentence);
    
    display_joke(); // Show a joke to lighten the mood

    printf("Press Enter to start...\n");
    while (getchar() != '\n') {} // Wait for the user to press enter

    start = clock();
    printf("Go!\n\nType now: ");
    
    // Read user input
    fgets(input, sizeof(input), stdin);
    
    end = clock();

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Calculate typing time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // in seconds
    printf("\nYou typed: \"%s\"\n", input);
    
    if (strcmp(input, sentence) == 0) {
        printf("Congratulations! You typed the sentence correctly!\n");
    } else {
        printf("Oh no! You typed the sentence incorrectly!\n");
    }

    printf("Time taken: %.2f seconds\n", time_taken);
    double speed = (double)strlen(input) / time_taken; // characters per second
    printf("Your typing speed is: %.2f characters per second.\n", speed);
    
    printf("Remember, speed isn't everything! Unless you're running from a bear!\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    typing_speed_test();
    
    printf("\nThanks for participating in the Typing Speed Test! Have a great day!\n");
    return 0;
}