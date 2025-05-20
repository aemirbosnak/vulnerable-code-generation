//FormAI DATASET v1.0 Category: Smart home automation ; Style: brave
//BRAVE STYLE SMART HOME AUTOMATION EXAMPLE

#include<stdio.h>
#include<stdlib.h>

int main(){
    int time=0, light_status=0, temp, humidity;
    //Initial values of time, light and temperature
    
    printf("Welcome to the Brave Smart Home Automation Program\n\n");
    
    printf("Please enter the temperature and humidity of the room\n");
    scanf("%d%d", &temp, &humidity);
    
    //Checking if the temperature is too high
    if(temp>30){
        printf("\nWARNING: The room temperature is higher than the ideal value.\n");
    }
    
    //Checking if the humidity is too high
    if(humidity>80){
        printf("\nWARNING: The room humidity is higher than the ideal value.\n");
    }
    
    while(1){
        printf("\nPlease enter the current time in hours (24-hour format)\n");
        scanf("%d", &time);
        
        //Checking if it's morning
        if(time>=6 && time<12){
            printf("\nGood Morning! The time is %d:00 hours\n", time);
            //Turning on the lights for morning
            light_status = 1;
        }
        //Checking if it's afternoon
        else if(time>=12 && time<17){
            printf("\nGood Afternoon! The time is %d:00 hours\n", time);
            //Turning off the lights for afternoon
            light_status = 0;
        }
        //Checking if it's evening
        else if(time>=17 && time<22){
            printf("\nGood Evening! The time is %d:00 hours\n", time);
            //Turning on the lights for evening
            light_status = 1;
        }
        //Checking if it's night
        else{
            printf("\nGood Night! The time is %d:00 hours\n", time);
            //Turning on the lights for night
            light_status = 1;
        }
        
        //Checking the status of the lights
        if(light_status == 1){
            printf("\nThe lights are turned ON\n");
        }
        else{
            printf("\nThe lights are turned OFF\n");
        }
        
        //Prompt for exiting the program
        printf("\nDo you want to exit the program? Press '1' for Yes or '0' for No\n");
        int choice;
        scanf("%d", &choice);
        if(choice == 1){
            printf("\nExiting the program. Thank you for using Brave Smart Home Automation program.\n");
            exit(0);
        }
    }
    return 0;
}