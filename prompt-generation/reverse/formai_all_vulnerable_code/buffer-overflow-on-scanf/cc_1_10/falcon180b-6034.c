//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COLOR_CODE_LENGTH 7

//structure to hold the RGB color code
typedef struct{
    char name[20];
    int red;
    int green;
    int blue;
}colorCode;

//function to initialize an array of colorCode structs
void initColorCodeArray(colorCode arr[], int size){
    for(int i=0;i<size;i++){
        arr[i].red=0;
        arr[i].green=0;
        arr[i].blue=0;
        strcpy(arr[i].name,"");
    }
}

//function to read in a color code from the user
void readColorCode(colorCode* code){
    printf("Enter the name of the color code: ");
    scanf("%s",code->name);
    printf("Enter the red value: ");
    scanf("%d",&code->red);
    printf("Enter the green value: ");
    scanf("%d",&code->green);
    printf("Enter the blue value: ");
    scanf("%d",&code->blue);
}

//function to display the RGB color code
void displayColorCode(colorCode code){
    printf("%.2X%.2X%.2X\n",code.red,code.green,code.blue);
}

//function to convert a color code from RGB to hexadecimal
void convertColorCode(colorCode code){
    int r=code.red;
    int g=code.green;
    int b=code.blue;
    char hexCode[MAX_COLOR_CODE_LENGTH];
    sprintf(hexCode,"%02X%02X%02X",r,g,b);
    strcpy(code.name,hexCode);
}

//function to convert a color code from hexadecimal to RGB
void invertColorCode(colorCode code){
    int r,g,b;
    sscanf(code.name,"%02X%02X%02X",&r,&g,&b);
    code.red=r;
    code.green=g;
    code.blue=b;
}

int main(){
    int numOfColorCodes;
    printf("Enter the number of color codes: ");
    scanf("%d",&numOfColorCodes);

    colorCode colorCodes[numOfColorCodes];
    initColorCodeArray(colorCodes,numOfColorCodes);

    for(int i=0;i<numOfColorCodes;i++){
        readColorCode(&colorCodes[i]);
        convertColorCode(colorCodes[i]);
        displayColorCode(colorCodes[i]);
    }

    printf("\nEnter the name of the color code you want to invert: ");
    scanf("%s",colorCodes[0].name);
    invertColorCode(colorCodes[0]);
    displayColorCode(colorCodes[0]);

    return 0;
}