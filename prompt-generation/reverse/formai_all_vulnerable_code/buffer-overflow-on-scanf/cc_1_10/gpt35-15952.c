//FormAI DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lightState = 0; // 0 means OFF, 1 means ON
int temp = 15;

void turnOnLight()
{
    if (lightState == 0)
    {
        printf("Turning ON the light\n");
        lightState = 1;
    }
}

void turnOffLight()
{
    if (lightState == 1)
    {
        printf("Turning OFF the light\n");
        lightState = 0;
    }
}

void increaseTemp()
{
    if (temp < 30)
    {
        printf("Increasing temperature by 1 degree\n");
        temp++;
        if(temp == 30){
            printf("Maximum temperature reached\n");
        }
    }
    else{
        printf("Maximum temperature reached\n");
    }
}

void decreaseTemp()
{
    if(temp > 15){
        printf("Decreasing temperature by 1 degree\n");
        temp--;
        if(temp == 15){
            printf("Minimum temperature reached\n");
        }
    }
    else{
        printf("Minimum temperature reached\n");
    }
}

bool isInputValid(char input){
    char validInputs[] = {'1', '2', '3', '4', '5'};
    for(int i=0; i<5; i++){
        if(input == validInputs[i]){
            return true;
        }
    }
    return false;
}

void processInput(char input){
    switch(input){
        case '1':
            turnOnLight();
            break;
        case '2':
            turnOffLight();
            break;
        case '3':
            increaseTemp();
            break;
        case '4':
            decreaseTemp();
            break;
        case '5':
            printf("Exiting program\n");
            exit(EXIT_SUCCESS);
    }
}

void getUserInput(){
    char input;
    printf("\nSmart Home Automation System\n");
    printf("1. Turn ON the light\n");
    printf("2. Turn OFF the light\n");
    printf("3. Increase temperature\n");
    printf("4. Decrease temperature\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &input);
    if(isInputValid(input)){
        processInput(input);
        getUserInput();
    }
    else{
        printf("Invalid input. Please try again.\n");
        getUserInput();
    }
}

int main(){
    getUserInput();
    return 0;
}