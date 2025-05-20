//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int i, j, n, m, sum = 0, count = 0;
    double x, y, z, avg;
    char str[100];

    // Prompt user for two integers and calculate their sum
    printf("Enter two integers: ");
    scanf("%d %d", &n, &m);
    sum = n + m;
    printf("The sum of %d and %d is %d\n", n, m, sum);

    // Prompt user for a string and reverse it
    printf("Enter a string: ");
    scanf("%s", str);
    for (i = strlen(str) - 1, j = 0; i >= 0; i--, j++)
        str[j] = str[i];
    printf("The reversed string is: %s\n", str);

    // Prompt user for a number and calculate its square
    printf("Enter a number: ");
    scanf("%lf", &x);
    y = x * x;
    printf("The square of %lf is %lf\n", x, y);

    // Prompt user for an array of integers and calculate their average
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    avg = (double)sum / n;
    printf("The average of the array is %lf\n", avg);

    // Prompt user for a number and generate a random number between 0 and the input number
    srand(time(NULL));
    printf("Enter a number: ");
    scanf("%d", &n);
    int rand_num = rand() % n;
    printf("The random number between 0 and %d is %d\n", n, rand_num);

    // Prompt user for a number and calculate its factorial
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 1, count = 0; i <= n; i++) {
        count++;
        if (count == n)
            break;
    }
    printf("The factorial of %d is %d\n", n, count);

    // Prompt user for a number and calculate its cube
    printf("Enter a number: ");
    scanf("%lf", &x);
    y = x * x * x;
    printf("The cube of %lf is %lf\n", x, y);

    // Prompt user for a number and calculate its square root
    printf("Enter a number: ");
    scanf("%lf", &x);
    y = sqrt(x);
    printf("The square root of %lf is %lf\n", x, y);

    return 0;
}