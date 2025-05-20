//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define Max_name_size 50
#define Appointment_slots 10

struct appointment {
    char name[Max_name_size];
    char date[20];
    char time[10];
    int id;
};

void create_appointment(struct appointment* a) {
    printf("Enter Name: ");
    scanf("%s",a->name);
    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s",a->date);
    printf("Enter Time (HH:MM): ");
    scanf("%s",a->time);
    a->id = rand()%1000 + 1;
}

void display_appointments(struct appointment a[], int n) {
    printf("ID\tName\tDate\tTime\n");
    for(int i=0;i<n;i++) {
        printf("%d\t%s\t%s\t%s\n",a[i].id,a[i].name,a[i].date,a[i].time);
    }
}

void delete_appointment(struct appointment a[], int* n, int id) {
    int found = 0;
    for(int i=0;i<*n;i++) {
        if(a[i].id == id) {
            found = 1;
            for(int j=i;j<(*n)-1;j++) {
                a[j] = a[j+1];
            }
            (*n)--;
            break;
        }
    }
    if(found == 0) {
        printf("Appointment not found.\n");
    }
    else {
        printf("Appointment with ID %d has been deleted successfully!\n", id);
    }
}

void search_appointment(struct appointment a[], int n, char name[]) {
    int found = 0;
    printf("ID\tName\tDate\tTime\n");
    for(int i=0;i<n;i++) {
        if(strcmp(name,a[i].name) == 0) {
            printf("%d\t%s\t%s\t%s\n",a[i].id,a[i].name,a[i].date,a[i].time);
            found = 1;
        }
    }
    if(found == 0) {
        printf("No appointments found for the given name.\n");
    }
}

void clear_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    struct appointment appointment_list[Appointment_slots];
    int option, num_appointment = 0;
    
    while(1) {
        printf("\n");
        printf("Appointment Scheduler\n");
        printf("----------------------\n");
        printf("1. Create Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Search Appointment\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        
        switch(option) {
            case 1: if(num_appointment == Appointment_slots) {
                        printf("Sorry, the maximum number of appointments have been reached.\n");
                    }
                    else {
                        create_appointment(&appointment_list[num_appointment]);
                        num_appointment++;
                    }
                    clear_buffer();
                    break;
            
            case 2: if(num_appointment == 0) {
                        printf("No Appointments found.\n");
                    }
                    else {
                        display_appointments(appointment_list, num_appointment);
                    }
                    break;
                    
            case 3: if(num_appointment == 0) {
                        printf("No Appointments found.\n");
                    }
                    else {
                        int id;
                        printf("Enter the ID of the appointment to be deleted: ");
                        scanf("%d",&id);
                        delete_appointment(appointment_list, &num_appointment, id);
                    }
                    clear_buffer();
                    break;
                    
            case 4: if(num_appointment == 0) {
                        printf("No Appointments found.\n");
                    }
                    else {
                        char name[Max_name_size];
                        printf("Enter name to search: ");
                        clear_buffer();
                        fgets(name,Max_name_size,stdin);
                        if(name[strlen(name)-1] == '\n') {
                            name[strlen(name)-1] = '\0';
                        }
                        search_appointment(appointment_list, num_appointment, name);
                    }
                    break;
            
            case 5: printf("Exiting program.\n");
                    exit(0);
                    break;
                    
            default: printf("Invalid option. Please try again.\n");
                     clear_buffer();
                     break;
        }
    }
    return 0;
}