//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include<stdio.h>
int main(){
  printf("Welcome to my unique search algorithm!\n");
  int data[10] = {2, 3, 6, 8, 9, 12, 14, 17, 22, 25};
  int target, found = 0;
  char shape = 'c';

  do{
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    if(shape == 'c') {
        for(int i = 0; i < 10; i++){
          if(data[i] == target){
            printf("The number %d is found at index %d using circular search\n", target, i);
            found = 1;
            break;
          }
        }
        if(found == 0) printf("The number %d is not found using circular search\n", target);
    }
    else if(shape == 'l') {
        int low = 0, high = 9, mid;

        while(low <= high){
            mid = (low + high) / 2;

            if(data[mid] == target){
              printf("The number %d is found at index %d using linear search\n", target, mid);
              found = 1;
              break;
            }
            else if(data[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        if(found == 0) printf("The number %d is not found using linear search\n", target);
    }
    
    if(found == 0) printf("Would you like to try searching in a different shape? Enter 'c' for circular or 'l' for linear: ");
    else printf("Would you like to search for another number in the same shape? Enter 'y' for yes or 'n' for no: ");
    
    fflush(stdin);
    scanf("%c", &shape);
    found = 0;
  }while(shape == 'c' || shape == 'l');

  printf("Goodbye!\n");
  return 0;
}