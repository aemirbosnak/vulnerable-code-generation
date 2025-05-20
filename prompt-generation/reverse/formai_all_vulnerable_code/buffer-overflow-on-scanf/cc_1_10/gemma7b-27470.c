//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch;
    float f, t, k;
    int y;
    FILE *fp;

    fp = fopen("temperature.txt", "w");
    fprintf(fp, "Welcome to the Temperature Converter!\n");
    fprintf(fp, "Please choose an option:\n");
    fprintf(fp, "1. Fahrenheit to Celsius\n");
    fprintf(fp, "2. Celsius to Fahrenheit\n");
    fprintf(fp, "3. Kelvin to Fahrenheit\n");
    fprintf(fp, "4. Fahrenheit to Kelvin\n");

    scanf(" %c", &ch);

    switch (ch)
    {
        case '1':
            printf("Enter the Fahrenheit temperature: ");
            scanf(" %f", &f);
            t = (f - 32) * 5 / 9;
            fprintf(fp, "The Celsius temperature is: %.2f\n", t);
            break;
        case '2':
            printf("Enter the Celsius temperature: ");
            scanf(" %f", &t);
            f = (t * 9 / 5) + 32;
            fprintf(fp, "The Fahrenheit temperature is: %.2f\n", f);
            break;
        case '3':
            printf("Enter the Kelvin temperature: ");
            scanf(" %f", &k);
            t = k - 273.15;
            fprintf(fp, "The Celsius temperature is: %.2f\n", t);
            break;
        case '4':
            printf("Enter the Fahrenheit temperature: ");
            scanf(" %f", &f);
            k = (f - 32) * 5 / 9 + 273.15;
            fprintf(fp, "The Kelvin temperature is: %.2f\n", k);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    fclose(fp);
    return 0;
}