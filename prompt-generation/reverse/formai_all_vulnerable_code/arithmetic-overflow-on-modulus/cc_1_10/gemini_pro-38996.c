//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: retro
// ** Ye Olde Arithmetike Emporium **

#include <stdio.h>
#include <stdlib.h>

// Declare our trusty abacus
int main(void) {
  // Tokens to hold the digits of our grand calculations
  int a, b, c, d, e, f, g, h, i, j;

  // Fetch the numerals from the user's parchment
  printf("Enter thy first number, good sir:\n");
  scanf("%d", &a);
  printf("Enter thy second number, fair maiden:\n");
  scanf("%d", &b);

  // Perform the arcane rituals of addition
  c = a + b;
  printf("Behold, the sum of thy numbers: %d\n", c);

  // Continue our magical feats with subtraction
  d = a - b;
  printf("And now, the difference betwixt them: %d\n", d);

  // Multiply the digits with the grace of a court wizard
  e = a * b;
  printf("The fruits of thy multiplication: %d\n", e);

  // Divide the spoils as the sages of old
  f = a / b;
  printf("The quotient of thy division: %d\n", f);

  // Delve into the mysteries of modulus
  g = a % b;
  printf("The remainder of thy arcane operation: %d\n", g);

  // Calculate the mean of our digits
  h = (a + b) / 2;
  printf("The average of thy two numbers: %d\n", h);

  // Increment and decrement like the turning of gears
  i = a++;
  j = b--;
  printf("The values after incrementing and decrementing: %d, %d\n", i, j);

  // Assign the grand total to a variable for future use
  int sum = c + e;
  printf("The grand sum of thy calculations: %d\n", sum);

  // Print a farewell message to our noble users
  printf("May thy arithmetical endeavors be ever fruitful!\n");

  return 0;
}