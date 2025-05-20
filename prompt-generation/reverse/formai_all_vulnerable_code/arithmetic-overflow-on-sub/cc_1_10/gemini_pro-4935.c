//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: random
// Assembling a crew of vigilant uptime monitors, like tireless sentries guarding your website's well-being.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_URLS 100 // A generous limit for our watchful guardians.
#define MAX_HOST_LENGTH 255 // A roomy abode for website addresses.

struct monitor {
    char host[MAX_HOST_LENGTH]; // The website under constant observation.
    int interval; // The frequency of check-ins (in seconds).
    int lastCheck; // Time of the most recent inspection (epoch time).
    int status; // Flag indicating website's availability (0 for down, 1 for up).
};

struct monitor monitors[MAX_URLS]; // An army of monitors, ever vigilant.
int numMonitors = 0; // The size of our watchful posse.

void addMonitor(char* host, int interval) {
    // Enlisting a new monitor into our ranks.
    strcpy(monitors[numMonitors].host, host);
    monitors[numMonitors].interval = interval;
    monitors[numMonitors].lastCheck = 0;
    monitors[numMonitors].status = 0;
    numMonitors++;
}

void checkWebsites() {
    // Dispatching our monitors on their rounds.
    for (int i = 0; i < numMonitors; i++) {
        if (time(NULL) - monitors[i].lastCheck >= monitors[i].interval) {
            // Time for a checkup!
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in serv_addr;

            memset(&serv_addr, 0, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(80);
            serv_addr.sin_addr.s_addr = inet_addr(monitors[i].host);

            if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == 0) {
                // Connection established, website is up and running.
                monitors[i].status = 1;
            } else {
                // Connection failed, website is down.
                monitors[i].status = 0;
            }

            close(sockfd);

            monitors[i].lastCheck = time(NULL);
        }
    }
}

void reportStatus() {
    // Broadcasting the health of our monitored websites.
    for (int i = 0; i < numMonitors; i++) {
        printf("%s: %s\n", monitors[i].host, monitors[i].status ? "Up" : "Down");
    }
}

int main() {
    // Assembling our monitoring team.
    addMonitor("google.com", 60);
    addMonitor("github.com", 120);
    addMonitor("stackoverflow.com", 180);

    // Our endless vigil for website availability begins.
    while (1) {
        checkWebsites(); // Conducting routine checkups.
        reportStatus(); // Announcing the fate of our monitored websites.

        sleep(60); // A brief respite before the next round of inspections.
    }

    return 0;
}