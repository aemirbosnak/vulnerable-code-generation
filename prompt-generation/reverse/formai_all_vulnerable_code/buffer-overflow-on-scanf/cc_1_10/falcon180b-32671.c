//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_HISTORY 100

struct Temperature {
    time_t timestamp;
    double temperature;
};

struct Temperature temp_history[MAX_TEMP_HISTORY];
int temp_history_index = 0;

void add_temperature(double temp) {
    struct Temperature new_temp = { time(NULL), temp };
    temp_history[temp_history_index++] = new_temp;
    if (temp_history_index >= MAX_TEMP_HISTORY) {
        temp_history_index = 0;
    }
}

void print_temperature_history() {
    printf("Temperature History:\n");
    for (int i = 0; i < MAX_TEMP_HISTORY; i++) {
        if (temp_history[i].timestamp!= 0) {
            printf("%s - %.2f\n", ctime(&temp_history[i].timestamp), temp_history[i].temperature);
        }
    }
}

int main() {
    double temp = 0.0;
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Add Temperature\n");
        printf("2. Print Temperature History\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter temperature: ");
                scanf("%lf", &temp);
                add_temperature(temp);
                printf("Temperature added successfully.\n");
                break;
            case 2:
                print_temperature_history();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);
    return 0;
}