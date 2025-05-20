//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main()
{
    char unit1[20],unit2[20],result[20];
    double num1,num2;

    printf("Enter the first unit: ");
    scanf("%s",unit1);

    printf("Enter the second unit: ");
    scanf("%s",unit2);

    printf("Enter the value to convert: ");
    scanf("%lf",&num1);

    if(strcmp(unit1,"m")==0 && strcmp(unit2,"ft")==0)
    {
        num2=num1*3.28084;
        strcpy(result,"ft");
    }
    else if(strcmp(unit1,"ft")==0 && strcmp(unit2,"m")==0)
    {
        num2=num1/3.28084;
        strcpy(result,"m");
    }
    else if(strcmp(unit1,"m")==0 && strcmp(unit2,"in")==0)
    {
        num2=num1*39.3701;
        strcpy(result,"in");
    }
    else if(strcmp(unit1,"in")==0 && strcmp(unit2,"m")==0)
    {
        num2=num1/39.3701;
        strcpy(result,"m");
    }
    else if(strcmp(unit1,"m")==0 && strcmp(unit2,"cm")==0)
    {
        num2=num1*100;
        strcpy(result,"cm");
    }
    else if(strcmp(unit1,"cm")==0 && strcmp(unit2,"m")==0)
    {
        num2=num1/100;
        strcpy(result,"m");
    }
    else if(strcmp(unit1,"kg")==0 && strcmp(unit2,"lb")==0)
    {
        num2=num1*2.20462;
        strcpy(result,"lb");
    }
    else if(strcmp(unit1,"lb")==0 && strcmp(unit2,"kg")==0)
    {
        num2=num1/2.20462;
        strcpy(result,"kg");
    }
    else
    {
        printf("Invalid units selected");
        exit(0);
    }

    printf("Result: %.2lf %s = %.2lf %s",num1,unit1,num2,result);
}