//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIMESTAMPS 1000
#define TIMESTAMP_SIZE 20

typedef struct {
    char timestamp[TIMESTAMP_SIZE];
    int year, month, day, hour, minute, second;
} Timestamp;

void print_timestamp(Timestamp* timestamp) {
    printf("%s (%04d-%02d-%02d %02d:%02d:%02d)\n", timestamp->timestamp, timestamp->year, timestamp->month, timestamp->day, timestamp->hour, timestamp->minute, timestamp->second);
}

int main() {
    srand(time(NULL));

    Timestamp* timestamps = malloc(MAX_TIMESTAMPS * sizeof(Timestamp));

    int num_timestamps = 0;
    char input[TIMESTAMP_SIZE];

    while (num_timestamps < MAX_TIMESTAMPS) {
        printf("Enter a timestamp (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);

        if (strlen(input)!= TIMESTAMP_SIZE) {
            printf("Invalid timestamp format.\n");
            continue;
        }

        Timestamp timestamp;
        if (sscanf(input, "%s (%04d-%02d-%02d %02d:%02d:%02d)", timestamp.timestamp, &timestamp.year, &timestamp.month, &timestamp.day, &timestamp.hour, &timestamp.minute, &timestamp.second)!= 7) {
            printf("Invalid timestamp format.\n");
            continue;
        }

        if (timestamp.year < 1900 || timestamp.year > 9999 || timestamp.month < 1 || timestamp.month > 12 || timestamp.day < 1 || timestamp.day > 31 || timestamp.hour < 0 || timestamp.hour > 23 || timestamp.minute < 0 || timestamp.minute > 59 || timestamp.second < 0 || timestamp.second > 59) {
            printf("Invalid timestamp.\n");
            continue;
        }

        timestamps[num_timestamps] = timestamp;
        num_timestamps++;
    }

    printf("Time travel itinerary:\n");

    for (int i = 0; i < num_timestamps; i++) {
        print_timestamp(&timestamps[i]);
    }

    free(timestamps);

    return 0;
}