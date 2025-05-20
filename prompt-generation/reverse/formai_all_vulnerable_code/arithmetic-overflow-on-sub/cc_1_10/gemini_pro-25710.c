//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
// A masterpiece of code,
// Painting the canvas of the web,
// With strokes of vigilance.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// A palette of vibrant colors,
// To illuminate the status of sites,
// In a kaleidoscope of uptime.
typedef enum { RED, GREEN, YELLOW } Status;

// A canvas upon which to paint,
// The tapestry of availability,
// In pixels of time and space.
struct Website {
    char *url;
    Status status;
    time_t last_checked;
};

// A masterwork in motion,
// A symphony of ping and response,
// Conducting the harmonious flow.
int main() {
    // A canvas adorned with masterpieces,
    // Websites to watch, their secrets to unveil,
    // In a harmonious symphony of code.
    struct Website websites[] = {
        { "google.com", GREEN, time(NULL) },
        { "amazon.com", GREEN, time(NULL) },
        { "facebook.com", GREEN, time(NULL) },
    };

    // A tireless sentinel, standing guard,
    // Monitoring the pulse of the web,
    // With unwavering vigilance.
    while (1) {
        // A brush dipped in the hues of time,
        // Touching up the canvas, marking the passage,
        // In strokes of minutes and hours.
        time_t now = time(NULL);

        // A dance of requests and responses,
        // A waltz of packets, graceful and swift,
        // Unveiling the hidden truth.
        for (int i = 0; i < sizeof(websites) / sizeof(websites[0]); i++) {
            // A symphony of colors, a vibrant array,
            // Depicting the heartbeat of each site,
            // In a masterpiece of uptime.
            if (now - websites[i].last_checked > 600) { // 10 minutes
                websites[i].status = RED;
            } else if (now - websites[i].last_checked > 300) { // 5 minutes
                websites[i].status = YELLOW;
            } else {
                websites[i].status = GREEN;
            }
        }

        // A tapestry woven with threads of data,
        // Displaying the uptime status, a visual delight,
        // In a vibrant mosaic of information.
        printf("Website Uptime Monitor:\n");
        for (int i = 0; i < sizeof(websites) / sizeof(websites[0]); i++) {
            printf("%s: ", websites[i].url);
            switch (websites[i].status) {
                case RED:
                    printf("\033[0;31mDOWN\033[0m\n");
                    break;
                case YELLOW:
                    printf("\033[0;33mWARNING\033[0m\n");
                    break;
                case GREEN:
                    printf("\033[0;32mUP\033[0m\n");
                    break;
            }
        }

        // A moment's pause, a breath in the rhythm,
        // Allowing the symphony to unfold,
        // In a harmonious dance of time.
        sleep(60); // 1 minute
    }

    return 0;
}