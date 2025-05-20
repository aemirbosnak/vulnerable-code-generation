//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 1000

struct time_travel {
    int time;
    int destination;
};

void time_travel(int* arr, int n) {
    struct time_travel travels[MAX_TIME_TRAVEL];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            travels[count].time = arr[i];
            travels[count].destination = i;
            count++;
        }
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int index = rand() % count;
        struct time_travel temp = travels[i];
        travels[i] = travels[index];
        travels[index] = temp;
    }

    for (int i = 0; i < count; i++) {
        int index = travels[i].destination;
        arr[index] += travels[i].time;
    }
}

int main() {
    int arr[MAX_TIME_TRAVEL];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    time_travel(arr, n);

    printf("Modified array after time travel:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}