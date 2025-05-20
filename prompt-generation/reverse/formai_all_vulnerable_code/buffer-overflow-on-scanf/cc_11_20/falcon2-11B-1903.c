//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <math.h>

int main() {
    float distance, speed, time;
    char unit1, unit2;

    printf("Enter the distance (in kilometers): ");
    scanf("%f", &distance);

    printf("Enter the speed (in kilometers per hour): ");
    scanf("%f", &speed);

    printf("Enter the time (in hours): ");
    scanf("%f", &time);

    printf("Enter the unit of the distance (k or m): ");
    scanf(" %c", &unit1);

    printf("Enter the unit of the speed (k/h or m/s): ");
    scanf(" %c", &unit2);

    float distance_km, speed_kmph, time_hours;
    if (unit1 == 'k' && unit2 == 'k') {
        distance_km = distance;
        speed_kmph = speed;
    } else if (unit1 == 'k' && unit2 == 'h') {
        distance_km = distance * 0.001;
        speed_kmph = speed / 3600.0;
    } else if (unit1 == 'k' && unit2 =='s') {
        distance_km = distance * 0.001;
        speed_kmph = speed / 3600.0;
    } else if (unit1 =='m' && unit2 == 'k') {
        distance_km = distance * 0.001;
        speed_kmph = speed / 3600.0;
    } else if (unit1 =='m' && unit2 == 'h') {
        distance_km = distance * 1000.0;
        speed_kmph = speed / 3600.0;
    } else if (unit1 =='m' && unit2 =='s') {
        distance_km = distance * 1000.0;
        speed_kmph = speed / 3600.0;
    } else {
        printf("Invalid input\n");
        return 0;
    }

    float time_sec = time * 3600.0;
    float distance_meters = distance_km * 1000.0;
    float speed_mps = speed_kmph * 1000.0 / 3600.0;

    printf("The distance in meters is %.2f\n", distance_meters);
    printf("The speed in meters per second is %.2f\n", speed_mps);
    printf("The time in seconds is %.2f\n", time_sec);

    return 0;
}