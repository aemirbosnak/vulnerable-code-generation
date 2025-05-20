//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include<stdio.h>

int main(){
    int a,b,c;
    printf("Welcome to the arithmetic example program by Dennis Ritchie\n");

    //Addition
    printf("Enter two numbers to perform addition:\n");
    scanf("%d %d",&a,&b);
    c = a+b;
    printf("The sum of %d and %d is %d\n\n",a,b,c);

    //Subtraction
    printf("Enter two numbers to perform subtraction:\n");
    scanf("%d %d",&a,&b);
    c = a-b;
    printf("The difference of %d and %d is %d\n\n",a,b,c);

    //Multiplication
    printf("Enter two numbers to perform multiplication:\n");
    scanf("%d %d",&a,&b);
    c = a*b;
    printf("The product of %d and %d is %d\n\n",a,b,c);

    //Division
    float d,e,f;
    printf("Enter two numbers to perform division:\n");
    scanf("%f %f",&d,&e);
    f = d/e;
    printf("The quotient of %f and %f is %f\n\n",d,e,f);

    //Modulo
    int g,h,i;
    printf("Enter two numbers to perform modulo operation:\n");
    scanf("%d %d",&g,&h);
    i = g%h;
    printf("The remainder of %d divided by %d is %d\n\n",g,h,i);

    //Bitwise AND
    unsigned int j,k,l;
    printf("Enter two numbers (in decimal form) to perform bitwise AND operation:\n");
    scanf("%u %u",&j,&k);
    l = j&k;
    printf("The result of bitwise AND operation on %u and %u is %u\n\n",j,k,l);

    //Bitwise OR
    unsigned int m,n,o;
    printf("Enter two numbers (in decimal form) to perform bitwise OR operation:\n");
    scanf("%u %u",&m,&n);
    o = m|n;
    printf("The result of bitwise OR operation on %u and %u is %u\n\n",m,n,o);

    //Bitwise XOR
    unsigned int p,q,r;
    printf("Enter two numbers (in decimal form) to perform bitwise XOR operation:\n");
    scanf("%u %u",&p,&q);
    r = p^q;
    printf("The result of bitwise XOR operation on %u and %u is %u\n\n",p,q,r);

    printf("Thank you for using the arithmetic example program by Dennis Ritchie.\n");
    return 0;
}