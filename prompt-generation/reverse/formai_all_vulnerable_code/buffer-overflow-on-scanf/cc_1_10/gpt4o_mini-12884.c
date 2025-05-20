//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ACTIVITIES 100

typedef struct {
    int start;
    int finish;
} Activity;

Activity activities[MAX_ACTIVITIES];
int n;

typedef struct {
    int index;
    int result;
} ThreadData;

void *select_activity(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int index = data->index;
    int last_selected = -1;
    
    data->result = 0;
    
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= last_selected) {
            last_selected = activities[i].finish;
            data->result++; // Counting the selected activity
        }
    }
    
    pthread_exit(NULL);
}

void read_activities() {
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    printf("Enter start and finish times of activities (start finish):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }
}

int compare(const void *a, const void *b) {
    return ((Activity *)a)->finish - ((Activity *)b)->finish;
}

void print_selected_activities() {
    ThreadData thread_data;
    pthread_t thread;

    // Create a new thread for selecting activities
    thread_data.index = 0;
    
    // Sort activities by their finish time
    qsort(activities, n, sizeof(Activity), compare);
    
    // Start the thread to select activities
    pthread_create(&thread, NULL, select_activity, &thread_data);
    
    // Wait for the thread to finish
    pthread_join(thread, NULL);

    printf("Number of activities selected: %d\n", thread_data.result);
}

int main() {
    printf("Activity Selection Problem using Greedy Algorithm\n");
    
    read_activities();
    print_selected_activities();

    return 0;
}