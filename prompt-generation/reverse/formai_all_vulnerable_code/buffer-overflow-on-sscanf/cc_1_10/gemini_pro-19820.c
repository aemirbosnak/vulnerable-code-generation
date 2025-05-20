//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

#define MAX_PROC_NAME_LEN 16

struct proc_stat {
  int pid;
  char name[MAX_PROC_NAME_LEN];
  long statm_size;
  long statm_rss;
  long statm_swap;
};

int compare_proc_stats(const void *a, const void *b) {
  const struct proc_stat *pa = (const struct proc_stat *)a;
  const struct proc_stat *pb = (const struct proc_stat *)b;

  return pb->statm_rss - pa->statm_rss;
}

int main(int argc, char *argv[]) {
  DIR *procdir;
  struct dirent *procdirent;
  char procdirpath[PATH_MAX];
  char procstatpath[PATH_MAX];
  int procfd;
  struct proc_stat *procstats;
  int procstats_count;
  int i;

  procdir = opendir("/proc");
  if (procdir == NULL) {
    perror("Error opening /proc");
    exit(EXIT_FAILURE);
  }

  procstats_count = 0;
  while ((procdirent = readdir(procdir)) != NULL) {
    if (strcmp(procdirent->d_name, ".") == 0 || strcmp(procdirent->d_name, "..") == 0) {
      continue;
    }

    if (sscanf(procdirent->d_name, "%d", &i) != 1) {
      continue;
    }

    procstats_count++;
  }

  procstats = malloc(sizeof(struct proc_stat) * procstats_count);
  if (procstats == NULL) {
    perror("Error allocating memory for procstats");
    exit(EXIT_FAILURE);
  }

  i = 0;
  rewinddir(procdir);
  while ((procdirent = readdir(procdir)) != NULL) {
    if (strcmp(procdirent->d_name, ".") == 0 || strcmp(procdirent->d_name, "..") == 0) {
      continue;
    }

    if (sscanf(procdirent->d_name, "%d", &procstats[i].pid) != 1) {
      continue;
    }

    snprintf(procdirpath, sizeof(procdirpath), "/proc/%d", procstats[i].pid);
    snprintf(procstatpath, sizeof(procstatpath), "%s/stat", procdirpath);

    procfd = open(procstatpath, O_RDONLY);
    if (procfd == -1) {
      perror("Error opening procstatpath");
      continue;
    }

    if (fscanf(procfd, "%d %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*ld %ld %ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld",
        &procstats[i].pid, procstats[i].name, &procstats[i].statm_size, &procstats[i].statm_rss, &procstats[i].statm_swap) != 5) {
      perror("Error reading stat file");
      close(procfd);
      continue;
    }

    close(procfd);

    i++;
  }

  closedir(procdir);

  qsort(procstats, procstats_count, sizeof(struct proc_stat), compare_proc_stats);

  printf("Process Name         PID    RSS\n");
  for (i = 0; i < procstats_count; i++) {
    printf("%-19s %-8d %8ldkB\n", procstats[i].name, procstats[i].pid, procstats[i].statm_rss);
  }

  free(procstats);

  return EXIT_SUCCESS;
}