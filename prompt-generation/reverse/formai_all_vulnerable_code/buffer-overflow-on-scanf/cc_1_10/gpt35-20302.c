//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

double deg_to_rad(double x)
{
    return x*PI/180;
}

double rad_to_deg(double x)
{
    return x/PI*180;
}

double sin_func(double x)
{
    double rad_val = deg_to_rad(x);
    return sin(rad_val);
}

double cos_func(double x)
{
    double rad_val = deg_to_rad(x);
    return cos(rad_val);
}

double tan_func(double x)
{
    double rad_val = deg_to_rad(x);
    return tan(rad_val);
}

double log_func(double x)
{
    return log10(x);
}

double ln_func(double x)
{
    return log(x);
}

int main()
{
    printf("Welcome to the ultraprecise scientific calculator!\n");

    int choice;
    double x;

    while(1){
        printf("\nMenu:\n");
        printf("1) Sin\n");
        printf("2) Cos\n");
        printf("3) Tan\n");
        printf("4) Log\n");
        printf("5) Ln\n");
        printf("6) Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 6){
            printf("Thank you for using the ultraprecise scientific calculator!\n");
            break;
        }
        else if(choice < 1 || choice > 5){
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter value of x: ");
        scanf("%lf", &x);

        if(choice == 1){
            printf("sin(%lf) = %lf\n", x, sin_func(x));
        }
        else if(choice == 2){
            printf("cos(%lf) = %lf\n", x, cos_func(x));
        }
        else if(choice == 3){
            printf("tan(%lf) = %lf\n", x, tan_func(x));
        }
        else if(choice == 4){
            printf("log(%lf) = %lf\n", x, log_func(x));
        }
        else if(choice == 5){
            printf("ln(%lf) = %lf\n", x, ln_func(x));
        }
    }

    return 0;
}