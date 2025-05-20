//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct Appointment {
  char* name;
  char* email;
  char* phone;
  char* date;
  char* time;
  char* duration;
};

struct AppointmentList {
  struct Appointment* appointments;
  int num_appointments;
};

void createAppointment(struct AppointmentList* list, char* name, char* email, char* phone, char* date, char* time, char* duration) {
  struct Appointment appointment;
  appointment.name = name;
  appointment.email = email;
  appointment.phone = phone;
  appointment.date = date;
  appointment.time = time;
  appointment.duration = duration;
  list->appointments = realloc(list->appointments, (list->num_appointments + 1) * sizeof(struct Appointment));
  list->appointments[list->num_appointments] = appointment;
  list->num_appointments++;
}

void displayAppointments(struct AppointmentList* list) {
  for (int i = 0; i < list->num_appointments; i++) {
    struct Appointment appointment = list->appointments[i];
    printf("Appointment %d:\n", i);
    printf("  Name: %s\n", appointment.name);
    printf("  Email: %s\n", appointment.email);
    printf("  Phone: %s\n", appointment.phone);
    printf("  Date: %s\n", appointment.date);
    printf("  Time: %s\n", appointment.time);
    printf("  Duration: %s\n", appointment.duration);
  }
}

int main() {
  struct AppointmentList list;
  list.num_appointments = 0;
  list.appointments = NULL;

  createAppointment(&list, "John Doe", "johndoe@example.com", "555-555-5555", "12/12/2022", "10:00 AM", "30 minutes");
  createAppointment(&list, "Jane Doe", "janedoe@example.com", "555-555-5556", "12/12/2022", "11:00 AM", "1 hour");
  createAppointment(&list, "Bob Smith", "bobsmith@example.com", "555-555-5557", "12/12/2022", "12:00 PM", "1 hour 30 minutes");

  displayAppointments(&list);

  return 0;
}