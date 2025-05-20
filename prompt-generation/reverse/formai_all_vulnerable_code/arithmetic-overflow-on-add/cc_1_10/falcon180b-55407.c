//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MB (1024*1024)

int main()
{
   struct statvfs stat;
   double total, used, available;
   int i, j;
   char *units[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
   char buf[1024];
   FILE *fp;
   int num_files = 0;
   int total_size = 0;

   if(statvfs("/", &stat) == -1)
   {
      perror("statvfs");
      exit(1);
   }

   total = (double)stat.f_blocks * (double)stat.f_frsize;
   used = (double)stat.f_blocks - (double)stat.f_bfree;
   available = (double)stat.f_bavail * (double)stat.f_frsize;

   printf("\nRAM Usage Monitor\n");
   printf("===================\n\n");
   printf("Total RAM: %.2f %s\n", total/MB, units[0]);
   printf("Used RAM: %.2f %s\n", used/MB, units[0]);
   printf("Available RAM: %.2f %s\n", available/MB, units[0]);
   printf("\n");

   for(i=0; i<stat.f_files; i++)
   {
      snprintf(buf, 1024, "/proc/self/fd/%d", i);
      fp = fopen(buf, "r");

      if(fp!= NULL)
      {
         fseek(fp, 0, SEEK_END);
         num_files++;
         total_size += ftell(fp);
         fclose(fp);
      }
   }

   printf("Number of open files: %d\n", num_files);
   printf("Total size of open files: %.2f %s\n", total_size/MB, units[0]);
   printf("\n");

   return 0;
}