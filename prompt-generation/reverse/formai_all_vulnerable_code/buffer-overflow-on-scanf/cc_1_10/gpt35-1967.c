//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include<stdio.h>

int main(){

  printf("Welcome to our Cafe. We only serve Coffee and Tea \n");

  int choice, quantity;
  float price;

  printf("Which do you prefer? Coffee (1) or Tea (2)?\n");
  scanf("%d",&choice);

  if(choice==1){

    printf("Great Choice! How many cups would you like to have?\n");
    scanf("%d",&quantity);

    if(quantity<1){
      printf("Sorry, we cannot serve you less than 1 cup. \n");
    } else if(quantity>10){
      printf("Sorry, we cannot serve you more than 10 cups at a time. \n");
    } else {
      price = quantity * 2.5; // Each cup of coffee costs 2.5 dollars
      printf("That would be %.2f dollars. \n", price);
    }

  } else if(choice==2){

    printf("Great Choice! How many cups would you like to have? \n");
    scanf("%d",&quantity);

    if(quantity<1){
      printf("Sorry, we cannot serve you less than 1 cup. \n");
    } else if(quantity>5){
      printf("Sorry, we cannot serve you more than 5 cups at a time. \n");
    } else {
      price = quantity * 2; // Each cup of tea costs 2 dollars
      printf("That would be %.2f dollars. \n", price);
    }

  } else {

    printf("Sorry, we do not have that on our menu. \n");

  }

  printf("Thank you for stopping by! Come back soon. \n");

  return 0;
}