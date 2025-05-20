//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  int threshold = 80; // set threshold in percent
  int interval = 5;   // set update interval in seconds
  
  // check if threshold and interval arguments provided, otherwise use defaults
  if (argc >= 2) {
    threshold = atoi(argv[1]);
    if (threshold < 0 || threshold > 100) {
      fprintf(stderr, "Invalid threshold, please provide a number between 0 and 100\n");
      exit(EXIT_FAILURE);
    }
  }
  if (argc >= 3) {
    interval = atoi(argv[2]);
    if (interval <= 0) {
      fprintf(stderr, "Invalid interval, please provide a positive number\n");
      exit(EXIT_FAILURE);
    }
  }
  
  printf("Starting paranoid C RAM usage monitor with threshold %d%% and update interval %d second(s)\n", threshold, interval);
  
  while (1) {
    // read memory usage from /proc/meminfo
    FILE *fp = fopen("/proc/meminfo", "r");
    char line[128];
    int total_mem = 0;
    int free_mem = 0;
    int used_mem = 0;
    while (fgets(line, sizeof(line), fp)) {
      if (strncmp(line, "MemTotal:", 9) == 0) {
        total_mem = atoi(line + 9) / 1024; // convert to MiB
      }
      else if (strncmp(line, "MemFree:", 8) == 0) {
        free_mem = atoi(line + 8) / 1024; // convert to MiB
      }
    }
    fclose(fp);
    used_mem = total_mem - free_mem;
    
    // calculate usage percentage
    int usage = used_mem * 100 / total_mem;
    
    if (usage >= threshold) { // check if usage above threshold
      printf("[ALERT] RAM usage is at %d%%!\n", usage);
      
      // run command to check for suspicious processes
      printf("Checking for suspicious processes...\n");
      system("ps -eo pid,cmd,%mem | awk '$3 > 10 { print $0 }'");
    }
    else {
      printf("RAM usage is at %d%%\n", usage);
    }
    
    sleep(interval);
  }
  
  return 0;
}