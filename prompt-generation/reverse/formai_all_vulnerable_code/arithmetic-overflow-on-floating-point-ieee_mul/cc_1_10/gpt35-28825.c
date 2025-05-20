//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
// C Scientific Calculator with Shape-Shifting feature
#include <stdio.h>
#include <math.h>

// Function to calculate the square
float square(float num) {
    return num * num;
}

// Function to calculate the square root
float squareRoot(float num) {
    return sqrt(num);
}

// Function to calculate the cube
float cube(float num) {
    return num * num * num;
}

// Function to calculate the absolute value
float absoluteValue(float num) {
    return fabs(num);
}

// Function to calculate the sine
float sine(float num) {
    return sin(num);
}

// Function to calculate the cosine
float cosine(float num) {
    return cos(num);
}

// Function to calculate the tangent
float tangent(float num) {
    return tan(num);
}

int main() {
    float num, result;
    int choice;

    while (1) {
        printf("\n------------- Shape-Shifting Scientific Calculator -------------\n");
        printf("\n(1) Square \t (2) Square Root \t (3) Cube \n(4) Absolute Value \t (5) Sine \t\t (6) Cosine \n(7) Tangent \t (8) Quit \n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 8) {
            printf("\nGoodbye!\n");
            break;
        }

        printf("Enter a number: ");
        scanf("%f", &num);

        // Shape-Shifting feature
        switch (choice) {
            case 1:
                result = square(num);
                printf("\nThe square of %.2f is: %.2f\n", num, result);
                break;
            case 2:
                result = squareRoot(num);
                printf("\nThe square root of %.2f is: %.2f\n", num, result);
                break;
            case 3:
                result = cube(num);
                printf("\nThe cube of %.2f is: %.2f\n", num, result);
                break;
            case 4:
                result = absoluteValue(num);
                printf("\nThe absolute value of %.2f is: %.2f\n", num, result);
                break;
            case 5:
                result = sine(num);
                printf("\nThe sine of %.2f is: %.2f\n", num, result);
                break;
            case 6:
                result = cosine(num);
                printf("\nThe cosine of %.2f is: %.2f\n", num, result);
                break;
            case 7:
                result = tangent(num);
                printf("\nThe tangent of %.2f is: %.2f\n", num, result);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}