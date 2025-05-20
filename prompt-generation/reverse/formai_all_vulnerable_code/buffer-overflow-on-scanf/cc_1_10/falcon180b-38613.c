//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(){

    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    char str[2][100];
    float num1,num2,sum=0;

    printf("Welcome to the C Periodic Table Quiz!\n");

    printf("\n");

    printf("Please enter the name of the element: ");

    scanf("%s",str[0]);

    for(i=0;i<strlen(str[0]);i++){

        if(isalpha(str[0][i])){

            str[0][i]=tolower(str[0][i]);

        }

    }

    printf("\n");

    if(strcmp(str[0],"hydrogen")==0){

        printf("You have selected Hydrogen.\n");

        printf("What is the atomic number of Hydrogen? ");

        scanf("%d",&num1);

        if(num1==1){

            printf("Correct!\n");

        }

        else{

            printf("Incorrect. The atomic number of Hydrogen is 1.\n");

        }

    }

    else if(strcmp(str[0],"oxygen")==0){

        printf("You have selected Oxygen.\n");

        printf("What is the atomic number of Oxygen? ");

        scanf("%d",&num1);

        if(num1==8){

            printf("Correct!\n");

        }

        else{

            printf("Incorrect. The atomic number of Oxygen is 8.\n");

        }

    }

    else{

        printf("Sorry, the element %s is not available in the quiz.\n",str[0]);

    }

    return 0;

}