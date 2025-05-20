//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* signal(int c){

    switch(c){
        case 1:
            return "Red light";
            break;
        case 2:
            return "Green light";
            break;
        case 3:
            return "Yellow light";
            break;
        default:
            return "Error";
    }

}

int main(){

    time_t t;
    srand((unsigned) time(&t));

    int c;
    int n = 1;
    int r, y, g;
    int total_seconds = 0;
    int prev = -1;

    printf("Welcome to the Traffic Light Controller!\n\n");

    printf("How many traffic signals should we simulate?\n");
    scanf("%d", &n);

    printf("\n");

    while(total_seconds <= n*20){

        r = 1 + rand() % 5;
        g = 1 + rand() % 5;
        y = 1 + rand() % 3;

        c = 1;

        if(prev != 1){
            printf("Red Light\n");
            prev = 1;
            c = 1;
        } else if(prev == 1){
            printf("Green Light\n");
            prev = 2;
            c = 2;
        } else if(prev == 2){
            printf("Yellow Light\n");
            prev = 3;
            c = 3;
        } else if(prev == 3){
            printf("Red Light\n");
            prev = 1;
            c = 1;
        }

        printf("Color: %s\n", signal(c));
        printf("Interval: %d seconds\n", c==1?r:c==2?g:y);
        printf("Total elapsed time: %d seconds\n", total_seconds);

        total_seconds += c==1?r:c==2?g:y;

        sleep(c==1?r:c==2?g:y);

        printf("\n");

    }

    printf("Simulation complete. Thank you for using the Traffic Light Controller!\n");

    return 0;

}