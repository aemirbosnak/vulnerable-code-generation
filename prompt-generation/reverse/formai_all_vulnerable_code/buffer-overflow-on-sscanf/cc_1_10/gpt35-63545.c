//FormAI DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>

int main() {
   char hostname[50];

   // Get the hostname of the system
   if(gethostname(hostname, sizeof(hostname)) == 0) {
      printf("Hostname: %s\n", hostname);
   } else {
      printf("Error: Could not get hostname\n");
      return 1;
   }

   // Get the total amount of memory available
   FILE* memFile = fopen("/proc/meminfo", "r");
   if(memFile == NULL) {
      printf("Error: Could not get memory info\n");
      return 1;
   }

   char line[256];
   unsigned long long totalMemory = 0;
   while(fgets(line, sizeof(line), memFile)) {
      if(sscanf(line, "MemTotal: %llu kB", &totalMemory) == 1) {
         break;
      }
   }

   fclose(memFile);

   printf("Total memory: %llu kB\n", totalMemory);

   // Get the current load average of the system
   double loadAverage[3];
   if(getloadavg(loadAverage, sizeof(loadAverage) / sizeof(loadAverage[0])) == -1) {
      printf("Error: Could not get load average\n");
      return 1;
   }

   printf("Load average: %.2f, %.2f, %.2f\n", loadAverage[0], loadAverage[1], loadAverage[2]);

   // Get the number of running processes on the system
   FILE* statFile = fopen("/proc/stat", "r");
   if(statFile == NULL) {
      printf("Error: Could not get system stats\n");
      return 1;
   }

   unsigned long long processes = 0;
   while(fgets(line, sizeof(line), statFile)) {
      if(sscanf(line, "procs_running %llu", &processes) == 1) {
         break;
      }
   }

   fclose(statFile);

   printf("Processes running: %llu\n", processes);

   return 0;
}