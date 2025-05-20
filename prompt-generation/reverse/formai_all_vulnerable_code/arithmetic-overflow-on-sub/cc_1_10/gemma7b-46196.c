//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 10

typedef struct TimeCapsule {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  struct TimeCapsule* next;
} TimeCapsule;

TimeCapsule* createTimeCapsule(int year, int month, int day, int hour, int minute) {
  TimeCapsule* capsule = malloc(sizeof(TimeCapsule));
  capsule->year = year;
  capsule->month = month;
  capsule->day = day;
  capsule->hour = hour;
  capsule->minute = minute;
  capsule->next = NULL;
  return capsule;
}

void addToHistory(TimeCapsule* capsule, TimeCapsule* history) {
  if (history == NULL) {
    history = capsule;
  } else {
    history->next = capsule;
    history = capsule;
  }
}

void travelToTime(TimeCapsule* capsule, TimeCapsule* history) {
  time_t t = time(NULL);
  struct tm* tm = localtime(&t);

  tm->tm_year = capsule->year;
  tm->tm_mon = capsule->month - 1;
  tm->tm_mday = capsule->day;
  tm->tm_hour = capsule->hour;
  tm->tm_min = capsule->minute;

  t = mktime(tm);
  sleep(t - time(NULL));

  addToHistory(capsule, history);
}

int main() {
  TimeCapsule* history = NULL;

  TimeCapsule* capsule = createTimeCapsule(2023, 10, 26, 12, 0);
  travelToTime(capsule, history);

  capsule = createTimeCapsule(2023, 10, 27, 16, 0);
  travelToTime(capsule, history);

  capsule = createTimeCapsule(2023, 10, 28, 18, 0);
  travelToTime(capsule, history);

  printf("Your history:\n");
  TimeCapsule* current = history;
  while (current) {
    printf("%d-%d-%d %d:%d\n", current->year, current->month, current->day, current->hour, current->minute);
    current = current->next;
  }

  return 0;
}