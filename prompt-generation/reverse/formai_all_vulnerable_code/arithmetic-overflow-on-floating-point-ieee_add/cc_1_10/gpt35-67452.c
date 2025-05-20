//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c,d,e;
    float x,y,z;
    char ch;

    printf("Enter two integers:");
    scanf("%d %d",&a,&b);

    c = a+b;
    printf("\nSum of %d and %d is %d\n",a,b,c);

    if(a>b)
    {
        d = a-b;
        printf("%d subtracted from %d is %d\n",b,a,d);
    }
    else if(b>a)
    {
        d = b-a;
        printf("%d subtracted from %d is %d\n",a,b,d);
    }
    else
    {
        printf("%d and %d are equal\n",a,b);
    }

    printf("Enter a character:");
    scanf(" %c",&ch);
    printf("ASCII value of %c is %d\n",ch,ch);

    printf("Enter three floating point numbers:");
    scanf("%f %f %f",&x,&y,&z);

    e = (int)(x+y+z);
    printf("\nSum of %f, %f and %f when converted to integer is %d\n",x,y,z,e);

    if(x>y)
    {
        if(x>z)
        {
            printf("%f is the biggest among %f, %f and %f\n",x,x,y,z);
        }
        else
        {
            printf("%f is the biggest among %f, %f and %f\n",z,x,y,z);
        }
    }
    else if(y>x)
    {
        if(y>z)
        {
            printf("%f is the biggest among %f, %f and %f\n",y,x,y,z);
        }
        else
        {
            printf("%f is the biggest among %f, %f and %f\n",z,x,y,z);
        }
    }
    else
    {
        printf("All three numbers are equal\n");
    }

    return 0;
}