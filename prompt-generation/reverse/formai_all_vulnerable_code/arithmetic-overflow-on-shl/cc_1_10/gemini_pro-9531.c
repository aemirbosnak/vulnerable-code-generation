//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: Donald Knuth
/*
 * Knuthian Bitwise Operations
 *
 * Behold! A testament to the power and whimsy of the master, Donald Knuth.
 *
 * This program, inspired by the grand master's own writings, delves into the enigmatic realm of bitwise operators.
 * Prepare to witness a symphony of 1s and 0s, as we explore their twisted and wonderful dance.
 *
 * Let us begin our journey with a declaration of intent.
 */

#include <stdio.h>

/*
 * A macro to define the NOT operator.
 */
#define NOT(x) (~x)

/*
 * A macro to define the AND operator.
 */
#define AND(x, y) ((x) & (y))

/*
 * A macro to define the OR operator.
 */
#define OR(x, y) ((x) | (y))

/*
 * A macro to define the XOR operator.
 */
#define XOR(x, y) ((x) ^ (y))

/*
 * A macro to define the shift left operator.
 */
#define SHIFT_LEFT(x, y) ((x) << (y))

/*
 * A macro to define the shift right operator.
 */
#define SHIFT_RIGHT(x, y) ((x) >> (y))

/*
 * A macro to define the rotate left operator.
 */
#define ROTATE_LEFT(x, y) ((x) << (y)) | ((x) >> (32 - (y)))

/*
 * A macro to define the rotate right operator.
 */
#define ROTATE_RIGHT(x, y) ((x) >> (y)) | ((x) << (32 - (y)))

/*
 * A macro to define the reverse bits operator.
 */
#define REVERSE_BITS(x) (((x) >> 24) | (((x) >> 8) & 0x00FF0000) | (((x) << 8) & 0x0000FF00) | ((x) << 24))

/*
 * A macro to define the sign extend operator.
 */
#define SIGN_EXTEND(x, y) (((x) >> (y - 1)) & 1)

/*
 * A macro to define the zero extend operator.
 */
#define ZERO_EXTEND(x, y) ((x) & ((1 << (y)) - 1))

/*
 * And now, let us test our newfound powers!
 */

int main(void) {
  /*
   * Let us begin with a simple NOT operation.
   */
  int x = 0x12345678;
  printf("NOT(x): %08X\n", NOT(x));

  /*
   * Behold, the AND operator in all its glory.
   */
  int y = 0x87654321;
  printf("AND(x, y): %08X\n", AND(x, y));

  /*
   * The OR operator, a symbol of unity.
   */
  printf("OR(x, y): %08X\n", OR(x, y));

  /*
   * The XOR operator, a dance of opposites.
   */
  printf("XOR(x, y): %08X\n", XOR(x, y));

  /*
   * Let us shift our focus to the left.
   */
  printf("SHIFT_LEFT(x, 4): %08X\n", SHIFT_LEFT(x, 4));

  /*
   * And then, to the right.
   */
  printf("SHIFT_RIGHT(x, 4): %08X\n", SHIFT_RIGHT(x, 4));

  /*
   * The rotate left operator, a graceful swirl.
   */
  printf("ROTATE_LEFT(x, 4): %08X\n", ROTATE_LEFT(x, 4));

  /*
   * And the rotate right operator, a mirror image.
   */
  printf("ROTATE_RIGHT(x, 4): %08X\n", ROTATE_RIGHT(x, 4));

  /*
   * Let us reverse the bits, like a time-bending incantation.
   */
  printf("REVERSE_BITS(x): %08X\n", REVERSE_BITS(x));

  /*
   * And now, for the sign extend operator, a tale of hidden secrets.
   */
  printf("SIGN_EXTEND(x, 32): %08X\n", SIGN_EXTEND(x, 32));

  /*
   * And finally, the zero extend operator, a canvas of possibilities.
   */
  printf("ZERO_EXTEND(x, 32): %08X\n", ZERO_EXTEND(x, 32));

  /*
   * Thus ends our journey into the realm of bitwise operators.
   * May you forever wield their power with wisdom and delight.
   */

  return 0;
}