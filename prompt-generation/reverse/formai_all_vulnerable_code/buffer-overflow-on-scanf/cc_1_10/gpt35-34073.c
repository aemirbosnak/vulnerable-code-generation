//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>

// This program is a color code converter for people who are extra about their colors.

int main() {
  int hexCode;
  char rgb[20];

  printf("Enter a hex color code (without the # symbol): ");
  scanf("%x", &hexCode);

  sprintf(rgb, "( %d , %d , %d )", (hexCode >> 16) & 0xFF, (hexCode >> 8) & 0xFF, hexCode & 0xFF);

  printf("Your RGB color code is: %s\n", rgb);

  printf("Now let's convert that to an even more extra color code!\n");
  printf("Please choose from one of the following options:\n");

  printf("1. Rainbow Code (ROYGBIV)\n");
  printf("2. Unicorn Code (PPPINK)\n");
  printf("3. Mermaid Code (TTURQUOISE)\n");
  printf("4. Monster Code (BBLUE)\n");
  printf("5. Flower Code (FLILAC)\n");

  int codeOption;
  scanf("%d", &codeOption);

  switch (codeOption) {
    case 1:
      printf("Your Rainbow Code is: ( ");
      printf("%d , ", (hexCode >> 20) & 0xF);
      printf("%d , ", (hexCode >> 16) & 0xF);
      printf("%d , ", (hexCode >> 12) & 0xF);
      printf("%d , ", (hexCode >> 8) & 0xF);
      printf("%d , ", (hexCode >> 4) & 0xF);
      printf("%d )\n", hexCode & 0xF);
      break;

    case 2:
      printf("Your Unicorn Code is: ( ");
      printf("%d , ", (hexCode >> 20) & 0xF + 5);
      printf("%d , ", (hexCode >> 16) & 0xF + 5);
      printf("%d , ", (hexCode >> 12) & 0xF + 5);
      printf("%d , ", (hexCode >> 8) & 0xF + 5);
      printf("%d , ", (hexCode >> 4) & 0xF + 5);
      printf("%d )\n", hexCode & 0xF + 5);
      break;

    case 3:
      printf("Your Mermaid Code is: ( ");
      printf("%d , ", (hexCode >> 20) & 0xF + 2);
      printf("%d , ", (hexCode >> 16) & 0xF + 2);
      printf("%d , ", (hexCode >> 12) & 0xF + 10);
      printf("%d , ", (hexCode >> 8) & 0xF + 2);
      printf("%d , ", (hexCode >> 4) & 0xF + 10);
      printf("%d )\n", hexCode & 0xF + 2);
      break;

    case 4:
      printf("Your Monster Code is: ( ");
      printf("%d , ", (hexCode >> 20) & 0xF - 4);
      printf("%d , ", (hexCode >> 16) & 0xF + 2);
      printf("%d , ", (hexCode >> 12) & 0xF - 4);
      printf("%d , ", (hexCode >> 8) & 0xF);
      printf("%d , ", (hexCode >> 4) & 0xF + 8);
      printf("%d )\n", hexCode & 0xF);
      break;

    case 5:
      printf("Your Flower Code is: ( ");
      printf("%d , ", (hexCode >> 20) & 0xF);
      printf("%d , ", (hexCode >> 16) & 0xF + 5);
      printf("%d , ", (hexCode >> 12) & 0xF + 2);
      printf("%d , ", (hexCode >> 8) & 0xF + 10);
      printf("%d , ", (hexCode >> 4) & 0xF + 5);
      printf("%d )\n", hexCode & 0xF);
      break;

    default:
      printf("Sorry, that's not a valid option. Please try again!\n");
      main();
      break;
  }

  return 0;
}