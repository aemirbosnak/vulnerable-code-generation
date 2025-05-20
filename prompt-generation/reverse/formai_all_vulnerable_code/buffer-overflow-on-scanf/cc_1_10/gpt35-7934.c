//FormAI DATASET v1.0 Category: Unit converter ; Style: modular
#include<stdio.h>
//Functions for different unit conversions
float celToFahr(float celsius){
    return((celsius * 9/5) + 32);
}
float fahrToCel(float fahrenheit){
    return((fahrenheit - 32) * 5/9);
}
float celToKel(float celsius){
    return(celsius + 273.15);
}

float kelToCel(float kelvin){
    return(kelvin - 273.15);
}
float fahrToKel(float fahrenheit){
    float celsius = fahrToCel(fahrenheit);
    return(celToKel(celsius));
}
float kelToFahr(float kelvin){
    float celsius = kelToCel(kelvin);
    return(celToFahr(celsius));
}
//Main Function
int main(){
    int choice;
    float temperature, temp_converted;
    printf("Choose an option to convert temperature:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    scanf("%d", &choice);
    printf("Enter temperature: ");
    scanf("%f", &temperature);
    switch(choice){
        case 1: 
            temp_converted = celToFahr(temperature);
            printf("%.2fC is equal to %.2fF", temperature, temp_converted);
            break;
        case 2:
            temp_converted = fahrToCel(temperature);
            printf("%.2fF is equal to %.2fC", temperature, temp_converted);
            break;
        case 3:
            temp_converted = celToKel(temperature);
            printf("%.2fC is equal to %.2fK", temperature, temp_converted);
            break;
        case 4:
            temp_converted = kelToCel(temperature);
            printf("%.2fK is equal to %.2fC", temperature, temp_converted);
            break;
        case 5:
            temp_converted = fahrToKel(temperature);
            printf("%.2fF is equal to %.2fK", temperature, temp_converted);
            break;
        case 6:
            temp_converted = kelToFahr(temperature);
            printf("%.2fK is equal to %.2fF", temperature, temp_converted);
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}