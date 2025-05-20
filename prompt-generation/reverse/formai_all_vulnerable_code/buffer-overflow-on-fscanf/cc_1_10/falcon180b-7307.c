//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define PI 3.14159265358979323846
#define MAX_TEMP 50.0
#define MIN_TEMP -50.0

typedef struct{
    float temp;
    int status;
} Temperature;

int main(){
    int choice;
    Temperature temp;
    float max_temp, min_temp;
    char filename[50];

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please enter the name of the temperature file: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: File not found.\n");
        exit(1);
    }

    fscanf(fp, "%f", &max_temp);
    fscanf(fp, "%f", &min_temp);
    fclose(fp);

    printf("Enter your choice:\n");
    printf("1. Display current temperature\n");
    printf("2. Set maximum temperature\n");
    printf("3. Set minimum temperature\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Current temperature: %.2f\n", temp.temp);
            break;

        case 2:
            printf("Enter new maximum temperature: ");
            scanf("%f", &max_temp);
            fp = fopen(filename, "w");
            fprintf(fp, "%.2f\n", max_temp);
            fprintf(fp, "%.2f\n", min_temp);
            fclose(fp);
            printf("Maximum temperature set successfully.\n");
            break;

        case 3:
            printf("Enter new minimum temperature: ");
            scanf("%f", &min_temp);
            fp = fopen(filename, "w");
            fprintf(fp, "%.2f\n", max_temp);
            fprintf(fp, "%.2f\n", min_temp);
            fclose(fp);
            printf("Minimum temperature set successfully.\n");
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}