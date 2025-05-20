//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>

int main() {
  char text[100];
  printf("Enter some text: ");
  scanf("%[^\n]", text);

  printf("\nHere is your ASCII art:\n\n");

  // Loop through each character in the text
  for(int i = 0; text[i] != '\0'; i++) {
    // Get the ASCII value of the character
    int asciiVal = (int) text[i];

    // Print the corresponding ASCII art for each character
    switch(asciiVal) {
      case 32:
        printf("     "); // Space
        break;
      case 33:
        printf(" !   \n"); // !
        printf(" !   \n");
        printf(" !   \n");
        printf("     \n");
        printf(" !   \n");
        break;
      case 34:
        printf(" \" \" \n"); // "
        printf(" \" \" \n");
        printf("     \n");
        printf("     \n");
        printf("     \n");
        break;
      case 35:
        printf(" # # \n"); // #
        printf("#   #\n");
        printf("#####\n");
        printf("#   #\n");
        printf("#   #\n");
        break;
      case 36:
        printf(" $$$ \n"); // $
        printf("$    \n");
        printf(" $$$ \n");
        printf("   $ \n");
        printf(" $$$ \n");
        break;
      // Add more cases for each character (up to 128 total)
      default:
        printf("     \n");
        printf("     \n");
        printf("  %c  \n", text[i]);
        printf("     \n");
        printf("     \n");
        break;
    }
  }

  return 0;
}