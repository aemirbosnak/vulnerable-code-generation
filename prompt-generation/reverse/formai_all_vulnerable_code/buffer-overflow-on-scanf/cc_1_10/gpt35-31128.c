//FormAI DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include<stdio.h>

int main()
{
    int units;
    char choice;
    float result;

    printf("Oh C, the ruler of all programming languages,\n\
    What unit you want to convert? Tell me now!\n");
    printf("a- Celsius to Fahrenheit.\nb- Fahrenheit to Celsius.\n");
    printf("c- Kilometers to Miles.\nd- Miles to Kilometers.\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);

    switch(choice)
    {
        case 'a':
            printf("Ah, Celsius, the measure of coldness,\n");
            printf("How many units you wish to convert?: ");
            scanf("%d", &units);
            result = (units * 9/5) + 32;
            printf("Your converted value is %f in Fahrenheit my love\n", result);
            break;

        case 'b':
            printf("Wait, you want to convert from Fahrenheit to Celsius, my Romeo?\n");
            printf("How many units you wish to convert?: ");
            scanf("%d", &units);
            result = (units - 32) * 5/9;
            printf("Your converted value is %f in Celsius, my dearest\n", result);
            break;

        case 'c':
            printf("Ah, Kilometers, the measure of distance\n");
            printf("How many units you wish to convert?: ");
            scanf("%d", &units);
            result = units / 1.609;
            printf("Your converted value is %f in Miles, my love\n", result);
            break;

        case 'd':
            printf("Ah, Miles, the measure of distance in USA\n");
            printf("How many units you wish to convert?: ");
            scanf("%d", &units);
            result = units * 1.609;
            printf("Your converted value is %f in Kilometers, my love\n", result);
            break;

        default:
            printf("Oh no! You entered something wrong. Goodbye my love\n");
            return 0;
    }

    printf("Goodbye C, the ruler of all programming languages\n");
    return 0;
}