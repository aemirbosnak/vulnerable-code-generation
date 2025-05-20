//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include <stdio.h>

int main() {
  char input_char;
  printf("Enter a character: ");
  scanf("%c", &input_char);
  
  printf("The ASCII art for %c is:\n", input_char);

  printf("              %d\n", input_char);
  printf("             ");
  for(int i=0; i<5; i++) {
    printf("%c", input_char);
  }
  printf("\n");

  int square_root = sqrt(input_char);
  if(square_root * square_root == input_char) {
    printf("             ");
    for(int i=0; i<5; i++) {
      printf("%c", input_char);
    }
    printf("\n");

    printf("             ");
    for(int i=0; i<5; i++) {
      printf("%c", input_char);
    }
    printf("\n");

    printf("      %d      ", square_root);
    for(int i=0; i<square_root; i++) {
      printf("%c", input_char);
    }
    printf("\n");

    printf("             ");
    for(int i=0; i<5; i++) {
      printf("%c", input_char);
    }
    printf("\n");

    printf("             ");
    for(int i=0; i<5; i++) {
      printf("%c", input_char);
    }
    printf("\n");
  } else {
    printf("             ");
    for(int i=0; i<5; i++) {
      printf("%c", input_char);
    }
    printf("\n");

    printf("             ");
    for(int i=0; i<5; i++) {
      printf("%c", input_char);
    }
    printf("\n");

    printf("      %d      ", square_root + 1);
    for(int i=0; i<square_root; i++) {
      printf("%c", input_char);
    }
    printf("\n");

    printf("             ");
    for(int i=0; i<5; i++) {
      printf("%c", input_char);
    }
    printf("\n");

    printf("             ");
    for(int i=0; i<5; i++) {
      printf("%c", input_char);
    }
    printf("\n");
  }
  
  return 0;
}