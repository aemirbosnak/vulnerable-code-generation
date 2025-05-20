//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URLS 100
#define MAX_CHECKS 1000

typedef struct {
    char *url;
    int checks;
    int successes;
    double uptime;
} url_t;

url_t urls[MAX_URLS];

int main(int argc, char **argv) {
    int num_urls = 0;
    int num_checks = 0;
    int i, j;

    // Parse command line arguments
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-u")) {
            if (num_urls >= MAX_URLS) {
                fprintf(stderr, "Error: Too many URLs specified\n");
                return 1;
            }
            urls[num_urls].url = argv[i + 1];
            num_urls++;
        } else if (!strcmp(argv[i], "-c")) {
            num_checks = atoi(argv[i + 1]);
            if (num_checks <= 0 || num_checks > MAX_CHECKS) {
                fprintf(stderr, "Error: Invalid number of checks specified\n");
                return 1;
            }
        }
    }

    // Perform uptime checks
    for (i = 0; i < num_urls; i++) {
        for (j = 0; j < num_checks; j++) {
            // Simulate uptime check
            int success = rand() % 2;
            urls[i].checks++;
            if (success) {
                urls[i].successes++;
            }
        }
        urls[i].uptime = (double)urls[i].successes / (double)urls[i].checks;
    }

    // Print uptime statistics
    printf("Uptime Statistics:\n");
    for (i = 0; i < num_urls; i++) {
        printf("%s: %.2f%%\n", urls[i].url, urls[i].uptime * 100);
    }

    return 0;
}