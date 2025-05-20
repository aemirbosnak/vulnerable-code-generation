//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_QUOTES 5
#define MAX_LENGTH 256

const char *quotes[MAX_QUOTES] = {
    "The purpose of our lives is to be happy.",
    "Get busy living or get busy dying.",
    "You have within you right now, everything you need to deal with whatever the world can throw at you.",
    "Life is what happens when you’re busy making other plans.",
    "Love the life you live. Live the life you love."
};

void display_welcome_message() {
    printf("=====================================\n");
    printf("   WELCOME TO THE TYPING SPEED TEST  \n");
    printf("=====================================\n");
    printf("Type the quote displayed on the screen as fast as you can!\n");
    printf("Let's have some fun!\n\n");
}

void select_and_display_quote() {
    srand(time(NULL));
    int random_index = rand() % MAX_QUOTES;
    printf("Here is your quote:\n");
    printf("\"%s\"\n\n", quotes[random_index]);
}

double measure_typing_speed(const char *quote) {
    char user_input[MAX_LENGTH];
    printf("Start typing... (Press Enter to finish)\n");

    clock_t start_time = clock();
    fgets(user_input, MAX_LENGTH, stdin);
    clock_t end_time = clock();

    user_input[strcspn(user_input, "\n")] = 0; // Remove newline character from input

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int character_count = strlen(quote);
    int typed_count = strlen(user_input);

    if (strcmp(quote, user_input) == 0) {
        printf("Bravo! You typed it correctly!\n");
    } else {
        printf("Oops! There were some mistakes.\n");
    }

    double speed_wpm = (typed_count / 5.0) / (time_taken / 60.0); // words per minute (approximation)
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Your typing speed: %.2f WPM\n", speed_wpm);

    return speed_wpm;
}

void display_feedback(double speed) {
    printf("=====================================\n");
    printf("            FEEDBACK                \n");
    printf("=====================================\n");
    if (speed < 20) {
        printf("Keep practicing! Don't give up! 🌱\n");
    } else if (speed < 40) {
        printf("Nice job! You're getting there! 🚀\n");
    } else if (speed < 60) {
        printf("Great speed! Keep it up! 😊\n");
    } else {
        printf("Wow! You're a typing superstar! ⭐️\n");
    }
    printf("=====================================\n");
}

int main() {
    display_welcome_message();
    select_and_display_quote();

    const char *quote = quotes[rand() % MAX_QUOTES]; // Get the quote we'll test with.
    measure_typing_speed(quote);
    
    printf("Thank you for participating!\n");
    printf("Would you like to test again? (y/n): ");

    char response;
    scanf(" %c", &response);
    
    while (response == 'y' || response == 'Y') {
        printf("\nAwesome! Let's go again.\n\n");
        select_and_display_quote();
        measure_typing_speed(quote);
        printf("Would you like to test again? (y/n): ");
        scanf(" %c", &response);
    }
    
    printf("Goodbye! Keep typing and have a wonderful day! 😊\n");
    return 0;
}