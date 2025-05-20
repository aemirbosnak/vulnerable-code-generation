//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPrime(int n){
  if(n<=1) return 0;
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0) return 0;
  }
  return 1;
}

int gcd(int a, int b){
  if(a==0) return b;
  return gcd(b%a,a);
}

int findPublicKey(int phi){
  int publicKey;
  for(publicKey=2;publicKey<phi;publicKey++){
    if(gcd(publicKey,phi) == 1){
      return publicKey;
    }
  }
  return 0;
}

int findPrivateKey(int publicKey, int phi){
  int privateKey = 1;
  while(1){
    if( (publicKey * privateKey)%phi == 1){
      return privateKey;
    }
    privateKey++;
  }
}

int encrypt(int message, int publicKey, int p){
  int encrypted = 1;
  while(publicKey){
    if(publicKey&1){
      encrypted = (encrypted*message)%p;
    }
    message = (message*message)%p;
    publicKey >>= 1;
  }
  return encrypted;
}

int decrypt(int message, int privateKey, int p){
  int decrypted = 1;
  while(privateKey){
    if(privateKey&1){
      decrypted = (decrypted*message)%p;
    }
    message = (message*message)%p;
    privateKey >>= 1;
  }
  return decrypted;
}

int main(){
  int p,q;
  printf("Enter two prime numbers:\n");
  scanf("%d %d",&p,&q);

  if(!isPrime(p) || !isPrime(q)){
    printf("Wrong input! Both numbers should be prime.\n");
    exit(0);
  }

  int n = p * q;
  int phi = (p-1) * (q-1);
  int publicKey = findPublicKey(phi);
  int privateKey = findPrivateKey(publicKey,phi);

  int message;
  printf("Enter the message to encrypt: ");
  scanf("%d",&message);

  int encrypted = encrypt(message,publicKey,n);
  int decrypted = decrypt(encrypted,privateKey,n);

  printf("The encrypted message is: %d \n",encrypted);
  printf("The decrypted message is: %d \n",decrypted);

  return 0;
}