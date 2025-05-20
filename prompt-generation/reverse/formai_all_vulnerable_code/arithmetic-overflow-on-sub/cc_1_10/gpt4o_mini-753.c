//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>

#define LOG_FILE "ids_log.txt"
#define MAX_IPS 100
#define THRESHOLD 5
#define MONITOR_INTERVAL 10

typedef struct {
    char ip_address[16];
    int access_count;
    time_t last_access_time;
} IPRecord;

IPRecord ip_records[MAX_IPS];
int record_count = 0;
pthread_mutex_t ip_mutex;

void log_event(const char *event) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file) {
        fprintf(log_file, "%s: %s\n", ctime(&(time_t){time(NULL)}), event);
        fclose(log_file);
    }
}

void add_access(const char *ip) {
    pthread_mutex_lock(&ip_mutex);
    for (int i = 0; i < record_count; i++) {
        if (strcmp(ip_records[i].ip_address, ip) == 0) {
            ip_records[i].access_count++;
            ip_records[i].last_access_time = time(NULL);
            if (ip_records[i].access_count > THRESHOLD) {
                log_event("Possible intrusion detected.");
            }
            pthread_mutex_unlock(&ip_mutex);
            return;
        }
    }
    
    // New IP address
    if (record_count < MAX_IPS) {
        strcpy(ip_records[record_count].ip_address, ip);
        ip_records[record_count].access_count = 1;
        ip_records[record_count].last_access_time = time(NULL);
        record_count++;
    } else {
        log_event("Max IP records reached!");
    }
    pthread_mutex_unlock(&ip_mutex);
}

void *monitor_activity(void *arg) {
    while (1) {
        sleep(MONITOR_INTERVAL);
        time_t current_time = time(NULL);
        pthread_mutex_lock(&ip_mutex);
        
        for (int i = 0; i < record_count; i++) {
            if (current_time - ip_records[i].last_access_time > MONITOR_INTERVAL) {
                log_event("IP address inactive, removing record.");
                // Shift left to remove this IP
                for (int j = i; j < record_count - 1; j++) {
                    ip_records[j] = ip_records[j + 1];
                }
                record_count--;
                i--; // Adjust index to account for shift
            }
        }
        
        pthread_mutex_unlock(&ip_mutex);
    }
    return NULL;
}

void simulate_access(const char *ip) {
    add_access(ip);
}

int main() {
    pthread_mutex_init(&ip_mutex, NULL);
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitor_activity, NULL);

    // Simulate some access for demonstration
    for (int i = 0; i < 10; i++) {
        char ip[16];
        snprintf(ip, sizeof(ip), "192.168.1.%d", (i % 10) + 1);
        simulate_access(ip);
        sleep(1); // Simulate delay between accesses
    }

    pthread_join(monitor_thread, NULL);
    pthread_mutex_destroy(&ip_mutex);
    return 0;
}