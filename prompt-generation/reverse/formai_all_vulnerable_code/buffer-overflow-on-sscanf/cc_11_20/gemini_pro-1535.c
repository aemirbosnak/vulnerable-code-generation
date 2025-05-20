//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Introspection: Am I running in a virtual machine?
  FILE *f = fopen("/proc/cpuinfo", "r");
  if (f) {
    char line[1024];
    while (fgets(line, sizeof(line), f)) {
      if (strstr(line, "QEMU")) {
        printf("Yes, I am running in a QEMU virtual machine.\n");
        break;
      }
    }
    fclose(f);
  }

  // Introspection: What is my boot time?
  f = fopen("/proc/stat", "r");
  if (f) {
    char line[1024];
    while (fgets(line, sizeof(line), f)) {
      if (strstr(line, "btime")) {
        unsigned long long btime;
        sscanf(line, "btime %llu", &btime);
        printf("My boot time: %llu\n", btime);
        break;
      }
    }
    fclose(f);
  }

  // Introspection: What is my uptime?
  f = fopen("/proc/uptime", "r");
  if (f) {
    char line[1024];
    while (fgets(line, sizeof(line), f)) {
      unsigned long long uptime;
      sscanf(line, "%llu", &uptime);
      printf("My uptime: %llu seconds\n", uptime);
      break;
    }
    fclose(f);
  }

  // Introspection: What is my CPU frequency?
  f = fopen("/proc/cpuinfo", "r");
  if (f) {
    char line[1024];
    while (fgets(line, sizeof(line), f)) {
      if (strstr(line, "cpu MHz")) {
        float cpu_freq;
        sscanf(line, "cpu MHz : %f", &cpu_freq);
        printf("My CPU frequency: %.2f MHz\n", cpu_freq);
        break;
      }
    }
    fclose(f);
  }

  // Introspection: What is my memory usage?
  f = fopen("/proc/meminfo", "r");
  if (f) {
    char line[1024];
    unsigned long long mem_total, mem_free;
    while (fgets(line, sizeof(line), f)) {
      if (strstr(line, "MemTotal")) {
        sscanf(line, "MemTotal: %llu kB", &mem_total);
      } else if (strstr(line, "MemFree")) {
        sscanf(line, "MemFree: %llu kB", &mem_free);
      }
    }
    printf("My memory usage: %.2f%%\n", (100.0 * (mem_total - mem_free)) / mem_total);
    fclose(f);
  }

  // Introspection: What is my disk usage?
  f = fopen("/proc/diskstats", "r");
  if (f) {
    char line[1024];
    unsigned long long disk_reads, disk_writes;
    while (fgets(line, sizeof(line), f)) {
      if (!strncmp(line, "sda ", 4)) {
        sscanf(line, "sda %llu %llu %llu %llu %llu %llu %llu %llu", &disk_reads, &disk_writes,
              &disk_reads, &disk_writes, &disk_reads, &disk_writes, &disk_reads, &disk_writes);
        break;
      }
    }
    printf("My disk usage: %.2f%%\n", (100.0 * (disk_reads + disk_writes)) / (1024 * 1024 * 1024));
    fclose(f);
  }

  return 0;
}