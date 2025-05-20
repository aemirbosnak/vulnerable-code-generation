//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void show_menu() {
    printf("Welcome to the Whimsical Scientific Calculator! 🎉\n");
    printf("Here's a list of hilarious options for you to try:\n");
    printf("1. Add two numbers (+)\n");
    printf("2. Subtract two numbers (-)\n");
    printf("3. Multiply two numbers (×)\n");
    printf("4. Divide two numbers (÷)\n");
    printf("5. Square a number (²)\n");
    printf("6. Square root (√)\n");
    printf("7. Sin of an angle (in degrees) (sin)\n");
    printf("8. Cos of an angle (in degrees) (cos)\n");
    printf("9. Tan of an angle (in degrees) (tan)\n");
    printf("10. Exit (👋)\n");
    printf("Enter your choice (1-10): ");
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Oops! Dividing by zero is like trying to catch smoke! 🥴\n");
        return 0;
    }
    return a / b;
}

double square(double a) {
    return a * a;
}

double square_root(double a) {
    if (a < 0) {
        printf("You can't take the square root of a negative number in the real world! Try a positive number. 😒\n");
        return -1;
    }
    return sqrt(a);
}

double sine(double degrees) {
    return sin(degrees * M_PI / 180);
}

double cosine(double degrees) {
    return cos(degrees * M_PI / 180);
}

double tangent(double degrees) {
    return tan(degrees * M_PI / 180);
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Fine! Enter the first number: ");
                scanf("%lf", &num1);
                printf("Now, enter the second number: ");
                scanf("%lf", &num2);
                result = add(num1, num2);
                printf("Well, look at that! %lf + %lf = %lf 🎉\n", num1, num2, result);
                break;

            case 2:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = subtract(num1, num2);
                printf("Subtraction time! %lf - %lf = %lf 🤯\n", num1, num2, result);
                break;

            case 3:
                printf("It's multiplication madness! Enter the first number: ");
                scanf("%lf", &num1);
                printf("And the second number? ");
                scanf("%lf", &num2);
                result = multiply(num1, num2);
                printf("Wowza! %lf × %lf = %lf 🕺\n", num1, num2, result);
                break;

            case 4:
                printf("Division time! Enter the first number: ");
                scanf("%lf", &num1);
                printf("And the second number (don’t be a zero!): ");
                scanf("%lf", &num2);
                result = divide(num1, num2);
                if (num2 != 0) {
                    printf("Splendid! %lf ÷ %lf = %lf 🎈\n", num1, num2, result);
                }
                break;

            case 5:
                printf("Enter a number to square: ");
                scanf("%lf", &num1);
                result = square(num1);
                printf("Squaring time! %lf² = %lf 🟡\n", num1, result);
                break;

            case 6:
                printf("Enter a number to take its square root: ");
                scanf("%lf", &num1);
                result = square_root(num1);
                if (result != -1) {
                    printf("The square root of %lf is %lf 🟣\n", num1, result);
                }
                break;

            case 7:
                printf("Enter an angle (in degrees) for sine: ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Sine, oh sine! sin(%lf) = %lf 🎪\n", num1, result);
                break;

            case 8:
                printf("Enter an angle (in degrees) for cosine: ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Cosine is fine! cos(%lf) = %lf 🎠\n", num1, result);
                break;

            case 9:
                printf("Enter an angle (in degrees) for tangent: ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Tangents can be tricky! tan(%lf) = %lf 🎭\n", num1, result);
                break;

            case 10:
                printf("Thank you for using the Whimsical Scientific Calculator! Until next time! 👋\n");
                exit(0);

            default:
                printf("Oops! I think you mistyped. Try again! 🤔\n");
                break;
        }
    }
    return 0;
}