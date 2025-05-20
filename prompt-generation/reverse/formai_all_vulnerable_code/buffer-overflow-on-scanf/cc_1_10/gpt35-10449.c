//FormAI DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>

int main() {
  printf("Welcome to the C Syntax Parsing Adventure Game!\n");
  printf("You wake up in a mysterious room, surrounded by code.\n");
  printf("As you look around, you see multiple C files scattered on the ground.\n");
  printf("You realize that in order to escape, you will have to parse through each file and find the correct syntax pattern.\n");
  printf("Are you ready to begin your adventure? (y/n)\n");

  char response;
  scanf("%c", &response);

  if (response == 'y') {
    printf("Great! Let's begin.\n");
    printf("You pick up the first file and see the following code:\n\n");

    printf("#include <stdio.h>\n");
    printf("int main() {\n");
    printf("  printf('Hello World!');\n");
    printf("  return 0;\n");
    printf("}\n\n");

    printf("What is missing in this syntax?\n");
    printf("(a) A semicolon after the printf statement\n");
    printf("(b) A closing bracket after the return statement\n");
    printf("(c) An opening bracket before the main function\n");

    char answer;
    scanf(" %c", &answer);

    if (answer == 'a') {
      printf("Correct! You move on to the next file.\n\n");
    } else {
      printf("Incorrect. You are trapped. Game over.\n");
      return 0;
    }

    printf("The next file contains the following code:\n\n");

    printf("#include <stdio.h>\n");
    printf("int main() {\n");
    printf("  int x = 5;\n");
    printf("  if (x == 5)\n");
    printf("    printf('x is equal to 5!');\n");
    printf("  else\n");
    printf("    printf('x is not equal to 5.');\n");
    printf("  return 0;\n");
    printf("}\n\n");

    printf("What is the correct syntax of an if else statement?\n");
    printf("(a) if <condition> {\n     <statement>\n} else {\n     <statement>\n}\n");
    printf("(b) if (<condition>) {\n     <statement>\n} else {\n     <statement>\n}\n");
    printf("(c) if (<condition>)\n     <statement>;\nelse\n     <statement>;\n");

    scanf(" %c", &answer);

    if (answer == 'b') {
      printf("Correct! You move on to the final file.\n\n");
    } else {
      printf("Incorrect. You are trapped. Game over.\n");
      return 0;
    }

    printf("The final file contains the following code:\n\n");

    printf("#include <stdio.h>\n");
    printf("int main() {\n");
    printf("  int x = 5;\n");
    printf("  int y = 10;\n");
    printf("  int z = x + y;\n");
    printf("  printf('%d', z);\n");
    printf("  return 0;\n");
    printf("}\n\n");

    printf("What is the correct syntax of declaring multiple variables in one line?\n");
    printf("(a) int x, y, z = 0;\n");
    printf("(b) declare x as int;\n     declare y as int;\n     declare z as int;\n");
    printf("(c) int x; int y; int z;\n");

    scanf(" %c", &answer);

    if (answer == 'a') {
      printf("Congratulations! You have completed the C Syntax Parsing Adventure Game!\n");
      return 0;
    } else {
      printf("Incorrect. You are trapped. Game over.\n");
      return 0;
    }
  } else {
    printf("Game over. Goodbye.\n");
  }
}