//FormAI DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

int main()
{
    int choice1, choice2;
    float input, output;
    printf("***Unit Converter***\n");
    printf("Choose the input unit:\n");
    printf("1. Centimeters\n2. Meters\n3. Kilometers\n");
    scanf("%d", &choice1);

    printf("Enter the value:");
    scanf("%f", &input);

    printf("Choose the output unit:\n");
    printf("1. Centimeters\n2. Meters\n3. Kilometers\n");
    scanf("%d", &choice2);

    switch(choice1)
    {
        case 1:
            switch(choice2)
            {
                case 1:
                {
                    output = input;
                    printf("%.2f centimeters = %.2f centimeters\n", input, output);
                    break;
                }

                case 2:
                {
                    output = input / 100;
                    printf("%.2f centimeters = %.2f meters\n", input, output);
                    break;
                }

                case 3:
                {
                    output = input / 100000;
                    printf("%.2f centimeters = %.2f kilometers\n", input, output);
                    break;
                }

                default: printf("Wrong choice!\n");
            }
            break;

        case 2:
            switch(choice2)
            {
                case 1:
                {
                    output = input * 100;
                    printf("%.2f meters = %.2f centimeters\n", input, output);
                    break;
                }

                case 2:
                {
                    output = input;
                    printf("%.2f meters = %.2f meters\n", input, output);
                    break;
                }

                case 3:
                {
                    output = input / 1000;
                    printf("%.2f meters = %.2f kilometers\n", input, output);
                    break;
                }

                default: printf("Wrong choice!\n");
            }
            break;

        case 3:
            switch(choice2)
            {
                case 1:
                {
                    output = input * 100000;
                    printf("%.2f kilometers = %.2f centimeters\n", input, output);
                    break;
                }

                case 2:
                {
                    output = input * 1000;
                    printf("%.2f kilometers = %.2f meters\n", input, output);
                    break;
                }

                case 3:
                {
                    output = input;
                    printf("%.2f kilometers = %.2f kilometers\n", input, output);
                    break;
                }

                default: printf("Wrong choice!\n");
            }
            break;

        default: printf("Wrong choice!\n");
    }
    return 0;
}