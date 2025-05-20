//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <pthread.h>

#define NUM_BARS 50
#define SLEEP_TIME 1

// Function to draw RAM usage in the Cyberpunk world style
void draw_progress_bar(float percentage) {
    int completed = (int)(percentage * NUM_BARS);
    int remaining = NUM_BARS - completed;
    
    printf("\r[");
    for (int i = 0; i < completed; i++) {
        printf("█");
    }
    for (int i = 0; i < remaining; i++) {
        printf("░");
    }
    printf("] %.2f%%\n", percentage * 100);
    fflush(stdout);
}

// Function to get the RAM usage
float get_ram_usage() {
    struct sysinfo info;
    sysinfo(&info);
    
    long total_ram = info.totalram;
    long free_ram = info.freeram;
    long used_ram = total_ram - free_ram;
    
    return (float)used_ram / total_ram;
}

// Function to simulate the Cyberpunk environment with a terminal interface
void *cyberpunk_env(void *arg) {
    const char *cyberpunk_anime = "A world of neon lights and cybernetic enhancements...\n";
    const char *cyberpunk_data_stream = "=== Data Stream Initiated ===\n";

    printf("%s", cyberpunk_anime);
    sleep(1);
    printf("%s", cyberpunk_data_stream);
    
    for (int i = 0; i < 3; i++) {
        printf("... Loading...\n");
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread_id;

    // Initialize the Cyberpunk environment
    if (pthread_create(&thread_id, NULL, cyberpunk_env, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }

    sleep(5); // Allow the intro to finish before starting RAM usage monitoring

    printf("\n* Monitoring Memory Usage...\n");

    while (1) {
        float ram_usage = get_ram_usage();
        draw_progress_bar(ram_usage);

        sleep(SLEEP_TIME);
    }

    // Join the thread before exiting (this will never be reached)
    pthread_join(thread_id, NULL);
    return EXIT_SUCCESS;
}