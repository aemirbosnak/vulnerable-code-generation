//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include<stdio.h>

//Function to generate watermark from a given number.
int generateWatermark(int num){
    int watermark = 0;
    while(num != 0){
        watermark += num % 10;
        num /= 10;
    }
    return watermark;
}

int main(){
    //Initialization of variables
    int input, watermark;
    FILE *fp;

    //Open file in write mode
    fp = fopen("sample.txt", "w");

    if(fp == NULL){
        printf("Error in opening file.\n");
        return 0;
    }

    //Take input from user
    printf("Enter a number: ");
    scanf("%d", &input);

    //Generate watermark
    watermark = generateWatermark(input);

    //Write the input and the watermark to the file
    fprintf(fp, "%d|%d", input, watermark);

    //Close the file
    fclose(fp);

    //Open the file in read mode
    fp = fopen("sample.txt", "r");

    if(fp == NULL){
        printf("Error in opening file.\n");
        return 0;
    }

    //Read the input and the watermark from the file
    fscanf(fp, "%d|%d", &input, &watermark);

    //Check if the watermark matches the input
    if(generateWatermark(input) == watermark)
        printf("Watermark is valid.\n");
    else
        printf("Watermark is invalid.\n");

    //Close the file
    fclose(fp);

    return 0;
}