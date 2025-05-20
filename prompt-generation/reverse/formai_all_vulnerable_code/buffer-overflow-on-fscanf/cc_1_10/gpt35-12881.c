//FormAI DATASET v1.0 Category: System administration ; Style: visionary
/*
* The following program is a vision of a unique system administration tool that can be used by system administrators to monitor the health of various hardware components of a server.
* This tool will be able to monitor the CPU, memory, disk usage and network activity of the server and alert the administrators in case of any anomalies.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CPU_THRESHOLD 80
#define MEMORY_THRESHOLD 80
#define DISK_THRESHOLD 80
#define NETWORK_THRESHOLD 80

int main()
{
    while(1)
    {
        int cpu_usage, memory_usage, disk_usage, network_activity;

        // Get CPU usage
        FILE *cpu_file = popen("top -bn1 | grep load | awk '{printf \"%.2f\", $(NF-2)}'", "r");
        fscanf(cpu_file, "%d", &cpu_usage);
        pclose(cpu_file);

        // Get memory usage
        FILE *mem_file = popen("free | awk 'NR == 2{printf \"%.2f\", $3*100/$2}'","r");
        fscanf(mem_file, "%d", &memory_usage);
        pclose(mem_file);

        // Get disk usage
        FILE *disk_file = popen("df -h | awk '$NF==\"/\"{printf \"%d\", $5}'", "r");
        fscanf(disk_file, "%d", &disk_usage);
        pclose(disk_file);

        // Get network activity
        FILE *network_file = popen("cat /proc/net/dev | awk '/total:/{print $2}'", "r");
        fscanf(network_file, "%d", &network_activity);
        pclose(network_file);

        // Check for anomalies
        if(cpu_usage > CPU_THRESHOLD)
        {
            printf("High CPU usage detected! Current usage: %d\n", cpu_usage);
            // Send an alert to the system administrator
            system("mail -s 'High CPU usage detected!' admin@example.com < /dev/null");
        }

        if(memory_usage > MEMORY_THRESHOLD)
        {
            printf("High memory usage detected! Current usage: %d\n", memory_usage);
            // Send an alert to the system administrator
            system("mail -s 'High memory usage detected!' admin@example.com < /dev/null");
        }

        if(disk_usage > DISK_THRESHOLD)
        {
            printf("High disk usage detected! Current usage: %d\n", disk_usage);
            // Send an alert to the system administrator
            system("mail -s 'High disk usage detected!' admin@example.com < /dev/null");
        }

        if(network_activity > NETWORK_THRESHOLD)
        {
            printf("High network activity detected! Current activity: %d\n", network_activity);
            // Send an alert to the system administrator
            system("mail -s 'High network activity detected!' admin@example.com < /dev/null");
        }

        // Wait for 60 seconds before checking again
        sleep(60);
    }
    return 0;
}