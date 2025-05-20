//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  time_t current_time;
  struct tm *time_info;
  int year,month,day,hour,minute,second;
  int future_year,future_month,future_day,future_hour,future_minute,future_second;
  int past_year,past_month,past_day,past_hour,past_minute,past_second;
  char time_input[20];

  //Get current time
  current_time=time(NULL);
  time_info=localtime(&current_time);

  printf("Welcome to the Time Travel Simulator!\n");

  //Display current time
  printf("\nCurrent date and time is: %s",asctime(time_info));

  //Prompt user for desired year to travel to
  printf("\nEnter the year you wish to travel to: ");
  scanf("%d",&year);

  //Prompt user for desired month
  printf("Enter the month (1-12): ");
  scanf("%d",&month);

  //Prompt user for desired day
  printf("Enter the day (1-31): ");
  scanf("%d",&day);

  //Prompt user for desired hour
  printf("Enter the hour (0-23): ");
  scanf("%d",&hour);

  //Prompt user for desired minute
  printf("Enter the minute (0-59): ");
  scanf("%d",&minute);

  //Prompt user for desired second
  printf("Enter the second (0-59): ");
  scanf("%d",&second);

  //Construct future time structure
  struct tm future_time={0};
  future_time.tm_year=year-1900;
  future_time.tm_mon=month-1;
  future_time.tm_mday=day;
  future_time.tm_hour=hour;
  future_time.tm_min=minute;
  future_time.tm_sec=second;

  //Convert future time to seconds
  time_t future_sec=mktime(&future_time);

  //If future time is before current time, prompt user for a new time
  if(future_sec<=current_time){
    printf("\nError: You cannot travel to the past. Please enter a future time.\n");
    printf("\nEnter the year you wish to travel to: ");
    scanf("%d",&year);
    printf("Enter the month (1-12): ");
    scanf("%d",&month);
    printf("Enter the day (1-31): ");
    scanf("%d",&day);
    printf("Enter the hour (0-23): ");
    scanf("%d",&hour);
    printf("Enter the minute (0-59): ");
    scanf("%d",&minute);
    printf("Enter the second (0-59): ");
    scanf("%d",&second);
    future_time.tm_year=year-1900;
    future_time.tm_mon=month-1;
    future_time.tm_mday=day;
    future_time.tm_hour=hour;
    future_time.tm_min=minute;
    future_time.tm_sec=second;
    future_sec=mktime(&future_time);
  }

  //Calculate difference between current and future time
  double time_diff=difftime(future_sec,current_time);

  //Display time travel information
  printf("\nYou will travel %0.0f seconds into the future.\n",time_diff);
  printf("Destination:\n%s",asctime(&future_time));

  //Prompt user to begin time travel
  printf("\nPress 'Enter' to begin time travel.");
  getchar(); //flush the input buffer
  getchar(); //wait for user to press Enter

  //Calculate current time as seconds since epoch
  time_t start_time=time(NULL);
  
  //Simulate time travel by looping until current time matches future time
  while(difftime(start_time,current_time)<time_diff){
    time_t current=time(NULL);
    printf("\nTime Traveling...%d seconds left", (int)(time_diff-difftime(current,current_time)));
    sleep(1);
  }

  //Display arrival message
  printf("\n\nYou have arrived at your destination!\n");
  
  //return 0 upon success
  return 0;
}