//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20
#define BUFFER_SIZE 256

void generate_random_sentence(char *sentence, int word_count) {
    const char *words[MAX_WORDS] = {
        "Linux", "Torvalds", "Git", "Kernel", "Development",
        "Programming", "C", "OpenSource", "Community", "Code",
        "System", "Architecture", "Performance", "Software", 
        "Hardware", "Repository", "Version", "Control", "Function",
        "Debug", "Compile", "Run", "Build", "Deploy"
    };

    for (int i = 0; i < word_count; i++) {
        strcat(sentence, words[rand() % 24]);
        if (i < word_count - 1) {
            strcat(sentence, " ");
        }
    }
}

void validate_input(const char *input, const char *reference) {
    if (strcmp(input, reference) == 0) {
        printf("Correct! Well done.\n");
    } else {
        printf("Incorrect! Your input did not match the reference.\n");
    }
}

double calculate_typing_speed(double time_taken, int word_count) {
    return (word_count / time_taken) * 60; // speed in words per minute
}

void typing_test() {
    char sentence[BUFFER_SIZE] = {0};
    char user_input[BUFFER_SIZE] = {0};
    int word_count = rand() % 8 + 3; // Between 3 and 10 words

    generate_random_sentence(sentence, word_count);
    printf("Type the following sentence:\n%s\n\n", sentence);
    printf("Start typing...\n");

    clock_t start_time = clock();
    fgets(user_input, BUFFER_SIZE, stdin);
    clock_t end_time = clock();

    // Remove trailing newline
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    validate_input(user_input, sentence);

    double speed = calculate_typing_speed(time_taken, word_count);
    printf("You took %.2f seconds.\n", time_taken);
    printf("Your typing speed is %.2f words per minute.\n", speed);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Press Enter to start the test...\n");
    getchar();
    
    for (int i = 0; i < 3; i++) {
        typing_test();
        printf("\nTest %d completed.\n\n", i + 1);
        printf("Press Enter to try again...\n");
        getchar();
    }

    printf("Thank you for participating in the typing test!\n");
    return 0;
}