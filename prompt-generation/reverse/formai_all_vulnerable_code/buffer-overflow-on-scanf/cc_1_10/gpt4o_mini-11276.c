//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

volatile sig_atomic_t keep_running = 1;

// Signal handler to gracefully exit the program
void handle_sigint(int sig) {
    keep_running = 0;
}

// Function to calculate the average of an array
double average(double *array, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum / n;
}

// Function to ping the target IP address
void ping(const char *ip_address) {
    char command[256];
    sprintf(command, "ping -c 5 -n %s", ip_address);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run ping command");
        return;
    }

    char line[256];
    double ms[5];
    int i = 0;
    int loss = 0;
    while (fgets(line, sizeof(line) - 1, fp) != NULL) {
        // Find latency in the output
        if (strstr(line, "time=")) {
            char *pos = strstr(line, "time=");
            sscanf(pos, "time=%lf", &ms[i]);
            i++;
        } else if (strstr(line, "packet loss")) {
            sscanf(line, "%*d %% packet loss", &loss);
        }
    }

    pclose(fp);

    if (i > 0) {
        double avg = average(ms, i);
        printf("Average Latency: %.2f ms | Packet Loss: %d%%\n", avg, loss);
    } else {
        printf("Ping failed or no responses received.\n");
    }
}

int main() {
    char ip_address[100];
    int interval;

    printf("Enter the IP address to monitor (e.g., google.com): ");
    scanf("%s", ip_address);
    printf("Enter ping interval in seconds: ");
    scanf("%d", &interval);

    // Register signal handler
    signal(SIGINT, handle_sigint);

    printf("Monitoring QoS to %s every %d seconds. Press Ctrl+C to stop.\n", ip_address, interval);

    while (keep_running) {
        ping(ip_address);
        sleep(interval);
    }

    printf("Monitoring stopped.\n");
    return 0;
}