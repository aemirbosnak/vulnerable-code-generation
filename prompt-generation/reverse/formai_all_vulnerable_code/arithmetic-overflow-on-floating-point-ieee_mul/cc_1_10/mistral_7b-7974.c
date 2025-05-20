//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#define MAX_DAYS 30
#define STEPS_PER_MINUTE 100
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24

struct day {
    int steps;
    float avg_heart_rate;
};

struct fitness_tracker {
    struct day days[MAX_DAYS];
    int current_day;
};

void init_tracker(struct fitness_tracker *tracker) {
    tracker->current_day = -1;
}

void record_step_count(struct fitness_tracker *tracker, int steps) {
    if (tracker->current_day == -1) {
        tracker->days[0].steps = steps;
        tracker->current_day = 0;
    } else {
        tracker->days[tracker->current_day].steps += steps;
    }
}

void record_heart_rate(struct fitness_tracker *tracker, float heart_rate) {
    if (tracker->current_day == -1) {
        tracker->days[0].avg_heart_rate = heart_rate;
        tracker->current_day = 0;
    } else {
        tracker->days[tracker->current_day].avg_heart_rate =
            (tracker->days[tracker->current_day].avg_heart_rate *
             (float)(HOURS_PER_DAY - 1) + heart_rate) /
            (float)HOURS_PER_DAY;
    }
}

void next_day(struct fitness_tracker *tracker) {
    if (tracker->current_day < MAX_DAYS - 1) {
        tracker->current_day++;
    } else {
        printf("Reached maximum number of days.\n");
    }
}

int main() {
    struct fitness_tracker tracker;
    int steps;
    float heart_rate;

    init_tracker(&tracker);

    for (int i = 0; i < 1440; i += 60) { // Simulate 24 hours of activity
        if (i % 60 == 0) {
            scanf("%d", &steps);
            record_step_count(&tracker, steps);
        }
        if (i % 5 == 0) {
            scanf("%f", &heart_rate);
            record_heart_rate(&tracker, heart_rate);
        }
        if (i % 3600 == 0) {
            next_day(&tracker);
            printf("\nNew day: %d\n", tracker.current_day + 1);
        }
        if (i == 1439) {
            printf("\nTotal steps: %d\n", tracker.days[0].steps);
            printf("Average heart rate: %.2f bpm\n",
                   tracker.days[0].avg_heart_rate);
        }
    }

    return 0;
}