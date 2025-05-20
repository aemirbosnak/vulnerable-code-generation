//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Function to convert date from yyyy-mm-dd format to dd/mm/yyyy format
void convertDate(char *date){
    int day, month, year;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    printf("%d/%d/%d\n", day, month, year);
}

//Function to convert date from dd/mm/yyyy format to yyyy-mm-dd format
void convertDateReverse(char *date){
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    printf("%d-%d-%d\n", year, month, day);
}

//Function to validate date
int validateDate(char *date){
    int day, month, year;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    if(year < 1000 || year > 9999){
        return 0;
    }
    if(month < 1 || month > 12){
        return 0;
    }
    if(day < 1 || day > 31){
        return 0;
    }
    return 1;
}

int main(){
    char date[20];
    printf("Enter a date in yyyy-mm-dd format: ");
    scanf("%s", date);

    //Validate date
    if(validateDate(date)){
        //Convert to dd/mm/yyyy format
        convertDateReverse(date);
    }else{
        printf("Invalid date!\n");
    }

    return 0;
}