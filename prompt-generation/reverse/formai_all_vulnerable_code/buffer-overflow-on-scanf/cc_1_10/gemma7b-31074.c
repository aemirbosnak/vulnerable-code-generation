//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROC_NUM 10

int main()
{
  int i, j, k, status, proc_num = 0;
  pid_t pid;
  char cmd[1024], proc_name[256];

  system("clear");

  printf("Process Viewer - Press Ctrl+C to exit\n");

  while (1)
  {
    printf("Enter command (or leave blank for list): ");
    scanf("%s", cmd);

    if (strcmp(cmd, "") == 0)
    {
      system("ps -eo pid,user,cmd");
    }
    else
    {
      proc_num = 0;
      for (i = 0; i < MAX_PROC_NUM; i++)
      {
        sprintf(proc_name, "/proc/%d/name", i);
        FILE *fp = fopen(proc_name, "r");
        if (fp)
        {
          fscanf(fp, "%s", proc_name);
          if (strcmp(proc_name, cmd) == 0)
          {
            proc_num++;
          }
          fclose(fp);
        }
      }

      if (proc_num > 0)
      {
        printf("Processes found: %d\n", proc_num);
        for (j = 0; j < proc_num; j++)
        {
          printf("PID: %d, User: %s, Command: %s\n", pid, proc_name, cmd);
        }
      }
      else
      {
        printf("No processes found.\n");
      }
    }

    printf("\n");
  }

  return 0;
}