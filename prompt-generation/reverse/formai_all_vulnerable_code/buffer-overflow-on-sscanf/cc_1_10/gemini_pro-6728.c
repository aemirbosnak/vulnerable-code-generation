//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

struct proc_info {
  int pid;
  char name[100];
  char state;
  time_t start_time;
};

struct proc_info *get_proc_info(int pid) {
  struct proc_info *proc = malloc(sizeof(struct proc_info));
  char path[100];
  sprintf(path, "/proc/%d/status", pid);
  FILE *f = fopen(path, "r");
  if (f == NULL) {
    perror("fopen");
    return NULL;
  }
  char line[100];
  while (fgets(line, 100, f)) {
    if (strncmp(line, "Name:", 5) == 0) {
      sscanf(line, "Name: %s", proc->name);
    } else if (strncmp(line, "State:", 6) == 0) {
      sscanf(line, "State: %c", &proc->state);
    } else if (strncmp(line, "Start time:", 11) == 0) {
      sscanf(line, "Start time: %lldu", &proc->start_time);
    }
  }
  fclose(f);
  return proc;
}

void print_proc_info(struct proc_info *proc) {
  printf("%d %s %c %s", proc->pid, proc->name, proc->state,
         ctime(&proc->start_time));
}

void list_procs(char *dir, int depth) {
  DIR *d = opendir(dir);
  if (d == NULL) {
    perror("opendir");
    return;
  }
  struct dirent *entry;
  while ((entry = readdir(d)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    char path[100];
    sprintf(path, "%s/%s", dir, entry->d_name);
    struct stat statbuf;
    if (lstat(path, &statbuf) == -1) {
      perror("lstat");
      continue;
    }
    if (S_ISDIR(statbuf.st_mode)) {
      list_procs(path, depth + 1);
    } else if (S_ISREG(statbuf.st_mode)) {
      int pid;
      sscanf(entry->d_name, "%d", &pid);
      struct proc_info *proc = get_proc_info(pid);
      if (proc != NULL) {
        printf("%*s", depth * 2, "");
        print_proc_info(proc);
        free(proc);
      }
    }
  }
  closedir(d);
}

int main() {
  list_procs("/proc", 0);
  return 0;
}