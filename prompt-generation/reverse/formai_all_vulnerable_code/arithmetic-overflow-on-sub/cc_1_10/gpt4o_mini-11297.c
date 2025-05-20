//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_BUFFER 256
#define TEST_PHRASE "The quick brown fox jumps over the lazy dog"
#define TIME_LIMIT 15

typedef struct {
    int seconds;
    int running;
} TimerData;

void* timer_thread(void* arg) {
    TimerData* timer_data = (TimerData*) arg;
    while (timer_data->running && timer_data->seconds < TIME_LIMIT) {
        sleep(1);
        timer_data->seconds++;
    }
    timer_data->running = 0; // Stop when time is out
    return NULL;
}

int main() {
    TimerData timer_data = {0, 1};
    pthread_t timer_tid;
    char input[MAX_BUFFER];

    printf("Typing Speed Test\n");
    printf("Type the following phrase as fast as you can:\n");
    printf("\"%s\"\n", TEST_PHRASE);
    printf("You have %d seconds. Press Enter to start!\n", TIME_LIMIT);
    getchar();

    // Start timer thread
    pthread_create(&timer_tid, NULL, timer_thread, (void*)&timer_data);

    // Get user input
    printf("Start typing now:\n");
    clock_t start_time = clock();
    fgets(input, MAX_BUFFER, stdin);
    clock_t end_time = clock();

    // Stop the timer thread
    timer_data.running = 0;
    pthread_join(timer_tid, NULL);

    // Calculate time taken
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int total_chars = strlen(input) - 1; // Ignore newline character
    double speed = (total_chars / elapsed_time) * 60; // characters per minute

    // Check if the user typed correctly
    if (strcmp(input, TEST_PHRASE) == 0) {
        printf("Congratulations! You typed the phrase correctly.\n");
    } else {
        printf("Oops! The phrase you typed is incorrect.\n");
    }

    // Display results
    printf("You typed %d characters in %.2f seconds.\n", total_chars, elapsed_time);
    printf("Your typing speed is %.2f characters per minute.\n", speed);

    // Clean up and exit
    return 0;
}