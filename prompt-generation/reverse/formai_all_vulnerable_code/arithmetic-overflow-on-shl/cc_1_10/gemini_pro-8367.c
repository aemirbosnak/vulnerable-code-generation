//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main(void) {
  // Let's play with some bits!

  // 😲 Whoa! Look at these 32-bit integers.
  int a = 0xABCDEF01;
  int b = 0x56789ABC;

  // 👀 Peek inside their binary representation.
  printf("a: %08X\nb: %08X\n", a, b);

  // 🎭 Let's put on their bitwise masks.
  int mask1 = 0xFF00FF00; // Mask for even-indexed bits
  int mask2 = 0x00FF00FF; // Mask for odd-indexed bits

  // ✨ Apply the masks to extract the even and odd bits.
  int even_bits = a & mask1;
  int odd_bits = a & mask2;

  // 🎩 Now, let's take off the masks.
  even_bits >>= 8;
  odd_bits <<= 8;

  // 🤹‍♂️ Shuffle the bits!
  a = even_bits | odd_bits;

  // 👀 Let's check if the bits are rearranged.
  printf("Rearranged a: %08X\n", a);

  // 🤝 Let's swap the first and last 8 bits of b.
  b = ((b << 8) & 0xFF00FF00) | ((b >> 8) & 0x00FF00FF);

  // 👀 And see the result.
  printf("Swapped b: %08X\n", b);

  // 👽 We can even set or clear individual bits!
  int bit_to_set = 5;
  int bit_to_clear = 10;

  // 🛠 Set bit 5.
  a |= (1 << bit_to_set);

  // 🧹 Clear bit 10.
  b &= ~(1 << bit_to_clear);

  // 👀 And check the changes.
  printf("Bit 5 set a: %08X\n", a);
  printf("Bit 10 cleared b: %08X\n", b);

  // 🧐 Finally, let's check if a particular bit is set or not.
  int bit_to_check = 7;
  int bit_is_set = (a & (1 << bit_to_check)) != 0;

  // 💡 Report our findings.
  printf("Bit %d in a is %s\n", bit_to_check, bit_is_set ? "set" : "clear");

  // 🎭 We can also perform bitwise operations on characters.
  char c = 'A';

  // 👀 Let's convert it to lower case.
  c |= 0x20;

  // 👀 And check the result.
  printf("Lowercase c: %c (%d)\n", c, c);

  return 0;
}