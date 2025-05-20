//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DATE_LEN 11
#define DESC_LEN 100

typedef struct {
    char date[DATE_LEN];
    char description[DESC_LEN];
} Appointment;

// Function prototypes
void addAppointment(Appointment appointments[], int *count);
void viewAppointments(Appointment appointments[], int count);
void deleteAppointment(Appointment appointments[], int *count, int index);
void swap(Appointment *a, Appointment *b);
int compareDates(const void *a, const void *b);
void sortAppointments(Appointment appointments[], int count);
void clearBuffer();

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointmentCount = 0;
    int choice;

    while (1) {
        printf("\n=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Sort Appointments by Date\n");
        printf("5. Exit\n");
        printf("============================\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addAppointment(appointments, &appointmentCount);
                break;
            case 2:
                viewAppointments(appointments, appointmentCount);
                break;
            case 3: {
                int index;
                printf("Enter the appointment index to delete (0 to %d): ", appointmentCount - 1);
                scanf("%d", &index);
                clearBuffer();
                if (index >= 0 && index < appointmentCount) {
                    deleteAppointment(appointments, &appointmentCount, index);
                } else {
                    printf("Invalid index!\n");
                }
                break;
            }
            case 4:
                sortAppointments(appointments, appointmentCount);
                printf("Appointments sorted by date.\n");
                break;
            case 5:
                printf("Exiting the scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Limit reached!\n");
        return;
    }
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appointments[*count].date, DATE_LEN, stdin);
    appointments[*count].date[strcspn(appointments[*count].date, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(appointments[*count].description, DESC_LEN, stdin);
    appointments[*count].description[strcspn(appointments[*count].description, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Appointment added!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\n=== Your Appointments ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. [%s] %s\n", i, appointments[i].date, appointments[i].description);
    }
    printf("=========================\n");
}

void deleteAppointment(Appointment appointments[], int *count, int index) {
    for (int i = index; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*count)--;
    printf("Appointment deleted successfully!\n");
}

void swap(Appointment *a, Appointment *b) {
    Appointment temp = *a;
    *a = *b;
    *b = temp;
}

int compareDates(const void *a, const void *b) {
    return strcmp(((Appointment *)a)->date, ((Appointment *)b)->date);
}

void sortAppointments(Appointment appointments[], int count) {
    qsort(appointments, count, sizeof(Appointment), compareDates);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear buffer to avoid input issues
}