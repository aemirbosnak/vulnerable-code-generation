//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];

int main()
{
  struct rusage usage;
  int i, j;
  double cpu_usage;
  FILE *fp;

  // Open the file to write CPU usage
  fp = fopen("cpu_usage.log", "w");
  if (fp == NULL)
  {
    printf("Error: Could not open file.\n");
    exit(1);
  }

  // Loop indefinitely
  for (i = 0; i < 1000000; i++)
  {
    // Get the current CPU usage
    getrusage(RUSAGE_SELF, &usage);

    // Calculate the CPU usage percentage
    cpu_usage = ((double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000.0) / (double) i * 100.0;

    // Print the CPU usage to the console
    printf("CPU Usage: %.2f%%\n", cpu_usage);

    // Write the CPU usage to the log file
    fprintf(fp, "CPU Usage: %.2f%%\n", cpu_usage);

    // Clear the buffer
    memset(buffer, 0, BUFFER_SIZE);

    // Read from the file and print to the console
    j = fread(buffer, 1, BUFFER_SIZE, fp);
    if (j > 0)
    {
      buffer[j] = '\0';
      printf("%s", buffer);
    }
  }

  // Close the file
  fclose(fp);

  return 0;
}