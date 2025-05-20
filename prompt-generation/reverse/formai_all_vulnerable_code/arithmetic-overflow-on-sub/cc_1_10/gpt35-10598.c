//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROC 1024
#define BUFSIZE 512

struct CpuData {
  int user;
  int nice;
  int system;
  int idle;
  int iowait;
  int irq;
  int softirq;
};

struct ProcData {
  int pid;
  char name[BUFSIZE];
  char state;
  int ppid;
  int cpu;
  float cpu_usage;
};

int read_cpu_data(struct CpuData *cpu_data) {
  FILE *fp = fopen("/proc/stat", "r");
  if (!fp) {
    perror("fopen /proc/stat failed");
    return -1;
  }

  char buf[BUFSIZE];
  if (!fgets(buf, sizeof(buf), fp)) {
    perror("fgets /proc/stat failed");
    fclose(fp);
    return -1;
  }

  int ret = sscanf(buf, "cpu %d %d %d %d %d %d %d",
                      &cpu_data->user,
                      &cpu_data->nice,
                      &cpu_data->system,
                      &cpu_data->idle,
                      &cpu_data->iowait,
                      &cpu_data->irq,
                      &cpu_data->softirq
                      );
  if (ret != 7) {
    perror("sscanf /proc/stat failed");
    fclose(fp);
    return -1;
  }

  fclose(fp);
  return 0;
}

int read_proc_data(struct ProcData proc_data[MAX_PROC], int proc_count) {
  FILE *fp = fopen("/proc/stat", "r");
  if (!fp) {
    perror("fopen /proc/stat failed");
    return -1;
  }

  char buf[BUFSIZE];
  while (fgets(buf, sizeof(buf), fp)) {
    if (!isdigit(buf[0])) break;

    int pid;
    char name[BUFSIZE];
    char state;
    int ppid;
    int cpu;

    int ret = sscanf(buf, "%d %s %c %d %d",
                        &pid,
                        name,
                        &state,
                        &ppid,
                        &cpu
                        );
    if (ret != 5) {
      perror("sscanf /proc/stat failed");
      fclose(fp);
      return -1;
    }
    proc_data[proc_count].pid = pid;
    strcpy(proc_data[proc_count].name, name);
    proc_data[proc_count].state = state;
    proc_data[proc_count].ppid = ppid;
    proc_data[proc_count].cpu = cpu;
    proc_data[proc_count].cpu_usage = 0.0;
    proc_count++;
  }

  fclose(fp);
  return proc_count;
}

int main() {
  struct CpuData old_cpu_data = {0, 0, 0, 0, 0, 0, 0};
  struct ProcData old_proc_data[MAX_PROC];
  int old_proc_count = read_proc_data(old_proc_data, 0);

  while (1) {
      sleep(1);

      struct CpuData cpu_data = {0, 0, 0, 0, 0, 0, 0};
      struct ProcData proc_data[MAX_PROC];
      int proc_count = read_proc_data(proc_data, 0);

      if (read_cpu_data(&cpu_data) < 0) {
        exit(EXIT_FAILURE);
      }

      // calculate cpu usage
      int user_diff = cpu_data.user - old_cpu_data.user;
      int nice_diff = cpu_data.nice - old_cpu_data.nice;
      int system_diff = cpu_data.system - old_cpu_data.system;
      int idle_diff = cpu_data.idle - old_cpu_data.idle;
      int iowait_diff = cpu_data.iowait - old_cpu_data.iowait;
      int irq_diff = cpu_data.irq - old_cpu_data.irq;
      int softirq_diff = cpu_data.softirq - old_cpu_data.softirq;
      int cpu_total = user_diff + nice_diff + system_diff + idle_diff + iowait_diff + irq_diff + softirq_diff;
      float cpu_usage = (float)(cpu_total - idle_diff) / (float)cpu_total;

      // calculate individual process cpu usage
      for (int i = 0; i < proc_count; i++) {
        for (int j = 0; j < old_proc_count; j++) {
          if (proc_data[i].pid == old_proc_data[j].pid) {
            int cpu_diff = proc_data[i].cpu - old_proc_data[j].cpu;
            proc_data[i].cpu_usage = (float)cpu_diff / (float)cpu_total;
            break;
          }
        }
      }

      // print results
      printf("CPU usage: %f\n", cpu_usage);
      for (int i = 0; i < proc_count; i++) {
        printf("PID: %d, Name: %s, CPU usage: %f\n", proc_data[i].pid, proc_data[i].name, proc_data[i].cpu_usage);
      }

      old_cpu_data = cpu_data;
      memcpy(old_proc_data, proc_data, sizeof(proc_data));
      old_proc_count = proc_count;
  }

  return 0;
}