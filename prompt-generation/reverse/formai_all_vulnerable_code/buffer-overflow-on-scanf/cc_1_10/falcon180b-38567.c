//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include<stdio.h>
#include<string.h>

#define MAX 10

struct{
    char unit[MAX];
    float factor;
}conversion_table[]={
    {"meter",1},
    {"centimeter",0.01},
    {"millimeter",0.001},
    {"kilogram",1},
    {"gram",0.001},
    {"liter",1},
    {"milliliter",0.001},
    {"second",1},
    {"minute",60},
    {"hour",3600}
};

int main(){
    int choice,i,n;
    char unit1[MAX],unit2[MAX];

    printf("Enter the unit to convert from: ");
    scanf("%s",unit1);

    printf("Enter the unit to convert to: ");
    scanf("%s",unit2);

    for(i=0;i<MAX;i++){
        if(!strcmp(unit1,conversion_table[i].unit) &&!strcmp(unit2,conversion_table[i].unit)){
            printf("Cannot convert from and to same unit\n");
            return 0;
        }
    }

    for(i=0;i<MAX;i++){
        if(!strcmp(unit1,conversion_table[i].unit)){
            choice=i;
            break;
        }
    }

    for(i=0;i<MAX;i++){
        if(!strcmp(unit2,conversion_table[i].unit)){
            n=i;
            break;
        }
    }

    printf("Enter the value to convert: ");
    scanf("%f",&conversion_table[choice].factor);

    conversion_table[n].factor=conversion_table[n].factor/conversion_table[choice].factor;

    printf("%.2f %s = %.2f %s\n",conversion_table[choice].factor,unit1,conversion_table[n].factor,unit2);

    return 0;
}