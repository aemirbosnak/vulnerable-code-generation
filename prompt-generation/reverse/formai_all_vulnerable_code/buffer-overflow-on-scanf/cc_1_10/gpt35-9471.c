//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  time_t t;
  srand((unsigned) time(&t));

  int year = rand() % 100 + 1900; // generate a random year between 1900 and 2000
  int month = rand() % 12 + 1; // generate a random month between 1 and 12
  int day = rand() % 28 + 1; // generate a random day between 1 and 28

  printf("Welcome to the Time Travel Simulator!\n");
  printf("Today's date is: %02d/%02d/%d\n\n", day, month, year);

  int choice;

  printf("What year would you like to travel to?\n");
  scanf("%d", &choice);

  if(choice > year){
    printf("You have traveled to the future!\n");
  }else if(choice < year){
    printf("You have traveled to the past!\n");
  }else{
    printf("You have chosen the current year!\n");
  }

  printf("Press any key to continue...\n");

  getchar(); // clear input buffer

  printf("\nWould you like to see what day it is on your time travel destination?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  scanf("%d", &choice);

  if(choice == 1){
    int destination_year, destination_month, destination_day;

    printf("\nEnter the destination year:\n");
    scanf("%d", &destination_year);

    printf("Enter the destination month:\n");
    scanf("%d", &destination_month);

    printf("Enter the destination day:\n");
    scanf("%d", &destination_day);

    printf("The date on your destination is: %02d/%02d/%d\n", destination_day, destination_month, destination_year);
  }

  printf("\nThank you for using the Time Travel Simulator!\n");

  return 0;
}