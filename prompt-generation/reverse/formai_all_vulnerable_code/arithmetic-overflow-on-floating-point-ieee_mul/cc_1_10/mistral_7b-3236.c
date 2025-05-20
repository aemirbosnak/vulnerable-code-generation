//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define FUTURISTIC_TEMPERATURE_UNIT "Röntgen"
#define C_TO_R_CONVERSION_FACTOR 1.251
#define R_TO_C_CONVERSION_FACTOR 0.8

typedef struct Temperature {
    double value;
    char unit[10];
} Temperature;

void print_temperature(Temperature temp) {
    printf("The temperature is %.2f %s.\n", temp.value, temp.unit);
}

Temperature convert_c_to_r(double celsius) {
    Temperature rontgen;
    rontgen.value = celsius * C_TO_R_CONVERSION_FACTOR;
    strcpy(rontgen.unit, FUTURISTIC_TEMPERATURE_UNIT);
    return rontgen;
}

Temperature convert_r_to_c(double rontgen) {
    Temperature celsius;
    celsius.value = rontgen * R_TO_C_CONVERSION_FACTOR;
    strcpy(celsius.unit, "°C");
    return celsius;
}

int main() {
    double celsius, rontgen;

    printf("Welcome to the Futuristic Temperature Converter!\n");
    printf("Enter temperature in °C: ");
    scanf("%lf", &celsius);

    Temperature celsius_temp = {celsius, "°C"};
    Temperature rontgen_temp = convert_c_to_r(celsius);

    printf("You entered: ");
    print_temperature(celsius_temp);

    printf("Converting to Röntgen: ");
    print_temperature(rontgen_temp);

    rontgen = rontgen_temp.value;
    Temperature celsius_from_r = convert_r_to_c(rontgen);

    printf("Converting back to Celsius: ");
    print_temperature(celsius_from_r);

    return 0;
}