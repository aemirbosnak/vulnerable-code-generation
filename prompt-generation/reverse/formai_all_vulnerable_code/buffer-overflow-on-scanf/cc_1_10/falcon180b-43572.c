//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TEMP 1000

int main() {
    double temp;
    int choice;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please enter the current temperature in Celsius: ");
    scanf("%lf", &temp);

    while (1) {
        printf("\n");
        printf("1. Convert to Fahrenheit\n");
        printf("2. Convert to Kelvin\n");
        printf("3. Convert to Rankine\n");
        printf("4. Convert to Delisle\n");
        printf("5. Convert to Newton\n");
        printf("6. Convert to Romer\n");
        printf("7. Convert to Reaumur\n");
        printf("8. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temp = (temp * 9.0) / 5.0 + 32;
                printf("The temperature is %.2lf degrees Fahrenheit.\n", temp);
                break;
            case 2:
                temp += 273.15;
                printf("The temperature is %.2lf degrees Kelvin.\n", temp);
                break;
            case 3:
                temp += 459.67;
                printf("The temperature is %.2lf degrees Rankine.\n", temp);
                break;
            case 4:
                temp = (temp - 40) * 4 / 5;
                printf("The temperature is %.2lf degrees Delisle.\n", temp);
                break;
            case 5:
                temp = (temp - 32) * 5 / 9;
                printf("The temperature is %.2lf degrees Newton.\n", temp);
                break;
            case 6:
                temp = (temp - 32) * 4 / 5;
                printf("The temperature is %.2lf degrees Romer.\n", temp);
                break;
            case 7:
                temp = (temp - 32) * 4 / 9;
                printf("The temperature is %.2lf degrees Reaumur.\n", temp);
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}