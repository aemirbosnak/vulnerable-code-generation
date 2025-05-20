//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the appointment structure
typedef struct appointment_s {
  char name[50];
  char date[20];
  char time[20];
} appointment_t;

// Define the appointment list
appointment_t appointment_list[MAX_APPOINTMENTS];

// Define the mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the condition variable
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Define the thread function
void *thread_func(void *arg) {
  // Get the appointment from the argument
  appointment_t *appointment = (appointment_t *)arg;

  // Lock the mutex
  pthread_mutex_lock(&mutex);

  // Add the appointment to the list
  for (int i = 0; i < MAX_APPOINTMENTS; i++) {
    if (strcmp(appointment_list[i].name, "") == 0) {
      appointment_list[i] = *appointment;
      break;
    }
  }

  // Unlock the mutex
  pthread_mutex_unlock(&mutex);

  // Signal the condition variable
  pthread_cond_signal(&cond);

  return NULL;
}

int main() {
  // Create the threads
  pthread_t threads[MAX_APPOINTMENTS];

  // Create the appointments
  appointment_t appointments[MAX_APPOINTMENTS];

  for (int i = 0; i < MAX_APPOINTMENTS; i++) {
    // Get the appointment information
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[i].name);

    printf("Enter the date of the appointment: ");
    scanf("%s", appointments[i].date);

    printf("Enter the time of the appointment: ");
    scanf("%s", appointments[i].time);

    // Create the thread
    pthread_create(&threads[i], NULL, thread_func, &appointments[i]);
  }

  // Join the threads
  for (int i = 0; i < MAX_APPOINTMENTS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the list of appointments
  printf("The list of appointments is:\n");

  for (int i = 0; i < MAX_APPOINTMENTS; i++) {
    printf("%s, %s, %s\n", appointment_list[i].name, appointment_list[i].date, appointment_list[i].time);
  }

  return 0;
}