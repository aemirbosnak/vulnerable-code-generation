//Falcon-180B DATASET v1.0 Category: Educational ; Style: puzzling
#include<stdio.h>

int main(){
    int a,b,c,d,e;
    printf("Enter the value of a:\n");
    scanf("%d",&a);
    printf("Enter the value of b:\n");
    scanf("%d",&b);
    printf("Enter the value of c:\n");
    scanf("%d",&c);
    printf("Enter the value of d:\n");
    scanf("%d",&d);
    printf("Enter the value of e:\n");
    scanf("%d",&e);
    if(a>b){
        if(b>c){
            if(c>d){
                if(d>e){
                    printf("The largest number is %d",a);
                }else{
                    printf("The largest number is %d",d);
                }
            }else{
                printf("The largest number is %d",c);
            }
        }else{
            if(c>d){
                if(d>e){
                    printf("The largest number is %d",b);
                }else{
                    printf("The largest number is %d",d);
                }
            }else{
                printf("The largest number is %d",c);
            }
        }
    }else{
        if(b>c){
            if(c>d){
                if(d>e){
                    printf("The largest number is %d",b);
                }else{
                    printf("The largest number is %d",d);
                }
            }else{
                printf("The largest number is %d",c);
            }
        }else{
            if(c>d){
                if(d>e){
                    printf("The largest number is %d",c);
                }else{
                    printf("The largest number is %d",d);
                }
            }else{
                printf("The largest number is %d",d);
            }
        }
    }
    return 0;
}