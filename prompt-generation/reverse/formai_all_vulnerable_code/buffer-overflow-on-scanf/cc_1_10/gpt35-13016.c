//FormAI DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>

int convertToF(int tempC);
int convertToK(int tempC);
float roundToTwoDecimals(float num);
void dismiss();
void warning();

int main() {
    printf("Welcome to the paranoid temperature converter!\n");
    printf("This program will convert Celsius to Fahrenheit and Kelvin.\n");
    printf("You may proceed, but beware of the dangers that lie ahead!\n");

    int tempC;
    printf("\nEnter the temperature in Celsius: ");
    scanf("%d", &tempC);

    if (tempC < -273) {
        warning();
        printf("\nTemperature cannot be lower than absolute zero.\n");
        return 1;
    }

    int tempF = convertToF(tempC);
    float tempK = convertToK(tempC);

    printf("\n===Results for %d degrees Celsius===\n", tempC);
    printf("Fahrenheit: %d\n", tempF);
    printf("Kelvin: %.2f\n", roundToTwoDecimals(tempK));

    dismiss();
    return 0;
}

int convertToF(int tempC) {
    return tempC * 9 / 5 + 32;
}

int convertToK(int tempC) {
    return tempC + 273.15;
}

float roundToTwoDecimals(float num) {
    return (int)(num * 100 + 0.5) / 100.0;
}

void dismiss() {
    printf("\nThank you for using the paranoid temperature converter.\n");
    printf("You may now proceed with caution.\n");
}

void warning() {
    printf("Warning! Lower than absolute zero detected!\n");
    printf("Please exercise extreme caution!\n");
}