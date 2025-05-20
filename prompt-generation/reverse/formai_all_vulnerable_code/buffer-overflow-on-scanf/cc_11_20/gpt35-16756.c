//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char date[11];
    char time[6];
    char client[51];
    char therapist[51];
};

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (true) {
        printf("Enter an option:\n");
        printf("1. Add appointment\n");
        printf("2. View all appointments\n");
        printf("3. Search for appointment\n");
        printf("4. Delete appointment\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%s", appointments[num_appointments].date);

                printf("Enter time (hh:mm): ");
                scanf("%s", appointments[num_appointments].time);

                printf("Enter client name: ");
                scanf("%s", appointments[num_appointments].client);

                printf("Enter therapist name: ");
                scanf("%s", appointments[num_appointments].therapist);

                printf("Appointment added!\n");
                num_appointments++;
                break;
            case 2:
                printf("Date        Time    Client                   Therapist\n");
                printf("-------------------------------------------------------\n");

                for (int i = 0; i < num_appointments; i++) {
                    struct appointment appt = appointments[i];
                    printf("%s   %s   %-24s%s\n", appt.date, appt.time, appt.client, appt.therapist);
                }

                printf("-------------------------------------------------------\n");
                break;
            case 3:
                printf("Enter date of appointment to search for (dd/mm/yyyy): ");
                char search_date[11];
                scanf("%s", search_date);

                printf("Enter time of appointment to search for (hh:mm): ");
                char search_time[6];
                scanf("%s", search_time);

                bool found = false;

                for (int i = 0; i < num_appointments; i++) {
                    struct appointment appt = appointments[i];

                    if (strcmp(appt.date, search_date) == 0 && strcmp(appt.time, search_time) == 0) {
                        printf("Appointment found!\n");
                        printf("Date: %s\n", appt.date);
                        printf("Time: %s\n", appt.time);
                        printf("Client: %s\n", appt.client);
                        printf("Therapist: %s\n", appt.therapist);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    printf("Appointment not found\n");
                }
                break;
            case 4:
                printf("Enter date of appointment to delete (dd/mm/yyyy): ");
                char delete_date[11];
                scanf("%s", delete_date);

                printf("Enter time of appointment to delete (hh:mm): ");
                char delete_time[6];
                scanf("%s", delete_time);

                int delete_index = -1;

                for (int i = 0; i < num_appointments; i++) {
                    struct appointment appt = appointments[i];

                    if (strcmp(appt.date, delete_date) == 0 && strcmp(appt.time, delete_time) == 0) {
                        printf("Appointment deleted\n");
                        delete_index = i;
                        break;
                    }
                }

                if (delete_index != -1) {
                    for (int i = delete_index; i < num_appointments - 1; i++) {
                        appointments[i] = appointments[i + 1];
                    }
                    num_appointments--;
                } else {
                    printf("Appointment not found\n");
                }
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}