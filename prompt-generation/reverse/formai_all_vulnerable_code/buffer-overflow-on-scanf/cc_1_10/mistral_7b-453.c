//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>

#define BUF_SIZE 10

typedef struct {
    time_t timestamp;
    char state[100];
} state_t;

state_t buffer[BUF_SIZE];
int head = 0, tail = 0;

void print_state() {
    struct tm *tm;
    char str[20];

    printf("\nState at %s:", ctime_r(&buffer[head].timestamp, str));
    printf("\n%s\n", buffer[head].state);
}

void update_state() {
    struct tm *tm;
    char str[20];

    time(&buffer[tail].timestamp);
    strftime(buffer[tail].state, sizeof(buffer[tail].state), "%Y-%m-%d %H:%M:%S", localtime(&buffer[tail].timestamp));

    if ((head + 1) % BUF_SIZE == tail) {
        printf("\nBuffer is full! Overwriting oldest state.\n");
        head = (head + 1) % BUF_SIZE;
    }

    head++;
}

int main() {
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");

    while (1) {
        printf("\n1. Travel back in time\n2. Update current state\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (head != 0) {
                    tail = head - 1;
                    if (tail < 0) tail += BUF_SIZE;
                    print_state();
                } else {
                    printf("\nNo previous state to travel to.\n");
                }
                break;
            case 2:
                update_state();
                print_state();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }

        usleep(500000); // Delay for a half second to prevent too many state updates
    }

    return 0;
}