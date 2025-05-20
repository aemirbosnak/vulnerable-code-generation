//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num){
  if(num == 1){
    return false;
  }
  for(int i = 2; i <= num / 2; ++i){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}

int* generate_primes(int n){
  if(n <= 0){
    printf("Error: Number must be greater than 0.\n");
    return NULL;
  }
  int* primes = malloc(sizeof(int) * n);
  if(primes == NULL){
    printf("Error: Memory allocation failed.\n");
    return NULL;
  }
  int count = 0;
  int i = 2;
  while(count < n){
    if(is_prime(i)){
      primes[count++] = i;
    }
    ++i;
  }
  return primes;
}

int main(){
  int n;
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &n);
  
  int* primes = generate_primes(n);
  
  if(primes == NULL){
    return 1;
  }
  
  printf("The first %d prime numbers are: ", n);
  for(int i = 0; i < n; ++i){
    printf("%d ", primes[i]);
  }
  printf("\n");
  
  free(primes);
  return 0;
}