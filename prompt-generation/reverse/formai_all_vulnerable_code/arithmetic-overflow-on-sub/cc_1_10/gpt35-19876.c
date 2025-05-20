//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <ctype.h>

// length of random string to generate
#define MAX_STR_LEN 100

// thread function for testing typing speed
void *typing_speed_test(void *arg);

// global variables for thread communication
char str[MAX_STR_LEN];
int correct_chars = 0;

int main() {
    srand(time(NULL)); // seed random number generator
    
    // generate random string to type
    for (int i=0; i<MAX_STR_LEN; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    
    // create thread for typing speed test
    pthread_t tid;
    pthread_create(&tid, NULL, &typing_speed_test, NULL);
    
    // get user input and check for correctness
    printf("Please type the following string:\n%s\n", str);
    char input[MAX_STR_LEN];
    fgets(input, MAX_STR_LEN, stdin);
    for (int i=0; i<MAX_STR_LEN; i++) {
        if (tolower(input[i]) == str[i]) {
            correct_chars++;
        }
    }
    
    // wait for typing speed test thread to finish
    pthread_join(tid, NULL);
    
    // calculate typing speed
    double accuracy = ((double)correct_chars / MAX_STR_LEN) * 100;
    double speed = ((double)correct_chars / 5) / 60; // assuming 5 characters per word
    printf("Typing speed: %.2f words per minute with %.2f%% accuracy\n", speed, accuracy);
    
    return 0;
}

void *typing_speed_test(void *arg) {
    int start = time(NULL); // start the timer
    while (1) {
        // print random string to type every 5 seconds
        printf("\nString to type: %s\n", str);
        sleep(5);
        for (int i=0; i<MAX_STR_LEN; i++) {
            printf("%c ", str[i]);
        }
        printf("\n");
        
        // stop the timer after 60 seconds
        if (time(NULL) - start >= 60) {
            pthread_exit(NULL);
        }
    }
}