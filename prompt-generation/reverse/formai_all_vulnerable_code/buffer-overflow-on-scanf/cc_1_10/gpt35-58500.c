//FormAI DATASET v1.0 Category: Unit converter ; Style: medieval
#include<stdio.h>

int main(){

  float length_in_cm,hours_in_min;

  printf("Greetings traveler! I am the unit converter, here to assist thee with all of your measurement needs.\n");
  printf("\n\nFirst tell me of what thou wishes to convert? Length or time?\n");

  char choice[10];

  scanf("%s",choice);

  if(strcmp(choice,"length")==0){

  printf("\n\nThen tell me your length in cm, and I shall convert it to inches, feet, and yards.\n");

  scanf("%f",&length_in_cm);

  float length_in_inches=length_in_cm/2.54;

  float length_in_feet=length_in_inches/12;

  float length_in_yards=length_in_feet/3;

  printf("\nYour length in inches is: %f \n\nYour length in feet is: %f \n\nYour length in yards is: %f",length_in_inches,length_in_feet,length_in_yards);

  printf("\n\nMay you find this helpful in your travels!\n");

  }

  else if(strcmp(choice,"time")==0){

  printf("\n\nThen tell me how many hours you wish to convert to minutes, and I shall do so.\n");

  scanf("%f",&hours_in_min);

  float time_in_min=hours_in_min*60;

  printf("\nYour time in minutes is: %f \n\nMay you find this helpful in your travels!\n",time_in_min);

  }

  else{

  printf("I'm sorry, I didn't understand that input. Please try again.");

  }

  return 0;
}