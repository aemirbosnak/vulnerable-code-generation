//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_STR_LEN 256
#define NUM_TESTS 5

const char *sentences[NUM_TESTS] = {
    "In a world where silence reigns, echoes of the past still linger.",
    "Rust covered machines lay still in the twilight, forgotten by time.",
    "The horizon burns orange, shadows flicker in the ghost towns.",
    "Survivors roam the barren streets searching for lost hope.",
    "Every keystroke is a reminder of the world that once was."
};

void display_instructions() {
    printf("=== Post-Apocalyptic Typing Speed Test ===\n");
    printf("Type the following sentences as fast as you can.\n");
    printf("Prepare yourself for a journey through the remnants of humanity.\n");
    printf("Press Enter to begin...\n");
}

void start_typing_test(const char *sentence) {
    char user_input[MAX_STR_LEN];
    time_t start_time, end_time;

    printf("\nType this sentence:\n\n");
    printf("\"%s\"\n\n", sentence);

    // Get ready to start
    printf("Ready... Set... Go!\n");
    time(&start_time);

    // Capture user input
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = 0; // Remove the newline

    time(&end_time);
    
    double time_taken = difftime(end_time, start_time);

    // Calculate the words per minute (WPM)
    int words_typed = 0;
    char *token = strtok(user_input, " ");
    while (token != NULL) {
        words_typed++;
        token = strtok(NULL, " ");
    }
    double wpm = (double)words_typed / (time_taken / 60.0);

    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Words typed: %d\n", words_typed);
    printf("Typing speed: %.2f WPM\n", wpm);

    if (strcmp(user_input, sentence) == 0) {
        printf("Congratulations! You typed the sentence correctly.\n");
    } else {
        printf("Incorrect typing. The original sentence was:\n\"%s\"\n", sentence);
    }
}

int main() {
    display_instructions();
    getchar(); // Wait for user to press Enter

    for (int i = 0; i < NUM_TESTS; i++) {
        start_typing_test(sentences[i]);
        printf("\n");

        // Simulate delay between tests
        sleep(2);
    }

    printf("\n=== Test Completed ===\n");
    printf("Remember, typing is a skill that can save you in this desolate world.\n");
    return 0;
}