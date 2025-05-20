//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds){
    clock_t start_time = clock();
    while((clock() - start_time) < (seconds * CLOCKS_PER_SEC));
}

struct TrafficLight{
    int red;
    int yellow;
    int green;
};

struct TrafficLight initTrafficLight(){
    struct TrafficLight tl;
    tl.red = 0;
    tl.yellow = 0;
    tl.green = 0;
    return tl;
}

void printColoredChar(char color, char character){
    if(color == 'r') printf("\x1B[31m%c\x1B[0m", character);
    if(color == 'y') printf("\x1B[33m%c\x1B[0m", character);
    if(color == 'g') printf("\x1B[32m%c\x1B[0m", character);
}

void printTrafficLight(struct TrafficLight tl){
    printf("___\n");
    printf("|");
    printColoredChar('r', 'R');
    printf("|\n");
    printf("|");
    if(tl.red == 1) printColoredChar('r', '-');
    else if(tl.yellow == 1) printColoredChar('y', '-');
    else if(tl.green == 1) printColoredChar('g', '-');
    printf("|\n");
    printf("___\n");
}

void switchToRed(struct TrafficLight *tl){
    tl->red = 1;
    tl->yellow = 0;
    tl->green = 0;
}

void switchToYellow(struct TrafficLight *tl){
    tl->red = 0;
    tl->yellow = 1;
    tl->green = 0;
}

void switchToGreen(struct TrafficLight *tl){
    tl->red = 0;
    tl->yellow = 0;
    tl->green = 1;
}

int main(){
    struct TrafficLight tl = initTrafficLight();
    int counter = 0;
    while(1){
        if(counter == 0){
            switchToGreen(&tl);
            printTrafficLight(tl);
            delay(10);
            counter++;
        }
        else if(counter == 1){
            switchToYellow(&tl);
            printTrafficLight(tl);
            delay(3);
            counter++;
        }
        else if(counter == 2){
            switchToRed(&tl);
            printTrafficLight(tl);
            delay(10);
            counter++;
        }
        else{
            switchToYellow(&tl);
            printTrafficLight(tl);
            delay(3);
            counter = 0;
        }
    }
    return 0;
}