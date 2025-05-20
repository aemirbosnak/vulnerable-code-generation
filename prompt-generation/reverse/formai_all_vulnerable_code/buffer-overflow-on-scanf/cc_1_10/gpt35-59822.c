//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: retro
#include <stdio.h>

#define MAX_SIZE 100

// function to perform the greedy algorithm
void activitySelection(int start[], int finish[], int n) {
    int selected[MAX_SIZE];
    int currIndex = 0;

    selected[currIndex] = 0;

    for(int i = 1; i < n; i++) {
        if(start[i] >= finish[selected[currIndex]]) {
            currIndex++;
            selected[currIndex] = i;
        }
    }

    printf("\nSelected activities: ");

    for(int i = 0; i <= currIndex; i++) {
        printf("%d ", selected[i] + 1);
    }

    printf("\n");
}

int main() {
    int n;
    int start[MAX_SIZE], finish[MAX_SIZE];

    printf("Enter the number of activities: ");
    scanf("%d", &n);
    printf("Enter the start and finish times of the activities:\n");

    for(int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort the activities based on their finish times
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(finish[i] > finish[j]) {
                int temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }

    activitySelection(start, finish, n);

    return 0;
}