//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Activity {
    int start;
    int finish;
    int duration;
};

void activitySelection(struct Activity activities[], int n) {
    int i, j;
    struct Activity schedule[MAX];
    int count = 0;

    for (i = 0; i < n; i++) {
        int maxFinish = activities[i].start;
        int index = -1;

        for (j = 0; j < i; j++) {
            if (activities[j].finish <= maxFinish && activities[j].duration > maxFinish) {
                maxFinish = activities[j].finish;
                index = j;
            }
        }

        if (index!= -1) {
            schedule[count] = activities[index];
            count++;
        }
    }

    printf("The schedule is:\n");
    for (i = 0; i < count; i++) {
        printf("%d - %d: %d\n", schedule[i].start, schedule[i].finish, schedule[i].duration);
    }
}

int main() {
    struct Activity activities[MAX];
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    printf("Enter the start time, finish time and duration of each activity:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &activities[i].start, &activities[i].finish, &activities[i].duration);
    }

    activitySelection(activities, n);

    return 0;
}