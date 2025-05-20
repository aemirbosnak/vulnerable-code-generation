//FormAI DATASET v1.0 Category: System process viewer ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>

void printProcessInfo(char* processPath, char* processName) {
   printf("Process Path: %s\n", processPath);

   char statFilePath[strlen(processPath) + 7];
   sprintf(statFilePath, "%s/%s", processPath, "stat");

   FILE* statFile = fopen(statFilePath, "r");
   if(statFile == NULL) {
      printf("Unable to open statfile for %s", processName);
      return;
   }

   unsigned long long int processID;
   char com[100];
   char state;
   unsigned long long int ppid, pgrp, session, tty_nr, tpgid;
   unsigned long long int flags, minflt, cminflt, majflt, cmajflt;
   unsigned long long int utime, stime, cutime, cstime;
   long long int priority, nice, num_threads, itrealvalue, starttime;

   fscanf(statFile, "%llu", &processID); fscanf(statFile, "%s", com); fscanf(statFile, " %c", &state); 
   fscanf(statFile, "%llu %llu %llu %llu %llu %llu %llu", &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt);
   fscanf(statFile, "%llu %llu %llu %llu %llu %llu %llu", &cminflt, &majflt, &cmajflt, &utime, &stime, &cutime, &cstime);
   fscanf(statFile, "%lld %lld %lld %lld %llu", &priority, &nice, &num_threads, &itrealvalue, &starttime);

   fclose(statFile);

   printf("Process ID: %llu\n", processID);
   printf("Command: %s\n", com);
   printf("State: %c\n", state);
   printf("Parent Process ID: %llu\n", ppid);
   printf("Process Group ID: %llu\n", pgrp);
   printf("Session ID: %llu\n", session);
   printf("Terminal ID: %llu\n", tty_nr);
   printf("Foreground Process Group ID: %llu\n", tpgid);
   printf("Process Flags: %llu\n", flags);
   printf("Number of Minor Page Faults: %llu\n", minflt);
   printf("Number of Minor Page Faults: %llu\n", minflt);
   printf("Number of Major Page Faults: %llu\n", majflt);
   printf("Number of Major Page Faults: %llu\n", cmajflt);
   printf("User Time: %llu\n", utime);
   printf("System Time: %llu\n", stime);
   printf("User Time (Children): %llu\n", cutime);
   printf("System Time (Children): %llu\n", cstime);
   printf("Process Priority: %lld\n", priority);
   printf("Process Nice Value: %lld\n", nice);
   printf("Number of Threads: %lld\n", num_threads);
   printf("Real Time Priority: %lld\n", itrealvalue);
   printf("Start Time: %lld\n", starttime);
}

int main() {
   DIR* proc_dir = opendir("/proc/");
   struct dirent* proc_file;
   int i = 0;

   while((proc_file = readdir(proc_dir))) {
      if(!isdigit(*proc_file->d_name)) {
         continue;
      }

      char stat_path[100];
      sprintf(stat_path, "/proc/%s", proc_file->d_name);

      printProcessInfo(stat_path, proc_file->d_name);
   }

   closedir(proc_dir);

   return 0;
}