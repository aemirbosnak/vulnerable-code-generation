//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tracker{
    char date[20];
    int calories;
    float distance;
};

int main(){
    int option;
    int total_calories = 0;
    float total_distance = 0.0;
    struct Tracker track[50];
    int count = 0;
    int i;

    while(1){
        printf("Choose an option:\n");
        printf("1. Add data\n");
        printf("2. View data\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        if(option == 1){
            printf("Enter date (YYYY/MM/DD):\n");
            scanf("%s", track[count].date);
            printf("Enter calories burned:\n");
            scanf("%d", &track[count].calories);
            printf("Enter distance traveled (in km):\n");
            scanf("%f", &track[count].distance);
            total_calories += track[count].calories;
            total_distance += track[count].distance;
            printf("Data added successfully!\n");
            count++;
        }
        else if(option == 2){
            printf("Date\t\tCalories Burned\tDistance Traveled (km)\n");
            for(i=0; i<count; i++){
                printf("%s\t\t%d\t\t%.2f\n", track[i].date, track[i].calories, track[i].distance);
            }
            printf("Total\t\t%d\t\t%.2f\n", total_calories, total_distance);
        }
        else if(option == 3){
            printf("Exiting...");
            break;
        }
        else{
            printf("Invalid option! Please select again.\n");
        }
    }
    return 0;
}