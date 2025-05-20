//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 1000
#define MAX_IP_LENGTH 16
#define MAX_URL_LENGTH 2048
#define MAX_LINE_LENGTH 2048

typedef struct {
    char ip[MAX_IP_LENGTH];
    int count;
} IPAddress;

typedef struct {
    char url[MAX_URL_LENGTH];
    int count;
} URL;

IPAddress ipAddresses[MAX_LOG_LINES];
URL urls[MAX_LOG_LINES];
int ipCount = 0;
int urlCount = 0;

void add_ip(const char* ip) {
    for (int i = 0; i < ipCount; i++) {
        if (strcmp(ipAddresses[i].ip, ip) == 0) {
            ipAddresses[i].count++;
            return;
        }
    }
    strcpy(ipAddresses[ipCount].ip, ip);
    ipAddresses[ipCount].count = 1;
    ipCount++;
}

void add_url(const char* url) {
    for (int i = 0; i < urlCount; i++) {
        if (strcmp(urls[i].url, url) == 0) {
            urls[i].count++;
            return;
        }
    }
    strcpy(urls[urlCount].url, url);
    urls[urlCount].count = 1;
    urlCount++;
}

void analyze_log(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char ip[MAX_IP_LENGTH];
        char url[MAX_URL_LENGTH];
        int status_code;

        if (sscanf(line, "%15s %2047s %d", ip, url, &status_code) == 3) {
            add_ip(ip);
            add_url(url);
            
            if (status_code >= 400) {
                printf("Error encountered from IP: %s at URL: %s with status code: %d\n", ip, url, status_code);
            }
        }
    }

    fclose(file);
}

void print_results() {
    printf("Unique IP addresses:\n");
    for (int i = 0; i < ipCount; i++) {
        printf("IP: %s -> Count: %d\n", ipAddresses[i].ip, ipAddresses[i].count);
    }

    printf("\nMost accessed URL:\n");
    int max_count = 0;
    char most_accessed_url[MAX_URL_LENGTH] = "";
    for (int i = 0; i < urlCount; i++) {
        if (urls[i].count > max_count) {
            max_count = urls[i].count;
            strcpy(most_accessed_url, urls[i].url);
        }
    }
    printf("URL: %s -> Count: %d\n", most_accessed_url, max_count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_log(argv[1]);
    print_results();

    return EXIT_SUCCESS;
}