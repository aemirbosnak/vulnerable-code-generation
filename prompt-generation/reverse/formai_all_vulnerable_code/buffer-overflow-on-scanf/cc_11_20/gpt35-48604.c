//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char name[50];
    char date[20];
    char time[20];
    char contact[20];
};

int main() {
    struct appointment appointment_list[100];
    int num_appointments = 0;
    int selection = 0;

    printf("CyberPunk Appointment Scheduler\n\n");

    while (selection != 6) {
        printf("Please choose an action:\n");
        printf("1. Schedule appointment\n");
        printf("2. View appointment\n");
        printf("3. Edit appointment\n");
        printf("4. Delete appointment\n");
        printf("5. View all appointments\n");
        printf("6. Quit\n");
        printf("Selection: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1: {
                printf("\nEnter name: ");
                scanf("%s", appointment_list[num_appointments].name);
                printf("Enter date (yyyy-mm-dd): ");
                scanf("%s", appointment_list[num_appointments].date);
                printf("Enter time (hh:mm:ss): ");
                scanf("%s", appointment_list[num_appointments].time);
                printf("Enter contact info: ");
                scanf("%s", appointment_list[num_appointments].contact);
                num_appointments++;
                printf("\nAppointment scheduled successfully!\n\n");
                break;
            }
            case 2: {
                char find_name[50];
                printf("\nEnter name to view appointment: ");
                scanf("%s", find_name);
                int found = 0;
                for (int i = 0; i < num_appointments; i++) {
                    if (strcmp(find_name, appointment_list[i].name) == 0) {
                        printf("\nAppointment found!\n");
                        printf("Name: %s\n", appointment_list[i].name);
                        printf("Date: %s\n", appointment_list[i].date);
                        printf("Time: %s\n", appointment_list[i].time);
                        printf("Contact: %s\n\n", appointment_list[i].contact);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nAppointment not found.\n\n");
                }
                break;
            }
            case 3: {
                char find_name[50];
                printf("\nEnter name to edit appointment: ");
                scanf("%s", find_name);
                int found = 0;
                for (int i = 0; i < num_appointments; i++) {
                    if (strcmp(find_name, appointment_list[i].name) == 0) {
                        printf("\nAppointment found!\n");
                        printf("Enter new date (yyyy-mm-dd): ");
                        scanf("%s", appointment_list[i].date);
                        printf("Enter new time (hh:mm:ss): ");
                        scanf("%s", appointment_list[i].time);
                        printf("Enter new contact info: ");
                        scanf("%s", appointment_list[i].contact);
                        found = 1;
                        printf("\nAppointment updated successfully!\n\n");
                        break;
                    }
                }
                if (!found) {
                    printf("\nAppointment not found.\n\n");
                }
                break;
            }
            case 4: {
                char find_name[50];
                printf("\nEnter name to delete appointment: ");
                scanf("%s", find_name);
                int found = 0;
                for (int i = 0; i < num_appointments; i++) {
                    if (strcmp(find_name, appointment_list[i].name) == 0) {
                        printf("\nAppointment found!\n");
                        memmove(&appointment_list[i], &appointment_list[i+1], (num_appointments - i - 1) * sizeof(struct appointment));
                        num_appointments--;
                        found = 1;
                        printf("\nAppointment deleted successfully!\n\n");
                        break;
                    }
                }
                if (!found) {
                    printf("\nAppointment not found.\n\n");
                }
                break;
            }
            case 5: {
                if (num_appointments == 0) {
                    printf("\nNo appointments found.\n\n");
                } else {
                    printf("\nHere are all the appointments:\n\n");
                    for (int i = 0; i < num_appointments; i++) {
                        printf("Appointment %d:\n", i+1);
                        printf("Name: %s\n", appointment_list[i].name);
                        printf("Date: %s\n", appointment_list[i].date);
                        printf("Time: %s\n", appointment_list[i].time);
                        printf("Contact: %s\n\n", appointment_list[i].contact);
                    }
                }
                break;
            }
            case 6: {
                printf("\nThank you for using CyberPunk Appointment Scheduler!\n\n");
                break;
            }
            default: {
                printf("\nInvalid selection.\n\n");
                break;
            }
        }
    }

    return 0;
}