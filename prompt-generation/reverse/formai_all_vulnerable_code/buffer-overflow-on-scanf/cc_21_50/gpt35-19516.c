//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include<stdio.h>
#include<string.h>

int main(){
    char input_date[11];
    char day[3], month[3], year[5];
    int i, flag=0;

    printf("Welcome to the Natural Language Date Converter!");
    printf("\nPlease enter a date in any of the following formats: \n");
    printf("1. April 12, 2021\n2. 12/04/2021\n3. 12-04-2021\n4. 2021-04-12\n");
    scanf("%s", input_date);

    // Check the format of the date entered

    for(i=0; i<strlen(input_date); i++){
        if(input_date[i] == '/' || input_date[i] == '-' || input_date[i] == ','){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        if(input_date[2] == '/' && input_date[5] == '/'){
            sscanf(input_date, "%2s/%2s/%4s", day, month, year);
            printf("The date in natural language is: %s %s, %s", month, day, year);
        }
        else if(input_date[2] == '-' && input_date[5] == '-'){
            sscanf(input_date, "%2s-%2s-%4s", day, month, year);
            printf("The date in natural language is: %s %s, %s", month, day, year);
        }
        else if(input_date[3] == '/' && input_date[6] == '/'){
            sscanf(input_date, "%4s/%2s/%2s", year, month, day);
            if(strcmp(month, "01")==0){
                printf("The date in natural language is: January %s, %s", day, year);
            }
            else if(strcmp(month, "02")==0){
                printf("The date in natural language is: February %s, %s", day, year);
            }
            else if(strcmp(month, "03")==0){
                printf("The date in natural language is: March %s, %s", day, year);
            }
            else if(strcmp(month, "04")==0){
                printf("The date in natural language is: April %s, %s", day, year);
            }
            else if(strcmp(month, "05")==0){
                printf("The date in natural language is: May %s, %s", day, year);
            }
            else if(strcmp(month, "06")==0){
                printf("The date in natural language is: June %s, %s", day, year);
            }
            else if(strcmp(month, "07")==0){
                printf("The date in natural language is: July %s, %s", day, year);
            }
            else if(strcmp(month, "08")==0){
                printf("The date in natural language is: August %s, %s", day, year);
            }
            else if(strcmp(month, "09")==0){
                printf("The date in natural language is: September %s, %s", day, year);
            }
            else if(strcmp(month, "10")==0){
                printf("The date in natural language is: October %s, %s", day, year);
            }
            else if(strcmp(month, "11")==0){
                printf("The date in natural language is: November %s, %s", day, year);
            }
            else if(strcmp(month, "12")==0){
                printf("The date in natural language is: December %s, %s", day, year);
            }
        }
        else if(input_date[4] == '-' && input_date[7] == '-'){
            sscanf(input_date, "%4s-%2s-%2s", year, month, day);
            if(strcmp(month, "01")==0){
                printf("The date in natural language is: January %s, %s", day, year);
            }
            else if(strcmp(month, "02")==0){
                printf("The date in natural language is: February %s, %s", day, year);
            }
            else if(strcmp(month, "03")==0){
                printf("The date in natural language is: March %s, %s", day, year);
            }
            else if(strcmp(month, "04")==0){
                printf("The date in natural language is: April %s, %s", day, year);
            }
            else if(strcmp(month, "05")==0){
                printf("The date in natural language is: May %s, %s", day, year);
            }
            else if(strcmp(month, "06")==0){
                printf("The date in natural language is: June %s, %s", day, year);
            }
            else if(strcmp(month, "07")==0){
                printf("The date in natural language is: July %s, %s", day, year);
            }
            else if(strcmp(month, "08")==0){
                printf("The date in natural language is: August %s, %s", day, year);
            }
            else if(strcmp(month, "09")==0){
                printf("The date in natural language is: September %s, %s", day, year);
            }
            else if(strcmp(month, "10")==0){
                printf("The date in natural language is: October %s, %s", day, year);
            }
            else if(strcmp(month, "11")==0){
                printf("The date in natural language is: November %s, %s", day, year);
            }
            else if(strcmp(month, "12")==0){
                printf("The date in natural language is: December %s, %s", day, year);
            }
        }
        else{
            printf("Sorry! You have entered an invalid date format.");
        }
    }
    else{
        printf("Sorry! You have entered an invalid date format.");
    }

    return 0;
}