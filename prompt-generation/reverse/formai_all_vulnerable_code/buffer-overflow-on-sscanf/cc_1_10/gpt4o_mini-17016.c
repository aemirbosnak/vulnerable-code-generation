//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

void get_current_date(char* buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void parse_date(const char* input, int* day, int* month, int* year) {
    // Set defaults (current date) if parsing fails
    *day = -1; 
    *month = -1; 
    *year = -1;

    char buffer[MAX_INPUT] = {0};
    strcpy(buffer, input);

    char* token = strtok(buffer, " ");
    while (token != NULL) {
        if (strcmp(token, "today") == 0) {
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            *day = tm.tm_mday;
            *month = tm.tm_mon + 1;
            *year = tm.tm_year + 1900;
            return;
        }
        if (strcmp(token, "tomorrow") == 0) {
            time_t t = time(NULL) + 86400; // add one day
            struct tm tm = *localtime(&t);
            *day = tm.tm_mday;
            *month = tm.tm_mon + 1;
            *year = tm.tm_year + 1900;
            return;
        }
        if (strcmp(token, "yesterday") == 0) {
            time_t t = time(NULL) - 86400; // subtract one day
            struct tm tm = *localtime(&t);
            *day = tm.tm_mday;
            *month = tm.tm_mon + 1;
            *year = tm.tm_year + 1900;
            return;
        }

        if (sscanf(token, "%d/%d/%d", day, month, year) == 3) {
            return;
        }
        if (sscanf(token, "%d-%d-%d", day, month, year) == 3) {
            return;
        }

        token = strtok(NULL, " ");
    }
}

void print_date(int day, int month, int year) {
    if (day == -1 || month == -1 || year == -1) {
        printf("DCT: I couldn't grasp your request. Please try again!\n");
    } else {
        printf("DCT: You requested the date: %02d/%02d/%04d!\n", day, month, year);
    }
}

int main() {
    char input[MAX_INPUT];

    printf("Welcome to the Dispatched Chrono-Transmuter (DCT)! 🌌\n");
    printf("Please speak your date in natural language. You can say 'today', 'tomorrow', or 'yesterday'.\n");
    printf("You may also provide a date in formats like '15/03/2023' or '2023-03-15'.\n");
    printf("Type 'exit' to terminate. Let's begin! ✨\n");

    while (1) {
        printf("You: ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from the input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("DCT: Until we meet again among the stars! 🚀\n");
            break;
        }

        int day, month, year;
        parse_date(input, &day, &month, &year);
        print_date(day, month, year);
    }

    return 0;
}