//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <math.h>

void invasive_unit_converter(void)
{
    float imperial_measurement, metric_measurement;
    int choice;

    printf("Please select an option:\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert kilograms to pounds\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number of meters:");
            scanf("%f", &metric_measurement);
            imperial_measurement = metric_measurement * 3.28084;
            printf("The number of feet is: %.2f\n", imperial_measurement);
            break;

        case 2:
            printf("Enter the number of liters:");
            scanf("%f", &metric_measurement);
            imperial_measurement = metric_measurement * 1.05669;
            printf("The number of gallons is: %.2f\n", imperial_measurement);
            break;

        case 3:
            printf("Enter the number of kilograms:");
            scanf("%f", &metric_measurement);
            imperial_measurement = metric_measurement * 2.20462;
            printf("The number of pounds is: %.2f\n", imperial_measurement);
            break;

        default:
            printf("Invalid option\n");
            break;
    }

    return;
}

int main()
{
    invasive_unit_converter();

    return 0;
}