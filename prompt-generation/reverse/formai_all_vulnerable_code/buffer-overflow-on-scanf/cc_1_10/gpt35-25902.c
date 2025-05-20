//FormAI DATASET v1.0 Category: Binary Converter ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter a decimal number: ");
    scanf("%d",&n);
    int binary[32],i=0;   
    while(n>0){    //Converting decimal to binary
        binary[i]=n%2;
        n=n/2;
        i++; 
    }
    printf("The binary equivalent is: ");
    for(i=i-1;i>=0;i--){   //Printing binary number in reverse order
        printf("%d",binary[i]);
    }
    printf("\n\n\nWelcome to the Surreal C Binary Converter!\n");
    printf("In this program, we won't be converting normal decimal numbers to binary.\n");
    printf("No, we'll be converting imaginary numbers from a parallel universe to binary!\n");
    printf("Let's start with a little math equation. Ready? 1 + 1 = ?\n");
    printf("Enter your answer: ");
    int answer;
    scanf("%d",&answer);
    if(answer==11){
        printf("Whoa, you're good at this! Welcome to the parallel universe where numbers defy logic.\n");
    }
    else{
        printf("Sorry, wrong answer. We can't let you enter the parallel universe with that kind of math skills.\n");
        printf("Better luck next time!\n");
        exit(0);    //Program ends if user enters the wrong answer
    }
    printf("Now, let's enter the imaginary number you'd like to convert to binary.\n");
    float imaginary;
    printf("Enter the real part: ");
    float real;
    scanf("%f",&real);
    printf("Enter the imaginary part: ");
    scanf("%f",&imaginary);
    printf("Processing your number...\n");
    printf("...");
    printf("...");
    printf("...");
    printf("Done!\n");
    printf("Here's your number in binary: ");
    printf("%.0f",real);    //Printing real part in binary
    printf(".");   
    int imaginary_int=imaginary*100;    //Multiplying imaginary part by 100 to convert to integer
    int imaginary_binary[16], j=0;
    while(imaginary_int>0){    //Converting imaginary part to binary
        imaginary_binary[j]=imaginary_int%2;
        imaginary_int=imaginary_int/2;
        j++; 
    }
    for(j=j-1;j>=0;j--){    //Printing imaginary part in binary
        printf("%d",imaginary_binary[j]);
    }
    printf("\n\nThank you for using the Surreal C Binary Converter! Come back anytime.\n");
    return 0;    
}