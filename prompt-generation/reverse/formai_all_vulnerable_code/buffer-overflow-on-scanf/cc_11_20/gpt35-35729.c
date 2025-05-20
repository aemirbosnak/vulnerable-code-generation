//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand((unsigned) time(&t));
    int num = rand() % 10 + 1;
 
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I am here to provide you with your destiny!\n");
    printf("Let us start with your first decision.\n\n");
 
    char choice1;
    printf("Do you want to choose (L)ove or (D)eath?\n");
    scanf("%c", &choice1);
 
    if (choice1 == 'L') {
        char choice2;
        printf("\nYou have chosen Love. What is your zodiac sign?\n");
        printf("(A)ries\n(B)Taurus\n(C)Gemini\n(D)Cancer\n(E)Leo\n(F)Virgo\n(G)Libra\n(H)Scorpio\n(I)Sagittarius\n(J)Capricorn\n(K)Aquarius\n(L)Pisces\n");
        scanf(" %c", &choice2);
 
         switch(choice2) {
             case 'A': 
             case 'F':
                 printf("\nYour fortune: You will find true love with someone who is your complete opposite.\n");
                 break;
             case 'B':
             case 'C':
             case 'D':
             case 'E':
                 printf("\nYour fortune: You will experience heartbreak before finding your true love.\n");
                 break;
             case 'G':
             case 'H':
             case 'I':
                 printf("\nYour fortune: You will find love where you least expect it.\n");
                 break;
             case 'J':
             case 'K':
             case 'L':
                 printf("\nYour fortune: You will have a secret admirer that will soon confess their love for you.\n");
                 break;
             default:
                 printf("Invalid choice. Try again.\n");
                 break;
         }
     } else if (choice1 == 'D') {
         int choice3;
         printf("\nYou have chosen Death. Please choose a number between 1 and 10.\n");
         scanf("%d", &choice3);
 
         if (choice3 == num) {
             printf("\nYour fortune: You will die a tragic death like Romeo and Juliet.\n");
         } else {
             printf("\nYour fortune: You will live a long and fulfilling life.\n");
         }
     } else {
         printf("Invalid choice. Try again.\n");
     }
 
     printf("\nThank you for using the Automated Fortune Teller!\n");
     return 0;
}