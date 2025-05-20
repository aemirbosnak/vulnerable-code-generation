//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>

#define MAX_ACTIVITY 100

typedef struct {
    int start_time;
    int end_time;
} activity;

// sort activities by ascending order of end time
void sort_activities(activity arr[], int n) {
    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < n - i - 1;j++) {
            if(arr[j].end_time > arr[j + 1].end_time) {
                activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_activities(activity arr[], int n) {
    printf("Selected Activities: ");
    int last_end_time = -1;
    for(int i = 0;i < n;i++) {
        if(arr[i].start_time > last_end_time) {
            printf("[%d, %d] ", arr[i].start_time, arr[i].end_time);
            last_end_time = arr[i].end_time;
        }
    }
    printf("\n");
}

int main() {
    int n;
    activity activities[MAX_ACTIVITY];
    
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    printf("Enter the start and end times of each activity:\n");
    for(int i = 0;i < n;i++) {
        scanf("%d %d", &activities[i].start_time, &activities[i].end_time);
    }

    sort_activities(activities, n);

    print_activities(activities, n);

    return 0;
}