//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <string.h>

typedef struct logRecord {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char message[100];
} logRecord;

char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void printLogRecord(logRecord record) {
    printf("[%.2d:%.2d:%.2d %.3s %.2d %.4d] %s\n", record.hour, record.minute, record.second, months[record.month - 1], record.day, record.year, record.message);
}

int main() {
    logRecord logs[10];
    int numLogs = 0;
    char option;
    do {
        printf("Choose an option:\n");
        printf("1. Add log record\n");
        printf("2. View log records\n");
        printf("3. Quit\n");
        scanf(" %c", &option);
        switch (option) {
            case '1': {
                logRecord record;
                printf("Enter the year: ");
                scanf("%d", &record.year);
                printf("Enter the month: ");
                scanf("%d", &record.month);
                printf("Enter the day: ");
                scanf("%d", &record.day);
                printf("Enter the hour: ");
                scanf("%d", &record.hour);
                printf("Enter the minute: ");
                scanf("%d", &record.minute);
                printf("Enter the second: ");
                scanf("%d", &record.second);
                printf("Enter the log message: ");
                fgets(record.message, sizeof(record.message), stdin);
                numLogs += 1;
                logs[numLogs - 1] = record;                    
                break;
            }
            case '2': {
                for (int i = 0; i < numLogs; i++) {
                    printLogRecord(logs[i]);
                }
                break;
            }
            case '3': {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid option. Please try again.\n");
                break;
            }
        }
    } while (option != '3');
    return 0;
}