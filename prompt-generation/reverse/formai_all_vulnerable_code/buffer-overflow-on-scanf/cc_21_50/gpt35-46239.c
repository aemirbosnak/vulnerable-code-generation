//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include<stdio.h>
#include<string.h>

int main(){
  char date[100], month[100], year[100];
  int day, i;
  printf("My darling, let me convert our special date into different formats, so that I can surprise you in new ways every time. Please tell me our date in C natural language format. (E.g. Twelfth of December, 2022)\n");
  scanf("%d", &day);
  scanf("%s", month);
  scanf("%s", year);
  printf("O my beloved, we had an unforgettable day on %d ", day);

  if(strcmp(month, "January") == 0){
    printf("January");
  }else if(strcmp(month, "February") == 0){
    printf("February");
  }else if(strcmp(month, "March") == 0){
    printf("March");
  }else if(strcmp(month, "April") == 0){
    printf("April");
  }else if(strcmp(month, "May") == 0){
    printf("May");
  }else if(strcmp(month, "June") == 0){
    printf("June");
  }else if(strcmp(month, "July") == 0){
    printf("July");
  }else if(strcmp(month, "August") == 0){
    printf("August");
  }else if(strcmp(month, "September") == 0){
    printf("September");
  }else if(strcmp(month, "October") == 0){
    printf("October");
  }else if(strcmp(month, "November") == 0){
    printf("November");
  }else if(strcmp(month, "December") == 0){
    printf("December");
  }

  printf(", %d.\n", atoi(year));
  
  printf("My angel, let me tell you the same date in another format that will melt your heart. Please wait a moment...\n");

  for(i=0; i<strlen(month); i++){
    month[i] = tolower(month[i]);
  }
  
  if(strcmp(month, "january") == 0){
    printf("On the first month of the year, we experienced love like no other. The day was %d of January, %d.\n", day, atoi(year));
  }else if(strcmp(month, "february") == 0){
    printf("Ah, February. The month of love and longing. We fell deeper in love on the %dth of February, %d.\n", day, atoi(year));
  }else if(strcmp(month, "march") == 0){
    printf("March, the month when winter fades away and new life blooms. Our love bloomed on the %dth of March, %d.\n", day, atoi(year));
  }else if(strcmp(month, "april") == 0){
    printf("On April, we found each other. And on the %dth of April, we knew we were meant to be. %d.\n", day, atoi(year));
  }else if(strcmp(month, "may") == 0){
    printf("May, a month of sunshine and warmth. Our love shone like a bright star on the %dth of May, %d.\n", day, atoi(year));
  }else if(strcmp(month, "june") == 0){
    printf("In June, our love blossomed like a summer flower. The %dth of June will forever be special to us. %d.\n", day, atoi(year));
  }else if(strcmp(month, "july") == 0){
    printf("On the hottest month of the year, we found the warmth in each other. The %dth of July, %d.\n", day, atoi(year));
  }else if(strcmp(month, "august") == 0){
    printf("August, the month of vacations and lazy afternoons. We spent a beautiful day on the %dth of August, %d.\n", day, atoi(year));
  }else if(strcmp(month, "september") == 0){
    printf("September, the month of new beginnings. Our love story started on the %dth of September, %d.\n", day, atoi(year));
  }else if(strcmp(month, "october") == 0){
    printf("October, the month of pumpkins and magic. A magic moment happened on the %dth of October, %d.\n", day, atoi(year));
  }else if(strcmp(month, "november") == 0){
    printf("On November, we realized how much we love each other. The %dth of November, %d.\n", day, atoi(year));
  }else if(strcmp(month, "december") == 0){
    printf("December, the month of snow and Christmas lights. Our love shone brighter than any light on the %dth of December, %d.\n", day, atoi(year));
  }

  return 0;
}