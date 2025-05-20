//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  char time[10];
  int day;
  int month;
  int year;
} appointment;

int cmp_appt(const void *a, const void *b) {
  const appointment *appt1 = (const appointment *)a;
  const appointment *appt2 = (const appointment *)b;

  if (appt1->year < appt2->year) {
    return -1;
  } else if (appt1->year > appt2->year) {
    return 1;
  } else if (appt1->month < appt2->month) {
    return -1;
  } else if (appt1->month > appt2->month) {
    return 1;
  } else if (appt1->day < appt2->day) {
    return -1;
  } else if (appt1->day > appt2->day) {
    return 1;
  } else {
    return strcmp(appt1->time, appt2->time);
  }
}

int main() {
  int num_appts, i;

  printf("Enter the number of appointments: ");
  scanf("%d", &num_appts);

  appointment *appts = (appointment *)malloc(num_appts * sizeof(appointment));

  for (i = 0; i < num_appts; i++) {
    printf("Enter the name for appointment %d: ", i + 1);
    scanf("%s", appts[i].name);

    printf("Enter the time for appointment %d (hh:mm): ", i + 1);
    scanf("%s", appts[i].time);

    printf("Enter the day for appointment %d: ", i + 1);
    scanf("%d", &appts[i].day);

    printf("Enter the month for appointment %d: ", i + 1);
    scanf("%d", &appts[i].month);

    printf("Enter the year for appointment %d: ", i + 1);
    scanf("%d", &appts[i].year);

    printf("\n");
  }

  qsort(appts, num_appts, sizeof(appointment), cmp_appt);

  printf("\nYour appointments:\n");
  for (i = 0; i < num_appts; i++) {
    printf("%s at %s on %d/%d/%d\n", appts[i].name, appts[i].time, appts[i].day,
           appts[i].month, appts[i].year);
  }

  free(appts);

  return 0;
}