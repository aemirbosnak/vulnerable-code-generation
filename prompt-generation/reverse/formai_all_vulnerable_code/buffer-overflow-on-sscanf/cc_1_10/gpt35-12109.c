//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define NUM_DAYS 7
#define NUM_SLOTS 3

// Define the appointment structure with fields name and phone
struct appointment {
    char name[50];
    char phone[15];
};

// Define the weekday structure with fields appointments and num_appointments
struct weekday {
    struct appointment appointments[NUM_SLOTS];
    int num_appointments;
};

void printMenu() {
    printf("\nSelect an option:\n");
    printf("1. Schedule an appointment\n");
    printf("2. Cancel an appointment\n");
    printf("3. View all appointments for a day\n");
    printf("4. View all appointments for the week\n");
    printf("5. Exit\n\n");
}

int getIntegerInput() {
    int input;
    char buffer[50];
    fgets(buffer, sizeof buffer, stdin);
    sscanf(buffer, "%d", &input);
    return input;
}

void getStringInput(char *str, int len) {
    char buffer[50];
    fgets(buffer, sizeof buffer, stdin);
    sscanf(buffer, "%s", str);
    str[len - 1] = '\0';
}

void printAppointment(struct appointment appt) {
    printf("%s, %s\n", appt.name, appt.phone);
}

void printWeekday(struct weekday day) {
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (day.appointments[i].name[0] != '\0') {
            printf("Slot %d: ", i+1);
            printAppointment(day.appointments[i]);
        }
    }
}

int getWeekdayIndex(char *str) {
    char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < NUM_DAYS; i++) {
        if (strcmp(str, days[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int getSlotIndex(char *str) {
    char *slots[] = {"Morning", "Afternoon", "Evening"};
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (strcmp(str, slots[i]) == 0) {
            return i;
        }
    }
    return -1;
}

bool isAppointmentAvailable(struct weekday day, int slot) {
    return (day.appointments[slot].name[0] == '\0') && (day.appointments[slot].phone[0] == '\0');
}

void scheduleAppointment(struct weekday *week, int dayIndex, int slot) {
    struct appointment newAppt;
    printf("Enter name: ");
    getStringInput(newAppt.name, 50);
    printf("Enter phone number: ");
    getStringInput(newAppt.phone, 15);
    week[dayIndex].appointments[slot] = newAppt;
    week[dayIndex].num_appointments++;
}

void cancelAppointment(struct weekday *week, int dayIndex, int slot) {
    week[dayIndex].appointments[slot].name[0] = '\0';
    week[dayIndex].appointments[slot].phone[0] = '\0';
    week[dayIndex].num_appointments--;
}

void viewDayAppointments(struct weekday *week, int dayIndex) {
    printf("Appointments for %d/%d/%d:\n", dayIndex + 1, 9, 2021);
    printWeekday(week[dayIndex]);
}

void viewWeekAppointments(struct weekday *week) {
    for (int i = 0; i < NUM_DAYS; i++) {
        viewDayAppointments(week, i);
        printf("\n");
    }
}

int main() {
    bool running = true;
    struct weekday week[NUM_DAYS] = {};
    while (running) {
        printMenu();
        int choice = getIntegerInput();
        switch (choice) {
            case 1: {
                printf("Enter weekday (Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday): ");
                char buffer[50];
                getStringInput(buffer, 50);
                int dayIndex = getWeekdayIndex(buffer);
                if (dayIndex == -1) {
                    printf("Invalid input!\n");
                } else {
                    printf("Enter slot (Morning, Afternoon, Evening): ");
                    getStringInput(buffer, 50);
                    int slotIndex = getSlotIndex(buffer);
                    if (slotIndex == -1) {
                        printf("Invalid input!\n");
                    } else {
                        if (isAppointmentAvailable(week[dayIndex], slotIndex)) {
                            scheduleAppointment(week, dayIndex, slotIndex);
                            printf("Appointment scheduled!\n");
                        } else {
                            printf("Slot already booked!\n");
                        }
                    }
                }
                break;
            }
            case 2: {
                printf("Enter weekday (Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday): ");
                char buffer[50];
                getStringInput(buffer, 50);
                int dayIndex = getWeekdayIndex(buffer);
                if (dayIndex == -1) {
                    printf("Invalid input!\n");
                } else {
                    printf("Enter slot (Morning, Afternoon, Evening): ");
                    getStringInput(buffer, 50);
                    int slotIndex = getSlotIndex(buffer);
                    if (slotIndex == -1) {
                        printf("Invalid input!\n");
                    } else {
                        if (isAppointmentAvailable(week[dayIndex], slotIndex)) {
                            printf("Slot already empty!\n");
                        } else {
                            cancelAppointment(week, dayIndex, slotIndex);
                            printf("Appointment cancelled!\n");
                        }
                    }
                }
                break;
            }
            case 3: {
                printf("Enter weekday (Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday): ");
                char buffer[50];
                getStringInput(buffer, 50);
                int dayIndex = getWeekdayIndex(buffer);
                if (dayIndex == -1) {
                    printf("Invalid input!\n");
                } else {
                    viewDayAppointments(week, dayIndex);
                }
                break;
            }
            case 4: {
                viewWeekAppointments(week);
                break;
            }
            case 5: {
                running = false;
                break;
            }
            default: {
                printf("Invalid input!\n");
                break;
            }
        }
    }
    return 0;
}