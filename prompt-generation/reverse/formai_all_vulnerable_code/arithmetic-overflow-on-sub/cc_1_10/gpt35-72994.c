//FormAI DATASET v1.0 Category: System administration ; Style: statistical
/*
This program performs a statistical analysis of system performance data.
It retrieves system utilization metrics and outputs statistical analysis in real time, including:
1. Average CPU utilization
2. Memory usage percentage
3. Storage usage percentage
4. Network traffic rate
5. Input/output operations per second

All the performance metrics are stored in a CSV file for historical analysis. 
*/

#include <stdio.h> //standard input-output header file
#include <string.h> //string manipulation header file
#include <time.h>   //time header file
#include <stdlib.h> //stdlib header file

#define MAX_LINE_LENGTH 1024
#define SAMPLE_PERIOD 5 //Sample period in seconds
#define MAX_SAMPLES 1000 //Maximum number of samples
#define FILE_NAME "system_metrics.csv" //Output file name

//Structures for storing performance metrics
struct cpu_utilization_t {
  float usage_percentage; //CPU utilization percentage
};

struct memory_utilization_t {
  float usage_percentage; //Memory usage percentage
};

struct storage_utilization_t {
  float usage_percentage; //Storage usage percentage
};

struct network_traffic_t {
  float rate; //Network traffic rate
};

struct iops_t {
  float read_rate;  //Read operations per second
  float write_rate; //Write operations per second
};

//Function for retrieving CPU utilization
struct cpu_utilization_t get_cpu_utilization() {
    FILE* fp = fopen("/proc/stat", "r");
    char buf[MAX_LINE_LENGTH];
    float usage_percentage = 0;
    fgets(buf, MAX_LINE_LENGTH, fp); //Get first line
    long user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buf+4, "%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &user, &nice, &sys, &idle, &iowait,
           &irq, &softirq, &steal, &guest, &guest_nice);
    long total = user + nice + sys + idle + iowait + irq + softirq + steal;
    long used = total - idle;
    usage_percentage = (used * 100.0) / total;
    fclose(fp);
    struct cpu_utilization_t cpu_util;
    cpu_util.usage_percentage = usage_percentage;
    return cpu_util;
}

//Function for retrieving memory utilization
struct memory_utilization_t get_memory_utilization() {
    FILE* fp = fopen("/proc/meminfo", "r");
    char buf[MAX_LINE_LENGTH];
    long mem_total, mem_free, buffers, cached, swap_cached, active, inactive;
    float usage_percentage;
    fgets(buf, MAX_LINE_LENGTH, fp); //Get first line
    sscanf(buf, "MemTotal: %ld kB", &mem_total);
    fgets(buf, MAX_LINE_LENGTH, fp); //Get second line
    sscanf(buf, "MemFree: %ld kB", &mem_free);
    fgets(buf, MAX_LINE_LENGTH, fp); //Get third line
    sscanf(buf, "Buffers: %ld kB", &buffers);
    fgets(buf, MAX_LINE_LENGTH, fp); //Get fourth line
    sscanf(buf, "Cached: %ld kB", &cached);
    fgets(buf, MAX_LINE_LENGTH, fp); //Get fifth line
    sscanf(buf, "SwapCached: %ld kB", &swap_cached);
    fgets(buf, MAX_LINE_LENGTH, fp); //Get sixth line
    sscanf(buf, "Active: %ld kB", &active);
    fgets(buf, MAX_LINE_LENGTH, fp); //Get seventh line
    sscanf(buf, "Inactive: %ld kB", &inactive);
    fclose(fp);
    long mem_used = mem_total - mem_free - buffers - cached - swap_cached - active - inactive;
    usage_percentage = (mem_used * 100.0) / mem_total;
    struct memory_utilization_t mem_util;
    mem_util.usage_percentage = usage_percentage;
    return mem_util;
}

//Function for retrieving storage utilization
struct storage_utilization_t get_storage_utilization() {
    FILE* fp = popen("df /", "r");
    char buf[MAX_LINE_LENGTH];
    float usage_percentage;
    fgets(buf, MAX_LINE_LENGTH, fp); //Discard first line
    fgets(buf, MAX_LINE_LENGTH, fp); //Get second line
    sscanf(buf, "/dev: %*d %*d %*d %*d %f", &usage_percentage);
    fclose(fp);
    struct storage_utilization_t storage_util;
    storage_util.usage_percentage = usage_percentage;
    return storage_util;
}

//Function for retrieving network traffic rate
struct network_traffic_t get_network_traffic() {
    FILE* fp = fopen("/proc/net/dev", "r");
    char buf[MAX_LINE_LENGTH];
    fgets(buf, MAX_LINE_LENGTH, fp); //Discard first line
    fgets(buf, MAX_LINE_LENGTH, fp); //Discard second line
    long rx_bytes, rx_packets, tx_bytes, tx_packets;
    float rate;
    int num_interfaces = 0;
    while (fgets(buf, MAX_LINE_LENGTH, fp)) {
        char* pos = strchr(buf, ':');
        if (pos && *(pos+1) == ' ') {
            sscanf(pos+2, "%ld %*d %*d %*d %*d %*d %*d %*d %ld", &rx_bytes, &tx_bytes);
            num_interfaces++;
            rate += (rx_bytes + tx_bytes) * 8.0;
        }
    }
    fclose(fp);
    rate /= num_interfaces; //Average rate for all interfaces
    struct network_traffic_t network_traffic;
    network_traffic.rate = rate;
    return network_traffic;
}

//Function for retrieving input/output operations per second
struct iops_t get_iops() {
    FILE* fp = popen("iostat -d 1 1", "r");
    char buf[MAX_LINE_LENGTH];
    float read_rate, write_rate;
    fgets(buf, MAX_LINE_LENGTH, fp); //Discard first line
    fgets(buf, MAX_LINE_LENGTH, fp); //Discard second line
    fgets(buf, MAX_LINE_LENGTH, fp); //Discard third line
    fgets(buf, MAX_LINE_LENGTH, fp); //Discard fourth line
    fgets(buf, MAX_LINE_LENGTH, fp); //Get fifth line
    sscanf(buf, "%*s %*s %*f %*f %*f %*f %*f %f %*f %*f %*f %f", &read_rate, &write_rate);
    fclose(fp);
    struct iops_t iops;
    iops.read_rate = read_rate;
    iops.write_rate = write_rate;
    return iops;
}

int main() {
    FILE* fp = fopen(FILE_NAME, "w+");
    if (!fp) {
        printf("Failed to open file %s\n", FILE_NAME);
        exit(1);
    }
    fprintf(fp, "Time, CPU Usage (%), Memory Usage (%), Storage Usage (%), Network Traffic (bits/s), IOPS (Read/s), IOPS (Write/s)\n");

    time_t start_time = time(NULL);
    int sample_count = 0;
    while (sample_count < MAX_SAMPLES) {
        struct cpu_utilization_t cpu_util = get_cpu_utilization();
        struct memory_utilization_t mem_util = get_memory_utilization();
        struct storage_utilization_t storage_util = get_storage_utilization();
        struct network_traffic_t network_traffic = get_network_traffic();
        struct iops_t iops = get_iops();
        time_t current_time = time(NULL);
        float time_diff = difftime(current_time, start_time);
        fprintf(fp, "%ld, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
            (long)time_diff, cpu_util.usage_percentage, mem_util.usage_percentage,
            storage_util.usage_percentage, network_traffic.rate, iops.read_rate, iops.write_rate);
        fflush(fp); //Flush output buffer
        sample_count++;
        sleep(SAMPLE_PERIOD);
    }
    fclose(fp);

    return 0;
}