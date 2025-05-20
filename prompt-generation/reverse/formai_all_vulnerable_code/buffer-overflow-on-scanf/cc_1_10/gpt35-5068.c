//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>

int main(void) {

// Puzzling Unit Converter

printf("Welcome to the PUZZLING UNIT CONVERTER! \n\n");
printf("Choose a Conversion Option: \n\n");
printf("1. Mysterious Length Converter \n");
printf("2. Cryptic Temperature Converter \n");
printf("3. Enigmatic Volume Converter \n\n");

int option;
printf("Enter your selection: ");
scanf("%d", &option);

if (option == 1) {

    float length;
    printf("\nEnter Length in Mysterious Units: ");
    scanf("%f", &length);

    // Mysterious to Normal length conversion math formula (Puzzle)
    float normalLength = length * 3.14 + 0.0052;

    printf("\n%f Mysterious Units is equivalent to %f Normal Units.\n", length, normalLength);

} else if (option == 2) {

    float temperature;
    printf("\nEnter Temperature in Cryptic Units: ");
    scanf("%f", &temperature);

    // Cryptic to Celsius temperature conversion math formula (Puzzle)
    float celsius = (temperature - 297.15) / 2.7182;

    printf("\n%f Cryptic Units is equivalent to %f Degrees Celsius.\n", temperature, celsius);

} else if (option == 3) {

    float volume;
    printf("\nEnter Volume in Enigmatic Units: ");
    scanf("%f", &volume);

    // Enigmatic to Normal volume conversion math formula (Puzzle)
    float normalVolume = volume / 1.618;

    printf("\n%f Enigmatic Units is equivalent to %f Normal Units.\n", volume, normalVolume);

} else {

    printf("\nInvalid Selection. Please choose a valid option (1, 2 or 3).\n");

}

return 0;
}