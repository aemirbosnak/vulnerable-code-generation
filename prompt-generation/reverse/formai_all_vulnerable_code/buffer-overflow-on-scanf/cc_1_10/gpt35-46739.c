//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>

/* this program takes a csv file of sales and calculates the total revenue by summing up the sales amount */

#define MAX_SALES 1000

/* function prototypes */
float sum(float arr[], int size);

/* main function */
int main(void)
{
    char file_name[100];
    float sales[MAX_SALES];
    float total_revenue;
    int i = 0;
    FILE *file_ptr; /* pointer to input file */

    /* get name of input file from user */
    printf("Enter the name of the input file: ");
    scanf("%s", file_name);

    /* open file */
    file_ptr = fopen(file_name, "r");
    if (file_ptr == NULL) {
        fprintf(stderr, "Error: File '%s' could not be opened\n", file_name);
        return -1;
    }

    /* read sales data from file */
    while (fscanf(file_ptr, "%f", &sales[i]) == 1) {
        i++;
    }

    /* calculate total revenue */
    total_revenue = sum(sales, i);

    /* close file */
    fclose(file_ptr);

    /* output total revenue */
    printf("Total revenue: $%.2f\n", total_revenue);

    return 0;
}

/* function to sum the values in an array */
float sum(float arr[], int size)
{
    int i;
    float result = 0.0;
    for (i = 0; i < size; i++) {
        result += arr[i];
    }
    return result;
}