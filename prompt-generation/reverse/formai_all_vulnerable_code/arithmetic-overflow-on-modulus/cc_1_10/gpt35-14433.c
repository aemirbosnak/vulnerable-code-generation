//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

void keyGeneration(int p,int q,int *n,int *e,int *d){
    *n=p*q;
    int phi=(p-1)*(q-1);
    do{
        srand(time(NULL));
        *e=rand()%phi;
    }while(gcd(*e,phi)!=1);
    *d=modInverse(*e,phi);
}

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int modInverse(int a,int m){
    int m0=m,t,q,x0=0,x1=1;
    if(m==1)
        return 0;
    while(a>1){
        q=a/m;
        t=m;
        m=a%m,a=t;
        t=x0;
        x0=x1-q*x0;
        x1=t;
    }
    if(x1<0)
        x1+=m0;
    return x1;
}

int encrypt(int num,int e,int n){
    int i,encr=1;
    for(i=0;i<e;i++)
        encr=((encr%n)*(num%n))%n;
    return encr;
}

int decrypt(int encr,int d,int n){
    int i,num=1;
    for(i=0;i<d;i++)
        num=((num%n)*(encr%n))%n;
    return num;
}

int main(){
    int p,q,n,e,d,msg,i=0,num[MAX],encr[MAX],decr[MAX];

    printf("Enter two prime numbers: ");
    scanf("%d %d",&p,&q);

    keyGeneration(p,q,&n,&e,&d);

    printf("\nEnter message (0 to end): ");
    scanf("%d",&msg);

    while(msg!=0){
        num[i]=msg;
        encr[i]=encrypt(num[i],e,n);
        decr[i]=decrypt(encr[i],d,n);
        i++;
        printf("Enter message (0 to end): ");
        scanf("%d",&msg);
    }

    printf("\nOriginal message: ");
    for(int j=0;j<i;j++)
        printf("%d ",num[j]);

    printf("\nEncrypted message: ");
    for(int j=0;j<i;j++)
        printf("%d ",encr[j]);

    printf("\nDecrypted message: ");
    for(int j=0;j<i;j++)
        printf("%d ",decr[j]);

    printf("\n");
    return 0;
}