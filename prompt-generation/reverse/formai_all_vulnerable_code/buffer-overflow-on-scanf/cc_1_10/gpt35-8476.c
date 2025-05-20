//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

//Declare variable
char name[20];
int age, birthMonth, luckyNumber, fortuneNum, sum = 0;
char color[10];

printf("Welcome to the automated fortune teller!\n");
printf("Please enter your name: ");
scanf("%s", name);

printf("Please enter your age: ");
scanf("%d", &age);

printf("Please enter the month you were born in (1-12): ");
scanf("%d", &birthMonth);

printf("Please enter your lucky number: ");
scanf("%d", &luckyNumber);

printf("Please enter your favorite color: ");
scanf("%s", color);

//Generate a random fortune number
srand(time(NULL));
fortuneNum = rand() % 100 + 1;

//Calculate sum of digits in fortune number
while(fortuneNum != 0){
    sum += fortuneNum % 10;
    fortuneNum /= 10;
}

//Output fortune
printf("%s, your fortune for today is:\n", name);
printf("Your lucky number for the day is: %d\n", luckyNumber);
if(luckyNumber % 2 == 0)
    printf("Even numbers bring good luck today!\n");
else
    printf("Odd numbers bring good luck today!\n");
if(sum == birthMonth)
    printf("Your lucky color for the day is: %s\n", color);
else
    printf("Your lucky color for the day is: green\n");
if(age == sum)
    printf("Today is a lucky day for you!\n");
else
    printf("Today may bring some challenges, but you are strong enough to overcome them!\n");

return 0;
}