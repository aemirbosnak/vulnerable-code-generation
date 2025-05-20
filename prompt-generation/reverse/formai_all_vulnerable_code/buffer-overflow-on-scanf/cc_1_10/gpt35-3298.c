//FormAI DATASET v1.0 Category: Smart home automation ; Style: innovative
#include<stdio.h>
#include<string.h>

// Function prototype to turn on/off lights
void lightsControl(int onOff);

// Function prototype to turn on/off air conditioner
void acControl(int onOff);

// Function prototype to turn on/off TV
void tvControl(int onOff);

int main(){
    int choice;
    printf("Welcome to Smart Home Automation\n");
    printf("What would you like to do?\n");
    printf("1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Turn on AC\n");
    printf("4. Turn off AC\n");
    printf("5. Turn on TV\n");
    printf("6. Turn off TV\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            lightsControl(1);
            break;
        case 2:
            lightsControl(0);
            break;
        case 3:
            acControl(1);
            break;
        case 4:
            acControl(0);
            break;
        case 5:
            tvControl(1);
            break;
        case 6:
            tvControl(0);
            break;
        default:
            printf("Invalid input\n");
            break;
    }

    return 0;
}

void lightsControl(int onOff){
    if(onOff){
        printf("Turning on lights\n");
    } else {
        printf("Turning off lights\n");
    }
}

void acControl(int onOff){
    if(onOff){
        printf("Turning on AC\n");
    } else {
        printf("Turning off AC\n");
    }
}

void tvControl(int onOff){
    if(onOff){
        printf("Turning on TV\n");
    } else {
        printf("Turning off TV\n");
    }
}