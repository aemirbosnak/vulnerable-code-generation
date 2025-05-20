//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the size of the array
#define SIZE 10

int main() {

    // Define file pointer
    FILE *fp;

    // Open file for writing
    fp = fopen("numbers.txt", "w");

    // Write numbers 1-10 to file
    for (int i = 1; i <= SIZE; i++) {
        fprintf(fp, "%d\n", i);
    }

    // Close file
    fclose(fp);

    // Open file for reading
    fp = fopen("numbers.txt", "r");

    // Initialize variables for calculations
    int sum = 0;
    int product = 1;

    // Read each number from file and calculate sum and product
    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
        product *= num;
    }

    // Close file
    fclose(fp);

    // Calculate the average of the numbers
    double average = (double)sum / SIZE;

    // Calculate the standard deviation of the numbers
    fp = fopen("numbers.txt", "r");
    double variance = 0;
    while (fscanf(fp, "%d", &num) == 1) {
        variance += pow(num - average, 2);
    }
    double std_dev = sqrt(variance / (SIZE - 1));
    fclose(fp);

    // Print results
    printf("The sum of the numbers is: %d\n", sum);
    printf("The product of the numbers is: %d\n", product);
    printf("The average of the numbers is: %f\n", average);
    printf("The standard deviation of the numbers is: %f\n", std_dev);

    return 0;
}