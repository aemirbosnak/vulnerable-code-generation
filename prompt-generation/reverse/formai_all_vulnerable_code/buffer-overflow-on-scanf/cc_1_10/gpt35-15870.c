//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include<stdio.h>

#define MIN_TEMP 0
#define MAX_TEMP 100

void printTemp(double temp);
double convertToFahrenheit(double celsius);
double getAverageTemp(double *tempArray, int size);
int checkTempStatus(double temp);

int main(){
    double cels,tempArray[10],averageTemp;
    int i,tempStatus;
    
    for(i=0;i<10;i++){
        printf("Enter temperature %d: ",i+1);
        scanf("%lf",&cels);
        
        if(cels<MIN_TEMP || cels>MAX_TEMP){
            printf("Invalid temperature entered. Please enter a temperature between %d and %d\n",MIN_TEMP,MAX_TEMP);
            i--;
            continue;
        }
        
        tempArray[i] = cels;
    }
    
    averageTemp = getAverageTemp(tempArray,10);
    
    printf("\nTemperature summary:\n");
    
    for(i=0;i<10;i++){
        printf("Temperature %d: %.2lfC\t%.2lfF\t",i+1,tempArray[i],convertToFahrenheit(tempArray[i]));
        tempStatus = checkTempStatus(tempArray[i]);
        if(tempStatus == 1)
            printf("NORMAL");
        else if(tempStatus == 2)
            printf("HIGH");
        else if(tempStatus == 3)
            printf("CRITICAL");
        printf("\n");
    }
    
    printf("\nAverage temperature is: %.2lfC / %.2lfF\n",averageTemp,convertToFahrenheit(averageTemp));
    
    return 0;
}

void printTemp(double temp){
    printf("%.2lfC\t%.2lfF\n",temp,convertToFahrenheit(temp));
}

double convertToFahrenheit(double celsius){
    double fahr = (celsius * 1.8) + 32;
    return fahr;
}

double getAverageTemp(double *tempArray, int size){
    double sum = 0;
    int i;
    for(i=0;i<size;i++){
        sum += tempArray[i];
    }
    double average = sum / size;
    return average;
}

int checkTempStatus(double temp){
    if(temp>=25 && temp<=35)
        return 1; // normal
    else if(temp>35 && temp<=45)
        return 2; // high
    else
        return 3; // critical
}