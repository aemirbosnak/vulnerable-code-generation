//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define PI 3.14159

int main() {
    char *string1 = "The sky is blue.";
    char *string2 = "The grass is green.";
    char *string3 = "The ocean is vast.";

    double pi = PI;
    double circumference = 0;
    double area = 0;

    // Calculate the circumference of a circle using the formula C = 2πr,
    // where r is the radius of the circle.
    char radius_str[MAX_STRING_LENGTH];
    printf("Enter the radius of the circle: ");
    fgets(radius_str, MAX_STRING_LENGTH, stdin);
    double radius = atof(radius_str);
    circumference = 2 * pi * radius;

    // Calculate the area of a circle using the formula A = πr^2,
    // where r is the radius of the circle.
    char radius2_str[MAX_STRING_LENGTH];
    printf("Enter the radius of the circle again: ");
    fgets(radius2_str, MAX_STRING_LENGTH, stdin);
    radius = atof(radius2_str);
    area = pi * radius * radius;

    // Print the results.
    printf("The circumference of the circle is: %f\n", circumference);
    printf("The area of the circle is: %f\n", area);

    // Manipulate the strings using various string functions.
    char *string4 = strcat(string1, " and the sun is shining brightly.");
    char *string5 = strstr(string2, "green");
    char *string6 = strtok(string3, " ");

    // Print the modified strings.
    printf("The modified string is: %s\n", string4);
    printf("The substring 'green' is found at index %d in the string %s\n",
           (int)strcspn(string5, ""), string2);
    printf("The tokenized string is: %s\n", string6);

    return 0;
}