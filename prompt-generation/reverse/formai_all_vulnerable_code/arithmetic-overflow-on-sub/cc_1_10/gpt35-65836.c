//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function for checking inputs
int checkInput(int num){
    if(num >= 0 && num <= 60) return 1;
    else return 0;
}

// function for timer
void timer(int seconds){
    int start = time(NULL);
    int current = time(NULL);
    while((current - start) != seconds){
        current = time(NULL);
    }
}

int main(){
    int red, yellow, green, cycles;
    printf("Welcome to the futuristic traffic light controller\n");
    printf("Please enter the duration for RED light (in seconds): ");
    scanf("%d", &red);
    while(!checkInput(red)){
        printf("Invalid input. Please enter a value between 0 and 60: ");
        scanf("%d", &red);
    }
    printf("Please enter the duration for YELLOW light (in seconds): ");
    scanf("%d", &yellow);
    while(!checkInput(yellow)){
        printf("Invalid input. Please enter a value between 0 and 60: ");
        scanf("%d", &yellow);
    }
    printf("Please enter the duration for GREEN light (in seconds): ");
    scanf("%d", &green);
    while(!checkInput(green)){
        printf("Invalid input. Please enter a value between 0 and 60: ");
        scanf("%d", &green);
    }
    printf("Please enter the number of cycles: ");
    scanf("%d", &cycles);
    while(cycles <= 0){
        printf("Invalid input. Please enter a value greater than 0: ");
        scanf("%d", &cycles);
    }

    for(int i=1; i<=cycles; i++){
        printf("\nCycle %d:\n", i);
        printf("RED light\n");
        timer(red);
        printf("YELLOW light\n");
        timer(yellow);
        printf("GREEN light\n");
        timer(green);
    }

    printf("\nThank you for using the futuristic traffic light controller system!");

    return 0;
}