//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>

/* Function declarations */
int calculate_checksum(int num_array[], int len_array);
int sum_digits(int num);
void display_checksum(int num);

/* Main function */
int main()
{
    /* Initializing variables */
    int num_array[10], len_array, i;

    /* Taking user input for the length of the array */
    printf("Enter the length of the array (maximum 10): ");
    scanf("%d", &len_array);

    /* Taking user input for the array elements */
    printf("Enter the array elements: ");
    for(i=0; i<len_array; i++)
    {
        scanf("%d", &num_array[i]);
    }

    /* Calling calculate_checksum function to get the result */
    int checksum = calculate_checksum(num_array, len_array);

    /* Displaying the result */
    display_checksum(checksum);

    return 0;
}

/* Function to calculate the checksum */
int calculate_checksum(int num_array[], int len_array)
{
    /* Initializing variables */
    int i, sum=0;

    /* Looping through the array elements */
    for(i=0; i<len_array; i++)
    {
        /* Calculating the sum of digits for each element */
        sum += sum_digits(num_array[i]);
    }

    /* Calculating the final checksum */
    int checksum = ((sum * 10) % 97);

    return checksum;
}

/* Function to calculate the sum of digits*/
int sum_digits(int num)
{
    /* Initializing variables */
    int sum=0, digit;

    /* Looping through the digits of the number */
    while(num > 0)
    {
        /* Getting the last digit */
        digit = num % 10;

        /* Adding the digit to the sum */
        sum += digit;

        /* Removing the last digit from the number */
        num /= 10;
    }

    return sum;
}

/* Function to display the checksum */
void display_checksum(int num)
{
    printf("The checksum is %d", num);
}