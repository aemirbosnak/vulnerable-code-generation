//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scientific
/* 
  C RAM Usage Monitor Example Program
  Created by [YOUR NAME]
  Date: [CURRENT DATE]

  This program monitors RAM usage of the computer and displays the
  statistics in a scientific manner.

  The program uses system commands to extract the required information
  from the computer. The information is then parsed and used to calculate
  the statistics.

  The program continuously runs until the user interrupts it. It updates
  the statistics at regular intervals. 

  The program uses POSIX-compliant system commands. It may not work on 
  non-POSIX systems.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 100

typedef struct {
  long long total_memory;
  long long used_memory;
  long long free_memory;
  float used_percentage;
} MemoryStats;

/* Function declarations */
void get_memory_stats(MemoryStats * stats);
void print_memory_stats(MemoryStats * stats);

/* Main function */
int main() {
  MemoryStats stats;

  /* Continuously run until user interrupts the program */
  while(1) {
    get_memory_stats(&stats);
    print_memory_stats(&stats);

    /* Sleep for 1 second */
    sleep(1);
  }

  return 0;
}

/* Function to get memory statistics */
void get_memory_stats(MemoryStats * stats) {
  char line[MAX_LINE_LENGTH];
  FILE * fp;
  long long mem_total, mem_free, mem_used;
  
  /* Open file to read memory statistics */
  fp = fopen("/proc/meminfo", "r");

  /* Check if file is opened successfully */
  if(fp == NULL) {
    fprintf(stderr, "Error: Could not read memory statistics\n");
    exit(1);
  }

  /* Read total memory */
  fgets(line, MAX_LINE_LENGTH, fp);
  sscanf(line, "MemTotal: %lld kB", &mem_total);
  
  /* Read free memory */
  fgets(line, MAX_LINE_LENGTH, fp);
  sscanf(line, "MemFree: %lld kB", &mem_free);

  /* Calculate used memory */
  mem_used = mem_total - mem_free;

  /* Store the statistics */
  stats->total_memory = mem_total;
  stats->free_memory = mem_free;
  stats->used_memory = mem_used;
  stats->used_percentage = ((float)mem_used / (float)mem_total) * 100;
  
  /* Close the file */
  fclose(fp);
}

/* Function to print memory statistics */
void print_memory_stats(MemoryStats * stats) {
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  char time_str[MAX_LINE_LENGTH];

  /* Get current time */
  strftime(time_str, MAX_LINE_LENGTH, "%m/%d/%Y %H:%M:%S", t);
  
  /* Print statistics */
  printf("%-20s %-20s %-20s %-20s %-20s\n", "Time", "Total Memory", "Free Memory", "Used Memory", "Used Percentage");
  printf("%-20s %-20lld %-20lld %-20lld %-20.2f%%\n", time_str, stats->total_memory, stats->free_memory, stats->used_memory, stats->used_percentage);
}