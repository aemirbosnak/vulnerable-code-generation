//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_URL_LENGTH 100

void print_header(char* url) {
    printf("\n------------------------\n");
    printf("Monitoring %s...\n", url);
    printf("------------------------\n\n");
}

int check_url(char* url) {
    int status = system(NULL);
    if (status == 0) {
        char ping_command[100];
        sprintf(ping_command, "ping -c 1 %s", url);
        if (system(ping_command) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char url[MAX_URL_LENGTH];
    int frequency;
    int status;
    time_t t = time(NULL);
    struct tm* time_info;
    char time_string[9];

    printf("Enter the URL to monitor: ");
    scanf("%s", url);
    printf("Enter the frequency (in seconds) to monitor the URL: ");
    scanf("%d", &frequency);

    print_header(url);

    while (1) {
        status = check_url(url);
        if (status == 1) {
            printf("%s: URL is up\n", time_string);
        } else {
            printf("%s: URL is down\n", time_string);
        }
        sleep(frequency);

        t = time(NULL);
        time_info = localtime(&t);
        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    }

    return 0;
}