//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: inquisitive
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

int main() {
  FILE *fp;
  int prev_idle, prev_total;
  char line[256];
  unsigned long long user, nice, sys, idle, total;
  float cpu_usage;
  struct statvfs diskInfo;
  double total_mem, used_mem, free_mem, buffer, cached;

  // Initializing previous idle and total times to 0
  fp = fopen("/proc/stat","r");
  fscanf(fp,"%*s %llu %llu %llu %llu",&user,&nice,&sys,&idle);
  fclose(fp);
  prev_idle = idle;
  prev_total = user+nice+sys+idle;

  while(1) {
    // Sleep for 1 second
    sleep(1);

    // Reading current CPU usage values from /proc/stat
    fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %llu %llu %llu %llu",&user,&nice,&sys,&idle);
    fclose(fp);
    total = user+nice+sys+idle;

    // Calculating CPU usage percentage
    cpu_usage = ((float)(total-prev_total) - (float)(idle-prev_idle))/(total-prev_total) * 100;

    printf("Current CPU usage: %.2f%%\n", cpu_usage);

    // Updating previous idle and total times
    prev_idle = idle;
    prev_total = total;

    // Reading current memory usage values from /proc/meminfo
    fp = fopen("/proc/meminfo","r");

    while(fgets(line, sizeof(line), fp)){
      if(strncmp(line, "MemTotal:", 9) == 0){
        sscanf(line, "MemTotal:%lf kB", &total_mem);
      }
      else if(strncmp(line, "MemFree:", 8) == 0){
        sscanf(line, "MemFree:%lf kB", &free_mem);
      }
      else if(strncmp(line, "Buffers:", 8) == 0){
        sscanf(line, "Buffers:%lf kB", &buffer);
      }
      else if(strncmp(line, "Cached:", 7) == 0){
        sscanf(line, "Cached:%lf kB", &cached);
      }
    }

    fclose(fp);

    // Calculating used memory and printing memory usage statistics
    used_mem = total_mem - free_mem - buffer - cached;
    printf("Memory Usage: Total: %.2f MB Used: %.2f MB Free: %.2f MB\n", total_mem/1024, used_mem/1024, free_mem/1024);

    // Reading disk usage statistics using statvfs and printing disk usage statistics
    statvfs("/", &diskInfo);
    printf("Disk Usage: Total Blocks: %ld Free Blocks: %ld Total Size: %ld MB Free Size: %lld MB\n", diskInfo.f_blocks, diskInfo.f_bfree, diskInfo.f_blocks*(diskInfo.f_frsize/1024)/1024, diskInfo.f_bfree*(diskInfo.f_frsize/1024)/1024);
  }

  return 0;
}