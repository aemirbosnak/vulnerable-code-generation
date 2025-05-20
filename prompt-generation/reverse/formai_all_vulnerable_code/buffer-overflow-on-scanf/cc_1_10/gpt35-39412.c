//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include<stdio.h>
#include<string.h>

//Function to check if the entered date is valid or not
int isValidDate(int day, int month, int year) {

    if(month < 1 || month > 12)
        return 0;
    if(day < 1 || day > 31)
        return 0;
    if((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
        return 0;
    if(month == 2) {
        if(day > 29)
            return 0;
        if(year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
            if(day == 29)
                return 0;
        }
    }
    return 1;
}

//Structure for Appointment
struct Appointment {
    int day;
    int month;
    int year;
    char name[100];
    char time[10];
};

//Function to display the appointment details
void displayAppointment(struct Appointment appt) {
    printf("Appointment Details:\n");
    printf("Name: %s\n", appt.name);
    printf("Date: %02d/%02d/%04d\n", appt.day, appt.month, appt.year);
    printf("Time: %s\n", appt.time);
}

//Function to search for an appointment
void searchAppointment(struct Appointment appts[], int count) {
    printf("Enter the Appointment date (DD/MM/YYYY): ");
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);
    int found = 0;
    for(int i=0; i<count; i++) {
        if(appts[i].day == day && appts[i].month == month && appts[i].year == year) {
            displayAppointment(appts[i]);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("No appointment found for the entered date!\n");
}

//Function to add a new appointment
void addAppointment(struct Appointment appts[], int count) {
    int day, month, year;
    printf("Enter the Appointment date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);
    if(isValidDate(day, month, year) == 0) {
        printf("Invalid date entered! Please enter a valid date.\n");
        return;
    }
    for(int i=0; i<count; i++) {
        if(appts[i].day == day && appts[i].month == month && appts[i].year == year) {
            printf("An appointment already exists for the entered date! Please enter a different date.\n");
            return;
        }
    }
    struct Appointment newAppt;
    newAppt.day = day;
    newAppt.month = month;
    newAppt.year = year;
    printf("Enter the name of the person taking the appointment: ");
    scanf("%s", &newAppt.name);
    printf("Enter the time of the appointment (hh:mm AM/PM): ");
    scanf("%s", &newAppt.time);
    appts[count] = newAppt;
    printf("Appointment added successfully!\n");
}

//Function to cancel an appointment
void cancelAppointment(struct Appointment appts[], int count) {
    printf("Enter the Appointment date (DD/MM/YYYY): ");
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);
    int found = 0;
    for(int i=0; i<count; i++) {
        if(appts[i].day == day && appts[i].month == month && appts[i].year == year) {
            displayAppointment(appts[i]);
            printf("Do you want to cancel this appointment? (Y/N): ");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'Y' || choice == 'y') {
                for(int j=i; j<count-1; j++) {
                    appts[j] = appts[j+1];
                }
                count--;
                printf("Appointment cancelled successfully!\n");
                found = 1;
                break;
            }
        }
    }
    if(found == 0)
        printf("No appointment found for the entered date!\n");
}

int main() {
    printf("==================================\n");
    printf("Welcome to our Appointment Scheduler\n");
    printf("==================================\n");
    struct Appointment appts[50];
    int count = 0;
    int choice;
    do {
        printf("\nMENU\n");
        printf("====\n");
        printf("1. View all Appointments\n");
        printf("2. Search an Appointment\n");
        printf("3. Add a new Appointment\n");
        printf("4. Cancel an Appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(count == 0)
                    printf("No Appointments to display!\n");
                else {
                    printf("Showing All Appointments:\n");
                    for(int i=0; i<count; i++)
                        displayAppointment(appts[i]);
                }
                break;
            case 2:
                if(count == 0)
                    printf("No Appointments to search!\n");
                else
                    searchAppointment(appts, count);
                break;
            case 3:
                if(count == 50)
                    printf("Max Appointments reached! No more appointments can be added.\n");
                else
                    addAppointment(appts, count++);
                break;
            case 4:
                if(count == 0)
                    printf("No Appointments to cancel!\n");
                else
                    cancelAppointment(appts, count--);
                break;
            case 5:
                printf("Thank you for using our Appointment Scheduler! Goodbye.\n");
                break;
            default:
                printf("Invalid Choice! Please enter a valid choice.\n");
                break;
        }
    } while(choice != 5);
    return 0;
}