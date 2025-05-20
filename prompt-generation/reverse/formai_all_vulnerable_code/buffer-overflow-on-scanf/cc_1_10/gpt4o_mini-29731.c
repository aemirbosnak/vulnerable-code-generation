//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float calories;
    float distance; // in kilometers
} FitnessRecord;

void addRecord(FitnessRecord records[], int* count) {
    if (*count >= MAX_RECORDS) {
        printf("Record limit reached! Can't add more records.\n");
        return;
    }
    
    printf("Enter your name: ");
    scanf("%s", records[*count].name);
    
    printf("Enter steps taken: ");
    scanf("%d", &records[*count].steps);
    
    printf("Enter calories burned: ");
    scanf("%f", &records[*count].calories);
    
    printf("Enter distance covered (in km): ");
    scanf("%f", &records[*count].distance);
    
    (*count)++;
    printf("Record added successfully!\n");
}

void viewRecords(FitnessRecord records[], int count) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("\nFitness Records:\n");
    printf("-----------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Steps", "Calories", "Distance");
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f %-10.2f\n", 
               records[i].name, 
               records[i].steps, 
               records[i].calories, 
               records[i].distance);
    }
    printf("-----------------------------------------------------\n");
}

void totalSummary(FitnessRecord records[], int count) {
    if (count == 0) {
        printf("No records to summarize.\n");
        return;
    }
    
    int totalSteps = 0;
    float totalCalories = 0.0, totalDistance = 0.0;
    
    for (int i = 0; i < count; i++) {
        totalSteps += records[i].steps;
        totalCalories += records[i].calories;
        totalDistance += records[i].distance;
    }
    
    printf("\nTotal Summary:\n");
    printf("-----------------------------------------------------\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Calories burned: %.2f\n", totalCalories);
    printf("Total Distance covered: %.2f km\n", totalDistance);
    printf("-----------------------------------------------------\n");
}

void saveRecords(FitnessRecord records[], int count) {
    FILE *file = fopen("fitness_records.txt", "w");
    
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f %.2f\n",
                records[i].name,
                records[i].steps,
                records[i].calories,
                records[i].distance);
    }
    
    fclose(file);
    printf("Records saved to fitness_records.txt successfully!\n");
}

void loadRecords(FitnessRecord records[], int* count) {
    FILE *file = fopen("fitness_records.txt", "r");
    
    if (file == NULL) {
        printf("No previous records found.\n");
        return;
    }
    
    while (fscanf(file, "%s %d %f %f", 
                  records[*count].name, 
                  &records[*count].steps, 
                  &records[*count].calories, 
                  &records[*count].distance) == 4) {
        (*count)++;
        if (*count >= MAX_RECORDS) break;
    }
    
    fclose(file);
    printf("Records loaded successfully!\n");
}

int main() {
    FitnessRecord records[MAX_RECORDS];
    int recordCount = 0;
    int choice;

    loadRecords(records, &recordCount);
    
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Total Summary\n");
        printf("4. Save Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(records, &recordCount);
                break;
            case 2:
                viewRecords(records, recordCount);
                break;
            case 3:
                totalSummary(records, recordCount);
                break;
            case 4:
                saveRecords(records, recordCount);
                break;
            case 5:
                printf("Exiting the fitness tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}