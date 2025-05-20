//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define INITIAL_TEMP 20
#define MAX_TEMP 50
#define MIN_TEMP 10
#define THRESHOLD 5

void get_temp(int *temp) {
    printf("Enter current temperature (in Celsius): ");
    scanf("%d", temp);
}

int is_valid_temp(int temp) {
    return (temp >= MIN_TEMP && temp <= MAX_TEMP)? TRUE : FALSE;
}

void print_menu() {
    printf("\n");
    printf("1. Monitor temperature\n");
    printf("2. Adjust threshold\n");
    printf("3. Exit\n");
    printf("\n");
}

void monitor_temp(int threshold) {
    int temp;
    get_temp(&temp);
    if (is_valid_temp(temp)) {
        if (temp >= INITIAL_TEMP + threshold) {
            printf("Temperature is too high! Current temperature: %d\n", temp);
        } else if (temp <= INITIAL_TEMP - threshold) {
            printf("Temperature is too low! Current temperature: %d\n", temp);
        } else {
            printf("Current temperature: %d\n", temp);
        }
    } else {
        printf("Invalid temperature value!\n");
    }
}

void adjust_threshold() {
    int threshold;
    printf("Enter new threshold: ");
    scanf("%d", &threshold);
    if (threshold >= THRESHOLD) {
        printf("New threshold set to %d\n", threshold);
    } else {
        printf("Invalid threshold value!\n");
    }
}

int main() {
    int choice, threshold = THRESHOLD;
    while (TRUE) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            monitor_temp(threshold);
            break;
        case 2:
            adjust_threshold();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}