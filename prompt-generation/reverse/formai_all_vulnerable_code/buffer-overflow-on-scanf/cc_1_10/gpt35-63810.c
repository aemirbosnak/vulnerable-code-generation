//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include <stdio.h>
#include <math.h>

void welcome() {
    printf("Welcome to the Surrealist Scientific Calculator!\n");
}

void menu() {
    printf("Please choose an operation:\n");
    printf("1. Calculate the square root of your dreams.\n");
    printf("2. Find the absolute value of your reality.\n");
    printf("3. Take the imaginary part of your mind.\n");
    printf("4. Exit this dimension.\n");
    printf("Your choice: ");
}

void calc_sqrt() {
    float dream;
    printf("Enter the number you dreamt of: ");
    scanf("%f", &dream);
    if (dream < 0) {
        printf("Sorry, your dream is too surreal for me to calculate.\n");
    } else {
        float root = sqrt(dream);
        printf("The square root of your dream is: %f\n", root);
    }
}

void calc_abs() {
    float reality;
    printf("Enter the reality you want to find the absolute value of: ");
    scanf("%f", &reality);
    float absolute = fabs(reality);
    printf("The absolute value of your reality is: %f\n", absolute);
}

void calc_imag() {
    float mind;
    printf("Enter the imaginary part of your mind: ");
    scanf("%f", &mind);
    float imaginary = fabs(mind);
    printf("The imaginary part of your mind is: %f\n", imaginary);
}

int main() {
    welcome();
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                calc_sqrt();
                break;
            case 2:
                calc_abs();
                break;
            case 3:
                calc_imag();
                break;
            case 4:
                printf("Goodbye, enjoy your journey to the unknown dimension.\n");
                break;
            default:
                printf("Sorry, your choice is too surreal for me to understand.\n");
        }
    } while (choice != 4);
    return 0;
}