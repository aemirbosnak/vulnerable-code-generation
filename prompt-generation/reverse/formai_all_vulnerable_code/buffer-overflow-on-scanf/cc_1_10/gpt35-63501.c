//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include<stdio.h>

// Function to calculate checksum recursively
int calculateChecksum(int num)
{
    int digit = 0, sum = 0, rem = 0;
    
    while(num > 0)
    {
        // Separating the last digit from the number
        digit = num % 10;
        
        // Adding the digit to the sum
        sum += digit;
        
        // Removing the last digit from the number
        num /= 10;
    }
    
    // If the sum has only one digit
    if(sum < 10)
    {
        return sum;
    }
    
    // If the sum has more than one digit
    else
    {
        // Recursively calculating the checksum
        rem = calculateChecksum(sum);
        
        // Returning the final checksum
        return rem;
    }
}

int main()
{
    int num, checksum;
    
    printf("Enter a number: ");
    scanf("%d",&num);
    
    // Calculating the checksum
    checksum = calculateChecksum(num);
    
    printf("The checksum of %d is: %d", num, checksum);
    
    return 0;
}