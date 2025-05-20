//FormAI DATASET v1.0 Category: Log analysis ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[256];
    int total_calls = 0;
    int success_calls = 0;
    int error_calls = 0;
    int longest_call_duration = 0;
    char longest_call_method[50];
    int shortest_call_duration = 1000000;
    char shortest_call_method[50];

    fp = fopen("calls.log", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    while (fgets(line, 256, fp)) {
        total_calls++;

        char *token = strtok(line, " ");
        token = strtok(NULL, " "); // skip date

        char *method = strtok(NULL, " ");
        if (method[strlen(method)-1] == '\n') {
            method[strlen(method)-1] = '\0';
        }

        token = strtok(NULL, " ");
        int status_code = atoi(token);
        if (status_code >= 200 && status_code < 300) {
            success_calls++;

            token = strtok(NULL, " ");
            if (strlen(token) > 2 && token[strlen(token)-2] == 'm' && token[strlen(token)-1] == 's') {
                char duration_str[strlen(token)-1];
                memcpy(duration_str, token, strlen(token)-2);
                duration_str[strlen(token)-2] = '\0';
                int duration = atoi(duration_str);
                if (duration > longest_call_duration) {
                    longest_call_duration = duration;
                    strcpy(longest_call_method, method);
                }
                if (duration < shortest_call_duration) {
                    shortest_call_duration = duration;
                    strcpy(shortest_call_method, method);
                }
            }

        } else {
            error_calls++;
        }
    }
    fclose(fp);

    printf("Total calls: %d\n", total_calls);
    printf("Successful calls: %d\n", success_calls);
    printf("Error calls: %d\n", error_calls);
    printf("Longest call duration: %dms (%s)\n", longest_call_duration, longest_call_method);
    printf("Shortest call duration: %dms (%s)\n", shortest_call_duration, shortest_call_method);

    return 0;
}