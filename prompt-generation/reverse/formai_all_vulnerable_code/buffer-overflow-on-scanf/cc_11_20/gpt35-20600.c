//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include<stdio.h>
#include<string.h>

int main(){
   char element[3];
   int score=0;
   printf("Welcome to the Periodic Table Quiz! \n");
   printf("Enter the symbol of the element for the corresponding atomic number\n");
   printf("Press 'q' to exit\n");
   while(1){ //Infinite loop until 'q' is pressed
      printf("1. Hydrogen: ");
      scanf("%s", element);
      if(strcmp(element, "H")==0){
         score+=1;
         printf("Correct! Your score is %d\n\n", score);
      }
      else if(strcmp(element, "q")==0){ //Exit the program
         printf("Thank you for playing the quiz! \n");
         break;
      }
      else{
         printf("Incorrect! The correct answer is H. Your score remains %d\n\n", score);
      }

      printf("2. Iron: ");
      scanf("%s", element);
      if(strcmp(element, "Fe")==0){
         score+=1;
         printf("Correct! Your score is %d\n\n", score);
      }
      else if(strcmp(element, "q")==0){ //Exit the program
         printf("Thank you for playing the quiz! \n");
         break;
      }
      else{
         printf("Incorrect! The correct answer is Fe. Your score remains %d\n\n", score);
      }

      printf("3. Oxygen: ");
      scanf("%s", element);
      if(strcmp(element, "O")==0){
         score+=1;
         printf("Correct! Your score is %d\n\n", score);
      }
      else if(strcmp(element, "q")==0){ //Exit the program
         printf("Thank you for playing the quiz! \n");
         break;
      }
      else{
         printf("Incorrect! The correct answer is O. Your score remains %d\n\n", score);
      }
      
      printf("4. Gold: ");
      scanf("%s", element);
      if(strcmp(element, "Au")==0){
         score+=1;
         printf("Correct! Your score is %d\n\n", score);
      }
      else if(strcmp(element, "q")==0){ //Exit the program
         printf("Thank you for playing the quiz! \n");
         break;
      }
      else{
         printf("Incorrect! The correct answer is Au. Your score remains %d\n\n", score);
      }

      printf("5. Sodium: ");
      scanf("%s", element);
      if(strcmp(element, "Na")==0){
         score+=1;
         printf("Correct! Your score is %d\n\n", score);
      }
      else if(strcmp(element, "q")==0){ //Exit the program
         printf("Thank you for playing the quiz! \n");
         break;
      }
      else{
         printf("Incorrect! The correct answer is Na. Your score remains %d\n\n", score);
      }
   }
   return 0;
}