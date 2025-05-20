//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
/* C Temperature Converter */

#include <stdio.h>

#define CELSIUS 0
#define FAHRENHEIT 1

#define C_TO_F 0
#define F_TO_C 1

float convertTemperature(float, int, int);

int main() {
    int sourceScale, targetScale;
    float sourceTemperature, targetTemperature;
    
    printf("Welcome to C Temperature Converter!\n\n");
    
    printf("Choose source temperature scale:\n"
           "0 for Celsius\n"
           "1 for Fahrenheit\n\n");
    scanf("%d", &sourceScale);
    
    printf("Input source temperature:\n");
    scanf("%f", &sourceTemperature);
    
    printf("Choose target temperature scale:\n"
           "0 for Celsius\n"
           "1 for Fahrenheit\n\n");
    scanf("%d", &targetScale);
    
    targetTemperature = convertTemperature(sourceTemperature, sourceScale, targetScale);
    
    printf("\n%.2f degrees ", sourceTemperature);
    if (sourceScale == CELSIUS) {
        printf("Celsius");
    } else {
        printf("Fahrenheit");
    }
    printf(" is equal to %.2f degrees ", targetTemperature);
    if (targetScale == CELSIUS) {
        printf("Celsius.");
    } else {
        printf("Fahrenheit.");
    }
    
    return 0;
}

float convertTemperature(float sourceTemperature, int sourceScale, int targetScale) {
    float targetTemperature;
    
    if (sourceScale == targetScale) {
        /* No conversion needed */
        targetTemperature = sourceTemperature;
    } else {
        /* Conversion needed */
        float factor = (sourceScale == CELSIUS) ? 9.0 / 5.0 : 5.0 / 9.0;
        int offset = (sourceScale == CELSIUS) ? 32 : 0;
        int direction = (sourceScale == CELSIUS) ? C_TO_F : F_TO_C;
        targetTemperature = sourceTemperature * factor + direction * offset;
    }
    
    return targetTemperature;
}