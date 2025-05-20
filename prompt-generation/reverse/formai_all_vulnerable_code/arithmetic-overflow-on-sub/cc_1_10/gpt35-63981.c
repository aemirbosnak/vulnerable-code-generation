//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int prime(long int);    //function to check whether a number is prime or not
void generate_key(long int *, long int *);    //function to generate public and private keys
long int encrypt(unsigned char *, long int, long int, long int);  //function to encrypt the message
void decrypt(long int *, long int, long int, long int);  //function to decrypt the message

int main(){
    long int p, q, n, phi, e, d, plaintext, ciphertext;
    char message[30];
    unsigned char hashed_message[20];
    
    printf("Enter the message to be encrypted: ");
    fgets(message, 30, stdin);  
    
    //hash the message
    for(int i=0; i< strlen(message); i++){
        hashed_message[i] = toupper(message[i]);  //convert each character to uppercase
    }
    
    //generate prime numbers
    printf("Enter two prime numbers:\n");
    scanf("%ld%ld",&p,&q);
    
    //check if they are prime or not
    if(prime(p)==0 || prime(q)==0){
        printf("Invalid Input! Both numbers are not prime.\n");
        exit(0);
    }
    
    //calculate n, phi and e
    n = p*q;
    phi = (p-1)*(q-1);
    generate_key(&e, &d);
    
    //encrypt the message
    ciphertext = encrypt(hashed_message, strlen(message), e, n);
    printf("\n\nEncrypted Message : %ld",ciphertext);

    //decrypt the message
    decrypt(&ciphertext, d, n, strlen(message));
    
    return 0;
}

int prime(long int number){
    int i;
    for(i = 2; i <= number/2; i++){
      if(number % i == 0){
         return 0;  //number is not prime
      }
   }
   return 1;    //number is prime
}

void generate_key(long int *e, long int *d){
    long int phi, gcd, flag;
    do{
        *e = rand()%100+1;   //generating random number between 1 to 100
        phi=2811;     //hard-coded value of phi to save time
        gcd=1;
        while(gcd!=1){
            *e=rand()%phi;
            for(long int i=2;i<*e;i++){
                if((*e)%i==0){
                    flag=1;
                    break;
                }
            }
            if(!flag && *e!=phi && *e!=1){
                for(long int j=2;j<=phi;j++){
                    if(((j**e)-1)%phi==0){
                        *d=j;
                        break;
                    }
                }
                gcd=1;
            }
            flag=0;
        }
    }while(gcd!=1);
    printf("\nPublic Key : (%ld,%ld)",*e,2811);
    printf("\nPrivate Key : (%ld,%ld)",*d,2811);
}

long int encrypt(unsigned char * message, long int len, long int e, long int n){
    long int i, cipher = 1;
    for(i = 0; i < len; i++){
        cipher = cipher*pow(message[i],e);
        cipher = cipher%n;
    }
    return cipher;
}

void decrypt(long int *message, long int d, long int n, long int len){
    long int i, cipher = 1;
    for(i = 0; i < len; i++){
        cipher = cipher*pow(*message,d);
        cipher = cipher%n;
    }
    printf("\nDecrypted Message : ");
    for(i = len-1; i >= 0; i--){
        printf("%c", cipher%256);
        cipher = cipher/256;
    }
    printf("\n");
}