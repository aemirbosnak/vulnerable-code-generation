//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include<stdio.h>
#include<math.h>

/* Happy New Year! We are going to draw a multicolored Christmas tree using geometric algorithms.*/

int main(){

    int levels;
    printf("Let's draw a multicolored Christmas tree! Choose the number of levels between 3 and 7: ");
    scanf("%d", &levels);

    if(levels<3 || levels> 7){
        printf("Oops! We cannot draw a tree with %d levels :( Please choose a number between 3 and 7\n", levels);
        return 0;
    }
    else{
        printf("HoHoHo! Get ready for the fun! Here's your multicolored Christmas tree with %d levels:\n", levels);
    }

    int width = pow(2,levels)-1; //calculate the width of the base of the tree
    int i,j,k;

    //draw the tree
    for(i=1;i<=levels;i++){
        for(j=1;j<=levels-i;j++){
            printf(" ");
        }
        for(k=1;k<=2*i-1;k++){
           if(i%3==1){
               printf("\x1b[31m"); //color red
           }
           else if(i%3==2){
               printf("\x1b[32m"); //color green
           }
           else{
               printf("\x1b[34m"); //color blue
           }
           printf("*");
        }
        printf("\n");
    }

    //draw the base of the tree
    for(i=1;i<=width;i++){
        printf("\x1b[33m"); //color yellow
        printf("=");
    }
    printf("\n");

    return 0;
}