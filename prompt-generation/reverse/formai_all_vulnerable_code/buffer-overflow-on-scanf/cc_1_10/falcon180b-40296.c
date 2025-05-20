//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>

// This function converts a number from one unit to another
double convert(double num, char from_unit, char to_unit) {
    if(from_unit =='m' && to_unit == 'ft') {
        return num * 3.28084; // metres to feet
    }
    else if(from_unit == 'ft' && to_unit =='m') {
        return num / 3.28084; // feet to metres
    }
    else if(from_unit == 'kg' && to_unit == 'lb') {
        return num * 2.20462; // kilograms to pounds
    }
    else if(from_unit == 'lb' && to_unit == 'kg') {
        return num / 2.20462; // pounds to kilograms
    }
    else if(from_unit == 'c' && to_unit == 'f') {
        return (num * 9/5) + 32; // celsius to fahrenheit
    }
    else if(from_unit == 'f' && to_unit == 'c') {
        return (num - 32) * 5/9; // fahrenheit to celsius
    }
    else {
        printf("Invalid conversion units!\n");
        return 0;
    }
}

// This function recursively converts a number from one unit to another
double recursive_convert(double num, char from_unit, char to_unit) {
    // Base case: if the units are the same, return the number
    if(from_unit == to_unit) {
        return num;
    }
    // Recursive case: convert the number to the base unit and then to the desired unit
    else {
        double base_num = num / 1000; // convert to base unit
        return recursive_convert(base_num,'m', to_unit) * 1000; // convert to desired unit
    }
}

int main() {
    double num, result;
    char from_unit, to_unit;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%lf", &num);
    printf("Enter the current unit (m/kg/c): ");
    scanf(" %c", &from_unit);
    printf("Enter the desired unit (m/kg/c/f): ");
    scanf(" %c", &to_unit);

    // Convert the number using the recursive function
    result = recursive_convert(num, from_unit, to_unit);

    // Display the result
    printf("The converted value is: %.2lf %c\n", result, to_unit);

    return 0;
}