//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEETINGS 100

typedef struct meeting {
    int start_time;
    int end_time;
} meeting_t;

int compare_meetings(const void *a, const void *b) {
    const meeting_t *m1 = (const meeting_t *)a;
    const meeting_t *m2 = (const meeting_t *)b;
    if (m1->end_time < m2->end_time)
        return -1;
    else if (m1->end_time > m2->end_time)
        return 1;
    else
        return 0;
}

int schedule_meetings(meeting_t *meetings, int num_meetings) {
    int num_rooms = 1;
    meeting_t *last_meeting = &meetings[0];
    for (int i = 1; i < num_meetings; i++) {
        if (meetings[i].start_time >= last_meeting->end_time) {
            last_meeting = &meetings[i];
        } else {
            num_rooms++;
        }
    }
    return num_rooms;
}

int main() {
    int num_meetings;
    scanf("%d", &num_meetings);
    if (num_meetings > MAX_MEETINGS) {
        fprintf(stderr, "Error: too many meetings\n");
        exit(1);
    }
    meeting_t meetings[MAX_MEETINGS];
    for (int i = 0; i < num_meetings; i++) {
        scanf("%d %d", &meetings[i].start_time, &meetings[i].end_time);
    }
    qsort(meetings, num_meetings, sizeof(meeting_t), compare_meetings);
    int num_rooms = schedule_meetings(meetings, num_meetings);
    printf("%d\n", num_rooms);
    return 0;
}