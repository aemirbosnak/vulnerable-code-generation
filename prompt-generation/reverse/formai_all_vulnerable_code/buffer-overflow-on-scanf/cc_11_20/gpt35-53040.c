//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include<stdio.h>
#include<string.h>

int main(){
    char date[20], month[10], year[6];
    int day, numMonth, numYear;

    printf("Enter date in natural language format (Eg: 15th March 2022): ");
    scanf("%d%s%d", &day, month, &numYear);

    //convert month to number
    if(strcmp(month, "January")==0){
        numMonth=1;
    }else if(strcmp(month, "February")==0){
        numMonth=2;
    }else if(strcmp(month, "March")==0){
        numMonth=3;
    }else if(strcmp(month, "April")==0){
        numMonth=4;
    }else if(strcmp(month, "May")==0){
        numMonth=5;
    }else if(strcmp(month, "June")==0){
        numMonth=6;
    }else if(strcmp(month, "July")==0){
        numMonth=7;
    }else if(strcmp(month, "August")==0){
        numMonth=8;
    }else if(strcmp(month, "September")==0){
        numMonth=9;
    }else if(strcmp(month, "October")==0){
        numMonth=10;
    }else if(strcmp(month, "November")==0){
        numMonth=11;
    }else if(strcmp(month, "December")==0){
        numMonth=12;
    }

    //convert year to number
    if(numYear>=1900 && numYear<=2000){
        numYear=numYear-1900;
    }else if(numYear>=2001 && numYear<=2100){
        numYear=numYear-2000;
    }

    //output in mm/dd/yy format
    printf("\nOutput in mm/dd/yy format: ");
    printf("%02d/%02d/%02d\n", numMonth, day, numYear);

    return 0;
}