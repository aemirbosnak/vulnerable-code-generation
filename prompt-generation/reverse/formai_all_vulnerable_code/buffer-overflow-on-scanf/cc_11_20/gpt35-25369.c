//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include<stdio.h>
#include<string.h>

void dateParser(char date[]) {

    int day, month, year, i=0, j=0;
    char temp_date[5][10];
    char *ptr;

    ptr = strtok(date, "-");
    while(ptr != NULL){
        strcpy(temp_date[i], ptr);
        i++;
        ptr = strtok(NULL, "-");
    }

    for(j=0; j<i; j++){
        if(isalpha(temp_date[j][0])){
            temp_date[j][0] = toupper(temp_date[j][0]);
            if((strcmp(temp_date[j], "Jan")) == 0 || (strcmp(temp_date[j], "January")) == 0){
                month = 1;
            }
            else if((strcmp(temp_date[j], "Feb")) == 0 || (strcmp(temp_date[j], "February")) == 0){
                month = 2;
            }
            else if((strcmp(temp_date[j], "Mar")) == 0 || (strcmp(temp_date[j], "March")) == 0){
                month = 3;
            }
            else if((strcmp(temp_date[j], "Apr")) == 0 || (strcmp(temp_date[j], "April")) == 0){
                month = 4;
            }
            else if((strcmp(temp_date[j], "May")) == 0){
                month = 5;
            }
            else if((strcmp(temp_date[j], "Jun")) == 0 || (strcmp(temp_date[j], "June")) == 0){
                month = 6;
            }
            else if((strcmp(temp_date[j], "Jul")) == 0 || (strcmp(temp_date[j], "July")) == 0){
                month = 7;
            }
            else if((strcmp(temp_date[j], "Aug")) == 0 || (strcmp(temp_date[j], "August")) == 0){
                month = 8;
            }
            else if((strcmp(temp_date[j], "Sep")) == 0 || (strcmp(temp_date[j], "September")) == 0){
                month = 9;
            }
            else if((strcmp(temp_date[j], "Oct")) == 0 || (strcmp(temp_date[j], "October")) == 0){
                month = 10;
            }
            else if((strcmp(temp_date[j], "Nov")) == 0 || (strcmp(temp_date[j], "November")) == 0){
                month = 11;
            }
            else if((strcmp(temp_date[j], "Dec")) == 0 || (strcmp(temp_date[j], "December")) == 0){
                month = 12;
            }
        }
        else{
            if(j==0){
                day = atoi(temp_date[j]);
            }
            else{
                year = atoi(temp_date[j]);
            }
        }
    }
    printf("%d / %d / %d", day, month, year);
}

int main(){

    char date[50];
    printf("Enter the date (dd-mm-yyyy or dd-mmm-yyyy): ");
    scanf("%s", date);
    dateParser(date);
    printf("\n");

    return 0;
}