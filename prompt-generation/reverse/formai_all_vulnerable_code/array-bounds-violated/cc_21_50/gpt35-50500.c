//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include<stdio.h>
#include<stdlib.h>

int main(){
  char input[100];
  int i, flag=0;
  printf("Enter a C syntax code: ");
  fgets(input, 100, stdin); // Take input from user

  for(i=0; input[i]!='\0'; i++){
    if(input[i]=='(' && input[i+1]!=')'){ 
      flag=1;
      break;
    }
    else if(input[i]=='[' && input[i+1]!=']'){ 
      flag=1;
      break;
    }
    else if(input[i]=='{' && input[i+1]!='}'){ 
      flag=1;
      break;
    }
    else if(input[i]==')' && input[i-1]!='('){ 
      flag=1;
      break;
    }
    else if(input[i]==']' && input[i-1]!='['){ 
      flag=1;
      break;
    }
    else if(input[i]=='}' && input[i-1]!='{'){ 
      flag=1;
      break;
    }
    else if(input[i]=='"' && input[i-1]!='\\' && input[i+1]!='"'){ 
      flag=1;
      break;
    }
    else if(input[i]=='/' && input[i+1]=='/'){
      while(input[i]!='\n'){
        i++;
      }
    }
    else if(input[i]=='/' && input[i+1]=='*'){
      i+=2;
      while(input[i]!='\0'){
        if(input[i]=='*' && input[i+1]=='/'){
          i+=2;
          break;
        }
        i++;
      }
      if(input[i]=='\0'){
        flag=1;
        break;
      }
    }
  }

  if(flag==0){
    printf("Valid C syntax code!\n");
  }
  else{
    printf("Invalid C syntax code!\n");
  }

  return 0;
}