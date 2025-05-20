//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 100
#define TEST_COUNT 5
#define DISPLAY_TIME 5

void display_instructions();
void generate_random_sentence(char* sentence, int length);
double calculate_typing_speed(double time_taken, int total_chars);
void run_typing_test();
void start_timer();
void stop_timer(double* time_taken);
void print_result(int chars_typed, double time_taken, double speed);

int main() {
    int choice;
    do {
        display_instructions();
        printf("\nEnter your choice (1 to start test, 0 to exit): ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after the integer input.
        
        if (choice == 1) {
            run_typing_test();
        }
    } while (choice != 0);
    
    printf("Thank you for using the typing speed test!\n");
    return 0;
}

void display_instructions() {
    printf("\n=== Typing Speed Test ===\n");
    printf("1. You will be presented with a random sentence.\n");
    printf("2. Type the sentence as quickly and accurately as possible.\n");
    printf("3. Your typing speed and accuracy will be displayed at the end.\n");
    printf("=========================\n");
}

void generate_random_sentence(char* sentence, int length) {
    const char* words[] = {
        "the", "quick", "brown", "fox", "jumps", "over", "lazy", "dog",
        "hello", "world", "this", "is", "a", "typing", "speed", "test",
        "programming", "languages", "are", "fun", "to", "learn", "and",
        "master", "keep", "practicing", "to", "improve", "skills"
    };
    int total_words = sizeof(words) / sizeof(words[0]);
    sentence[0] = '\0';

    for (int i = 0; i < length; i++) {
        strcat(sentence, words[rand() % total_words]);
        if (i < length - 1) {
            strcat(sentence, " ");
        }
    }
}

double calculate_typing_speed(double time_taken, int total_chars) {
    return (total_chars / time_taken) * 60; // speed in characters per minute
}

void run_typing_test() {
    char sentence[MAX_LENGTH];
    char user_input[MAX_LENGTH];
    double start_time, end_time;
    
    srand(time(NULL));
    generate_random_sentence(sentence, TEST_COUNT);
    
    printf("\nYour sentence to type is:\n");
    printf("\"%s\"\n", sentence);
    
    printf("You have %d seconds to type the sentence. Press [Enter] to start...\n", DISPLAY_TIME);
    getchar(); // wait for user to press Enter

    start_timer();
    
    printf("Start typing now:\n");
    
    // Start capturing user input
    fgets(user_input, MAX_LENGTH, stdin);
    
    stop_timer(&end_time);

    // Clean up the user input to avoid comparing against newline
    user_input[strcspn(user_input, "\n")] = 0;

    // Calculate results
    double time_taken = end_time - start_time;
    int chars_typed = strlen(user_input);
    double speed = calculate_typing_speed(time_taken, chars_typed);

    print_result(chars_typed, time_taken, speed);
}

void start_timer() {
    // This function uses a simple sleep to simulate a countdown timer.
    for (int i = DISPLAY_TIME; i > 0; i--) {
        printf("%d...\n", i);
        fflush(stdout);
        sleep(1);
    }
}

void stop_timer(double* time_taken) {
    clock_t end = clock();
    *time_taken = ((double)(end - clock())) / CLOCKS_PER_SEC;
}

void print_result(int chars_typed, double time_taken, double speed) {
    printf("\n=== Typing Test Results ===\n");
    printf("Characters Typed: %d\n", chars_typed);
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Typing Speed: %.2f characters per minute\n", speed);
    
    // Calculate accuracy
    int sentence_length = strlen(chars_typed);
    double accuracy = ((double)chars_typed / sentence_length) * 100;
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("==========================\n");
}