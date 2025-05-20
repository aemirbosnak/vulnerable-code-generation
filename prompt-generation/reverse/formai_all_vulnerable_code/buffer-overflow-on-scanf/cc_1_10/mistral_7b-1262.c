//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define BUF_SIZE 10

typedef struct {
    struct timeval tv;
    char state[100];
} state_t;

state_t states[BUF_SIZE];
int head = 0;
int tail = 0;

void print_state() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("\nCurrent Time: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    printf("State: %s\n", states[head].state);
}

void save_state() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    strcpy(states[head].state, "Saving State...");
    states[head].tv = tv;

    if ((head + 1) % BUF_SIZE == tail) {
        printf("\nBuffer Overflow! Clear Oldest State.\n");
        memset(&states[tail], 0, sizeof(state_t));
    }

    head = (head + 1) % BUF_SIZE;
}

int main() {
    int i;

    printf("Time Travel Simulator v1.0\n");
    printf("Press 's' to save the current state, 't' to travel back in time, or 'q' to quit.\n");

    while (1) {
        char c;
        scanf("%c", &c);

        switch (c) {
            case 's':
                save_state();
                printf("State saved.\n");
                break;

            case 't':
                if (head == tail) {
                    printf("\nNo previous states to travel to.\n");
                    break;
                }

                printf("\nTraveling back to time: %ld.%06ld\n", states[tail].tv.tv_sec, states[tail].tv.tv_usec);
                printf("State: %s\n", states[tail].state);

                tail = (tail + 1) % BUF_SIZE;
                break;

            case 'q':
                printf("\nQuitting the program...\n");
                exit(0);

            default:
                printf("\nInvalid Input.\n");
                break;
        }
    }

    return 0;
}