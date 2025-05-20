//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP_RECORDS 100

typedef struct {
    char date[20];
    float temperature;
} temp_record;

void display_menu() {
    printf("Temperature Monitor\n");
    printf("--------------------\n");
    printf("1. Add temperature record\n");
    printf("2. View all temperature records\n");
    printf("3. Exit\n");
}

void add_temperature_record(temp_record temp_records[], int *count) {
    temp_record temp;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", temp.date);

    printf("Enter temperature: ");
    scanf("%f", &temp.temperature);

    temp_records[*count] = temp;
    (*count)++;

    printf("Temperature record added successfully!\n");
}

void view_all_temperature_records(temp_record temp_records[], int count) {
    if (count == 0) {
        printf("No temperature records found.\n");
        return;
    }

    printf("%-15s %-10s\n", "Date", "Temperature");
    printf("----------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-15s %-10.2f\n", temp_records[i].date, temp_records[i].temperature);
    }
}

int main() {
    temp_record temp_records[MAX_TEMP_RECORDS];
    int count = 0;

    while (1) {
        display_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_temperature_record(temp_records, &count);
                break;
            case 2:
                view_all_temperature_records(temp_records, count);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}