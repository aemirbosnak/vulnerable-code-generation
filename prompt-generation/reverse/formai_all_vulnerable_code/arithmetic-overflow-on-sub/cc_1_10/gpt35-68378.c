//FormAI DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <string.h>

int main(){
  char words[100][100]; 
  int i, j, count, n;
  char temp[100];

  // medieval theme introduction
  printf("Greetings, noble knights and courtiers!\nI present to thee the finest spell checking program in all the land!\nPlease enter the number of words thou wishes to check: ");
  scanf("%d", &n);

  // loop for user input of words to be spell checked
  for(i=0; i<n; i++){
    printf("Enter word %d: ", i+1);
    scanf("%s", words[i]);
  }

  // medieval theme messaging of sorting the words
  printf("Verily, the words shall now be sorted alphabetically...\n");

  // bubble sort to alphabetically sort the words
  for(i=0; i<n-1; i++){
    for(j=i+1; j<n; j++){
      if(strcmp(words[i], words[j]) > 0){
        strncpy(temp, words[i], sizeof(temp)-1);
        temp[sizeof(temp)-1] = '\0';
        strncpy(words[i], words[j], sizeof(words[i])-1);
        words[i][sizeof(words[i])-1] = '\0';
        strncpy(words[j], temp, sizeof(words[j])-1);
        words[j][sizeof(words[j])-1] = '\0';
      }
    }
  }

  // medieval theme messaging of completed sorting
  printf("Huzzah! The sorting is complete!\n");

  // loop to spell check each word
  for(i=0; i<n; i++){
    count = 0; // initialize count to 0 for each word iteration

    //loop to check each alphabet of the word
    for(j=0; j<strlen(words[i]); j++){
      // if alphabet is not a letter, consider as a spelling mistake
      if(!isalpha(words[i][j])){
        count++;
      }
    }

    // if count is greater than 0, printing message of an error in spelling
    if(count > 0){
      printf("Alack! \"%s\" is incorrect in its spelling! Please correct it.\n", words[i]);
    }
  }

  // medieval theme conclusion
  printf("Thus endeth the great spell checking program. Fare thee well, noble adventurers!\n");

  return 0;
}