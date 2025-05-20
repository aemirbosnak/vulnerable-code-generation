//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ACTIVITIES 100

typedef struct {
    int start;
    int finish;
} Activity;

typedef struct {
    Activity activities[MAX_ACTIVITIES];
    int activity_count;
} ActivityList;

ActivityList activity_list;
int selected[MAX_ACTIVITIES];

void* select_activities(void* arg) {
    int idx = *(int*)arg;
    int last_finish_time = -1;
    int count = 0;

    for (int i = idx; i < activity_list.activity_count; i += 2) {
        if (activity_list.activities[i].start >= last_finish_time) {
            selected[count++] = i;
            last_finish_time = activity_list.activities[i].finish;
        }
    }
    int* count_ptr = malloc(sizeof(int));
    *count_ptr = count;
    pthread_exit(count_ptr);
}

void print_selected_activities(int count) {
    printf("Selected activities are:\n");
    for (int i = 0; i < count; i++) {
        printf("Activity %d: [%d, %d]\n", selected[i], activity_list.activities[selected[i]].start, activity_list.activities[selected[i]].finish);
    }
}

void sort_activities() {
    for (int i = 0; i < activity_list.activity_count - 1; i++) {
        for (int j = 0; j < activity_list.activity_count - i - 1; j++) {
            if (activity_list.activities[j].finish > activity_list.activities[j + 1].finish) {
                Activity temp = activity_list.activities[j];
                activity_list.activities[j] = activity_list.activities[j + 1];
                activity_list.activities[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Read the number of activities
    printf("Enter number of activities: ");
    scanf("%d", &activity_list.activity_count);
    
    // Read the activities
    printf("Enter start and finish times for each activity:\n");
    for (int i = 0; i < activity_list.activity_count; i++) {
        printf("Activity %d - Start and Finish: ", i + 1);
        scanf("%d %d", &activity_list.activities[i].start, &activity_list.activities[i].finish);
    }

    // Sort activities based on finish time
    sort_activities();

    pthread_t threads[2];
    int indices[2];
    
    // Create two threads to select activities
    for (int i = 0; i < 2; i++) {
        indices[i] = i; // Initialize indexes for threads
        if (pthread_create(&threads[i], NULL, select_activities, (void*)&indices[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    int total_selected = 0;

    // Wait for threads to finish and gather results
    for (int i = 0; i < 2; i++) {
        int* result;
        if (pthread_join(threads[i], (void**)&result)) {
            fprintf(stderr, "Error joining thread\n");
            return 2;
        }
        total_selected += *result;
        free(result);
    }

    print_selected_activities(total_selected);
    
    return 0;
}