//FormAI DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  DIR *dirptr;
  FILE *fp;
  struct dirent *entryPtr;
  char buf[1024], status;
  char name[1024], state[1024], cmdline[1024];
  char *path = "/proc/";
  int fd, pid, ppid, i, r;
  long int utime, stime;
  long unsigned int startTime, total_time;

  printf("%6s %15s %15s %15s %15s %15s %15s %15s %15s\n", "PID", "PPID", "STATUS", "USER", "UTIME", "STIME", "TOTALTIME", "COMMAND", "START TIME");

  dirptr = opendir(path);
  while((entryPtr = readdir(dirptr)) != NULL){
    if(isdigit(entryPtr->d_name[0])){
      pid = atoi(entryPtr->d_name);
      sprintf(buf, "%s%d/stat", path, pid);
      fp = fopen(buf, "r");
      if(fp == NULL) continue;
      fscanf(fp, "%d %s %c %d", &pid, name, &status, &ppid);
      fclose(fp);

      sprintf(buf, "%s%d/status", path, pid);
      fp = fopen(buf, "r");
      if(fp == NULL) continue;

      while(fgets(buf, sizeof(buf), fp)){
        if(strncmp(buf, "Uid:", 4) == 0){
          sscanf(buf, "%*s %*s %*s %s", &name);
          break;
        }
      }
      fclose(fp);

      sprintf(buf, "%s%d/stat", path, pid);
      fp = fopen(buf, "r");
      if(fp == NULL) continue;
      r = fscanf(fp, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %ld %ld %*d %*d %*d %*d", &utime, &stime);
      fclose(fp);

      sprintf(buf, "%s%d/stat", path, pid);
      fp = fopen(buf, "r");
      if(fp == NULL) continue;
      r = fscanf(fp, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %lu", &startTime);
      fclose(fp);

      total_time = utime + stime;
      sprintf(buf, "%s%d/cmdline", path, pid);
      fd = open(buf, O_RDONLY);
      if(fd == -1) continue;
      r = read(fd, cmdline, 1024);
      close(fd);
      if(r <= 0) continue;

      for(i = 0; i < r; i++){
        if(cmdline[i] == '\0') cmdline[i] = ' ';
      }

      printf("%6d %15d %15c %15s %15ld %15ld %15lu %15s %15lu\n", pid, ppid, status, name, utime, stime, total_time, cmdline, startTime);
    }
  }
  closedir(dirptr);
  return 0;
}