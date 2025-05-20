//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DAYS 30
#define MAX_HOURS 8

typedef struct {
    char name[50];
    bool is_available;
} Doctor;

typedef struct {
    char patient_name[50];
    int doctor_id;
    int day;
    int hour;
} Appointment;

Doctor doctors[] = {
    {"Dr. Smith", true},
    {"Dr. Brown", true},
    {"Dr. Lee", true},
    {"Dr. Patel", true},
    {"Dr. Garcia", true},
};

Appointment appointment_schedule[MAX_DAYS][MAX_HOURS];

void print_menu() {
    printf("Welcome to the appointment scheduler!\n\n");
    printf("MENU\n");
    printf("1. Schedule an appointment\n");
    printf("2. Cancel an appointment\n");
    printf("3. View schedule by day\n");
    printf("4. View schedule by doctor\n");
    printf("5. Quit\n\n");
}

void schedule_appointment() {
    char name[50];
    int doctor_id;
    int day;
    int hour;
    
    printf("Enter patient name: ");
    scanf("%s", name);
    
    printf("Enter doctor ID (1-5): ");
    scanf("%d", &doctor_id);
    
    if (doctor_id < 1 || doctor_id > 5) {
        printf("Invalid doctor ID\n");
        return;
    }
    
    if (!doctors[doctor_id-1].is_available) {
        printf("Doctor is not available\n");
        return;
    }
    
    printf("Enter day (1-30): ");
    scanf("%d", &day);
    
    if (day < 1 || day > 30) {
        printf("Invalid day\n");
        return;
    }
    
    printf("Enter hour (1-8): ");
    scanf("%d", &hour);
    
    if (hour < 1 || hour > 8) {
        printf("Invalid hour\n");
        return;
    }
    
    strcpy(appointment_schedule[day-1][hour-1].patient_name, name);
    appointment_schedule[day-1][hour-1].doctor_id = doctor_id;
    appointment_schedule[day-1][hour-1].day = day;
    appointment_schedule[day-1][hour-1].hour = hour;
    
    doctors[doctor_id-1].is_available = false;
    
    printf("Appointment scheduled!\n");
}

void cancel_appointment() {
    int day;
    int hour;
    
    printf("Enter day (1-30): ");
    scanf("%d", &day);
    
    if (day < 1 || day > 30) {
        printf("Invalid day\n");
        return;
    }
    
    printf("Enter hour (1-8): ");
    scanf("%d", &hour);
    
    if (hour < 1 || hour > 8) {
        printf("Invalid hour\n");
        return;
    }
    
    int doctor_id = appointment_schedule[day-1][hour-1].doctor_id;
    
    strcpy(appointment_schedule[day-1][hour-1].patient_name, "");
    appointment_schedule[day-1][hour-1].doctor_id = 0;
    appointment_schedule[day-1][hour-1].day = 0;
    appointment_schedule[day-1][hour-1].hour = 0;
    
    doctors[doctor_id-1].is_available = true;
    
    printf("Appointment cancelled!\n");
}

void view_schedule_by_day() {
    int day;
    
    printf("Enter day (1-30): ");
    scanf("%d", &day);
    
    if (day < 1 || day > 30) {
        printf("Invalid day\n");
        return;
    }
    
    printf("Schedule for day %d:\n", day);
    printf("Time     Doctor             Patient\n");
    
    for (int i = 0; i < MAX_HOURS; i++) {
        printf("%d:00 %s          %s\n", i+1, doctors[appointment_schedule[day-1][i].doctor_id-1].name, appointment_schedule[day-1][i].patient_name);
    }
}

void view_schedule_by_doctor() {
    int doctor_id;
    
    printf("Enter doctor ID (1-5): ");
    scanf("%d", &doctor_id);
    
    if (doctor_id < 1 || doctor_id > 5) {
        printf("Invalid doctor ID\n");
        return;
    }
    
    printf("Schedule for %s:\n", doctors[doctor_id-1].name);
    printf("Day      Time         Patient\n");
    
    for (int i = 0; i < MAX_DAYS; i++) {
        if (!strcmp(appointment_schedule[i][0].patient_name, "") && !strcmp(appointment_schedule[i][1].patient_name, "") && !strcmp(appointment_schedule[i][2].patient_name, "") && !strcmp(appointment_schedule[i][3].patient_name, "") && !strcmp(appointment_schedule[i][4].patient_name, "") && !strcmp(appointment_schedule[i][5].patient_name, "") && !strcmp(appointment_schedule[i][6].patient_name, "") && !strcmp(appointment_schedule[i][7].patient_name, "")) {
            continue;
        }
        
        printf("%d       ", i+1);
        
        int num_hours = 0;
        for (int j = 0; j < MAX_HOURS; j++) {
            if (appointment_schedule[i][j].doctor_id == doctor_id) {
                printf("%d:00 ", j+1);
                num_hours++;
            }
        }
        
        if (num_hours == 0) {
            continue;
        }
        
        for (int j = 0; j < MAX_HOURS; j++) {
            if (appointment_schedule[i][j].doctor_id == doctor_id) {
                printf("%s", appointment_schedule[i][j].patient_name);
                break;
            }
        }
        
        printf("\n");
    }
}

int main() {
    int choice;
    
    while (true) {
        print_menu();
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                cancel_appointment();
                break;
            case 3:
                view_schedule_by_day();
                break;
            case 4:
                view_schedule_by_doctor();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}