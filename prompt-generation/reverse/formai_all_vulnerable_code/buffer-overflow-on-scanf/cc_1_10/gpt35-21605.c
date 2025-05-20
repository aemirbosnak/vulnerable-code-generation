//FormAI DATASET v1.0 Category: Unit converter ; Style: decentralized
#include<stdio.h>

// Function to convert Celsius to Fahrenheit
float CtoF(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float FtoC(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Kilometers to Miles
float KtoM(float kilometers) {
    return kilometers / 1.609;
}

// Function to convert Miles to Kilometers
float MtoK(float miles) {
    return miles * 1.609;
}

int main() {
    int option;
    float input, output;

    printf("Choose an option:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Kilometers to Miles\n4. Miles to Kilometers\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            output = CtoF(input);
            printf("%.2f Celsius = %.2f Fahrenheit", input, output);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = FtoC(input);
            printf("%.2f Fahrenheit = %.2f Celsius", input, output);
            break;
        case 3:
            printf("Enter distance in Kilometers: ");
            scanf("%f", &input);
            output = KtoM(input);
            printf("%.2f Kilometers = %.2f Miles", input, output);
            break;
        case 4:
            printf("Enter Distance in Miles: ");
            scanf("%f", &input);
            output = MtoK(input);
            printf("%.2f Miles = %.2f Kilometers", input, output);
            break;
        default:
            printf("Invalid Option");
            break;
    }

    return 0;
}