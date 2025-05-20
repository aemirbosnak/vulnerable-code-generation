//FormAI DATASET v1.0 Category: Data validation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  char name[30], id[10], age[3];
  int flag = 0;
  
  printf("Please enter your name: ");
  scanf("%s", name);
  
  for(int i=0; i<strlen(name); i++) {
    if(!isalpha(name[i])) {
      flag = 1;
      break;
    }
  }
  
  if(flag == 1) {
    printf("Invalid input! Name should only contain alphabets.\n");
    return 0;
  }
  
  printf("Please enter your ID: ");
  scanf("%s", id);
  
  if(strlen(id) != 9) {
    printf("Invalid input! ID should be 9 characters long.\n");
    return 0;
  }
  
  for(int i=0; i<strlen(id); i++) {
    if(!isdigit(id[i])) {
      printf("Invalid input! ID should only contain digits.\n");
      return 0;
    }
  }
  
  printf("Please enter your age: ");
  scanf("%s", age);
  
  if(strlen(age) > 2 || !isdigit(age[0])) {
    printf("Invalid input! Age should only contain digits and can not be more than 2 digits.\n");
    return 0;
  }
  
  printf("Name: %s\nID: %s\nAge: %s\n", name, id, age);
  
  return 0;
}