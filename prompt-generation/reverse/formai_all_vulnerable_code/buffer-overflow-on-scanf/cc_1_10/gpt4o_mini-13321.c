//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

volatile sig_atomic_t running = 1;

void handle_signal(int sig) {
    running = 0;
}

void* fetch_signal_strength(void* arg) {
    while (running) {
        // Simulated signal strength value between 0 and 100
        int signal_strength = rand() % 101;
        printf("Current Wi-Fi Signal Strength: %d%%\n", signal_strength);
        sleep(1); // Wait for 1 second before next reading
    }
    return NULL;
}

void display_menu() {
    printf("\n*** Wi-Fi Signal Strength Analyzer ***\n");
    printf("1. Start Analyzing Signal Strength\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

void* user_input(void* arg) {
    int choice;

    while (running) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Signal strength analysis is already running.\n");
                break;
            case 2:
                running = 0; // Set the running flag to stop threads
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        sleep(1); // Sleep to avoid busy waiting
    }

    return NULL;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    signal(SIGINT, handle_signal); // Handle Ctrl+C gracefully

    pthread_t signal_thread, user_thread;

    // Start the signal fetching thread
    if (pthread_create(&signal_thread, NULL, fetch_signal_strength, NULL) != 0) {
        fprintf(stderr, "Error creating signal fetching thread\n");
        return 1;
    }

    // Start the user input thread
    if (pthread_create(&user_thread, NULL, user_input, NULL) != 0) {
        fprintf(stderr, "Error creating user input thread\n");
        return 1;
    }

    // Wait for threads to finish
    pthread_join(signal_thread, NULL);
    pthread_join(user_thread, NULL);

    return 0;
}