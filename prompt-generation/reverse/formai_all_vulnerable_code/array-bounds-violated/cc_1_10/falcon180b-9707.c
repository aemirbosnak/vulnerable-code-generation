//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct temperature{
    char unit[10];
    int value;
};

void convert(struct temperature *temp)
{
    char celsius[10] = "Celsius";
    char fahrenheit[10] = "Fahrenheit";
    if(strcmp(temp->unit,celsius)==0)
    {
        temp->value = (temp->value * 9/5) + 32;
        strcpy(temp->unit,fahrenheit);
    }
    else if(strcmp(temp->unit,fahrenheit)==0)
    {
        temp->value = (temp->value - 32) * 5/9;
        strcpy(temp->unit,celsius);
    }
}

int main()
{
    int i,j;
    struct temperature temp[MAX];
    char choice;
    do
    {
        printf("\n\nWelcome to Temperature Converter\n");
        printf("Enter 1 to Convert Temperature\n");
        printf("Enter 2 to Exit\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            if(i==MAX)
            {
                printf("\n\nSorry! You have reached the maximum limit of %d temperatures.\n",MAX);
                exit(0);
            }
            printf("\nEnter Temperature %d:\n",++i);
            scanf("%s %d",temp[i].unit,&temp[i].value);
            convert(&temp[i]);
            printf("\n%s %d %s is equal to %s %d %s\n",temp[i].unit,temp[i].value,temp[i].unit,temp[i].unit,temp[i].value,temp[i].unit);
        }
        else if(choice==2)
        {
            printf("\n\nThank You for using Temperature Converter\n");
            exit(0);
        }
        else
        {
            printf("\n\nInvalid Choice! Please Enter Again\n");
        }
    }while(1);
    return 0;
}