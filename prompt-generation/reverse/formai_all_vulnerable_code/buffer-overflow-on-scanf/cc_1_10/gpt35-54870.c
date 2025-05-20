//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>

void print_letters(int num_chars, char letter) {
  for (int i = 0; i < num_chars; i++) {
    putchar(letter);
  }
}

int main() {
  printf("Hey there, I'm a program that prints out custom ASCII art!\n");
  printf("How many lines of each letter do you want?\n");
  int num_lines = 0;
  scanf("%d", &num_lines);

  // A
  for (int i = 0; i < num_lines; i++) {
    print_letters((num_lines - i), ' ');
    print_letters(i + 1, '*');
    print_letters(i + 1, '*');
    putchar('\n');
  }

  // B
  for (int i = 0; i < num_lines; i++) {
    print_letters(i+1, '*');
    print_letters((num_lines-i-1)*4+1, ' ');
    print_letters(i+1, '*');
    putchar('\n');
  }

  // C
  for (int i = 0; i < num_lines; i++) {
    print_letters((num_lines - i), ' ');
    print_letters(i + 1, '*');
    print_letters((i*2), ' ');
    print_letters(i + 1, '*');
    putchar('\n');
  }

  // D
  for (int i = 0; i < num_lines; i++) {
    print_letters(i+1, '*');
    print_letters(num_lines-i-1, ' ');
    print_letters(num_lines-i-1, ' ');
    print_letters(i+1, '*');
    putchar('\n');
  }

  printf("All done! Thanks for using my ASCII art program!\n");
  return 0;
}