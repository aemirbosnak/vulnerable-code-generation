//FormAI DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX_EVENTS 100

struct event_t {
    int timestamp;
    char message[50];
};

struct event_t event_log[MAX_EVENTS];
int event_count = 0;

void log_event(char* message) {
    time_t current_time;
    time(&current_time);
    event_log[event_count].timestamp = (int)current_time;
    sprintf(event_log[event_count].message, "%d: %s", event_count, message);
    event_count++;
}

void print_logs() {
    printf("Event Log:\n");
    for(int i=0; i<event_count; i++) {
        printf("[%d] %s\n", event_log[i].timestamp, event_log[i].message);
    }
}

int main() {
    log_event("Program started");

    int num;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);

    if(num < 1 || num > 10) {
        log_event("Invalid number entered");
        printf("Invalid number entered. Exiting program.\n");
        return 1;
    }

    log_event("Number entered successfully");

    int sum = 0;
    for(int i=1; i<=num; i++) {
        sum += i;
    }

    printf("The sum of numbers from 1 to %d is %d\n", num, sum);

    log_event("Program completed successfully");

    print_logs();

    return 0;
}