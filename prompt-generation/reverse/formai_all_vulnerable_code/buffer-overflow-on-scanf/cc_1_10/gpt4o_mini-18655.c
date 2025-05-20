//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_FORTUNES 5
#define MAX_FORTUNE_LENGTH 256

char *fortunes[NUM_FORTUNES] = {
    "You will find great success in your career soon.",
    "Love is just around the corner waiting for you.",
    "An unexpected adventure awaits you in the coming days.",
    "A new friendship will bring you joy and happiness.",
    "You will discover an unknown talent that will amaze you."
};

typedef struct {
    int fortune_index;
    int delay;
} FortuneRequest;

void *tell_fortune(void *arg) {
    FortuneRequest *request = (FortuneRequest *)arg;
    sleep(request->delay);  // Simulating asynchronous delay
    printf("Your fortune: %s\n", fortunes[request->fortune_index]);
    free(request);
    pthread_exit(NULL);
}

void request_fortune(int delay) {
    FortuneRequest *request = malloc(sizeof(FortuneRequest));
    if (request == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    request->fortune_index = rand() % NUM_FORTUNES;  // Randomly pick a fortune
    request->delay = delay;

    pthread_t tid;
    if (pthread_create(&tid, NULL, tell_fortune, (void *)request) != 0) {
        fprintf(stderr, "Failed to create thread!\n");
        free(request);
        exit(1);
    }
    pthread_detach(tid); // Detach the thread to avoid needing to join
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;

    printf("Welcome to the Automated Fortune Teller!\n");
    
    while (1) {
        printf("\n1. Request a fortune\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int delay = rand() % 5 + 1; // Random delay between 1 and 5 seconds
            printf("Processing your request... Please wait for %d seconds.\n", delay);
            request_fortune(delay);
        } else if (choice == 2) {
            printf("Thank you for visiting! Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}