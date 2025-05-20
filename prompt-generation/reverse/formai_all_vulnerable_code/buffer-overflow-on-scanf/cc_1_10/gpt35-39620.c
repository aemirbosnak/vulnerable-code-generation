//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to check if a number is prime or not
// Returns 1 if prime, else 0
int is_prime(int num){
    int i;
    if(num<=1)
        return 0;
    for(i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

// Function to get a random prime number between 1 and n
int get_prime(int n){
    int num;
    do{
        num = rand()%n + 1;
    }while(!is_prime(num));
    return num;
}

// Function to calculate gcd of two numbers
int gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

// Function to calculate x raised to the power y
int powermod(int x, int y, int n){
    int res=1;
    while(y){
        if(y&1)
            res=(res*x)%n;
        x=(x*x)%n;
        y>>=1;
    }
    return res;
}

// Function to find the inverse of a mod m
int mod_inverse(int a, int m){
    a = a%m;
    int x,y;
    for(x=1;x<m;x++){
        if((a*x)%m==1)
            return x;
    }
}

// Function to implement the public key algorithm
void public_key_algorithm(){
    int p,q,n,e,d,phi,m,c;
    printf("Enter two large prime numbers:\n");
    scanf("%d%d",&p,&q);
    n = p*q;
    phi = (p-1)*(q-1);
    do{
        e = get_prime(phi);
    }while(gcd(phi,e)!=1);
    d = mod_inverse(e,phi);
    printf("Enter the message to be encrypted:\n");
    scanf("%d",&m);
    c = powermod(m,e,n);
    printf("The encrypted message is: %d\n",c);
    m = powermod(c,d,n);
    printf("The decrypted message is: %d",m);
}

// Main function
int main(){
    public_key_algorithm();
    return 0;
}