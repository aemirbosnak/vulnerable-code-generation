//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 512
#define BUFFER_SIZE 256

void display_intro() {
    printf("\n");
    printf("======================================\n");
    printf("        C TYPING SPEED TEST          \n");
    printf("======================================\n");
    printf("Welcome, aspiring typist! Test your typing speed and accuracy.\n");
    printf("In this test, you'll be given a random sentence to type as quickly as possible.\n");
    printf("Let's see how fast you can type!\n");
    printf("======================================\n\n");
    sleep(2);
}

void random_sentence(char *buffer) {
    const char *sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Programming is like solving a puzzle.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "In the end, we will remember not the words of our enemies, but the silence of our friends.",
        "Life is what happens when you're busy making other plans.",
        "The only limit to our realization of tomorrow is our doubts of today."
    };

    int random_index = rand() % (sizeof(sentences) / sizeof(sentences[0]));
    strcpy(buffer, sentences[random_index]);
}

void calculate_speed_and_accuracy(char *input, char *original, time_t start_time) {
    int correct_chars = 0;
    int total_chars = strlen(original);
    
    for(int i = 0; i < total_chars; i++) {
        if(input[i] == original[i]) {
            correct_chars++;
        }
    }

    time_t end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);
    double speed = (total_chars / 5.0) / (time_taken / 60.0); // WPM calculation
    double accuracy = (correct_chars / (double)total_chars) * 100;

    printf("\n======================================\n");
    printf("         RESULTS                     \n");
    printf("======================================\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Your speed: %.2f WPM\n", speed);
    printf("Your accuracy: %.2f%%\n", accuracy);
    printf("======================================\n\n");
}

void start_typing_test() {
    char original[MAX_TEXT_LENGTH];
    char user_input[MAX_TEXT_LENGTH];
    time_t start_time;

    random_sentence(original);

    printf("Type the following sentence:\n\n");
    printf("\"%s\"\n\n", original);
    
    printf("Press Enter to start typing...\n");
    getchar();

    start_time = time(NULL);
    fgets(user_input, sizeof(user_input), stdin);
    
    // Remove newline character if present
    user_input[strcspn(user_input, "\n")] = 0; 

    calculate_speed_and_accuracy(user_input, original, start_time);
}

int main() {
    srand(time(NULL));
    display_intro();
    
    start_typing_test();

    printf("Thank you for participating in the typing test!\n");
    printf("Keep practicing and improve your skills.\n");
    
    return 0;
}