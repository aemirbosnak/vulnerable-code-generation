//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct log_entry {
    char ip[16];
    char method[8];
    char path[64];
    int status_code;
};

void *analyze_log_file(void *args) {
    FILE *fp;
    struct log_entry entry;
    char line[1024];

    fp = fopen((char *)args, "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%15s %7s %63s %d", entry.ip, entry.method, entry.path, &entry.status_code);
        printf("IP: %s, Method: %s, Path: %s, Status Code: %d\n", entry.ip, entry.method, entry.path, entry.status_code);
    }

    fclose(fp);
    return NULL;
}

int main() {
    pthread_t thread_id;
    char log_file_path[64];
    int i;

    printf("Enter log file path: ");
    scanf("%s", log_file_path);

    for (i = 0; i < 4; i++) {
        pthread_create(&thread_id, NULL, analyze_log_file, (void *)log_file_path);
    }

    for (i = 0; i < 4; i++) {
        pthread_join(thread_id, NULL);
    }

    return 0;
}