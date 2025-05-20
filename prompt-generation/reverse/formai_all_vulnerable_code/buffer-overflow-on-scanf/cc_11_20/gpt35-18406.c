//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: immersive
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int date_converter(char *input_date){
    int day, month, year;

    sscanf(input_date, "%d-%d-%d", &year, &month, &day);
    if(day>31 || day<1 || month>12 || month<1){
        printf("Invalid Date!\n");
        return 1;
    }

    switch(month){
        case 2:
            if(day>29){
                printf("Invalid Date!\n");
                return 1;
            }
            if(day==29 && year%4!=0){
                printf("Invalid Date!\n");
                return 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day>30){
                printf("Invalid Date!\n");
                return 1;
            }
    }

    printf("Date in string format: %s\n", input_date);
    printf("Date in Natural Language: ");
    switch(month){
        case 1:
            printf("January ");
            break;
        case 2:
            printf("February ");
            break;
        case 3:
            printf("March ");
            break;
        case 4:
            printf("April ");
            break;
        case 5:
            printf("May ");
            break;
        case 6:
            printf("June ");
            break;
        case 7:
            printf("July ");
            break;
        case 8:
            printf("August ");
            break;
        case 9:
            printf("September ");
            break;
        case 10:
            printf("October ");
            break;
        case 11:
            printf("November ");
            break;
        case 12:
            printf("December ");
            break;
    }

    if(day==1 || day==21 || day==31){
        printf("%dst, ", day);
    }
    else if(day==2 || day==22){
        printf("%dnd, ", day);
    }
    else if(day==3 || day==23){
        printf("%drd, ", day);
    }
    else{
        printf("%dth, ", day);
    }

    printf("%d\n", year);

    return 0;
}

int main(){
    char input_date[20];

    printf("Enter a date in the format of yyyy-mm-dd:\n");
    scanf("%s", input_date);

    int i=0;
    while(input_date[i]){
        if(!(isdigit(input_date[i])) && i!=4 && i!=7){
            printf("Invalid Format! Enter in yyyy-mm-dd format.\n");
            return 1;
        }
        i++;
    }

    date_converter(input_date);

    return 0;
}