//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct appointment {
  int day;
  int month;
  int year;
};

struct patient {
  char name[50];
  char phone_no[15];
  struct appointment appt;
};

void displayMenu() {
  printf("\n\nWelcome to Appointment Scheduler\n");
  printf("================================\n");
  printf("1. Add New Appointment\n");
  printf("2. View Appointments\n");
  printf("3. Exit\n\n");
}

void addAppointment(struct patient p[], int *appointments) {
  printf("\nEnter Patient Details\n");
  printf("======================\n");
  printf("Name: ");
  fgets(p[*appointments].name, 50, stdin);
  printf("Phone: ");
  fgets(p[*appointments].phone_no, 15, stdin);
  printf("Appointment Date (DD/MM/YYYY): ");
  scanf("%d/%d/%d", &p[*appointments].appt.day, &p[*appointments].appt.month, &p[*appointments].appt.year);
  getchar();
  (*appointments)++;
  printf("\nAppointment added successfully!\n");
}

void viewAppointments(struct patient p[], int appointments) {
  if(appointments == 0) {
    printf("\nThere are no appointments to display!\n");
    return;
  }
  printf("\nAppointments\n");
  printf("============\n");
  for(int i = 0; i<appointments; i++) {
    printf("\n");
    printf("Patient Name: %s", p[i].name);
    printf("Phone No: %s", p[i].phone_no);
    printf("Appointment Date: %d/%d/%d\n", p[i].appt.day, p[i].appt.month, p[i].appt.year);
  }
}

int main() {
  struct patient patients[100];
  int appointments = 0;
  int choice;
  do {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    switch(choice) {
      case 1: addAppointment(patients, &appointments);
              break;
      case 2: viewAppointments(patients, appointments);
              break;
      case 3: printf("\nExiting program. Goodbye!\n");
              exit(0);
      default: printf("\nInvalid choice. Please try again.\n");
    }
    printf("\nPress Enter key to continue...");
    getchar();
    system("clear");
  } while(choice != 3);
  
  return 0;
}