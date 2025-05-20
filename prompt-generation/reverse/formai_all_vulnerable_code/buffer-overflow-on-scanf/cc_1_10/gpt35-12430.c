//FormAI DATASET v1.0 Category: Dice Roller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

int num_dice, num_sides, total; 
int i,j;


//Seed the random number generator using the current time 
srand(time(NULL)); 

//Get user input on the number of dice and number of sides 
printf("\nEnter the number of dice you want to roll: ");
scanf("%d",&num_dice);

printf("\nEnter the number of sides each die should have: ");
scanf("%d",&num_sides);

total=0;


//Roll the dice
for(i=0;i<num_dice;i++) {

//Generate a random number between 1 and num_sides
int roll = rand() % num_sides + 1;

//Add the roll to the total
total += roll;

//Print out each dice roll
printf("\nDice %d: %d",i+1,roll);

}


//Print out total of all dice rolls
printf("\n\nTotal: %d",total);


//Ask user if they want to roll again
char choice;
printf("\n\nRoll again? (y/n): ");
scanf(" %c",&choice);

if(choice=='y') {
main();
}
else {
printf("\nThanks for playing!\n");
}
return 0;
}