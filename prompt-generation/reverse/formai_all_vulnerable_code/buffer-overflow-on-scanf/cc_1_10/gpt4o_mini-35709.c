//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

void display_menu() {
    printf("\nTemperature Monitor Menu:\n");
    printf("1. Add a temperature reading\n");
    printf("2. Display all readings\n");
    printf("3. Calculate average temperature\n");
    printf("4. Find maximum temperature\n");
    printf("5. Find minimum temperature\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    float temperatures[MAX_ENTRIES];
    int count = 0;
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (count < MAX_ENTRIES) {
                    printf("Enter temperature (in Celsius): ");
                    scanf("%f", &temperatures[count]);
                    count++;
                    printf("Temperature added!\n");
                } else {
                    printf("Maximum entries reached. Can't add more temperatures!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No temperature readings available.\n");
                } else {
                    printf("\nTemperature Readings:\n");
                    for (int i = 0; i < count; i++) {
                        printf("%.2f °C\n", temperatures[i]);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("No temperature readings to calculate average.\n");
                } else {
                    float sum = 0;
                    for (int i = 0; i < count; i++) {
                        sum += temperatures[i];
                    }
                    printf("Average Temperature: %.2f °C\n", sum / count);
                }
                break;

            case 4:
                if (count == 0) {
                    printf("No temperature readings to find maximum.\n");
                } else {
                    float max_temp = temperatures[0];
                    for (int i = 1; i < count; i++) {
                        if (temperatures[i] > max_temp) {
                            max_temp = temperatures[i];
                        }
                    }
                    printf("Maximum Temperature: %.2f °C\n", max_temp);
                }
                break;

            case 5:
                if (count == 0) {
                    printf("No temperature readings to find minimum.\n");
                } else {
                    float min_temp = temperatures[0];
                    for (int i = 1; i < count; i++) {
                        if (temperatures[i] < min_temp) {
                            min_temp = temperatures[i];
                        }
                    }
                    printf("Minimum Temperature: %.2f °C\n", min_temp);
                }
                break;

            case 6:
                printf("Exiting the Temperature Monitor. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }

    return 0;
}