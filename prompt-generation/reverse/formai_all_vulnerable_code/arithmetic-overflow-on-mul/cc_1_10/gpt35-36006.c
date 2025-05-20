//FormAI DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void print_memory_status(int mem_size){
  if(mem_size <= 0){
    printf("No memory allocated!\n");
    return;
  }
  
  printf("You have %d kilobytes of memory allocated!\n", mem_size);
}

int main(){
  int mem_size = 0;
  char *my_memory = NULL;
  char command = 0;
  
  printf("Welcome to the Memory Management game!\n");
  printf("You are a medieval lord who needs to manage the memory of his castle!\n");
  printf("You currently have %d kilobytes of memory to manage.\n", mem_size);
  
  while(command != 'q'){
    printf("\nWhat would you like to do?\n");
    printf("(m) Allocate memory\n");
    printf("(f) Free memory\n");
    printf("(s) Show memory status\n");
    printf("(q) Quit\n");
    printf("Enter command: ");
    scanf("%c", &command);
    fflush(stdin);
    
    switch(command){
      case 'm':
        printf("\nHow much memory would you like to allocate (in kilobytes)? ");
        int new_mem_size = 0;
        scanf("%d", &new_mem_size);
        fflush(stdin);
        
        if(new_mem_size <= 0){
          printf("Invalid memory size! You must allocate at least 1 kilobyte.\n");
          break;
        }
        
        if(my_memory){
          printf("You already have memory allocated! You can only allocate once.\n");
          break;
        }
        
        my_memory = (char*) malloc(new_mem_size * 1024);
        
        if(!my_memory){
          printf("Not enough memory to allocate!\n");
          break;
        }
        
        mem_size = new_mem_size;
        printf("%d kilobytes of memory allocated successfully!\n", mem_size);
        break;
        
      case 'f':
        if(!my_memory){
          printf("No memory allocated to free!\n");
          break;
        }
        
        free(my_memory);
        my_memory = NULL;
        mem_size = 0;
        printf("Memory freed successfully!\n");
        break;
        
      case 's':
        print_memory_status(mem_size);
        break;
        
      case 'q':
        printf("\nExiting the Memory Management game. Thank you for playing!\n");
        break;
        
      default:
        printf("\nInvalid command, please try again!\n");
        break;
    }
  }
  
  return 0;
}