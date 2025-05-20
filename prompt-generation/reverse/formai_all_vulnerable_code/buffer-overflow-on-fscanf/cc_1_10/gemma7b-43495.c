//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define RAM_SIZE 1024

typedef struct RAM_DATA {
  unsigned long long free_space;
  unsigned long long used_space;
  unsigned long long total_space;
  struct RAM_DATA* next;
} RAM_DATA;

RAM_DATA* ram_head = NULL;

void update_ram_data() {
  FILE* f = fopen("/proc/meminfo", "r");
  char buffer[256];
  fscanf(f, "%s", buffer);
  fclose(f);

  char* p = strstr(buffer, "MemFree:");
  long long free_space = atoi(p + 12);

  p = strstr(buffer, "MemUsed:");
  long long used_space = atoi(p + 12);

  RAM_DATA* new_data = malloc(sizeof(RAM_DATA));
  new_data->free_space = free_space;
  new_data->used_space = used_space;
  new_data->total_space = RAM_SIZE - free_space - used_space;
  new_data->next = ram_head;
  ram_head = new_data;
}

int main() {
  update_ram_data();

  RAM_DATA* data = ram_head;
  while (data) {
    printf("Free Space: %llu\n", data->free_space);
    printf("Used Space: %llu\n", data->used_space);
    printf("Total Space: %llu\n", data->total_space);
    printf("\n");
    data = data->next;
  }

  return 0;
}