//FormAI DATASET v1.0 Category: Computer Biology ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int DNA[4]; // declaring array for storing the genetic code
  
  printf("Enter the genetic code (A=0, T=1, G=2, C=3):\n");
  for(int i=0; i<4; i++) {
    scanf("%d", &DNA[i]); // getting the input from user
  }

  // checking if the genetic code is valid or not
  int valid = 0;
  for(int i=0; i<4; i++) {
     if(DNA[i] != 0 && DNA[i] != 1 && DNA[i] != 2 && DNA[i] != 3) {
        valid = 1;
        break;
     }
  }

  if(valid == 1) {
    printf("Invalid genetic code entered!\n");
    exit(0);
  }

  // if the genetic code is valid
  printf("The genetic code is: ");
  for(int i=0; i<4; i++) {
    printf("%d", DNA[i]); // printing the genetic code
  }

  // checking if the genetic code is a palindrome or not
  int palindrome = 1;
  for(int i=0; i<2; i++) {
    if(DNA[i] != DNA[3-i]) {
      palindrome = 0;
      break;
    }
  }

  if(palindrome == 1) {
    printf("\nThe genetic code is a palindrome!\n");
  } else {
    printf("\nThe genetic code is not a palindrome.\n");
  }

  // checking if the genetic code is a sequence or not
  int sequence = 1;
  for(int i=0; i<3; i++) {
    if(DNA[i] == DNA[i+1]) {
      sequence = 0;
      break;
    }
  }

  if(sequence == 1) {
    printf("The genetic code is a sequence!\n");
  } else {
    printf("The genetic code is not a sequence.\n");
  }

  // calculating the GC content of the genetic code
  double gc_content = 0;
  for(int i=0; i<4; i++) {
    if(DNA[i] == 2 || DNA[i] == 3) {
      gc_content++;
    }
  }
  gc_content /= 4.0;
  gc_content *= 100.0;

  if(gc_content > 50.0) {
    printf("The GC content of the genetic code is %.2lf%%, which is shocking!\n", gc_content);
  } else {
    printf("The GC content of the genetic code is %.2lf%%.\n", gc_content);
  }

  return 0;
}