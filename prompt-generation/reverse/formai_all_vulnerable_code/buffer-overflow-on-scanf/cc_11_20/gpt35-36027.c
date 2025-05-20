//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char name[20];
  char response[20];
  int fortune_num;
  
  printf("Welcome to the Automated Fortune Teller.\n");
  printf("What is your name? ");
  scanf("%s", name);
  printf("Hello, %s! Are you ready to receive your fortune? (yes/no) ", name);
  scanf("%s", response);
  
  if (strcmp(response, "yes") == 0) {
    printf("Ok, let me consult the stars...\n");
    srand(time(0));
    fortune_num = rand() % 10 + 1;
    
    switch(fortune_num) {
      case 1:
        printf("%s, you will soon come into a great fortune!\n", name);
        break;
        
      case 2:
        printf("%s, beware of false friends. Watch your back.\n", name);
        break;
        
      case 3:
        printf("%s, your future is looking bright. Keep up the good work!\n", name);
        break;
        
      case 4:
        printf("%s, someone is plotting against you. Be cautious.\n", name);
        break;
        
      case 5:
        printf("%s, your luck is about to change for the better. Look out for opportunities.\n", name);
        break;
        
      case 6:
        printf("%s, you will soon need to make an important decision. Choose wisely.\n", name);
        break;
        
      case 7:
        printf("%s, now is the time to take risks and go after what you want.\n", name);
        break;
        
      case 8:
        printf("%s, your past mistakes will come back to haunt you. Make amends before it's too late.\n", name);
        break;
        
      case 9:
        printf("%s, a new love interest is on the horizon. Be open to new experiences.\n", name);
        break;
        
      case 10:
        printf("%s, bad luck is coming your way. Brace yourself.\n", name);
        break;
        
      default:
        printf("Error: fortune number out of range.\n");
        break;
    }
  }
  else {
    printf("Ok, maybe another time.\n");
  }
  
  return 0;
}