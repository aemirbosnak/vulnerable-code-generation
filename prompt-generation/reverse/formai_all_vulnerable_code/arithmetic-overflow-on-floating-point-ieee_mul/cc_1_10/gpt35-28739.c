//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Function to handle interrupt signal
void handle_interrupt(int sig)
{
    printf("\nQuality of Service monitor has been interrupted. Exiting...\n");
    exit(0);
}

int main()
{
    // Register interrupt signal handler
    signal(SIGINT, handle_interrupt);

    // Initialize variables
    int ping_runs = 0;
    int ping_success = 0;
    float avg_latency = 0.0;
    float latency_threshold = 100.0;

    // Loop until interrupted by user
    while (1)
    {
        ping_runs++;

        // Send ping to server
        int result = system("ping -c 1 google.com >/dev/null 2>&1");

        // Check if ping was successful
        if (result == 0)
        {
            ping_success++;

            // Get ping latency from output
            FILE *ping_output = popen("ping -c 1 google.com | grep 'time=' | awk -F '=' '{print $2}' | awk '{print $1}'", "r");
            if (ping_output != NULL)
            {
                char latency_str[20];
                fgets(latency_str, 20, ping_output);
                avg_latency = ((avg_latency * (ping_success - 1)) + atof(latency_str)) / (float)ping_success;
                pclose(ping_output);
            }

            // Check if latency is above threshold
            if (avg_latency > latency_threshold)
            {
                printf("\nAverage latency is above threshold: %.2f ms\n", avg_latency);
                printf("Quality of Service is degraded. Taking action...\n");
                // Code to take action here...
                // For example, reduce bandwidth usage or prioritize QoS traffic
            }
        }

        // Sleep for 5 seconds
        sleep(5);
    }

    return 0;
}