#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void log_event(const char *event) {
    char log_file[] = "log.txt";
    FILE *log_fp = fopen(log_file, "a");
    if (log_fp == NULL) {
        fprintf(stderr, "Error: Cannot open log file.\n");
        return;
    }

    fprintf(log_fp, "%s\n", event);
    fclose(log_fp);
}

int main() {
    time_t now;
    char input[10];
    char *event;

    time(&now);
    printf("Enter a logging event (up to 9 characters): ");
    scanf("%s", input);

    event = (char *) malloc(strlen(input) + 30);
    strcpy(event, "Event logged at ");
    strcat(event, ctime(&now));
    strcat(event, ": ");
    strcat(event, input);
    strcat(event, "\n");

    log_event(event);

    free(event);

    return 0;
}
