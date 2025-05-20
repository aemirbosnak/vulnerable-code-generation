//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULES 10

typedef struct Schedule {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct Schedule* next;
} Schedule;

Schedule* head = NULL;

void add_schedule(char* name, int priority, time_t start_time, time_t end_time) {
  Schedule* new_schedule = (Schedule*)malloc(sizeof(Schedule));
  strcpy(new_schedule->name, name);
  new_schedule->priority = priority;
  new_schedule->start_time = start_time;
  new_schedule->end_time = end_time;
  new_schedule->next = NULL;

  if (head == NULL) {
    head = new_schedule;
  } else {
    Schedule* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_schedule;
  }
}

void display_schedules() {
  Schedule* current = head;
  while (current) {
    printf("%s (Priority: %d)\n", current->name, current->priority);
    printf("Start Time: %s\n", current->start_time);
    printf("End Time: %s\n", current->end_time);
    printf("\n");
    current = current->next;
  }
}

int main() {
  add_schedule("Wake up", 1, time(NULL), time(NULL) + 60 * 8);
  add_schedule("Breakfast", 2, time(NULL) + 60 * 8, time(NULL) + 60 * 10);
  add_schedule("School", 3, time(NULL) + 60 * 10, time(NULL) + 60 * 16);
  add_schedule("Lunch", 2, time(NULL) + 60 * 16, time(NULL) + 60 * 18);
  add_schedule("Homework", 1, time(NULL) + 60 * 18, time(NULL) + 60 * 20);

  display_schedules();

  return 0;
}