//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main()
{
    char input_string[50], output_string[50];
    int choice, string_length, i;
    
    printf("Enter a string: ");
    scanf("%s", input_string); //Get input string from user
    
    string_length = strlen(input_string); //Calculate string length
    
    printf("Choose an operation:\n1. Convert string to uppercase\n2. Convert string to lowercase\n3. Reverse the string\n");
    scanf("%d", &choice); //Get user's choice
    
    switch(choice)
    {
        case 1: //Convert string to uppercase
            for(i=0; i<string_length; i++)
            {
                if(input_string[i] >= 'a' && input_string[i] <= 'z')
                {
                    output_string[i] = input_string[i] - 32; //Convert lowercase letters to uppercase
                }
                else
                {
                    output_string[i] = input_string[i];
                }
            }
            output_string[i] = '\0'; //Add null character to end of string
            printf("The uppercase string is: %s", output_string);
            break;
        
        case 2: //Convert string to lowercase
            for(i=0; i<string_length; i++)
            {
                if(input_string[i] >= 'A' && input_string[i] <= 'Z')
                {
                    output_string[i] = input_string[i] + 32; //Convert uppercase letters to lowercase
                }
                else
                {
                    output_string[i] = input_string[i];
                }
            }
            output_string[i] = '\0'; //Add null character to end of string
            printf("The lowercase string is: %s", output_string);
            break;
        
        case 3: //Reverse the string
            for(i=0; i<string_length; i++)
            {
                output_string[i] = input_string[string_length-i-1]; //Copy characters one by one in reverse order
            }
            output_string[i] = '\0'; //Add null character to end of string
            printf("The reversed string is: %s", output_string);
            break;
        
        default: //Invalid choice
            printf("Invalid choice.\n");
    }
    
    return 0;
}