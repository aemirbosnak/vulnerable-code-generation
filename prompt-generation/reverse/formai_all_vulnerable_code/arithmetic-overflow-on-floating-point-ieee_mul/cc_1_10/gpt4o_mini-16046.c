//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog."
#define MAX_INPUT_LENGTH 1000

typedef struct {
    time_t start_time;
    int is_done;
    pthread_mutex_t mutex;
} Timer;

void *start_timer(void *arg) {
    Timer *timer = (Timer *)arg;
    pthread_mutex_lock(&timer->mutex);
    timer->start_time = time(NULL);
    pthread_mutex_unlock(&timer->mutex);
    
    while (!timer->is_done) {
        sleep(1);
    }
    
    return NULL;
}

void clear_screen() {
    printf("\033[H\033[J");
}

void print_instructions() {
    printf("Typing Speed Test\n");
    printf("==================\n");
    printf("Type the following text as quickly as you can:\n");
    printf("\"%s\"\n", SAMPLE_TEXT);
    printf("Press Enter when you are ready.\n");
}

int main() {
    Timer timer;
    pthread_t timer_thread;
    char user_input[MAX_INPUT_LENGTH];
    char c;
    
    // Initialize timer
    timer.is_done = 0;
    pthread_mutex_init(&timer.mutex, NULL);
    
    // Clear screen and print instructions
    clear_screen();
    print_instructions();
    getchar(); // Wait for user to press Enter
    
    // Start timer
    pthread_create(&timer_thread, NULL, start_timer, &timer);
    
    // Get user input
    printf("Start typing now...\n");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    // Remove newline character from user input
    user_input[strcspn(user_input, "\n")] = '\0';
    
    // Mark timer as done
    pthread_mutex_lock(&timer.mutex);
    timer.is_done = 1;
    pthread_mutex_unlock(&timer.mutex);

    // Wait for the timer thread to finish
    pthread_join(timer_thread, NULL);
    
    // Calculate elapsed time
    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, timer.start_time);
    int words_typed = (user_input[0] == '\0') ? 0 : (strlen(user_input) / 5);
    double wpm = (words_typed / elapsed_time) * 60;
    
    // Display results
    printf("\nYou typed:\n\"%s\"\n", user_input);
    printf("Your typing speed is: %.2f WPM\n", wpm);
    
    // Free resources
    pthread_mutex_destroy(&timer.mutex);
    
    return 0;
}