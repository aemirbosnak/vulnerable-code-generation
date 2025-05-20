//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <string.h>

char input[20], output[50];
int day, month, year;

int isLeap(int y){
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)){
        return 1;
    }
    return 0;
}

void convertDate(){
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;
    int totalDays = 0;

    for (i = 0; i < month - 1; i++){
        totalDays += days[i];
    }
    if (month > 2 && isLeap(year)){
        totalDays++;
    }

    totalDays += day;

    sprintf(output, "%s %d, %d is the %dth day of the year.", months[month-1], day, year, totalDays);
}

int main(){
    printf("Please input the date in the format of MM/DD/YYYY:\n");
    scanf("%s", input);

    char *token = strtok(input, "/");
    month = atoi(token);

    token = strtok(NULL, "/");
    day = atoi(token);

    token = strtok(NULL, "/");
    year = atoi(token);

    convertDate();

    printf("%s", output);

    return 0;
}