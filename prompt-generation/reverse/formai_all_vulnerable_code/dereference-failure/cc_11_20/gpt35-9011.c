//FormAI DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]){
  DIR *dir;
  struct dirent *entry;
  FILE *fp;
  char path[PATH_MAX], buffer[1024], command[50];
  int pid, ppid, counter = 0, state;
  float mem;
  long unsigned int uptime, starttime;
  
  printf("PID\tPPID\tSTATUS\tMEMORY\t\tCOMMAND\n");

  dir = opendir("/proc");
  
  if (dir == NULL){
    printf("Error: Unable to open /proc");
    exit(1);
  }

  while ((entry = readdir(dir)) != NULL){
    if (isdigit(*entry->d_name)){
      pid = atoi(entry->d_name);
      sprintf(path, "/proc/%d/status", pid);
      fp = fopen(path, "r");
      
      if (fp){
        if (fgets(buffer, 1024, fp) == NULL){
          fclose(fp);
          continue;
        }
        sscanf(buffer, "%*s %s", command);
        
        if (fgets(buffer, 1024, fp) == NULL){
          fclose(fp);
          continue;
        }
        sscanf(buffer, "%*s %d", &ppid);

        if (fgets(buffer, 1024, fp) == NULL){
          fclose(fp);
          continue;
        }
        sscanf(buffer, "%*s %*s %*s %*s %d", &state);

        fclose(fp);

        sprintf(path, "/proc/%d/statm", pid);
        fp = fopen(path, "r");
        
        if (fp){
          if (fgets(buffer, 1024, fp) == NULL){
            fclose(fp);
            continue;
          }
          
          sscanf(buffer, "%*s %f", &mem);
          fclose(fp);

          sprintf(path, "/proc/%d/stat", pid);
          fp = fopen(path, "r");
          
          if (fp){
            if (fgets(buffer, 1024, fp) == NULL){
              fclose(fp);
              continue;
            }

            fclose(fp);

            sscanf(buffer, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu %lu", &uptime, &starttime);
          }
        }
        printf("%d\t%d\t%d\t%.2f\t\t%s\n", pid, ppid, state, mem, command);
        counter++;
      }
    }
  }

  printf("Total processes: %d\n", counter);
  closedir(dir);

  return 0;
}