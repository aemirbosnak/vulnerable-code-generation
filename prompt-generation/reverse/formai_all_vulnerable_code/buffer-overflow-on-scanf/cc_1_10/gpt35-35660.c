//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event, char* type) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if(type == "WARNING") {
        printf("\033[1;33m[WARNING]\033[0m ");
    }
    else if(type == "ERROR") {
        printf("\033[1;31m[ERROR]\033[0m ");
    }
    else {
        printf("\033[1;32m[INFO]\033[0m ");
    }

    printf("[%d-%02d-%02d %02d:%02d:%02d] %s\n", 
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec, event);
}

int main() {
    int choice;
    char event[100];

    while(1) {
        printf("Select the type of event:\n");
        printf("1. WARNING\n");
        printf("2. ERROR\n");
        printf("3. INFO\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 4) {
            break;
        }

        printf("Enter the event: ");
        scanf(" %[^\n]*s", event);

        switch(choice) {
            case 1:
                logEvent(event, "WARNING");
                break;
            case 2:
                logEvent(event, "ERROR");
                break;
            case 3:
                logEvent(event, "INFO");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}