//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_LENGTH 500

typedef struct{
    char name[MAX_LENGTH];
    float (*converter)(float);
}Converter;

float celsius_to_fahrenheit(float celsius){
    return (celsius * 9.0/5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32.0) * 5.0/9.0;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

int main(){
    char input[MAX_LENGTH];
    float temperature;
    Converter converters[4] = {{"Celsius to Fahrenheit", celsius_to_fahrenheit},
                              {"Fahrenheit to Celsius", fahrenheit_to_celsius},
                              {"Kelvin to Celsius", kelvin_to_celsius},
                              {"Celsius to Kelvin", celsius_to_kelvin}};
    int choice;

    printf("Enter the temperature and its unit (e.g. 25 Celsius): ");
    scanf("%s %f", input, &temperature);

    printf("Choose the conversion type:\n");
    for(int i=0; i<4; i++){
        printf("%d. %s\n", i+1, converters[i].name);
    }

    scanf("%d", &choice);

    printf("%.2f %s is equal to %.2f %s\n", temperature, input,
           converters[choice-1].converter(temperature), converters[choice-1].name);

    return 0;
}