//FormAI DATASET v1.0 Category: Calculator ; Style: complex
#include<stdio.h>
#include<stdlib.h>

//Structure to hold complex numbers
struct Complex
{
    double real;
    double imag;
};

//Function to add two complex numbers
struct Complex add(struct Complex c1, struct Complex c2)
{
    struct Complex res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

//Function to subtract two complex numbers
struct Complex subtract(struct Complex c1, struct Complex c2)
{
    struct Complex res;
    res.real = c1.real - c2.real;
    res.imag = c1.imag - c2.imag;
    return res;
}

//Function to multiply two complex numbers
struct Complex multiply(struct Complex c1, struct Complex c2)
{
    struct Complex res;
    res.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    res.imag = (c1.real * c2.imag) + (c2.real * c1.imag);
    return res;
}

//Function to divide two complex numbers
struct Complex divide(struct Complex c1, struct Complex c2)
{
    struct Complex res;
    double den = (c2.real * c2.real) + (c2.imag * c2.imag);
    res.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / den;
    res.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / den;
    return res;
}

//Function to display a complex number
void display(struct Complex c)
{
    if(c.imag >= 0)
        printf("%.2lf + %.2lfi\n", c.real, c.imag);
    else
        printf("%.2lf - %.2lfi\n", c.real, -c.imag);
}

int main()
{
    struct Complex c1, c2, c3;
    int choice;

    do
    {
        printf("Enter the real and imaginary parts of complex number 1: ");
        scanf("%lf %lf", &c1.real, &c1.imag);

        printf("Enter the real and imaginary parts of complex number 2: ");
        scanf("%lf %lf", &c2.real, &c2.imag);

        printf("\n---Complex Calculator---\n");
        printf("1. Add two complex numbers\n");
        printf("2. Subtract two complex numbers\n");
        printf("3. Multiply two complex numbers\n");
        printf("4. Divide two complex numbers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: c3 = add(c1, c2);
                    printf("Result: ");
                    display(c3);
                    break;

            case 2: c3 = subtract(c1, c2);
                    printf("Result: ");
                    display(c3);
                    break;

            case 3: c3 = multiply(c1, c2);
                    printf("Result: ");
                    display(c3);
                    break;

            case 4: c3 = divide(c1, c2);
                    printf("Result: ");
                    display(c3);
                    break;

            case 5: printf("Exiting...\n");
                    exit(0);
                    break;

            default: printf("Invalid choice\n");
        }

    }while(choice != 5);

    return 0;
}