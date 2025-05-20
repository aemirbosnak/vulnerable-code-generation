//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
  char password[20];
  int uppercase = 0, lowercase = 0, number = 0, symbol = 0, length = 0;
  
  printf("Enter password: ");
  scanf("%s", password);

  length = strlen(password);
  
  for(int i = 0; i < length; i++){
    if(isupper(password[i])){
      uppercase++;
    }
    else if(islower(password[i])){
      lowercase++;
    }
    else if(isdigit(password[i])){
      number++;
    }
    else if(!isdigit(password[i]) && !isalpha(password[i])){
      symbol++;
    }
  }

  printf("Password strength: ");
  // Check length
  if(length < 8){
    printf("Weak (minimum length is 8 characters)\n");
  }
  // Check uppercase letters
  else if(uppercase < 1){
    printf("Weak (include at least 1 uppercase letter)\n");
  }
  // Check lowercase letters
  else if(lowercase < 1){
    printf("Weak (include at least 1 lowercase letter)\n");
  }
  // Check numbers
  else if(number < 1){
    printf("Weak (include at least 1 number)\n");
  }
  // Check symbols
  else if(symbol < 1){
    printf("Weak (include at least 1 symbol)\n");
  }
  // Strong password
  else{
    printf("Strong\n");
  }

  return 0;
}