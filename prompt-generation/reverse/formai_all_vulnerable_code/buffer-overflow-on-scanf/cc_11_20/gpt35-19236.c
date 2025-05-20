//FormAI DATASET v1.0 Category: Funny ; Style: imaginative
#include <stdio.h>

int main() {

  int i, j, k, temp;
  char c = 'A';

  printf("Let's create a tower of letters:\n");

  for(i = 1; i <= 10; i++){
    for(j = i; j < 10; j++){
      printf(" ");
    }
    for(k = 1; k <= i * 2 - 1; k++){
      printf("%c", c);
      if(k < i){
        c++;
      }else{
        c--;
      }
    }
    c = 'A';
    printf("\n");
  }

  printf("\nBut wait, there's more! Let's reverse the tower:\n");

  for(i = 10; i >= 1; i--){
    for(j = i; j < 10; j++){
      printf(" ");
    }
    for(k = 1; k <= i * 2 - 1; k++){
      printf("%c", c);
      if(k < i){
        c++;
      }else{
        c--;
      }
    }
    c = 'A';
    printf("\n");
  }

  printf("\nNow let's sort some numbers! Enter 5 integers separated by spaces: ");
  int arr[5];
  for(i = 0; i < 5; i++){
    scanf("%d", &arr[i]);
  }

  for(i = 0; i < 5; i++){
    for(j = i + 1; j < 5; j++){
      if(arr[i] > arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  printf("Your sorted integers are: ");
  for(i = 0; i < 5; i++){
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}