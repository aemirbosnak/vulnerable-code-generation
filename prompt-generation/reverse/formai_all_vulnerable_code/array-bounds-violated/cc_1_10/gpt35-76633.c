//FormAI DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int i, j, k, l;
  int guess;
  int count;
  int table[4][4];
  srand(time(0));
  
  printf("*** WELCOME TO THE TREASURE HUNT GAME ***\n\n");
  printf("Guess the location of the treasure buried in a 4 x 4 table.\n");
  printf("You have 5 chances to guess. Good luck!\n\n");
  
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      table[i][j] = rand() % 2;
    }
  }
  
  for(count = 1; count <= 5; count++){
    printf("Guess #%d: ", count);
    scanf("%d", &guess);
    printf("\n");
    
    k = guess / 10;
    l = guess % 10;
    
    if(table[k][l] == 1){
      printf("Congratulations! You found the treasure.\n");
      return 0;
    }
    else{
      if(count < 5){
        printf("Sorry! The treasure is not at that location. Try again.\n");
      }
      else{
        printf("Sorry! You've used up all your chances. The treasure was at:\n");
      }
    }
  }
  
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      if(table[i][j] == 1){
        printf("%d%d\n", i, j);
      }
    }
  }
  return 0;
}