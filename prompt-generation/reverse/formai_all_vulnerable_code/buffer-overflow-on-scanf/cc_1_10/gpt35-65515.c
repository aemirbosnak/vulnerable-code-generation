//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[20];
    char phone_no[11];
    int age;
    char gender;
    char appointment_time[10];
} Patient;

void add_patient(Patient *patients, int *num_patients);
void show_patients(Patient *patients, int num_patients);
void remove_patient(Patient *patients, int *num_patients);

int main(){
    Patient *patients;
    int num_patients = 0;
    int menu_choice;

    while(1){
        printf("\nWelcome to the Appointment Scheduler! What would you like to do?\n");
        printf("1. Add a patient\n");
        printf("2. Show all patients\n");
        printf("3. Remove a patient\n");
        printf("4. Exit\n");

        scanf("%d",&menu_choice);

        switch(menu_choice){
            case 1:
                add_patient(patients, &num_patients);
                break;
            case 2:
                show_patients(patients, num_patients);
                break;
            case 3:
                remove_patient(patients, &num_patients);
                break;
            case 4:
                printf("\nThanks for using the Appointment Scheduler!\n");
                free(patients);
                return 0;
            default:
                printf("\nInvalid input, please try again.\n");
                break;
        }
    }

    return 0;
}

void add_patient(Patient *patients, int *num_patients){
    if(*num_patients == 0){
        patients = (Patient*) malloc(sizeof(Patient));
    }
    else{
        patients = (Patient*) realloc(patients,(*num_patients+1)*sizeof(Patient));
    }

    printf("\nEnter patient name: ");
    scanf("%s", patients[*num_patients].name);
    printf("Enter patient phone number: ");
    scanf("%s", patients[*num_patients].phone_no);
    printf("Enter patient age: ");
    scanf("%d", &patients[*num_patients].age);
    printf("Enter patient gender [M/F/O]: ");
    scanf(" %c", &patients[*num_patients].gender);
    printf("Enter preferred appointment time: ");
    scanf("%s", patients[*num_patients].appointment_time);

    (*num_patients)++;
    printf("\nPatient added successfully!\n");
}

void show_patients(Patient *patients, int num_patients){
    if(num_patients == 0){
        printf("\nNo patients added yet!\n");
    }
    else{
        printf("\nList of patients:\n");
        for(int i=0;i<num_patients;i++){
            printf("Name: %s\n",patients[i].name);
            printf("Phone Number: %s\n",patients[i].phone_no);
            printf("Age: %d\n",patients[i].age);
            printf("Gender: %c\n",patients[i].gender);
            printf("Preferred Appointment Time: %s\n",patients[i].appointment_time);
            printf("----------------------------------\n");
        }
    }
}

void remove_patient(Patient *patients, int *num_patients){
    if(*num_patients == 0){
        printf("\nNo patients to remove!\n");
        return;
    }

    printf("\nEnter the name of the patient to remove: ");
    char name[20];
    scanf("%s", name);

    int found_patient = 0;
    for(int i=0;i<*num_patients;i++){
        if(strcmp(name,patients[i].name) == 0){
            found_patient = 1;

            for(int j=i;j<*num_patients-1;j++){
                strcpy(patients[j].name,patients[j+1].name);
                strcpy(patients[j].phone_no,patients[j+1].phone_no);
                patients[j].age = patients[j+1].age;
                patients[j].gender = patients[j+1].gender;
                strcpy(patients[j].appointment_time,patients[j+1].appointment_time);
            }

            (*num_patients)--;
            patients = (Patient*) realloc(patients,(*num_patients)*sizeof(Patient));

            printf("\nPatient removed successfully!\n");
            break;
        }
    }

    if(found_patient == 0){
        printf("\nPatient not found!\n");
    }
}