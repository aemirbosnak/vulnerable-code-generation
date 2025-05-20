//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double num, result;

    printf("WELCOME TO THE UNIT CONVERTER!\n");
    printf("Enter your choice:\n");
    printf("1. Length\n2. Weight\n3. Temperature\n4. Volume\n5. Time\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the length in meters: ");
            scanf("%lf", &num);
            printf("The length in feet is: %lf\n", num * 3.28084);
            printf("The length in inches is: %lf\n", num * 39.3701);
            printf("The length in kilometers is: %lf\n", num / 1000);
            break;
        case 2:
            printf("Enter the weight in kilograms: ");
            scanf("%lf", &num);
            printf("The weight in pounds is: %lf\n", num * 2.20462);
            printf("The weight in ounces is: %lf\n", num * 35.274);
            break;
        case 3:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &num);
            printf("The temperature in Fahrenheit is: %lf\n", (num * 9/5) + 32);
            printf("The temperature in Kelvin is: %lf\n", num + 273.15);
            break;
        case 4:
            printf("Enter the volume in liters: ");
            scanf("%lf", &num);
            printf("The volume in gallons is: %lf\n", num * 0.264172);
            printf("The volume in fluid ounces is: %lf\n", num * 33.814);
            break;
        case 5:
            printf("Enter the time in seconds: ");
            scanf("%lf", &num);
            printf("The time in minutes is: %lf\n", num / 60);
            printf("The time in hours is: %lf\n", num / 3600);
            printf("The time in days is: %lf\n", num / 86400);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}