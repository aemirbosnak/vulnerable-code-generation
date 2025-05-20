//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 100 // maximum number of fitness records to store

typedef struct{
    char name[20];
    int age;
    float weight;
    float height;
    char gender[10];
} Person;

typedef struct{
    Person person;
    float bmi;
} FitnessRecord;

int num_records = 0;
FitnessRecord fitness_records[MAX_RECORDS];

void addRecord();
void viewRecords();
void viewStats();

int main(){
    char choice;

    while(1){
        printf("Press 'a' to add a new record\n");
        printf("Press 'v' to view all records\n");
        printf("Press 's' to view statistics\n");
        printf("Press 'q' to quit\n");
        scanf(" %c", &choice);

        switch(choice){
            case 'a':
                addRecord();
                break;
            case 'v':
                viewRecords();
                break;
            case 's':
                viewStats();
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void addRecord(){
    if(num_records == MAX_RECORDS){
        printf("Maximum number of records reached\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", fitness_records[num_records].person.name);

    printf("Enter age: ");
    scanf("%d", &fitness_records[num_records].person.age);

    printf("Enter weight in kg: ");
    scanf("%f", &fitness_records[num_records].person.weight);

    printf("Enter height in meters: ");
    scanf("%f", &fitness_records[num_records].person.height);

    printf("Enter gender (male/female): ");
    scanf("%s", fitness_records[num_records].person.gender);

    // calculate BMI
    fitness_records[num_records].bmi = fitness_records[num_records].person.weight / (fitness_records[num_records].person.height * fitness_records[num_records].person.height);

    printf("Record added successfully\n");
    num_records++;
}

void viewRecords(){
    if(num_records == 0){
        printf("No records to display\n");
        return;
    }

    printf("%-20s %-10s %-10s %-10s %s\n", "Name", "Age", "Weight", "Height", "BMI");
    for(int i = 0; i < num_records; i++){
        printf("%-20s %-10d %-10.2f %-10.2f %.2f\n", fitness_records[i].person.name, fitness_records[i].person.age, fitness_records[i].person.weight, fitness_records[i].person.height, fitness_records[i].bmi);
    }
}

void viewStats(){
    if(num_records == 0){
        printf("No records to display\n");
        return;
    }

    float avg_bmi = 0, max_bmi = 0, min_bmi = 100;

    for(int i = 0; i < num_records; i++){
        avg_bmi += fitness_records[i].bmi;

        if(fitness_records[i].bmi > max_bmi){
            max_bmi = fitness_records[i].bmi;
        }

        if(fitness_records[i].bmi < min_bmi){
            min_bmi = fitness_records[i].bmi;
        }
    }

    avg_bmi /= num_records;

    printf("Average BMI: %.2f\n", avg_bmi);
    printf("Maximum BMI: %.2f\n", max_bmi);
    printf("Minimum BMI: %.2f\n", min_bmi);
}