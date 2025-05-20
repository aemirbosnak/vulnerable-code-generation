//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "/proc/meminfo"

/**
* Function to read the first occurrence of a string in a file and return the value
* @param file the pointer to the file to be read
* @param string the string after which the value is located
* @return the integer value after the string
*/
int read_occurrence(FILE *file, char *string) {
    int value;
    char buffer[50];
    fgets(buffer, 50, file);
    sscanf(buffer, "%*s%d", &value);
    return value;
}


int main() {
   FILE* fd;
   fd = fopen(PATH, "r");

   if(fd == NULL) {
       printf("Failed to open file %s\n", PATH);
       exit(1);
   }

   int mem_total = read_occurrence(fd, "MemTotal:");
   int mem_free = read_occurrence(fd, "MemFree:");
   int buffers = read_occurrence(fd, "Buffers:");
   int cached = read_occurrence(fd, "Cached:");
   int s_reclaimable = read_occurrence(fd, "SReclaimable:");

   printf("Total Memory : %d kB\n", mem_total);
   printf("Free Memory  : %d kB\n", mem_free);
   printf("Buffers      : %d kB\n", buffers);
   printf("Cached       : %d kB\n", cached);
   printf("Reclaimable  : %d kB\n", s_reclaimable);

   int used = mem_total - mem_free - buffers - cached - s_reclaimable;
   int used_percent = used * 100 / mem_total;

   printf("Used Memory   : %d kB\n", used);
   printf("Usage Percent : %d%%\n", used_percent);

   fclose(fd);
}