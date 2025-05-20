//FormAI DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1000
#define LOG_FILE_PATH "example.log"

typedef struct {
    char datetime[20];
    char message[100];
} log_t;

int read_log_file(log_t logs[], int max_num_logs);
void print_logs(log_t logs[], int num_logs);
void print_count_by_hour(log_t logs[], int num_logs);
void print_count_by_message(log_t logs[], int num_logs);
void print_count_by_hour_and_message(log_t logs[], int num_logs);

int main() {
    log_t logs[BUFFER_SIZE];
    int num_logs = read_log_file(logs, BUFFER_SIZE);

    if (num_logs < 1) {
        printf("No logs found in '%s'.\n", LOG_FILE_PATH);
        exit(EXIT_FAILURE);
    }

    printf("\nLogs:\n");
    print_logs(logs, num_logs);

    printf("\nCount by Hour:\n");
    print_count_by_hour(logs, num_logs);

    printf("\nCount by Message:\n");
    print_count_by_message(logs, num_logs);

    printf("\nCount by Hour and Message:\n");
    print_count_by_hour_and_message(logs, num_logs);

    return 0;
}

int read_log_file(log_t logs[], int max_num_logs) {
    FILE *file;
    char buffer[100];
    int num_logs = 0;

    file = fopen(LOG_FILE_PATH, "r");
    if (file == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL && num_logs < max_num_logs) {
        sscanf(buffer, "%[^,], %s", logs[num_logs].datetime, logs[num_logs].message);
        num_logs++;
    }

    fclose(file);
    return num_logs;
}

void print_logs(log_t logs[], int num_logs) {
    for (int i = 0; i < num_logs; i++) {
        printf("%s %s\n", logs[i].datetime, logs[i].message);
    }
}

void print_count_by_hour(log_t logs[], int num_logs) {
    int count_by_hour[24] = {0};

    for (int i = 0; i < num_logs; i++) {
        char hour_buffer[3];
        sprintf(hour_buffer, "%c%c", logs[i].datetime[11], logs[i].datetime[12]);
        int hour = atoi(hour_buffer);
        count_by_hour[hour]++;
    }

    for (int i = 0; i < 24; i++) {
        printf("%02d: %d\n", i, count_by_hour[i]);
    }
}

void print_count_by_message(log_t logs[], int num_logs) {
    int count_by_message[num_logs];
    char messages[num_logs][100];
    int num_distinct_messages = 0;

    // Count how many times each message appears
    for (int i = 0; i < num_logs; i++) {
        int exists = 0;
        for (int j = 0; j < num_distinct_messages; j++) {
            if (strcmp(messages[j], logs[i].message) == 0) {
                count_by_message[j]++;
                exists = 1;
                break;
            }
        }
        if (!exists) {
            strcpy(messages[num_distinct_messages], logs[i].message);
            count_by_message[num_distinct_messages] = 1;
            num_distinct_messages++;
        }
    }

    // Print the count of each message
    for (int i = 0; i < num_distinct_messages; i++) {
        printf("%s: %d\n", messages[i], count_by_message[i]);
    }
}

void print_count_by_hour_and_message(log_t logs[], int num_logs) {
    int count_by_hour_and_message[24][100] = {0};

    for (int i = 0; i < num_logs; i++) {
        char hour_buffer[3];
        sprintf(hour_buffer, "%c%c", logs[i].datetime[11], logs[i].datetime[12]);
        int hour = atoi(hour_buffer);
        int j;
        for (j = 0; count_by_hour_and_message[hour][j] != 0; j++) {
            if (strcmp(logs[i].message, logs[count_by_hour_and_message[hour][j]-1].message) == 0) {
                count_by_hour_and_message[hour][j]++;
                break;
            }
        }
        if (count_by_hour_and_message[hour][j] == 0) {
            count_by_hour_and_message[hour][j] = i + 1;
        }
    }

    for (int i = 0; i < 24; i++) {
        for (int j = 0; count_by_hour_and_message[i][j] != 0; j++) {
            printf("%02d %s: %d\n", i, logs[count_by_hour_and_message[i][j]-1].message, count_by_hour_and_message[i][j]);
        }
    }
}