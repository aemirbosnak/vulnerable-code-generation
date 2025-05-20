//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){

    char message[100], ch;
    int p,q,n,phi,e,d,c,i;
    printf("Enter Message: ");
    gets(message);

    printf("Enter two Prime Numbers: ");
    scanf("%d %d",&p,&q);

    n=p*q;
    phi=(p-1)*(q-1);

    for( e=2; e < phi; e++) {
        if(gcd(e,phi) == 1)
            break;
    }

    for( d = 1; d < phi; d++){
        if(((d*e)%phi)==1)
            break;
    }

    printf("Public Key (e,n) : (%d,%d)\n",e,n);
    printf("Private Key (d,n) : (%d,%d)\n",d,n);

    int len=strlen(message);
    long int *encrypted_text=(long int*)calloc(len,sizeof(long int));
    for(i=0;i<len;i++){
        c=message[i];
        encrypted_text[i]=pow(c,e);
        encrypted_text[i]%=n;
    }
    printf("\nEncrypted Message: ");
    for(i=0;i<len;i++){
        printf("%ld ",*(encrypted_text+i));
    }

    printf("\nDecrypted Message: ");
    for(i=0;i<len;i++){
        ch=pow(*(encrypted_text+i),d);
        ch%=n;
        printf("%c",(char)ch);
    }

    free(encrypted_text);
    return 0;
}