//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 100
#define NUM_THREADS 5

void *date_converter(void *input_str);
void trim_whitespace(char *str);
void print_usage();

int main() {
    char input[MAX_INPUT];
    pthread_t threads[NUM_THREADS];
    int thread_index = 0;

    while (1) {
        printf("Enter a natural language date (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        trim_whitespace(input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (thread_index >= NUM_THREADS) {
            printf("Maximum number of threads reached. Please wait...\n");
            for (int i = 0; i < NUM_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_index = 0; // reset thread index
        }

        // Create a new thread for date conversion
        pthread_create(&threads[thread_index++], NULL, date_converter, (void *)strdup(input));
    }

    // Join all remaining threads
    for (int i = 0; i < thread_index; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *date_converter(void *input_str) {
    char *str = (char *)input_str;
    struct tm tm;
    time_t t;

    // Simple parsing logic for demonstration purposes:
    // In a real-world application, you would use a more robust parsing library or logic
    printf("Converting: %s\n", str);
    
    if (strstr(str, "next") != NULL) {
        strtok(str, " ");
        strtok(NULL, " ");
        char *day_of_week = strtok(NULL, " "); // Extract day of the week
        if (day_of_week) {
            time(&t);
            localtime_r(&t, &tm);
            // Adjust the tm struct to find the next occurrence of the day of week
            int current_day = tm.tm_wday;
            int target_day = -1;

            if (strcmp(day_of_week, "Monday") == 0) target_day = 1;
            if (strcmp(day_of_week, "Tuesday") == 0) target_day = 2;
            if (strcmp(day_of_week, "Wednesday") == 0) target_day = 3;
            if (strcmp(day_of_week, "Thursday") == 0) target_day = 4;
            if (strcmp(day_of_week, "Friday") == 0) target_day = 5;
            if (strcmp(day_of_week, "Saturday") == 0) target_day = 6;
            if (strcmp(day_of_week, "Sunday") == 0) target_day = 0;

            // If target_day is found, calculate the difference
            if (target_day != -1) {
                int days_until_target = (target_day - current_day + 7) % 7 + 7; // next occurrence
                tm.tm_mday += days_until_target; // move to the next week
                mktime(&tm);
                printf("Converted date is: %s", asctime(&tm));
            }
        }
    } else if (strstr(str, "January") || strstr(str, "February") 
               || strstr(str, "March") || strstr(str, "April") 
               || strstr(str, "May") || strstr(str, "June") 
               || strstr(str, "July") || strstr(str, "August") 
               || strstr(str, "September") || strstr(str, "October") 
               || strstr(str, "November") || strstr(str, "December")) {
        // Assuming input like "January 1, 2021"
        sscanf(str, "%s %d, %d", str, &tm.tm_mday, &tm.tm_year);
        tm.tm_year -= 1900; // Adjust year
        tm.tm_mon = -1; 
        if (strcmp(str, "January") == 0) tm.tm_mon = 0;
        else if (strcmp(str, "February") == 0) tm.tm_mon = 1;
        else if (strcmp(str, "March") == 0) tm.tm_mon = 2;
        else if (strcmp(str, "April") == 0) tm.tm_mon = 3;
        else if (strcmp(str, "May") == 0) tm.tm_mon = 4;
        else if (strcmp(str, "June") == 0) tm.tm_mon = 5;
        else if (strcmp(str, "July") == 0) tm.tm_mon = 6;
        else if (strcmp(str, "August") == 0) tm.tm_mon = 7;
        else if (strcmp(str, "September") == 0) tm.tm_mon = 8;
        else if (strcmp(str, "October") == 0) tm.tm_mon = 9;
        else if (strcmp(str, "November") == 0) tm.tm_mon = 10;
        else if (strcmp(str, "December") == 0) tm.tm_mon = 11;

        mktime(&tm);
        printf("Converted date is: %s", asctime(&tm));
    } else {
        printf("Invalid date format.\n");
    }

    free(input_str); // Free duplicated string
    pthread_exit(NULL);
}

// Helper function to trim whitespace
void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0'; // Null terminate
}

void print_usage() {
    printf("Usage: Enter a natural date format like 'next Monday' or 'January 1, 2021'.\n");
}