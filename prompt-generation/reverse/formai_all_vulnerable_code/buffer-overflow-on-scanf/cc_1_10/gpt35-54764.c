//FormAI DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include <stdio.h>

int main() {
  
  char* book_title = "The Illusion of Reality";
  int page_number = 1;
  float current_position = 0.00;
  
  while (1) {
    printf("\n\nYou are reading \"%s\"\n\n", book_title);
    printf("You are currently on page %d\n", page_number);
    
    printf("Press 'n' to move to the next page\n");
    printf("Press 'p' to move to the previous page\n");
    printf("Press 'j' to jump to a specific page\n");
    printf("Press 'q' to quit the program\n\n");
    
    printf("Current position: %.2f percent\n", current_position);
  
    char input = getchar();
    getchar(); // Consume newline character
    
    if (input == 'n') {
      page_number++;
      current_position += 0.25;
    }
    else if (input == 'p') {
      if (page_number > 1) {
        page_number--;
        current_position -= 0.25;   
      }
    }
    else if (input == 'j') {
      printf("Enter page number: ");
      scanf("%d", &page_number);
      getchar(); // Consume newline character
      
      if (page_number <= 0) {
        page_number = 1;
      }
      else if (page_number > 100) {
        page_number = 100;
      }
      
      current_position = ((float) page_number - 1) * 0.25;
    }
    else if (input == 'q') {
      printf("Thanks for reading \"%s\"!\n", book_title);
      break;
    }
    else {
      printf("Invalid input. Please try again.\n");
    }
  }
  
  return 0;
}