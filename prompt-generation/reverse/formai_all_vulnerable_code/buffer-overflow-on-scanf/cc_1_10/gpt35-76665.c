//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_URL_LENGTH 100
#define MAX_LOG_LENGTH 1000
#define INTERVAL 10 // time interval in seconds between server checks
#define MAX_SERVERS 10 // maximum number of servers to monitor
#define MAX_ERRORS_ALLOWED 5 // maximum number of errors allowed before marking server as down

struct server {
    char url[MAX_URL_LENGTH];
    int errors;
    bool is_up;
};

void check_server(struct server* s) {
    // simulate server response time
    double response_time = (double)rand() / RAND_MAX * 2.0 + 1.0;
    bool is_success = (rand() % 10) < 8; // simulate 80% success rate

    if (is_success) {
        s->errors = 0;
        s->is_up = true;
        printf("[%s] OK - response time %.2f seconds\n", s->url, response_time);
    } else {
        s->errors++;
        printf("[%s] ERROR - failed to connect\n", s->url);
    }
}

void log_output(char* log) {
    // append to file
    FILE* fp = fopen("uptime.log", "a");
    if (fp == NULL) return;

    fprintf(fp, "%s\n", log);
    fclose(fp);
}

int main() {
    srand(time(0)); // seed random number generator

    struct server servers[MAX_SERVERS];
    int num_servers = 0;

    char command[10];
    while (true) {
        printf("Enter command (add/check/quit):\n");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (num_servers >= MAX_SERVERS) {
                printf("Max servers reached.\n");
                continue;
            }

            printf("Enter server URL:\n");
            scanf("%s", servers[num_servers].url);

            servers[num_servers].errors = 0;
            servers[num_servers].is_up = true;
            num_servers++;

            printf("Server added.\n");
        } else if (strcmp(command, "check") == 0) {
            if (num_servers == 0) {
                printf("No servers added.\n");
                continue;
            }

            char log[MAX_LOG_LENGTH];
            sprintf(log, "[%s] ", __TIME__); // prefix log with current time

            for (int i = 0; i < num_servers; i++) {
                check_server(&servers[i]);

                if (!servers[i].is_up) {
                    sprintf(log, "%sServer %s is down. ", log, servers[i].url);
                }

                if (servers[i].errors >= MAX_ERRORS_ALLOWED) {
                    servers[i].is_up = false;
                    sprintf(log, "%sServer %s marked as down due to too many errors. ", log, servers[i].url);
                }
            }

            log_output(log);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }

        sleep(INTERVAL);
    }

    return 0;
}