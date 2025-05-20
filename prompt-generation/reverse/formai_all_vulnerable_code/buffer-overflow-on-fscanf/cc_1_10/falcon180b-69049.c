//Falcon-180B DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_EVENT_SIZE 100
#define MAX_EVENT_NUM 1000
#define EVENT_FILE_PATH "event.log"

//Function to get current time in string format
char* get_current_time() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", t);
    return strdup(time_str);
}

//Function to log event in file
void log_event(char* event) {
    FILE* file = fopen(EVENT_FILE_PATH, "a");
    if(file!= NULL) {
        fprintf(file, "%s - %s\n", get_current_time(), event);
        fclose(file);
    }
}

//Function to display statistics
void display_statistics() {
    FILE* file = fopen(EVENT_FILE_PATH, "r");
    if(file!= NULL) {
        char event[MAX_EVENT_SIZE];
        int count = 0;
        while(fscanf(file, "%s", event)!= EOF) {
            if(strlen(event) > 0) {
                count++;
            }
        }
        printf("Total events logged: %d\n", count);
        fclose(file);
    }
}

int main() {
    char event[MAX_EVENT_SIZE];
    int choice, count = 0;

    do {
        printf("\n1. Log event\n2. Display statistics\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter event: ");
                scanf("%s", event);
                log_event(event);
                break;

            case 2:
                display_statistics();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
        count++;
    } while(count < 10);

    return 0;
}