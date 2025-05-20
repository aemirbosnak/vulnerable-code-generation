//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main() {
    int i, j;
    char str[100];
    double num;
    FILE *fp;
    struct tm *tm;
    time_t t;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    scanf("%s", str);

    // Calculate the length of the string
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            printf("The length of the string is %d\n", i + 1);
            break;
        }
    }

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%lf", &num);

    // Calculate the square of the number
    printf("The square of %.2lf is %.2lf\n", num, num * num);

    // Open a file for reading
    fp = fopen("data.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    // Read the data from the file
    while (fscanf(fp, "%lf", &num)!= EOF) {
        printf("%.2lf ", num);
    }

    // Close the file
    fclose(fp);

    // Get the current date and time
    time(&t);
    tm = localtime(&t);

    // Print the date and time
    printf("\nCurrent date and time: %s\n", asctime(tm));

    return 0;
}