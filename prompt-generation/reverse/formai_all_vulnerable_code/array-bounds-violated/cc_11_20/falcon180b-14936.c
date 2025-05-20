//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main() {
    int i, j, n, m, sum = 0, count = 0;
    char str[100];
    double x, y, z;
    time_t t;

    // generate a random string of length n
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[n] = '\0';

    // prompt the user to enter the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // prompt the user to enter the value of m
    printf("Enter the value of m: ");
    scanf("%d", &m);

    // prompt the user to enter the string
    printf("Enter the string: ");
    scanf("%s", str);

    // count the number of vowels in the string
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }

    // calculate the sum of the first n odd numbers
    for (i = 1; i <= n; i++) {
        sum += (2 * i - 1);
    }

    // calculate the factorial of n
    for (i = 1; i <= n; i++) {
        if (i == 1) {
            x = 1;
        } else {
            x *= i;
        }
    }

    // calculate the power of m
    for (i = 1; i <= m; i++) {
        y = pow(2, i);
        z += y;
    }

    // print the results
    printf("The sum of the first %d odd numbers is: %d\n", n, sum);
    printf("The factorial of %d is: %f\n", n, x);
    printf("The power of %d is: %f\n", m, z);
    printf("The number of vowels in the string is: %d\n", count);

    return 0;
}