//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define MAX_THREADS 5

typedef struct {
    char input[MAX_INPUT_LENGTH];
    struct tm output_date;
} DateConverterTask;

void* parse_date(void* arg) {
    DateConverterTask* task = (DateConverterTask*)arg;

    // Initialize tm structure to zero
    memset(&(task->output_date), 0, sizeof(struct tm));
    char* month_str;
    int day, year;

    // Simple natural language parsing
    if (sscanf(task->input, "%d %m %d", &day, month_str, &year) == 3) {
        // Set the day, year and convert month string to number
        task->output_date.tm_mday = day;

        if (strcmp(month_str, "January") == 0) {
            task->output_date.tm_mon = 0; // January
        } else if (strcmp(month_str, "February") == 0) {
            task->output_date.tm_mon = 1; // February
        } else if (strcmp(month_str, "March") == 0) {
            task->output_date.tm_mon = 2; // March
        } else if (strcmp(month_str, "April") == 0) {
            task->output_date.tm_mon = 3; // April
        } else if (strcmp(month_str, "May") == 0) {
            task->output_date.tm_mon = 4; // May
        } else if (strcmp(month_str, "June") == 0) {
            task->output_date.tm_mon = 5; // June
        } else if (strcmp(month_str, "July") == 0) {
            task->output_date.tm_mon = 6; // July
        } else if (strcmp(month_str, "August") == 0) {
            task->output_date.tm_mon = 7; // August
        } else if (strcmp(month_str, "September") == 0) {
            task->output_date.tm_mon = 8; // September
        } else if (strcmp(month_str, "October") == 0) {
            task->output_date.tm_mon = 9; // October
        } else if (strcmp(month_str, "November") == 0) {
            task->output_date.tm_mon = 10; // November
        } else if (strcmp(month_str, "December") == 0) {
            task->output_date.tm_mon = 11; // December
        } else {
            fprintf(stderr, "Unknown month: %s\n", month_str);
            return NULL;
        }
        
        task->output_date.tm_year = year - 1900; // Years since 1900
    } else {
        fprintf(stderr, "Failed to parse date: %s\n", task->input);
        return NULL;
    }

    return NULL;
}

void print_date(struct tm* date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Parsed Date: %s\n", buffer);
}

int main() {
    pthread_t threads[MAX_THREADS];
    DateConverterTask tasks[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Enter a date (format: day month year, e.g., 15 March 2023): ");
        fgets(tasks[i].input, MAX_INPUT_LENGTH, stdin);
        
        // Remove newline character
        tasks[i].input[strcspn(tasks[i].input, "\n")] = 0;

        if (strlen(tasks[i].input) == 0) break;

        // Create a new thread to parse the date
        if (pthread_create(&threads[i], NULL, parse_date, (void*)&tasks[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        if (strlen(tasks[i].input) == 0) break;
        pthread_join(threads[i], NULL);
        print_date(&(tasks[i].output_date));
    }

    return 0;
}