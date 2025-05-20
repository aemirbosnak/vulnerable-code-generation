//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>  //For sleep() function

//Function to display the current status of traffic light
void displayStatus(int red, int yellow, int green){
    printf("\nRed Light Status: %d seconds", red);
    printf("\nYellow Light Status: %d seconds", yellow);
    printf("\nGreen Light Status: %d seconds\n", green);
}

int main(){
    //Initial status of traffic light
    int red = 10, yellow = 2, green = 10;
    int option;
    
    printf("\nWelcome to Traffic Light Controller System");
    displayStatus(red, yellow, green);
    
    //Menu for user to select different options
    while(1){
        printf("\nPlease choose one of the following options:\n");
        printf("1. Increase Red Light Time.\n");
        printf("2. Increase Green Light Time.\n");
        printf("3. Increase Yellow Light Time.\n");
        printf("4. Decrease Red Light Time.\n");
        printf("5. Decrease Green Light Time.\n");
        printf("6. Decrease Yellow Light Time.\n");
        printf("7. Display Current Traffic Light Status.\n");
        printf("8. Exit\n");
        
        printf("\nEnter your option: ");
        scanf("%d", &option);
        
        switch(option){
            //Increase Red Light Time
            case 1: red++;
                    displayStatus(red, yellow, green);
                    break;
            
            //Increase Green Light Time
            case 2: green++;
                    displayStatus(red, yellow, green);
                    break;
            
            //Increase Yellow Light Time
            case 3: yellow++;
                    displayStatus(red, yellow, green);
                    break;
            
            //Decrease Red Light Time
            case 4: red--;
                    if(red < 0) red = 0;  //To prevent negative time
                    displayStatus(red, yellow, green);
                    break;
            
            //Decrease Green Light Time
            case 5: green--;
                    if(green<0) green = 0;
                    displayStatus(red, yellow, green);
                    break;
            
            //Decrease Yellow Light Time
            case 6: yellow--;
                    if(yellow<0) yellow = 0;
                    displayStatus(red, yellow, green);
                    break;
            
            //Display Current Traffic Light Status
            case 7: displayStatus(red, yellow, green);
                    break;
            
            //Exit
            case 8: printf("\nThank you for using Traffic Light Controller System\n");
                    exit(0);
                    break;
            
            //Invalid Option
            default: printf("\nInvalid Option. Please choose a valid option.\n");
                     break;
        }
        //Delay of 1 second after each option selection
        sleep(1);
    }
    return 0;
}