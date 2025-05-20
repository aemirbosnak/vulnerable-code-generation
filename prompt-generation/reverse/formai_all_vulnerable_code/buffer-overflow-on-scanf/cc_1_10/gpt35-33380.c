//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* medieval_hash(char* string) // function to generate medieval hash
{
    char* hash = (char*)malloc(sizeof(char) * 40); // allocate memory for hash
    
    int i, j, length, sum = 0, product = 1, ascii_val = 0, count = 0;
    
    length = strlen(string);
    
    for(i=0; i<length; i++)
    {
        ascii_val = (int)string[i]; // convert the current character to its ASCII value
        sum = sum + ascii_val; // calculate the sum of ASCII values
        product = product * ascii_val; // calculate the product of ASCII values
    }
    
    sprintf(hash, "%d", sum+product); // concatenate sum and product to generate the hash
    
    for(i=0; hash[i] != '\0'; i++) // loop through the hash
    {
        if((int)hash[i] >= 97 && (int)hash[i] <= 122) // convert all lowercase letters to uppercase
            hash[i] = (char)((int)hash[i] - 32);
        
        if((int)hash[i] >= 48 && (int)hash[i] <= 57) // convert all digits to roman numerals
        {
            count = (int)hash[i] - 48;
            j = 0;
            
            while(j < count) // loop through to convert the digit to its roman numeral equivalent
            {
                strcat(hash, "I");
                j++;
            }
            
            hash[i] = '\0'; // remove the digit from the hash
            i--; // move back one character to compensate for the removed digit
        }
    }
    
    return hash; // return the medieval hash
}

int main()
{
    char string[100];
    char* hash;
    
    printf("Enter a string to generate a medieval hash: ");
    scanf("%s", string);
    
    hash = medieval_hash(string);
    
    printf("The medieval hash of %s is: %s\n", string, hash);
    
    free(hash); // free the allocated memory
    
    return 0;
}