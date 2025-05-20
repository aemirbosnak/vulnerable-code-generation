//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_LINE 8192
#define MAX_WORDS 256
#define MAX_DAYS 365

typedef struct {
    char day[11];
    int requests;
    off_t bytes;
} DayStats;

bool is_digit(char c) {
    return isdigit(c);
}

void extract_day(char *line, char *day) {
    int i = 0;
    while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
        day[i++] = line[i];
        day[i] = '\0';
    }
}

DayStats parse_line(char *line) {
    DayStats ds;
    strcpy(ds.day, "");
    extract_day(line, ds.day);
    sscanf(line + strlen(ds.day) + 1, "%d %*s %*s %*s %*s %*s %Ld", &ds.requests, NULL, NULL, NULL, NULL, NULL, &ds.bytes);
    return ds;
}

void process_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    DayStats current_day = {0};
    int num_days = 0;

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)) {
        DayStats ds = parse_line(line);
        if (strcmp(ds.day, current_day.day) != 0) {
            if (num_days > 0) {
                printf("Day %s:\n", current_day.day);
                printf("\tNumber of requests: %d\n", current_day.requests);
                printf("\tTotal bandwidth usage: %lld bytes\n", current_day.bytes);
                printf("\tAverage request size: %.2f bytes\n", (float)current_day.bytes / (float)current_day.requests);
                num_days--;
            }
            strcpy(current_day.day, ds.day);
            current_day.requests = ds.requests;
            current_day.bytes = ds.bytes;
            num_days++;
        } else {
            current_day.requests += ds.requests;
            current_day.bytes += ds.bytes;
        }
    }

    if (num_days > 0) {
        printf("Day %s:\n", current_day.day);
        printf("\tNumber of requests: %d\n", current_day.requests);
        printf("\tTotal bandwidth usage: %lld bytes\n", current_day.bytes);
        printf("\tAverage request size: %.2f bytes\n", (float)current_day.bytes / (float)current_day.requests);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);

    return 0;
}