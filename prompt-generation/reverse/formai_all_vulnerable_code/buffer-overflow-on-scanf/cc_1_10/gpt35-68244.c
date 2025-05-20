//FormAI DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>  
#include <stdlib.h>  

void lightOn(void);  
void lightOff(void);  
void acOn(void);  
void acOff(void);  

int main()  
{  
    int choice;  
    printf("\n*************Welcome to Smart Home Automation***************");
    
    while(1)  
    {  
        printf("\n\n\nPlease enter your choice 1/2/3/4:\n");  
        printf("1. Turn Lights on/off\n2. Turn AC on/off\n3. Set Temperature\n4. Exit\n");  
        scanf("%d",&choice);  
        
        switch(choice)  
        {  
            case 1:  
                {  
                    printf("\n\nEnter 1 to turn the lights on, 0 to turn them off: ");  
                    int lightChoice;  
                    scanf("%d", &lightChoice);  
                    if (lightChoice == 1)  
                        lightOn();  
                    else if (lightChoice == 0)  
                        lightOff();  
                    else  
                        printf("\nInvalid choice");  
                    break;  
                }  
            case 2:  
                {  
                    printf("\n\nEnter 1 to turn the AC on, 0 to turn it off: ");  
                    int acChoice;  
                    scanf("%d", &acChoice);  
                    if (acChoice == 1)  
                        acOn();  
                    else if (acChoice == 0)  
                        acOff();  
                    else  
                        printf("\nInvalid choice");  
                    break;  
                }  
            case 3:  
                {  
                    printf("\n\nEnter the desired temperature in Celsius: ");  
                    float temp;  
                    scanf("%f", &temp);  
                    if (temp >= 30)  
                        printf("\nWarning, high temperature!");  
                    else if (temp <= 15)  
                        printf("\nWarning, low temperature!");  
                    else  
                        printf("\nTemperature set to %.2f degrees Celsius", temp);  
                    break;  
                }  
            case 4:  
                {  
                    printf("\n\nExiting program...");  
                    exit(0);  
                }  
            default:  
                {  
                    printf("\n\nInvalid choice");  
                    break;  
                }  
        }  
    }  
}  

void lightOn()  
{  
    printf("\nLights turned on");  
}  

void lightOff()  
{  
    printf("\nLights turned off");  
}  

void acOn()  
{  
    printf("\nAC turned on");  
}  

void acOff()  
{  
    printf("\nAC turned off");  
}