//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

// Function to compare two meetings based on their end time
int compare(const void *a, const void *b) {
    Meeting *meetingA = (Meeting *)a;
    Meeting *meetingB = (Meeting *)b;
    return meetingA->end - meetingB->end;
}

// Function to schedule meetings
void scheduleMeetings(Meeting meetings[], int n) {
    // Step 1: Sort the meetings based on their end time
    qsort(meetings, n, sizeof(Meeting), compare);

    // Step 2: Initialize variables
    int count = 0; // Count of meetings that can be scheduled
    int lastEndTime = -1; // End time of the last scheduled meeting

    printf("Scheduled Meetings:\n");
    for (int i = 0; i < n; i++) {
        // If the start time of the current meeting is greater than or
        // equal to the end time of the last scheduled meeting
        if (meetings[i].start >= lastEndTime) {
            // Schedule the meeting
            lastEndTime = meetings[i].end;
            count++;
            printf("Meeting %d: Start = %d, End = %d\n", count, meetings[i].start, meetings[i].end);
        }
    }

    printf("Total meetings scheduled: %d\n", count);
}

int main() {
    int n;
    printf("Enter the number of meetings: ");
    scanf("%d", &n);

    Meeting *meetings = (Meeting *)malloc(n * sizeof(Meeting));
    if (meetings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input the meeting times
    for (int i = 0; i < n; i++) {
        printf("Enter start and end times for meeting %d: ", i + 1);
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    // Schedule the meetings
    scheduleMeetings(meetings, n);

    // Clean up
    free(meetings);
    return 0;
}