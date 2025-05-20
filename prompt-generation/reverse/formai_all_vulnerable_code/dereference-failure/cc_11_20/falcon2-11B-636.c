//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Please enter the temperature as a decimal number in Celsius\n");
        return 1;
    }
    double temperature = atof(argv[1]);
    int scale = 100;
    char* scaleStr = (char*)malloc(scale + 1);
    int i;
    for (i = 0; i < scale; i++) {
        scaleStr[i] = '0';
    }
    scaleStr[scale] = '\0';
    int temp = temperature * scale;
    int degree = temp % 10;
    if (degree >= 5 && degree <= 9) {
        scaleStr[degree] = '5';
    } else if (degree == 0) {
        scaleStr[0] = '0';
    } else if (degree == 1) {
        scaleStr[0] = '1';
    } else if (degree == 2) {
        scaleStr[0] = '2';
        scaleStr[1] = '0';
    } else if (degree == 3) {
        scaleStr[0] = '3';
        scaleStr[1] = '0';
        scaleStr[2] = '0';
    } else if (degree == 4) {
        scaleStr[0] = '4';
        scaleStr[1] = '0';
        scaleStr[2] = '0';
        scaleStr[3] = '0';
    } else if (degree == 5) {
        scaleStr[0] = '5';
        scaleStr[1] = '0';
        scaleStr[2] = '0';
        scaleStr[3] = '0';
        scaleStr[4] = '0';
    } else if (degree == 6) {
        scaleStr[0] = '6';
        scaleStr[1] = '0';
        scaleStr[2] = '0';
        scaleStr[3] = '0';
        scaleStr[4] = '0';
        scaleStr[5] = '0';
    } else if (degree == 7) {
        scaleStr[0] = '7';
        scaleStr[1] = '0';
        scaleStr[2] = '0';
        scaleStr[3] = '0';
        scaleStr[4] = '0';
        scaleStr[5] = '0';
        scaleStr[6] = '0';
    } else if (degree == 8) {
        scaleStr[0] = '8';
        scaleStr[1] = '0';
        scaleStr[2] = '0';
        scaleStr[3] = '0';
        scaleStr[4] = '0';
        scaleStr[5] = '0';
        scaleStr[6] = '0';
        scaleStr[7] = '0';
    } else if (degree == 9) {
        scaleStr[0] = '9';
        scaleStr[1] = '0';
        scaleStr[2] = '0';
        scaleStr[3] = '0';
        scaleStr[4] = '0';
        scaleStr[5] = '0';
        scaleStr[6] = '0';
        scaleStr[7] = '0';
        scaleStr[8] = '0';
    } else {
        printf("Invalid temperature entered\n");
        return 1;
    }
    printf("The temperature is %.*sK\n", scale, scaleStr);
    return 0;
}