//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int choice;
    float temperature, average, sum = 0, highest, lowest;
    time_t start_time, end_time;
    struct tm *local_time;
    char time_string[30];

    printf("Welcome to the Happy Temperature Monitor!\n");
    printf("Please choose an option:\n");
    printf("1. Enter a temperature\n");
    printf("2. Display current temperature\n");
    printf("3. Display average temperature\n");
    printf("4. Display highest temperature\n");
    printf("5. Display lowest temperature\n");
    printf("6. Exit\n");

    scanf("%d", &choice);

    while (choice!= 6) {
        switch (choice) {
            case 1:
                printf("Enter the temperature: ");
                scanf("%f", &temperature);
                printf("Temperature recorded: %.2f\n", temperature);
                sum += temperature;
                break;
            case 2:
                printf("Current temperature: %.2f\n", temperature);
                break;
            case 3:
                if (sum == 0) {
                    printf("No temperatures recorded.\n");
                } else {
                    average = sum / (float) sum;
                    printf("Average temperature: %.2f\n", average);
                }
                break;
            case 4:
                if (sum == 0) {
                    printf("No temperatures recorded.\n");
                } else {
                    highest = temperature;
                    printf("Highest temperature: %.2f\n", highest);
                }
                break;
            case 5:
                if (sum == 0) {
                    printf("No temperatures recorded.\n");
                } else {
                    lowest = temperature;
                    printf("Lowest temperature: %.2f\n", lowest);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
    }

    time(&start_time);
    local_time = localtime(&start_time);
    strftime(time_string, 30, "%Y-%m-%d %H:%M:%S", local_time);
    printf("\nProgram ended on: %s\n", time_string);

    return 0;
}