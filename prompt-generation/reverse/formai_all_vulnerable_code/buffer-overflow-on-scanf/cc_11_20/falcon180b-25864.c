//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

int main() {
    double distance, time, speed;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select the unit you want to convert:\n");
    printf("1. Distance\n");
    printf("2. Time\n");
    printf("3. Speed\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Please enter the distance in meters: ");
            scanf("%lf", &distance);

            printf("Please select the unit you want to convert to:\n");
            printf("1. Feet\n");
            printf("2. Yards\n");
            printf("3. Miles\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("%.2lf meters is equal to %.2lf feet.\n", distance, distance * 3.28084);
                    break;
                case 2:
                    printf("%.2lf meters is equal to %.2lf yards.\n", distance, distance / 0.9144);
                    break;
                case 3:
                    printf("%.2lf meters is equal to %.2lf miles.\n", distance, distance / 1609.34);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        case 2:
            printf("Please enter the time in seconds: ");
            scanf("%lf", &time);

            printf("Please select the unit you want to convert to:\n");
            printf("1. Minutes\n");
            printf("2. Hours\n");
            printf("3. Days\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("%.2lf seconds is equal to %.2lf minutes.\n", time, time / 60);
                    break;
                case 2:
                    printf("%.2lf seconds is equal to %.2lf hours.\n", time, time / 3600);
                    break;
                case 3:
                    printf("%.2lf seconds is equal to %.2lf days.\n", time, time / 86400);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        case 3:
            printf("Please enter the speed in meters per second: ");
            scanf("%lf", &speed);

            printf("Please select the unit you want to convert to:\n");
            printf("1. Kilometers per hour\n");
            printf("2. Miles per hour\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("%.2lf meters per second is equal to %.2lf kilometers per hour.\n", speed, speed / 3.6);
                    break;
                case 2:
                    printf("%.2lf meters per second is equal to %.2lf miles per hour.\n", speed, speed / 2.237);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}