//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert the date in natural language to numeric date format
void naturalLanguageDateConverter(char* inputDate){

    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    char suffix[3], month[10], day[3], year[5];

    //Using sscanf function to read formatted data
    sscanf(inputDate, "%s %s %s %s", month, day, suffix, year);

    int index = -1;

    //Matching the month name with the entered string and getting the index
    for(int i = 0; i < 12; i++){
        if(strcmp(months[i], month) == 0){
            index = i+1;
            break;
        }
    }

    //Handling if the index of month is not found
    if(index == -1){
        printf("Invalid date format entered\n");
        return;
    }

    //Checking for the suffix of day entered
    if(strcmp(suffix, "st") == 0 || strcmp(suffix, "nd") == 0 || strcmp(suffix, "rd") == 0 || strcmp(suffix, "th") == 0){
        day[0] = day[0];
        day[1] = day[1];
        day[2] = '\0';
    }
    else{
        printf("Invalid date format entered\n");
        return;
    }

    //Printing the numeric date format
    printf("%d/%s/%s\n", index, day, year);
}

int main(){
    char inputDate[20];
    printf("Enter the date in natural language format (Eg: March 22nd 2022): ");
    fgets(inputDate, 20, stdin);
    inputDate[strcspn(inputDate, "\n")] = '\0';
    naturalLanguageDateConverter(inputDate);
    return 0;
}