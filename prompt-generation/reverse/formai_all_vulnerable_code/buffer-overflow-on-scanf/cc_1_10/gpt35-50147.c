//FormAI DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>

float cel_to_fahr(float celsius);
float fahr_to_cel(float fahrenheit);
float m_to_km(float meters);
float km_to_m(float kilometers);
float lbs_to_kg(float pounds);
float kg_to_lbs(float kilograms);

int main(){

    float celsius, fahrenheit, meters, kilometers, pounds, kilograms;

    printf("Celsius to Fahrenheit converter\n");
    printf("Enter temperature in Celsius : ");
    scanf("%f", &celsius);

    fahrenheit = cel_to_fahr(celsius);

    printf("\n%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);

    printf("\n\nFahrenheit to Celsius converter\n");
    printf("Enter temperature in Fahrenheit : ");
    scanf("%f", &fahrenheit);

    celsius = fahr_to_cel(fahrenheit);

    printf("\n%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);

    printf("\n\nMeters to Kilometers converter\n");
    printf("Enter length in meters : ");
    scanf("%f", &meters);

    kilometers = m_to_km(meters);

    printf("\n%.2f meters = %.2f kilometers", meters, kilometers);

    printf("\n\nKilometers to Meters converter\n");
    printf("Enter length in kilometers : ");
    scanf("%f", &kilometers);

    meters = km_to_m(kilometers);

    printf("\n%.2f kilometers = %.2f meters", kilometers, meters);

    printf("\n\nPounds to Kilograms converter\n");
    printf("Enter weight in pounds : ");
    scanf("%f", &pounds);

    kilograms = lbs_to_kg(pounds);

    printf("\n%.2f pounds = %.2f kilograms", pounds, kilograms);

    printf("\n\nKilograms to Pounds converter\n");
    printf("Enter weight in kilograms : ");
    scanf("%f", &kilograms);

    pounds = kg_to_lbs(kilograms);

    printf("\n%.2f kilograms = %.2f pounds", kilograms, pounds);

    return 0;
}

float cel_to_fahr(float celsius){
    return ((9*celsius)/5)+32;
}

float fahr_to_cel(float fahrenheit){
    return (5*(fahrenheit-32))/9;
}

float m_to_km(float meters){
    return meters/1000;
}

float km_to_m(float kilometers){
    return kilometers*1000;
}

float lbs_to_kg(float pounds){
    return pounds*0.453592;
}

float kg_to_lbs(float kilograms){
    return kilograms*2.20462;
}