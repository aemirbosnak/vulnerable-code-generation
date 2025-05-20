//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DIR 10
#define THRESHOLD 80  // Threshold for CPU usage in percentage

typedef struct {
    char dir_name[256];
} Directory;

void check_disk_usage(Directory *dirs, int dir_count) {
    char command[512];
    FILE *fp;
    char buffer[256];

    for (int i = 0; i < dir_count; i++) {
        snprintf(command, sizeof(command), "df -h %s | tail -1 | awk '{print $5}'", dirs[i].dir_name);
        fp = popen(command, "r");
        if (fp == NULL) {
            perror("popen failed");
            continue;
        }

        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            // Remove newline character
            buffer[strcspn(buffer, "\n")] = '\0';

            // Parse the usage percentage
            int usage = atoi(buffer);
            if (usage > THRESHOLD) {
                printf("Warning: %s usage is at %d%%, exceeding threshold of %d%%\n",
                       dirs[i].dir_name, usage, THRESHOLD);
            } else {
                printf("%s usage is at %d%%, within safe limits.\n", dirs[i].dir_name, usage);
            }
        }
        
        pclose(fp);
    }
}

int main() {
    Directory dirs[MAX_DIR];
    int dir_count = 0;

    printf("Disk Usage Monitoring Tool\n");
    printf("Enter the directories to monitor (type 'done' to finish):\n");

    while (dir_count < MAX_DIR) {
        printf("Directory %d: ", dir_count + 1);
        scanf("%s", dirs[dir_count].dir_name);

        if (strcmp(dirs[dir_count].dir_name, "done") == 0) {
            break;
        }
        dir_count++;
    }

    printf("\nMonitoring disk usage for %d directories...\n", dir_count);
    
    while (1) {
        check_disk_usage(dirs, dir_count);
        printf("\nChecking again in 60 seconds...\n");
        sleep(60);  // Wait for 60 seconds before checking again
    }

    return 0;
}