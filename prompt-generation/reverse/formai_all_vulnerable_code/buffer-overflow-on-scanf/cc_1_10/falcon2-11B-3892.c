//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

void calculateTemperature(int days, float latitude, float longitude, float elevation, float sunIntensity) {
    if(days == 0) {
        printf("The temperature at the specified location is %f degrees Celsius.\n", -273.15 + (sunIntensity * elevation));
        return;
    }

    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.95);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.90);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.85);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.80);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.75);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.70);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.65);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.60);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.55);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.50);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.45);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.40);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.35);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.30);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.25);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.20);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.15);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.10);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.05);
    calculateTemperature(days - 1, latitude, longitude, elevation, sunIntensity * 0.00);
}

int main() {
    float latitude, longitude, elevation, sunIntensity;
    int days;

    printf("Enter the latitude (in degrees): ");
    scanf("%f", &latitude);

    printf("Enter the longitude (in degrees): ");
    scanf("%f", &longitude);

    printf("Enter the elevation (in meters): ");
    scanf("%f", &elevation);

    printf("Enter the sun intensity (in percentage): ");
    scanf("%f", &sunIntensity);

    printf("Enter the number of days: ");
    scanf("%d", &days);

    calculateTemperature(days, latitude, longitude, elevation, sunIntensity);

    return 0;
}