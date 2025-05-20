//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[50];
    int age;
    float weight;
    float height;
    float BMI;
} fitnessRecord;

fitnessRecord records[MAX_RECORDS];
int numRecords = 0;

bool addRecord(int id, char *name, int age, float weight, float height);
bool updateRecord(int id, float weight, float height);
int searchRecord(int id);
void calculateBMI(int i);

int main() {
    int choice = 0;
    int id;
    char name[50];
    int age;
    float weight, height;
    while (true) {
        printf("Select operation:\n");
        printf("1. Add record\n");
        printf("2. Update record\n");
        printf("3. Search record\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter weight (in kg): ");
                scanf("%f", &weight);
                printf("Enter height (in meters): ");
                scanf("%f", &height);
                if (addRecord(id, name, age, weight, height)) {
                    printf("Record added successfully!\n");
                } else {
                    printf("Record not added. Maximum limit reached!\n");
                }
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter new weight (in kg): ");
                scanf("%f", &weight);
                printf("Enter new height (in meters): ");
                scanf("%f", &height);
                if (updateRecord(id, weight, height)) {
                    printf("Record updated successfully!\n");
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                int index = searchRecord(id);
                if (index != -1) {
                    printf("Record found!\n");
                    printf("ID: %d\n", records[index].id);
                    printf("Name: %s\n", records[index].name);
                    printf("Age: %d\n", records[index].age);
                    printf("Weight: %.2f kg\n", records[index].weight);
                    printf("Height: %.2f meters\n", records[index].height);
                    printf("BMI: %.2f\n", records[index].BMI);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}

bool addRecord(int id, char *name, int age, float weight, float height) {
    if (numRecords == MAX_RECORDS) {
        return false;
    }
    fitnessRecord record = {id, "", age, weight, height, 0.0f};
    calculateBMI(numRecords);
    records[numRecords++] = record;
    return true;
}

bool updateRecord(int id, float weight, float height) {
    int index = searchRecord(id);
    if (index == -1) {
        return false;
    }
    records[index].weight = weight;
    records[index].height = height;
    calculateBMI(index);
    return true;
}

int searchRecord(int id) {
    int i;
    for (i = 0; i < numRecords; ++i) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1;
}

void calculateBMI(int i) {
    records[i].BMI = records[i].weight / (records[i].height * records[i].height);
}