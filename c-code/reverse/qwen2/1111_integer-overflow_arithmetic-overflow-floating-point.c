#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

double celsiusToGalactic(double celsius) {
    return celsius * 1.5;
}

double galacticToCelsius(double galactic) {
    return galactic / 1.5;
}

int main() {
    int choice;
    double temp;

    while (1) {
        printf("Temperature Converter\n");
        printf("1. Celsius to Galactic\n");
        printf("2. Galactic to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        printf("Enter temperature: ");
        scanf("%lf", &temp);

        switch (choice) {
            case 1:
                printf("%.2f Celsius is %.2f Galactic\n", temp, celsiusToGalactic(temp));
                break;
            case 2:
                printf("%.2f Galactic is %.2f Celsius\n", temp, galacticToCelsius(temp));
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
