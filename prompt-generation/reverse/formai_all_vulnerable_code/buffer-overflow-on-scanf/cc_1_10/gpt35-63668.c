//FormAI DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void color_converter(char color_code[8]){

    char red[3], green[3], blue[3];
    int red_dec, green_dec, blue_dec;

    strncpy(red, &color_code[0], 2);
    strncpy(green, &color_code[2], 2);
    strncpy(blue, &color_code[4], 2);

    red_dec = strtol(red, NULL, 16);
    green_dec = strtol(green, NULL, 16);
    blue_dec = strtol(blue, NULL, 16);

    printf("\nRGB code: (%d, %d, %d)\n", red_dec, green_dec, blue_dec);

}

int main(){

    char color_code[8];
    int i, flag = 0;

    printf("\nWelcome to Color Code Converter\n");
    printf("-------------------------------\n");

    do{
        printf("\nEnter a hex color code (e.g. FF0000): ");
        scanf("%s", color_code);

        for(i=0; i<strlen(color_code); i++){
            if((color_code[i]>='0' && color_code[i]<='9') || (color_code[i]>='A' && color_code[i]<='F')){
                flag = 1;
            }else{
                flag = 0;
                break;
            }
        }

        if(flag == 0){
            printf("Invalid input! Please enter a valid hex color code.\n");
        }

    }while(flag == 0);

    color_converter(color_code);

    return 0;
}