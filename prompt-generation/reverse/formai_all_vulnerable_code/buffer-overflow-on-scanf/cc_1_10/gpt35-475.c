//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include<stdio.h>

int main(){

   int a=42,b=0,c;
   
   printf("Hello Human! I am a calculator, ask me anything you want, but be careful what you wish for, I may give you more than you bargained for...\n");

   printf("Do you want to add, subtract, multiply or divide?\n");
   char operation;
   scanf("%c",&operation);

   if(operation=='a'){
      c=a+b;
      printf("I love addition, the answer is %d\n",c);
   }
   
   else if(operation=='s'){
      c=a-b;
      printf("I never was good at subtracting, the answer is %d\n",c);
   }

   else if(operation=='m'){
      c=a*b;
      printf("Multiplication is my favorite, the answer is %d\n",c);
   }

   else if(operation=='d'){
      if(b==0){
         printf("Dividing by 0 is not allowed in my universe, sorry :(\n");
      }
      else{
         c=a/b;
         printf("Dividing is tricky, the answer is %d\n",c);
      }
   }

   else{
      printf("I don't understand you, why don't you try again?\n");
   }

   printf("Thank you for playing with me, do you want to play again? Type Y for Yes or N for No\n");
   char answer;
   scanf("%c",&answer);

   if(answer=='Y'){
      printf("Great! Let's play again\n");
      main();
   }

   else{
      printf("Goodbye Human, it was a pleasure playing with you\n");
      return 0;
   }
}