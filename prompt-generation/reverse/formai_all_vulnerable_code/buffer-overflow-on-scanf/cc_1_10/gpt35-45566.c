//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h> 

/* This function will take a decimal number and 
   convert it into a hexadecimal number */
void decToHex(int dec_num) 
{ 
    char hexadecimal[20]; 
    int i = 0, remainder; 

    while(dec_num != 0) 
    {    
        remainder = dec_num % 16;

        /* If remainder is less than 10, then add 48 
         * to get the ASCII value of the number */
        if(remainder < 10) 
        { 
            hexadecimal[i] = remainder + 48; 
            i++; 
        } 
        else /* If the remainder is greater than 10, then add 55 
              * to get the ASCII value of the number */
        { 
            hexadecimal[i] = remainder + 55; 
            i++; 
        } 

        /* Divide the number by 16 to get the next digit */
        dec_num = dec_num / 16; 
    } 

    /* Print the hexadecimal number in reverse order */
    printf("The hexadecimal equivalent is: "); 
    for(i = i - 1; i >= 0; i--) 
        printf("%c", hexadecimal[i]);     
} 

int main() 
{ 
    int dec_num; 
    
    /* Greet the user with a message */
    printf("Welcome to our happy hexadecimal converter program! "); 
    
    /* Ask the user to enter a decimal number */
    printf("Please enter a decimal number: "); 
    scanf("%d", &dec_num); 

    /* Call the function to convert decimal number to hexadecimal */
    decToHex(dec_num); 

    /* Happy farewell message! */
    printf("\nThank you for using our happy hexadecimal converter program! Have a nice day! "); 

    return 0; 
}