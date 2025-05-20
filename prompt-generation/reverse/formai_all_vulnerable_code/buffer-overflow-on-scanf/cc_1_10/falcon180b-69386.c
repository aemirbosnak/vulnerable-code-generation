//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "romeo_juliet.log"
#define MAX_LINE_LEN 1024

void log_event(const char* event) {
    FILE* log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        printf("Error: Could not open log file.\n");
        return;
    }

    time_t now = time(NULL);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    fprintf(log_file, "%s - %s\n", timestamp, event);
    fclose(log_file);
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Choose an action:\n");
        printf("1. Romeo speaks\n");
        printf("2. Juliet speaks\n");
        printf("3. They kiss\n");
        printf("4. They fight\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                log_event("Romeo speaks");
                printf("Romeo: But, soft! What light through yonder window breaks?\n");
                break;
            case 2:
                log_event("Juliet speaks");
                printf("Juliet: It is the east, and Juliet is the sun.\n");
                break;
            case 3:
                log_event("They kiss");
                printf("They kiss passionately.\n");
                break;
            case 4:
                log_event("They fight");
                printf("They argue about their families.\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}