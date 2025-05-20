//FormAI DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>

//defining global variables
int light = 0; // 0 is off and 1 is on
int heater = 0; //0 is off and 1 is on
int ac = 0; //0 is off and 1 is on

//function to turn the lights on and off
void lightControl(int status){
    light = status;
    if (light == 1){
        printf("Lights turned on!\n");
    }else{
        printf("Lights turned off!\n");
    }
}

//function to turn heater on and off
void heaterControl(int status){
    heater = status;
    if (heater == 1){
        printf("Heater turned on!\n");
    }else{
        printf("Heater turned off!\n");
    }
}

//function to turn ac on and off
void acControl(int status){
    ac = status;
    if (ac == 1){
        printf("AC turned on!\n");
    }else{
        printf("AC turned off!\n");
    }
}

//main function
int main(){
    int choice, status;
    printf("Enter 1 to turn on the lights, 2 to turn off the lights, 3 to turn on the heater, 4 to turn off the heater, 5 to turn on the AC, and 6 to turn off the AC.\n");
    while (1){
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice){
            case 1 : lightControl(1); break;
            case 2 : lightControl(0); break;
            case 3 : heaterControl(1); break;
            case 4 : heaterControl(0); break;
            case 5 : acControl(1); break;
            case 6 : acControl(0); break;
            default: printf("Invalid choice!");
        }
    }
    return 0;
}