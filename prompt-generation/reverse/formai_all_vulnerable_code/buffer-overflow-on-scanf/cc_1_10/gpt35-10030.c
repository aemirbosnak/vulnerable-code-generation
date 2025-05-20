//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>

//function prototypes
void greenLight();
void yellowLight();
void redLight();

int main()
{
    char choice;
    do{
        //user menu
        printf("Choose a color: \n");
        printf("G - Green\n");
        printf("Y - Yellow\n");
        printf("R - Red\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        //switch statement to choose color
        switch(choice)
        {
            case 'G': greenLight(); break;
            case 'Y': yellowLight(); break;
            case 'R': redLight(); break;
            case 'Q': break; //exit program
            default : printf("Invalid input!\n");
        }
    }while(choice != 'Q');

    return 0;
}

//function definitions
void greenLight()
{
    printf("The Green Light is ON.\n");
    //code to turn on green light
}

void yellowLight()
{
    printf("The Yellow Light is ON.\n");
    //code to turn on yellow light
}

void redLight()
{
    printf("The Red Light is ON.\n");
    //code to turn on red light
}