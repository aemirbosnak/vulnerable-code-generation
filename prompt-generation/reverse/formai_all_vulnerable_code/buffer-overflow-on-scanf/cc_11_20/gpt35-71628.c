//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
  char password[50];
  int length, upper=0, lower=0, digit=0, special=0, score=0;
  
  printf("Please enter your password:\n");
  scanf("%s", password);

  length = strlen(password);

  for(int i = 0; i < length; i++) {
    if(password[i] >= 'A' && password[i] <= 'Z') {
      upper++;
    }
    else if(password[i] >= 'a' && password[i] <= 'z') {
      lower++;
    }
    else if(password[i] >= '0' && password[i] <= '9') {
      digit++;
    }
    else {
      special++;
    }
  }

  score = (length * 4) + (upper * 5) + (lower * 3) + (digit * 2) + (special * 6);

  printf("\nProcessing your password. Please wait a moment...\n\n");

  if(score >= 200) {
    printf("Wow, your password is awesome! Its score is %d!\n", score);
    printf("You must be a savior of the digital world!\n");
  }
  else if(score >= 150) {
    printf("Your password is fairly decent. Its score is %d.\n", score);
    printf("But come on, you can make it even better!\n");
  }
  else if(score >= 100) {
    printf("Your password is mediocre. It scored %d.\n", score);
    printf("You need to improve it, or you'll be an easy target for hackers!\n");
  }
  else {
    printf("Whoa, hold up! Your password is way too weak. Its score is only %d.\n", score);
    printf("You need to change it ASAP or you're as good as hacked!\n");
  }

  return 0;
}