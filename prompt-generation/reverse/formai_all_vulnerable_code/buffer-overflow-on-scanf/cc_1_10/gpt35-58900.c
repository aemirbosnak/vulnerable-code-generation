//FormAI DATASET v1.0 Category: Bitwise operations ; Style: immersive
#include <stdio.h>  

/*This program uses bitwise operations to simulate a security system that grants access based on the correct sequence of passcodes*/


int main() {
    int passcode1 = 176;    //First passcode
    int passcode2 = 227;    //Second passcode
    int passcode3 = 84;     //Third passcode
    int accessGranted = 0;  //Variable to check if access is granted
    
    printf("Welcome to the Security System!\n");
    printf("Please enter the first passcode: ");
    int input1;
    scanf("%d", &input1);
    
    //Check if first passcode is correct using bitwise AND operator
    if ((input1 & passcode1) == passcode1) {
        printf("Correct! Please enter the second passcode: ");
        int input2;
        scanf("%d", &input2);
        
        //Check if second passcode is correct using bitwise XOR operator
        if ((input2 ^ passcode2) == 73) {
            printf("Correct! Please enter the final passcode: ");
            int input3;
            scanf("%d", &input3);
            
            //Check if third passcode is correct using bitwise OR operator
            if ((input3 | passcode3) == 255) {
                printf("Access granted! Welcome to the system.\n");
                accessGranted = 1;  //Set variable to true
            }
            else {
                printf("Incorrect passcode. Access denied.\n");
            }
        }
        else {
            printf("Incorrect passcode. Access denied.\n");
        }
    }
    else {
        printf("Incorrect passcode. Access denied.\n");
    }
    
    //If access is not granted, print a message and exit the program
    if (!accessGranted) {
        printf("Sorry, you do not have access to the system. Goodbye.\n");
    }
    
    return 0;
}