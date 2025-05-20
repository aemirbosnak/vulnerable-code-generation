//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 80
#define ALERT_THRESHOLD 3
#define TIME_INTERVAL 5

int line_count = 0;
int alert_count = 0;
time_t last_alert_time = 0;

void analyze_line(char* line) {
    int i;
    for(i=0; i<strlen(line); i++) {
        if(isupper(line[i])) {
            alert_count++;
        }
    }
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    FILE* input_file;
    time_t current_time;

    input_file = fopen("input.txt", "r");
    if(input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while(fgets(input_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_count++;
        analyze_line(input_buffer);

        if(alert_count >= ALERT_THRESHOLD) {
            current_time = time(NULL);
            if(current_time - last_alert_time >= TIME_INTERVAL) {
                printf("Alert: Suspicious activity detected at line %d.\n", line_count);
                last_alert_time = current_time;
            }
        }
    }

    fclose(input_file);
    return 0;
}