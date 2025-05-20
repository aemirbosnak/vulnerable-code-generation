//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURES 1000

typedef struct {
    time_t timestamp;
    double temperature;
} Temperature;

void record_temperature(Temperature *temperatures, int index, double temp) {
    if (index >= MAX_TEMPERATURES - 1) {
        printf("Temperature buffer is full.\n");
        return;
    }
    temperatures[index].timestamp = time(NULL);
    temperatures[index].temperature = temp;
    printf("Recorded temperature: %.2f\n", temp);
}

void display_temperatures(Temperature *temperatures, int start_index, int end_index) {
    printf("Displaying temperatures from index %d to %d:\n", start_index, end_index);
    for (int i = start_index; i <= end_index; i++) {
        printf("%.2f at %s\n", temperatures[i].temperature, ctime(&temperatures[i].timestamp));
    }
}

int main() {
    Temperature temperatures[MAX_TEMPERATURES];
    int index = 0;
    char choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Record temperature\n");
        printf("2. Display temperatures\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter temperature: ");
                double temp = 0.0;
                if (scanf("%lf", &temp) == 1) {
                    record_temperature(temperatures, index, temp);
                    index++;
                } else {
                    printf("Invalid temperature.\n");
                }
                break;
            case '2':
                printf("Enter start index: ");
                int start_index = 0;
                if (scanf("%d", &start_index) == 1 && start_index < index) {
                    printf("Enter end index: ");
                    int end_index = index - 1;
                    if (scanf("%d", &end_index) == 1 && end_index >= start_index) {
                        display_temperatures(temperatures, start_index, end_index);
                    } else {
                        printf("Invalid end index.\n");
                    }
                } else {
                    printf("Invalid start index.\n");
                }
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}