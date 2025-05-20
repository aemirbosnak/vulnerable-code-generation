//FormAI DATASET v1.0 Category: Funny ; Style: curious
#include <stdio.h>

int main()
{
   int num1, num2, sum;
   printf("Enter two numbers to add: ");
   scanf("%d %d",&num1,&num2);
   if(num1 == 0 && num2 == 0)
   {
       printf("Well, you entered two zeros, so the sum is... um... well, zero!");
   }
   else
   {
       sum = num1 + num2;
       printf("The sum of %d and %d is %d\n", num1, num2, sum);
       printf("But wait, there's more! \n");
       printf("Now let's mix things up! \n");
       printf("How about we add %d and %d in a different order? \n", num2, num1);
       int sum2 = num2 + num1;
       printf("The sum of %d and %d is %d\n", num2, num1, sum2);
       if(sum == sum2)
       {
           printf("What sorcery is this? The sums are the same! \n");
           printf("You just accidentally discovered the commutative property of addition! \n");
           printf("Congrats! You're a math genius. \n");
       }
       else
       {
           printf("These sums aren't equal. Trippy. \n");
           printf("Alright, let's keep going. \n");
           printf("How about we add %d and %d together again? \n", sum, sum2);
           int sum3 = sum + sum2;
           printf("The sum of %d and %d is %d\n", sum, sum2, sum3);
           if(sum3%2 == 0)
           {
               printf("Hooray, this sum is even! \n");
               printf("But wait, there's more! \n");
               printf("Now let's do something really crazy. \n");
               printf("How about we divide this sum by 2? \n");
               int sum4 = sum3/2;
               printf("The quotient is %d\n", sum4);
               printf("Woohoo, we made it! \n");
               printf("Thanks for playing this fun little game of math with me. \n");
           }
           else
           {
               printf("Hmm, this sum is odd. How interesting. \n");
               printf("Well, let's keep going anyway. \n");
               printf("How about we multiply this sum by 3? \n");
               int sum4 = sum3*3;
               printf("The product is %d\n", sum4);
               printf("At this point, I'm not sure what we're doing anymore, but let's keep going. \n");
               printf("How about we subtract %d from this product? \n", sum2);
               int sum5 = sum4 - sum2;
               printf("The difference is %d\n", sum5);
               printf("What a ride that was! Thanks for playing along. \n");
           }
       }
   }
   return 0;
}