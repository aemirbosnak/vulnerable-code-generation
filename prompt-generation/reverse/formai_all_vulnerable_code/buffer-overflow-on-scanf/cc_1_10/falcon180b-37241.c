//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_SIZE 1000

// Function to calculate the checksum of a given string
unsigned char calculate_checksum(char* str)
{
    int i, sum = 0;
    for(i=0; i<strlen(str); i++)
    {
        sum += tolower(str[i]);
    }
    return (unsigned char)(sum%256);
}

// Function to validate the checksum of a given string
int validate_checksum(char* str, unsigned char expected_checksum)
{
    unsigned char calculated_checksum = calculate_checksum(str);
    if(calculated_checksum == expected_checksum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to generate a random string of given length
void generate_random_string(char* str, int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        str[i] = rand()%26+'A';
    }
    str[length] = '\0';
}

int main()
{
    char input_string[MAX_SIZE];
    char random_string[MAX_SIZE];
    unsigned char checksum;

    // Get input string from user
    printf("Enter a string to calculate checksum: ");
    scanf("%s", input_string);

    // Calculate checksum of input string
    checksum = calculate_checksum(input_string);

    // Display the checksum
    printf("\nChecksum of '%s' is: %d\n", input_string, checksum);

    // Generate a random string of same length as input string
    generate_random_string(random_string, strlen(input_string));

    // Display the random string
    printf("\nRandom string of length %d: %s\n", strlen(input_string), random_string);

    // Validate checksum of random string
    if(validate_checksum(random_string, checksum))
    {
        printf("\nChecksum of random string '%s' is valid.\n", random_string);
    }
    else
    {
        printf("\nChecksum of random string '%s' is invalid.\n", random_string);
    }

    return 0;
}