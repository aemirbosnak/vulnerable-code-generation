//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 

char *temp2cryptic(float temp);  
float cryptic2temp(char *cryptic_temp);

int main()  
{  
    char *cryptic_result;
    char cryptic_temp[30];  
    float temperature;  
    int choice;  

    printf("Welcome to the Cryptic Temperature Converter! \n");  
    printf("Select an option: \n");  
    printf("1. Convert Celsius to Cryptic\n");  
    printf("2. Convert Cryptic to Celsius\n");  
    scanf("%d", &choice);  

    switch(choice)  
    {  
        /* Celsius to Cryptic conversion */
        case 1:  
            printf("\nEnter temperature in Celsius: ");  
            scanf("%f", &temperature);  

            /* call function to convert temperature to cryptic */
            cryptic_result = temp2cryptic(temperature);  

            printf("Temperature in cryptic: %s\n", cryptic_result);  
            break;  

        /* Cryptic to Celsius conversion */  
        case 2:  
            printf("\nEnter temperature in cryptic: ");  
            scanf("%s", cryptic_temp);  

            /* call function to convert cryptic to temperature */
            temperature = cryptic2temp(cryptic_temp);  

            printf("Temperature in Celsius: %.2f\n", temperature);  
            break;  

        default:  
            printf("Invalid choice. Please try again.\n");  
            break;  
    }  
    return 0;  
}  

/* function to convert temperature to cryptic */
char *temp2cryptic(float temp)  
{  
    char *result = (char *)malloc(50*sizeof(char));  

    /* cryptic formula */
    float cryptic_temp = (temp * 3.1415) + 1529;  

    /* convert cryptic temperature to string */
    sprintf(result, "%.4f w@", cryptic_temp);   

    return result;  
}  

/* function to convert cryptic to temperature */
float cryptic2temp(char *cryptic_temp)  
{  
    /* keep only numeric characters */
    char temp[30];
    int j = 0;
    for(int i = 0; i < strlen(cryptic_temp); i++){
        if(cryptic_temp[i] >= '0' && cryptic_temp[i] <= '9'){
            temp[j] = cryptic_temp[i];
            j++;
        }
    }
    temp[j] = '\0';

    /* convert string to float */
    float result;
    sscanf(temp, "%f", &result);

    /* inverse cryptic formula */
    result = (result - 1529) / 3.1415;

    return result;  
}