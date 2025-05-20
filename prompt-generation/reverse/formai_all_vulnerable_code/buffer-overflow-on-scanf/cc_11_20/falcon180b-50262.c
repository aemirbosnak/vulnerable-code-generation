//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TEMP 1000

int main(void) {
    float temp;
    char unit;
    int choice;

    do {
        printf("Enter temperature and unit (e.g. 25C): ");
        scanf("%f%c", &temp, &unit);

        if (unit!= 'C' && unit!= 'F') {
            printf("Invalid unit.\n");
            continue;
        }

        if (temp < -MAX_TEMP || temp > MAX_TEMP) {
            printf("Temperature out of range.\n");
            continue;
        }

        printf("Convert from %c to:\n", unit);
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        printf("4. Rankine\n");
        printf("5. Delisle\n");
        printf("6. Newton\n");
        printf("7. Réaumur\n");
        printf("8. Rømer\n");
        printf("9. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("%.2fC = %.2fK\n", temp, temp + 273.15);
                break;
            case 2:
                printf("%.2fC = %.2fF\n", temp, (temp * 9.0 / 5.0) + 32.0);
                break;
            case 3:
                printf("%.2fC = %.2fK\n", temp, temp);
                break;
            case 4:
                printf("%.2fC = %.2fR\n", temp, (temp * 9.0 / 5.0) + 32.0);
                break;
            case 5:
                printf("%.2fC = %.2f°D\n", temp, (temp * 3.0 / 2.0));
                break;
            case 6:
                printf("%.2fC = %.2f°N\n", temp, temp - 32.0);
                break;
            case 7:
                printf("%.2fC = %.2f°Ré\n", temp, (temp * 4.0 / 5.0));
                break;
            case 8:
                printf("%.2fC = %.2f°Rø\n", temp, (temp * 7.0 / 4.0));
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 9);

    return 0;
}