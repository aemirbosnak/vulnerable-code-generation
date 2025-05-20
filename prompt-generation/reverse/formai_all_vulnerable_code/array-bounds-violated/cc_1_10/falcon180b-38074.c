//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RAD_TO_DEG 57.29577951308232087680
#define DEG_TO_RAD 0.01745329251994329576923

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double length_convert(double value) {
    return value;
}

double weight_convert(double value) {
    return value;
}

double volume_convert(double value) {
    return value;
}

double temperature_convert(double value) {
    return (value * 9.0 / 5.0) + 32.0;
}

double angle_convert(double value) {
    return value * RAD_TO_DEG;
}

double speed_convert(double value) {
    return value;
}

double time_convert(double value) {
    return value;
}

Unit units[] = {
    {"meters", length_convert},
    {"feet", length_convert},
    {"kilograms", weight_convert},
    {"pounds", weight_convert},
    {"liters", volume_convert},
    {"gallons", volume_convert},
    {"celsius", temperature_convert},
    {"fahrenheit", temperature_convert},
    {"radians", angle_convert},
    {"degrees", angle_convert},
    {"meters per second", speed_convert},
    {"kilometers per hour", speed_convert},
    {"seconds", time_convert},
    {"minutes", time_convert}
};

int main(int argc, char *argv[]) {
    printf("Welcome to the Medieval Unit Converter!\n");
    printf("Please select the unit you wish to convert:\n");
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    int choice;
    scanf("%d", &choice);
    double value, result;
    printf("Enter the value you wish to convert:\n");
    scanf("%lf", &value);
    printf("Converting %lf %s to ", value, units[choice - 1].name);
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (i!= choice - 1) {
            result = units[i].convert(value);
            printf("%s (%lf) ", units[i].name, result);
        }
    }
    printf("\n");
    return 0;
}