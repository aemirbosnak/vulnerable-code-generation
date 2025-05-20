//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Appointment {
  char *name;
  time_t start_time;
  time_t end_time;
  char *location;
};

struct AppointmentScheduler {
  struct Appointment **appointments;
  int num_appointments;
  int max_appointments;
};

struct AppointmentScheduler *create_scheduler(int max_appointments) {
  struct AppointmentScheduler *scheduler = malloc(sizeof(struct AppointmentScheduler));
  scheduler->appointments = malloc(max_appointments * sizeof(struct Appointment *));
  scheduler->num_appointments = 0;
  scheduler->max_appointments = max_appointments;
  return scheduler;
}

void destroy_scheduler(struct AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]->name);
    free(scheduler->appointments[i]->location);
    free(scheduler->appointments[i]);
  }
  free(scheduler->appointments);
  free(scheduler);
}

int add_appointment(struct AppointmentScheduler *scheduler, struct Appointment *appointment) {
  if (scheduler->num_appointments >= scheduler->max_appointments) {
    return -1;
  }
  scheduler->appointments[scheduler->num_appointments++] = appointment;
  return 0;
}

struct Appointment *find_appointment(struct AppointmentScheduler *scheduler, char *name) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    if (strcmp(scheduler->appointments[i]->name, name) == 0) {
      return scheduler->appointments[i];
    }
  }
  return NULL;
}

int remove_appointment(struct AppointmentScheduler *scheduler, char *name) {
  int index = -1;
  for (int i = 0; i < scheduler->num_appointments; i++) {
    if (strcmp(scheduler->appointments[i]->name, name) == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    return -1;
  }
  for (int i = index; i < scheduler->num_appointments - 1; i++) {
    scheduler->appointments[i] = scheduler->appointments[i + 1];
  }
  scheduler->num_appointments--;
  return 0;
}

void print_scheduler(struct AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("%s: %s - %s at %s\n",
           scheduler->appointments[i]->name,
           ctime(&scheduler->appointments[i]->start_time),
           ctime(&scheduler->appointments[i]->end_time),
           scheduler->appointments[i]->location);
  }
}

int main() {
  struct AppointmentScheduler *scheduler = create_scheduler(10);

  struct Appointment *appointment1 = malloc(sizeof(struct Appointment));
  appointment1->name = "John Doe";
  appointment1->start_time = time(NULL) + 3600;  // 1 hour from now
  appointment1->end_time = appointment1->start_time + 3600;  // 1 hour later
  appointment1->location = "Room 101";
  add_appointment(scheduler, appointment1);

  struct Appointment *appointment2 = malloc(sizeof(struct Appointment));
  appointment2->name = "Jane Doe";
  appointment2->start_time = time(NULL) + 7200;  // 2 hours from now
  appointment2->end_time = appointment2->start_time + 3600;  // 1 hour later
  appointment2->location = "Room 102";
  add_appointment(scheduler, appointment2);

  print_scheduler(scheduler);

  struct Appointment *appointment3 = find_appointment(scheduler, "John Doe");
  if (appointment3 != NULL) {
    printf("Found appointment for John Doe: %s\n", ctime(&appointment3->start_time));
  } else {
    printf("Appointment for John Doe not found.\n");
  }

  remove_appointment(scheduler, "Jane Doe");
  print_scheduler(scheduler);

  destroy_scheduler(scheduler);

  return 0;
}